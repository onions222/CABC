function [out_srgb_norm] = interpolation_v(img_dbl, tmf_lut)
%INTERPOLATION_V 计算 65 nodes 插值
idx_base = floor(img_dbl / 4);

rem_val = mod(img_dbl, 4);
w = rem_val/4.0;

idx1 = idx_base+1;
idx2 = idx1 +1;

val1 = tmf_lut(idx1);
val2 = tmf_lut(idx2);

out_srgb_norm = val1.*(1-w) + val2.*w;

end