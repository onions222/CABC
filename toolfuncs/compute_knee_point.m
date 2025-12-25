function [k_fb, m_index] = compute_knee_point(hist, binLocations, params)
%COMPUTE_KNEE_POINT 计算 knee point

total_pixels = sum(hist);
cdf = cumsum(hist)/total_pixels;
clip_percent = params.clip_ratio;
P_mod = params.P_mod;

m_index = find(cdf >= (1-clip_percent), 1, 'first');
if isempty(m_index) 
    m_index = 64;end
% m_fb = binLocations(m_index);

k_index = find(cdf >= (1-P_mod), 1, 'first');
if isempty(k_index) 
    m_index = 64;end
k_fb = binLocations(k_index);

end