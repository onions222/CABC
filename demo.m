clear; close all; clc;

%% 第 1 步：定义仿真参数 (全局)
VIDEO_FILE_IN = 'my_test_video.mp4'; % 
VIDEO_FILE_OUT = 'output/rhinos_processed_HSV_Method.mp4'; 

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

fprintf('视频文件 %s 已加载。 \n', v_in.Name);
fprintf('视频宽度 %d 像素 \n', v_in.Width);
fprintf('视频高度 %d 像素 \n', v_in.Height);
fprintf('帧率（fps） %.2f\n', v_in.FrameRate);
fprintf('总帧数 %.2f\n ', v_in.NumFrames);

% Global params
params.nbins      = 64;
params.clip_ratio = 0.0005;
params.alpha_fast = 0.5;
params.alpha_slow = 0.1;
params.s2         = 0.5;
params.P_mod      = 0.05;

% State init
state.st_i   = 1;
state.t2_i   = 1;
state.s2     = 1;
state.hist   = zeros(64, 1);
state.BL     = 1;
state.kp_lin = 1;
state.m_lin  = 1;
state.s_i    = 1;

BL_history   = ones(1, v_in.NumFrames);
si_history   = ones(1, v_in.NumFrames);
psnr_history = 100*ones(1, v_in.NumFrames);

% linear lut
nodes          = linspace(0, 256, 65);
nodes_lin      = srgb_to_linear(nodes);
nodes_lin(end) = 1;

%% 窗口初始化

vidHeight = v_in.Height;
vidWidth = v_in.Width;
vidRatio = vidWidth / vidHeight;

disp('正在初始化后台绘图对象...');

% =========================================================
% 【修改 1】设置 Visible 为 off，不弹出窗口
% =========================================================
% 虽然看不见，但为了保证 getframe 捕捉的分辨率正确，
figHeight = 720;
figWidth  = 1680;
hFig = figure('Name', 'Background Process', ...
    'NumberTitle', 'off', ...
    'Color', 'w', ...
    'Position', [50, 50, figWidth, figHeight], ...
    'Visible', 'off'); % <--- 关键修改：off

% --- 布局参数 (保持紧凑版配置) ---
plotBottom = 0.05;
plotHeight = 0.12;
plotWidth  = 0.70;
plotLeft = (1 - plotWidth) / 2;
layoutGap = 0.08;
imgBottomY = plotBottom + plotHeight + layoutGap;
maxImgHeight = 1 - imgBottomY - 0.04;

subplotWidth = vidRatio * (figHeight/figWidth) * maxImgHeight;
if subplotWidth > 0.48, subplotWidth = 0.48; end
realImgHeight = (subplotWidth / vidRatio) / (figHeight/figWidth);
totalImgWidth = 2 * subplotWidth + 0.01;
startX = (1 - totalImgWidth) / 2;

% --- 创建坐标轴 ---
ax1 = subplot(2, 2, 1);
ax2 = subplot(2, 2, 2);
ax3 = subplot(2, 2, [3, 4]);

firstFrame = readFrame(v_in);
[imgH, imgW, ~] = size(firstFrame);

% --- 初始化绘图对象 ---
hImOriginal = imshow(firstFrame, 'Parent', ax1, 'XData', [1, imgW], 'YData', [1, imgH]);
axis(ax1, 'off'); title(ax1, '原始图像', 'FontSize', 12);

hImProcessed = imshow(firstFrame, 'Parent', ax2, 'XData', [1, imgW], 'YData', [1, imgH]);
axis(ax2, 'off'); title(ax2, '处理后图像', 'FontSize', 12);

% 锁定坐标轴
set(ax1, 'DataAspectRatio', [1 1 1], 'XLim', [0.5, imgW+0.5], 'YLim', [0.5, imgH+0.5], 'XLimMode', 'manual', 'YLimMode', 'manual');
set(ax2, 'DataAspectRatio', [1 1 1], 'XLim', [0.5, imgW+0.5], 'YLim', [0.5, imgH+0.5], 'XLimMode', 'manual', 'YLimMode', 'manual');

hold(ax3, 'on'); grid(ax3, 'on');
frame_idx = 1;
frames = 1:length(BL_history);
yyaxis left
hLine1 = plot(ax3, frames(1:frame_idx), si_history(1:frame_idx), 'r:', 'LineWidth', 1.5);
hold on;
hLine2 = plot(ax3, frames(1:frame_idx), BL_history(1:frame_idx), 'g-', 'LineWidth', 2);
ylabel('Backlight Level (Normalized)');
ylim([0, 1.1]);

yyaxis right;

hLine3 = plot(ax3, frames(1:frame_idx), psnr_history(1:frame_idx), 'b-', 'LineWidth', 1.5);
ylabel('PSNR (dB)');
ylim([0, 100]);


legend(ax3, {'Target BL', 'Actual BL', 'PSNR'}, 'Location', 'southeast', 'Orientation', 'vertical', 'FontSize', 12);
hTitle = title(ax3, 'CABC Response Dynamics: Backlight & Quality', 'FontSize', 10);
xlabel(ax3, 'Frame Count', 'FontSize', 9);
set(ax3, 'FontSize', 9);
grid on;
hold(ax3, 'off');

% --- 应用布局 ---
set(ax3, 'Position', [plotLeft, plotBottom, plotWidth, plotHeight]);
set(ax1, 'Position', [startX, imgBottomY, subplotWidth, realImgHeight]);
set(ax2, 'Position', [startX + subplotWidth + 0.01, imgBottomY, subplotWidth, realImgHeight]);

frameCount = 0;
dataHistory = zeros(0, 3);
vReader.CurrentTime = 0;

% =========================================================
% 【修改 2】添加 Waitbar (进度条)
% =========================================================
% hWait = waitbar(0, '准备开始处理...', 'Name', '视频处理进度');
disp('开始后台处理...');

% 6. 循环
startTime = tic; % 计时
i = 1;
while hasFrame(v_in)
    frame_rgb_8bit = readFrame(v_in);
    frame_rgb      = im2double(frame_rgb_8bit);
    hsv_img        = rgb2hsv(frame_rgb_8bit);
    V              = hsv_img(:,:,3);

    if i == 1
        % 统计信息
        state = cabc_process_frame(V, state, params);

    else
        [img_out_rgb, psnr_val] = apply_tmf_lut(frame_rgb_8bit, state, nodes_lin);
        state = cabc_process_frame(V, state, params);
        si_history(i)   = 1/state.s_i;
        BL_history(i)   = state.BL;
        psnr_history(i) = min(psnr_val, 100);

        % --- 更新数据 (后台进行) ---
        set(hImOriginal, 'CData', frame_rgb_8bit);
        set(hImProcessed, 'CData', img_out_rgb);

        xData = 1:i;
        set(hLine1, 'XData', xData, 'YData', si_history(1:i));
        set(hLine2, 'XData', xData, 'YData', BL_history(1:i));
        set(hLine3, 'XData', xData, 'YData', psnr_history(1:i));
        
        tileString = sprintf('CABC Response Dynamics: Backlight & Quality | frame');
        set(hTitle, 'String', tileString);
        if i > 200
            set(ax3, 'XLim', [i - 200, i + 10]);
        else
            set(ax3, 'XLim', [1, max(200, i + 10)]);
        end

        drawnow limitrate;

        frameStruct = getframe(hFig);
        writeVideo(v_out, frameStruct);

        % % 每 20 帧更新一次进度条，避免拖慢速度
        % if mod(i, 20) == 0
        %     % 更新 Waitbar
        %     if isvalid(hWait)
        %         % 计算剩余时间
        %         elapsedTime = toc(startTime);
        %         avgTimePerFrame = elapsedTime / i;
        %         remainingFrames = totalFrames - i;
        %         remainingTime = remainingFrames * avgTimePerFrame;
        % 
        %         waitbar(i / totalFrames, hWait, ...
        %             sprintf('已处理: %d / %d 帧 (剩余约 %.1f 秒)', ...
        %             i, floor(v_in.NumFrames), remainingTime));
        %     else
        %         % 如果用户点了进度条的取消/关闭，则停止循环
        %         disp('进度条被关闭，停止处理。');
        %         break;
        %     end
        % 
        %     % 命令行输出
        %     fprintf('Processing: %d / %d ...\n', i, floor(v_in.NumFrames));
        % end

    end
    i = i+1;
end

% 清理
close(v_out);
delete(hFig); % 删除后台 Figure
% if isvalid(hWait), delete(hWait); end % 删除进度条

disp('处理完成！视频已保存。');

fprintf('平均功耗节省: %.2f%%\n', 100-mean(BL_history)*100);
fprintf('平均图像质量（PSNR）: % .2f dB\n', mean(psnr_history));
fprintf('最小图像质量（PSNR）: % .2f dB\n', min(psnr_history));



