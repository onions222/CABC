%% Apple 专利 (US10199011) 仿真 - 完整视频处理流程
%
% 目标：这是一个完整的仿真脚本，它将加载一个视频文件，
%       逐帧应用 Apple 专利的算法，并输出一个对比视频。
%

clear; close all; clc;

%% 第 1 步：定义仿真参数 (全局)
% --- 您可以在这里调整 ---
VIDEO_FILE_IN = 'my_test_video.mp4'; % 
VIDEO_FILE_OUT = 'rhinos_processed_HSV_Method.mp4'; % 【【【 更新为 .mp4 】】】

% Step 1 (分析) 参数
P_mod_target = 0.03; % 目标失真百分比 (3%) [cite: 955-959]
clip_percent = 0.001; % 忽略的噪点百分比 (0.1%)
hist_bins = 256; % 8-bit 精度

% Step 2 (计算) 参数
GAMMA = 2.2; % 假设的显示器 Gamma 值
s2 = 0.7;    % 预设的“失真区”斜率 s2 [cite: 994-997]
S_MAX_CLAMP = 5.0; % 【【【 s_i 的最大限制 (Clamp)，防止暗场景噪点放大 】】】

% Step 3 (滤波) 参数
% (高级滤波器 "advanced_temporal_filter.m" 的参数)
filter_params.pth_md = 0.3;  % Case I 阈值 (30% 增量) [cite: 1027-1033]
filter_params.pth_mb = 0.3;  % Case III 阈值 (30% 减量) [cite: 1027-1033]
filter_params.len_tmd = 128; % Case I 长度 (变暗很多)
filter_params.len_td  = 32;  % Case II 长度 (变暗一些)
filter_params.len_tmb = 4;   % Case III 长度 (变亮很多)
filter_params.len_tb  = 16;  % Case IV 长度 (变亮一些)

% Step 4 (应用 TMF) 参数
% (我们现在只使用 LUT 方式，因为它更接近硬件)
NUM_LUT_NODES = 65;           % [cite: 1121-1122, 1188-1189]

% -------------------------
fprintf('仿真参数初始化...完成。\n');

%% 第 2 步：初始化视频 I/O 和滤波器状态

% 1. 初始化视频读取器
try
    v_in = VideoReader(VIDEO_FILE_IN);
catch
    fprintf('错误：无法读取视频文件 "%s"\n', VIDEO_FILE_IN);
    fprintf('请检查 VIDEO_FILE_IN 变量是否设置了正确的文件路径。\n');
    return;
end
fprintf('视频文件 "%s" 已加载。\n', v_in.Name);

% 2. 初始化视频写入器
v_out = VideoWriter(VIDEO_FILE_OUT, 'MPEG-4'); % 【【【 修正：明确指定 MP4 格式 】】】
v_out.FrameRate = v_in.FrameRate;
open(v_out);

% 3. 初始化时间滤波器状态 (用于 "advanced_temporal_filter.m")
filter_state.params = filter_params;
filter_state.current_length = filter_params.len_td; 
filter_state.current_case = 2; 
filter_state.fifo_queue = ones(1, filter_state.current_length); 


% 4. 初始化数据存储
s_i_history = []; 
st_i_history = []; 
backlight_history = []; 

fprintf('视频 I/O 和滤波器已初始化。\n');
fprintf('开始逐帧处理... (这可能需要几分钟)\n');

%% 第 3 步：逐帧处理循环
frameCount = 0;
while hasFrame(v_in)
    % -----------------------------------------------------------------
    % (A) 读取原始帧
    % -----------------------------------------------------------------
    frame_rgb_8bit = readFrame(v_in);
    frame_rgb_fb = im2double(frame_rgb_8bit); % [0, 1] (FB Space)
    frameCount = frameCount + 1;

    % -----------------------------------------------------------------
    % (B) 执行【第 1 步逻辑】：分析帧 [对应 104, 108, 110]
    % -----------------------------------------------------------------
    % 【【【 恢复为 Method 1：HSV (V-Channel / max(R,G,B)) 】】】
    frame_hsv_fb = rgb2hsv(frame_rgb_fb);
    frame_p_fb = frame_hsv_fb(:,:,3); % V channel (Value = max(R,G,B))
    
    [counts, binLocations] = imhist(frame_p_fb, hist_bins);
    total_pixels = sum(counts);
    cdf = cumsum(counts) / total_pixels;
    
    m_index = find(cdf >= (1 - clip_percent), 1, 'first');
    if isempty(m_index), m_index = hist_bins; end
    m_fb = binLocations(m_index);
    
    k_index = find(cdf >= (1 - P_mod_target), 1, 'first');
    if isempty(k_index), k_index = hist_bins; end
    k_fb = binLocations(k_index);
    
    k_fb = min(k_fb, m_fb);
    
    % -----------------------------------------------------------------
    % (C) 执行【第 2 步逻辑】：计算瞬时斜率 [对应 116, 118]
    % -----------------------------------------------------------------
    m_lin = m_fb ^ GAMMA;
    k_lin = k_fb ^ GAMMA;
    
    if k_lin < 1e-6 % 避免除以零
        s_i = 1.0;
    else
        s_i = (1 - s2 * (m_lin - k_lin)) / k_lin; 
    end
    
    % 【【【 关键：限制 s_i 防止噪点放大 (对应您的 s_i=270 问题) 】】】
    s_i = max(1.0, min(s_i, S_MAX_CLAMP)); 
    
    % -----------------------------------------------------------------
    % (D) 执行【第 3 步逻辑】：时间滤波器 [对应 144]
    % -----------------------------------------------------------------
    [st_i, filter_state] = advanced_temporal_filter(s_i, filter_state);
    
    % -----------------------------------------------------------------
    % (E) 执行【第 4 步逻辑】：应用 TMF (HSV V-Channel) [对应 124, 150, 102]
    % -----------------------------------------------------------------
    
    % 1. 计算最终 TMF 参数 [对应 TMF Generation (124)]
    t2_i = 1 - s2 * m_lin; 
    if abs(st_i - s2) < 1e-6 
        kt_lin = m_lin;
    else
        kt_lin = t2_i / (st_i - s2); 
    end
    
    final_m_lin = m_lin;
    final_s2 = s2;
    final_t2_i = t2_i;
    
    if kt_lin >= m_lin % 检查 FIG. 16 的情况
        final_m_lin = 1 / st_i;
        kt_lin = final_m_lin;
        final_s2 = st_i;
        final_t2_i = 0;
    end
    
    % 2. 计算最终背光值 [对应 Backlight Modification (150)]
    bl_final_value = 1 / st_i; 

    % 3. 【【【 核心修正：应用 TMF 到 HSV 的 V 通道 】】】
    
    % 3a. De-Gamma 整个 V-channel (FB -> Linear)
    % frame_p_fb (V-channel) 是从 (B) 部分获取的
    frame_p_lin = frame_p_fb .^ GAMMA;
    
    % 3b. 创建 65 点线性 LUT (V_in_lin -> V_out_lin)
    lut_nodes_in_lin = (linspace(0, 1, NUM_LUT_NODES)').^GAMMA;
    lut_nodes_out_lin = zeros(size(lut_nodes_in_lin));
    
    idx1 = (lut_nodes_in_lin <= kt_lin);
    idx2 = (lut_nodes_in_lin > kt_lin) & (lut_nodes_in_lin <= final_m_lin);
    idx3 = (lut_nodes_in_lin > final_m_lin);
    
    lut_nodes_out_lin(idx1) = lut_nodes_in_lin(idx1) * st_i;
    lut_nodes_out_lin(idx2) = lut_nodes_in_lin(idx2) * final_s2 + final_t2_i;
    lut_nodes_out_lin(idx3) = 1.0;
    
    % 3c. 插值得到整个帧的 V_out_lin
    V_out_lin = interp1(lut_nodes_in_lin, lut_nodes_out_lin, frame_p_lin, 'linear', 'extrap');
    
    % 3d. En-Gamma 最终的 V 帧 (Linear -> FB)
    V_out_fb = V_out_lin .^ (1/GAMMA);
    
    % 3e. 确保 V_out_fb 在 [0, 1] 范围内
    V_out_fb(V_out_fb > 1) = 1;
    V_out_fb(V_out_fb < 0) = 0;
    
    % 3f. 重建 HSV 帧 [对应 TMF Unit (102)]
    % frame_hsv_fb 是从 (B) 部分获取的
    frame_hsv_out_fb = frame_hsv_fb; % 保持原始的 H 和 S 通道
    frame_hsv_out_fb(:,:,3) = V_out_fb; % 仅替换 V 通道
    
    % 3g. 将最终的 HSV 帧转换回 RGB (FB Space)
    frame_out_fb = hsv2rgb(frame_hsv_out_fb);
    
    % -----------------------------------------------------------------
    
    % 4. 确保 RGB 值在 [0, 1] 范围内 (hsv2rgb 可能会产生轻微超调)
    frame_out_fb(frame_out_fb > 1) = 1;
    frame_out_fb(frame_out_fb < 0) = 0;
    
    % 5. 模拟感知亮度
    frame_original_perceived = frame_rgb_fb * 1.0; 
    frame_processed_perceived = frame_out_fb * bl_final_value; 
    
    % -----------------------------------------------------------------
    % (F) 写入输出视频
    % -----------------------------------------------------------------
    comparison_frame = [frame_original_perceived, frame_processed_perceived];
    comparison_frame_8bit = im2uint8(comparison_frame);
    
    text_original = sprintf('原始 @ 100%% 背光');
    text_processed = sprintf('处理后 @ %.1f%% 背光', bl_final_value * 100);
    
    comparison_frame_8bit = insertText(comparison_frame_8bit, [10 10], text_original, 'FontSize', 18, 'BoxColor', 'black', 'TextColor', 'white');
    comparison_frame_8bit = insertText(comparison_frame_8bit, [size(frame_rgb_fb, 2)+10 10], text_processed, 'FontSize', 18, 'BoxColor', 'black', 'TextColor', 'white');
    
    writeVideo(v_out, comparison_frame_8bit);
    
    % -----------------------------------------------------------------
    % (G) 存储历史数据
    % -----------------------------------------------------------------
    s_i_history(end+1) = s_i;
    st_i_history(end+1) = st_i;
    backlight_history(end+1) = bl_final_value;
    
    if mod(frameCount, 10) == 0
        fprintf('已处理 %d 帧... (当前背光: %.1f%%)\n', frameCount, bl_final_value * 100);
    end
end

%% 第 4 步：清理并显示结果
close(v_out);
fprintf('仿真完成！\n');
fprintf('已处理 %d 帧。\n', frameCount);
fprintf('输出视频已保存到: %s\n', VIDEO_FILE_OUT);

% 绘制斜率变化图
figure('Name', 'Apple 专利仿真 - 完整结果 (Method 1: HSV V-Channel)');
t = 1:frameCount;
subplot(2, 1, 1);
plot(t, s_i_history, 'b-', 'DisplayName', '瞬时 s(i)');
hold on;
plot(t, st_i_history, 'r-', 'LineWidth', 2, 'DisplayName', '平滑后 st(i)');
title('瞬时斜率 vs 平滑后斜率 (基于 V-Channel / max(R,G,B))');
xlabel('帧数'); ylabel('斜率');
legend; grid on;

% 绘制背光变化图
subplot(2, 1, 2);
plot(t, backlight_history * 100, 'k-', 'LineWidth', 2, 'DisplayName', '背光强度');
title('背光强度随时间的变化');
xlabel('帧数'); ylabel('背光 (%)');
grid on;