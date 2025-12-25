%% CABC One-Click: export side-by-side video + backlight plot
% Linear RGB + Method-1 + piecewise TMF + synced BL
% Output:
%   my_test_video_cabc_compare.mp4
%   my_test_video_cabc_backlight.png

clear; clc; close all;

in_file   = 'my_test_video.mp4';
cmp_file  = 'my_test_video_cabc_compare.mp4';
plot_file = 'my_test_video_cabc_backlight.png';

% ------------------ Tunable parameters ------------------
P_mod_target = 0.01;     % 失真段占比
s2           = 0.35;     % 失真段斜率
p_max_guard  = 0.99;     % 主斜率保护分位
p_m_top      = 0.999;    % 上端稳健分位
B_min        = 0.18;     % 背光下限
B_max_rate   = 1.00;     % 背光不升高

% 时间平滑参数
ma_window    = 6;
alpha_iir    = 0.55;

% 背光条高度
bar_height_frac = 0.05;


APPLY_BL_IN_VIEW        = true;  % 并排视频里右侧画面要乘以背光
ENFORCE_NO_BRIGHTENING  = true;  % 算法层面也不允许 s * B_min > 1
CAP_VIS_TO_ID           = true;  % 可视化再保险，防止显示出净增亮

% --------------------------------------------------------
vr = VideoReader(in_file);
vw = VideoWriter(cmp_file, 'MPEG-4');
vw.FrameRate = vr.FrameRate;
open(vw);

s_hist   = [];
s_smooth = 1.0;
atf_ready = false;
atf_state = struct();

s_inst_series   = [];
s_smooth_series = [];
B_series        = [];

frame_idx = 0;
while hasFrame(vr)
    frame_idx = frame_idx + 1;
    rgb = im2double(readFrame(vr));
    [H,W,~] = size(rgb);

    % 1) sRGB -> Linear RGB
    lin = srgb2lin(rgb);

    % 2) Method-1
    P = max(lin, [], 3);

    % 3) 膝点和上端
    k = max(1e-4, qtile(P(:), 1 - P_mod_target));
    m = max(k+1e-4, qtile(P(:), p_m_top));

    % 4) 主斜率两个约束
    P99 = max(k, qtile(P(:), p_max_guard));
    s_guard = 1.0 / max(P99, 1e-4);
    if m > k
        s_cont = (1.0 - s2*(m - k)) / max(k, 1e-4);
    else
        s_cont = s_guard;
    end

    % 原本是 min([s_guard, s_cont, 6.0])
    % 现在加上 1/B_min 的硬上限
    if ENFORCE_NO_BRIGHTENING
        s_cap = 1.0 / B_min;     % 保证 s * B_min <= 1
        s_inst = min([s_guard, s_cont, s_cap]);
    else
        s_inst = min([s_guard, s_cont, 6.0]);
    end
    s_inst = max(s_inst, 1.0);   % 不做暗化

    % 5) 时间平滑
    if exist('advanced_temporal_filter', 'file') == 2
        try
            if ~atf_ready
                % th2: 判定"变化已经回落到很小，可以恢复强平滑"的退出阈值
                % th1: 判定"当前帧变化很大，需要快速响应”的进入阈值
                % window_short: ATF 进入"快速变化”状态时使用的最小平滑窗口长度
                % window_long:  窗口越长，抑制闪烁/细小抖动的能力越强，但响应变慢、过渡更平滑
                atf_state.params.window_short = 3;
                atf_state.params.window_long  = 7;
                atf_state.params.th1 = 0.15;
                atf_state.params.th2 = 0.05;
                atf_state.fifo_queue = ones(1, atf_state.params.window_short) * s_inst;
                atf_state.current_length = numel(atf_state.fifo_queue);
                atf_state.current_case   = 1;
                atf_ready = true;
            end
            [s_smooth, atf_state] = advanced_temporal_filter(s_inst, atf_state);
        catch
            [s_smooth, s_hist] = smooth_fallback(s_inst, s_hist, ma_window, alpha_iir, frame_idx, s_smooth);
        end
    else
        [s_smooth, s_hist] = smooth_fallback(s_inst, s_hist, ma_window, alpha_iir, frame_idx, s_smooth);
    end

    % 6) 背光
    B = 1.0 / max(s_smooth, 1e-6);
    B = min(max(B, B_min), B_max_rate);

    % 7) 在线性 RGB 上做 TMF
    lin_out = apply_tmf_linear(lin, k, s_smooth, s2);

    % 8) 并排输出
    srgb_orig = rgb;

    if APPLY_BL_IN_VIEW
        B_vis = B;
        if CAP_VIS_TO_ID
            B_vis = min(B_vis, 1.0 / max(s_smooth, 1e-6));  % 防止可视化净增亮
        end
        lin_out_view = min(max(lin_out * B_vis, 0), 1);
        srgb_proc = lin2srgb(lin_out_view);
    else
        srgb_proc = lin2srgb(lin_out);
    end

    panelW = W;
    panelH = H;
    canvas = zeros(panelH, 2*panelW, 3);
    canvas(:, 1:panelW, :) = srgb_orig;
    canvas(:, panelW+1:end, :) = srgb_proc;

    bar_h = max(2, round(bar_height_frac * panelH));
    canvas = draw_bar(canvas, 1, 1.0, bar_h);  % 左边 100%
    canvas = draw_bar(canvas, 2, B,   bar_h);  % 右边实际背光

    writeVideo(vw, im2uint8(canvas));

    % 日志
    s_inst_series(end+1)   = s_inst;
    s_smooth_series(end+1) = s_smooth;
    B_series(end+1)        = B;
end

close(vw);

% 生成背光曲线图
t = 1:numel(s_inst_series);
fig = figure('Name','CABC Diagnostics','Color','w','Position',[100,100,960,700]);
subplot(3,1,1); plot(t, s_inst_series, '-'); grid on; title('Instant slope s(i)');
subplot(3,1,2); plot(t, s_smooth_series, '-','LineWidth',1.5); grid on; title('Smoothed slope s_t(i)');
subplot(3,1,3); plot(t, 100*B_series, '-','LineWidth',1.5); grid on; title('Backlight (%)');
exportgraphics(fig, plot_file, 'Resolution', 160);

disp('Wrote comparison video:'); disp(cmp_file);
disp('Wrote backlight plot:');  disp(plot_file);

%% --------- helpers ----------
function [s_smooth, s_hist] = smooth_fallback(s_inst, s_hist, ma_window, alpha_iir, frame_idx, s_smooth)
if ma_window >= 2
    s_hist = [s_hist, s_inst];
    if numel(s_hist) > ma_window, s_hist = s_hist(end-ma_window+1:end); end
    s_smooth = mean(s_hist);
else
    if frame_idx == 1
        s_smooth = s_inst;
    else
        s_smooth = alpha_iir*s_smooth + (1-alpha_iir)*s_inst;
    end
end
end

function x = srgb2lin(x)
mask = (x <= 0.04045);
x(mask)  = x(mask)/12.92;
x(~mask) = ((x(~mask)+0.055)/1.055).^2.4;
end

function x = lin2srgb(x)
mask = (x <= 0.0031308);
x(mask)  = 12.92*x(mask);
x(~mask) = 1.055*(x(~mask).^(1/2.4)) - 0.055;
x = min(max(x,0),1);
end

function y = apply_tmf_linear(x, k, s, s2)
y = zeros(size(x), 'like', x);
for c = 1:3
    y(:,:,c) = piecewise_map(x(:,:,c), k, s, s2);
end
end

function y = piecewise_map(x, k, s, s2)
y = zeros(size(x), 'like', x);
idx1 = (x <= k);
y(idx1) = s .* x(idx1);
idx2 = ~idx1;
y(idx2) = s*k + s2.*(x(idx2) - k);
y = min(max(y, 0), 1);
end

function q = qtile(x, qf)
if exist('quantile','builtin') == 5 || exist('quantile','file') == 2
    q = quantile(x, qf);
elseif exist('prctile','file') == 2
    q = prctile(x, 100*qf);
else
    x = sort(x);
    n = numel(x);
    idx = max(1, min(n, round(qf*n)));
    q = x(idx);
end
end

function img = draw_bar(img, panel_idx, frac, bar_h)
[H,W,~] = size(img);
panelW = W/2;
x0 = round((panel_idx-1)*panelW) + 1;
x1 = round(panel_idx*panelW);
y0 = H - bar_h + 1;
y1 = H;
bg = 0.20;
img(y0:y1, x0:x1, :) = bg;
fw = x0 - 1 + round(frac * (panelW - 4));
fw = min(max(fw, x0+2), x1-2);
img(y0+2:y1-2, x0+2:fw, :) = 0.95;
img([y0 y1], x0:x1, :) = 1.0;
img(y0:y1, [x0 x1], :) = 1.0;
end