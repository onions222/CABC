%% 创建一个用于仿真的高级 AVI 视频
%
% 目标：生成一个名为 'my_test_video.avi' 的短视频文件，
%       其中包含多个复杂场景（暗、亮、突变、混合），
%       用于全面测试 Apple 专利仿真的时间滤波器和 TMF 逻辑。


clear; close all; clc;

%% 1. 定义视频参数
VIDEO_FILE_OUT = 'my_test_video.mp4'; % 【【【 更新为 .mp4 】】】
TOTAL_FRAMES = 240; % 视频总帧数 (约 8 秒)
FRAME_RATE = 30;
WIDTH = 320;
FRAME_HEIGHT = 240;

fprintf('正在创建视频写入器: %s\n', VIDEO_FILE_OUT);
v_out = VideoWriter(VIDEO_FILE_OUT, 'MPEG-4'); % 【【【 修正：明确指定 MP4 格式 】】】
v_out.FrameRate = FRAME_RATE;
open(v_out);

%% 2. 生成视频帧
fprintf('正在生成 %d 帧...\n', TOTAL_FRAMES);
[xx, yy] = meshgrid(1:WIDTH, 1:FRAME_HEIGHT); % 【【【 修正：HEIGHT -> FRAME_HEIGHT 】】】

% 循环生成每一帧
for t = 1:TOTAL_FRAMES
    % 创建一个黑色背景 (8-bit RGB)
    current_frame = zeros(FRAME_HEIGHT, WIDTH, 3, 'uint8'); % 【【【 修正：HEIGHT -> FRAME_HEIGHT 】】】 
    
    % --- 模拟场景 ---
    
    if t <= 60
        % -----------------------------------------------------------------
        % 场景 1: 暗场景 - 缓慢淡入 (帧 1-60)
        % 目的：测试 Case II (缓慢变暗 -> s_i 缓慢增大)
        % -----------------------------------------------------------------
        center_x = WIDTH / 2;
        center_y = FRAME_HEIGHT / 2; % 【【【 修正：HEIGHT -> FRAME_HEIGHT 】】】
        radius = FRAME_HEIGHT / 4;   % 【【【 修正：HEIGHT -> FRAME_HEIGHT 】】】
        % 颜色从 20 缓慢增加到 80
        color_val = uint8(round(20 + (t/60) * 60)); 
        
        mask = ((xx - center_x).^2 + (yy - center_y).^2) < radius^2;
        current_frame(mask) = color_val; % R,G,B 通道都设置

    elseif t <= 120
        % -----------------------------------------------------------------
        % 场景 2: 亮场景 - 移动的彩色方块 (帧 61-120)
        % 目的：测试对饱和亮色的处理
        % -----------------------------------------------------------------
        current_frame(:,:,:) = 255; % 白色背景
        
        box_size = 60;
        box_color_R = uint8(255); % 亮红色
        box_color_G = uint8(50);
        box_color_B = uint8(50);
        
        rel_t = t - 60;
        x_pos = round( (WIDTH - box_size) * (rel_t / 60) );
        y_pos = round(FRAME_HEIGHT / 2); % 【【【 修正：HEIGHT -> FRAME_HEIGHT 】】】
        
        y_start = max(1, y_pos - box_size/2);
        y_end = min(FRAME_HEIGHT, y_pos + box_size/2); % 【【【 修正：HEIGHT -> FRAME_HEIGHT 】】】
        x_start = max(1, x_pos - box_size/2);
        x_end = min(WIDTH, x_pos + box_size/2);
        
        current_frame(y_start:y_end, x_start:x_end, 1) = box_color_R;
        current_frame(y_start:y_end, x_start:x_end, 2) = box_color_G;
        current_frame(y_start:y_end, x_start:x_end, 3) = box_color_B;

    elseif t <= 180
        % -----------------------------------------------------------------
        % 场景 3: 突变场景 - 闪烁 (帧 121-180)
        % 目的：压力测试 Case I 和 Case III
        % -----------------------------------------------------------------
        % 每 10 帧在全白和全黑之间切换
        if mod(floor(t/10), 2) == 0
             current_frame(:,:,:) = 0; % 全黑
        else
             current_frame(:,:,:) = 255; % 全白
        end
        
    else
        % -----------------------------------------------------------------
        % 场景 4: 混合场景 - 移动的亮球 (帧 181-240)
        % 目的：测试在保留暗部细节的同时处理亮部
        % -----------------------------------------------------------------
        % 绘制一个灰色网格背景
        grid_val = 80;
        current_frame(1:10:end, :, :) = grid_val;
        current_frame(:, 1:10:end, :) = grid_val;
        
        % 移动的白球
        rel_t = t - 180;
        center_x = round( (WIDTH / 2) + sin(rel_t / 20) * (WIDTH / 3) );
        center_y = round( (FRAME_HEIGHT / 2) + cos(rel_t / 20) * (FRAME_HEIGHT / 3) ); % 【【【 修正：HEIGHT -> FRAME_HEIGHT 】】】
        radius = 30;
        
        mask = ((xx - center_x).^2 + (yy - center_y).^2) < radius^2;
        current_frame(mask) = 255; % R,G,B
    end
    
    % --- 写入帧 ---
    writeVideo(v_out, current_frame);
end

%% 3. 清理
close(v_out);
fprintf('高级测试视频创建完成！\n');
fprintf('文件已保存到: %s\n', VIDEO_FILE_OUT); % 将打印 .mp4

% 可选：播放视频
implay(VIDEO_FILE_OUT);