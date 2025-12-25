function [s_i, t2] = compute_tmf(k, m, params)
%COMPUTE_TMF 计算 tone mapping function
%   此处显示详细说明

s2          = params.s2;
S_MAX_CLAMP = 5;

% 转到线性域
m = (m/64).^2.2;
num = 1.0-s2*(m-k);

if num < 1e-6
    s_i = S_MAX_CLAMP;
else
    s_i = num / k;
end

s_i = max(1.0, min(s_i, S_MAX_CLAMP));

t2 = 1.0 - m*s2;

end