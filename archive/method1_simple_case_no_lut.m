
%% CABC One-Click: export side-by-side video + backlight plot
% Pipeline: Linear RGB + Method-1 (maxRGB) + piecewise TMF + synced backlight
% Output:
%   - my_test_video_cabc_compare.mp4   (side-by-side: left original, right processed with BL bars)
%   - my_test_video_cabc_backlight.png (3-panel diagnostics: s(i), s_t(i), BL%)
%
% Usage:
%   create_test_video           % (optional) generate demo input
%   main_proc_linear_method1    % one-click export

clear; clc; close all;

in_file   = 'my_test_video.mp4';
cmp_file  = 'my_test_video_cabc_compare.mp4';
plot_file = 'my_test_video_cabc_backlight.png';

% ------------------ Tunable parameters ------------------
P_mod_target = 0.01;    % 1% pixels in distortion segment (protect colors)
s2           = 0.35;    % slope in distortion region
p_max_guard  = 0.99;    % guard percentile to bound s (avoid mass clipping)
p_m_top      = 0.999;   % robust top value m
B_min        = 0.18;    % minimum backlight
B_max_rate   = 1.00;    % do not raise above 1
% temporal smoothing (fallback if advanced_temporal_filter is unavailable)
ENFORCE_NO_BRIGHTENING = true; % ensure s*B_min <= 1 at algorithm level
APPLY_BL_IN_VIEW   = true;   % multiply processed frame by backlight for visualization
CAP_VIS_TO_ID      = true;    % cap visual backlight to keep s*B_vis <= 1 (avoid early brightening)
ma_window    = 6;       % moving average window for s
alpha_iir    = 0.55;    % IIR smoothing if ma_window<2
bar_height_frac = 0.05; % backlight bar height fraction (5% of image height)

% --------------------------------------------------------
vr = VideoReader(in_file);
vw = VideoWriter(cmp_file, 'MPEG-4');
vw.FrameRate = vr.FrameRate;
open(vw);

% script-level state (no persistent)
s_hist = [];
s_smooth = 1.0;
atf_ready = false;
atf_state = struct();

% logs for diagnostics
s_inst_series = [];
s_smooth_series = [];
B_series = [];

frame_idx = 0;
while hasFrame(vr)
    frame_idx = frame_idx + 1;
    rgb = im2double(readFrame(vr));
    [H,W,~] = size(rgb);

    % 1) sRGB -> Linear RGB
    lin = srgb2lin(rgb);

    % 2) Method-1 brightness proxy (linear)
    P = max(lin, [], 3);

    % 3) Knee k and robust top m
    k = max(1e-4, qtile(P(:), 1 - P_mod_target));   % knee at (1 - P_mod) quantile
    m = max(k+1e-4, qtile(P(:), p_m_top));          % robust top

    % 4) main slope bounds
    P99 = max(k, qtile(P(:), p_max_guard));
    s_guard = 1.0 / max(P99, 1e-4);
    if m > k
        s_cont = (1.0 - s2*(m - k)) / max(k, 1e-4);
    else
        s_cont = s_guard; % degenerate
    end
    s_inst = min([s_guard, s_cont, 6.0]); % cap
    s_inst = max(s_inst, 1.0);            % do not dim (<1)

    % 5) temporal smoothing of s
    if exist('advanced_temporal_filter', 'file') == 2
        try
            if ~atf_ready
                atf_state.params.window_short = 3;
                atf_state.params.window_long  = 7;
                atf_state.params.th1 = 0.15;
                atf_state.params.th2 = 0.05;
                atf_state.fifo_queue = ones(1, atf_state.params.window_short) * s_inst;
                atf_state.current_length = numel(atf_state.fifo_queue);
                atf_state.current_case = 1;
                atf_ready = true;
            end
            [s_smooth, atf_state] = advanced_temporal_filter(s_inst, atf_state);
        catch
            [s_smooth, s_hist] = smooth_fallback(s_inst, s_hist, ma_window, alpha_iir, frame_idx, s_smooth);
        end
    else
        [s_smooth, s_hist] = smooth_fallback(s_inst, s_hist, ma_window, alpha_iir, frame_idx, s_smooth);
    end

    % 6) backlight
    B = 1.0 / max(s_smooth, 1e-6);
    B = min(max(B, B_min), B_max_rate);

    % 7) Apply TMF (linear space, per channel)
    lin_out = apply_tmf_linear(lin, k, s_smooth, s2);

    % Convert to sRGB
    srgb_orig = rgb;
    % Visualization: apply backlight to processed frame for fair comparison
B_vis = B;
if CAP_VIS_TO_ID
    B_vis = min(B_vis, 1.0 / max(s_smooth, 1e-6)); % ensure s*B_vis <= 1
end
lin_out_view = min(max(lin_out * B_vis, 0), 1);
srgb_proc = lin2srgb(lin_out_view);

    % 8) Compose side-by-side
    panelW = W;
    panelH = H;
    canvas = zeros(panelH, 2*panelW, 3);
    canvas(:, 1:panelW, :) = srgb_orig;
    canvas(:, panelW+1:end, :) = srgb_proc;

    % 9) Draw backlight bars
    bar_h = max(2, round(bar_height_frac * panelH));
    % Left: BL=100%
    canvas = draw_bar(canvas, 1, 1.0, bar_h);
    % Right: BL=B
    canvas = draw_bar(canvas, 2, B, bar_h);

    % Optional text if CVT is available
    if exist('insertText','file') == 2 %#ok<EXIST>
        try
            canvas = insertText(canvas, [10, panelH - bar_h - 20], sprintf('BL=100%%'), 'FontSize', 14, 'TextColor', 'white', 'BoxOpacity', 0);
            canvas = insertText(canvas, [panelW+10, panelH - bar_h - 20], sprintf('BL=%d%%', round(100*B)), 'FontSize', 14, 'TextColor', 'white', 'BoxOpacity', 0);
        catch
        end
    end

    writeVideo(vw, im2uint8(canvas));

    % logs
    s_inst_series(end+1)   = s_inst;   %#ok<SAGROW>
    s_smooth_series(end+1) = s_smooth; %#ok<SAGROW>
    B_series(end+1)        = B;        %#ok<SAGROW>
end

close(vw);
fprintf('Wrote comparison video: %s\n', cmp_file);

% 10) Backlight & slopes plot
t = 1:numel(s_inst_series);
fig = figure('Name','CABC Diagnostics','Color','w','Position',[100,100,960,700]);
subplot(3,1,1); plot(t, s_inst_series, '-'); grid on; title('Instant slope s(i)');
xlabel('Frame'); ylabel('s');
subplot(3,1,2); plot(t, s_smooth_series, '-','LineWidth',1.5); grid on; title('Smoothed slope s_t(i)');
xlabel('Frame'); ylabel('s_t');
subplot(3,1,3); plot(t, 100*B_series, '-','LineWidth',1.5); grid on; title('Backlight (%)');
xlabel('Frame'); ylabel('%');
exportgraphics(fig, plot_file, 'Resolution', 160);
fprintf('Wrote backlight plot: %s\n', plot_file);

%% --------------- helpers ---------------
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
    xc = x(:,:,c);
    y(:,:,c) = piecewise_map(xc, k, s, s2);
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
% Robust quantile fallback
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
% Draw a white bar at bottom on the specified panel.
[H,W,~] = size(img);
panelW = W/2;
x0 = round((panel_idx-1)*panelW) + 1;
x1 = round(panel_idx*panelW);
y0 = H - bar_h + 1;
y1 = H;
% background strip
bg = 0.20;
img(y0:y1, x0:x1, :) = bg;
% filled width
fw = x0 - 1 + round(frac * (panelW - 4));
fw = min(max(fw, x0+2), x1-2);
img(y0+2:y1-2, x0+2:fw, :) = 0.95; % bright
% thin border
img([y0 y1], x0:x1, :) = 1.0;
img(y0:y1, [x0 x1], :) = 1.0;
end


function [node_x, node_y] = build_tmf_nodes(k, s, s2, N)
% Build 65-node (default) TMF in linear RGB domain for scalar input x in [0,1].
% Nodes are uniform in [0,1] by default; y is piecewise-defined with knee k.
if nargin < 4, N = 65; end
node_x = linspace(0,1,N);
node_y = piecewise_map(node_x, k, s, s2);
node_y = min(max(node_y, 0), 1);
end

function yimg = apply_tmf_linear_lut(img, node_x, node_y, interp_kind)
% Apply per-channel LUT using interp1
if nargin < 4, interp_kind = 'pchip'; end
yimg = zeros(size(img), 'like', img);
for c = 1:3
    yimg(:,:,c) = interp1(node_x, node_y, img(:,:,c), interp_kind, 'extrap');
end
yimg = min(max(yimg, 0), 1);
end
