function srgb = linear_to_srgb(linear)
lin_d = double(linear);
srgb  = zeros(size(lin_d), "like", lin_d);

inv_gamma_cond = (lin_d <= 0.0031308);
srgb(inv_gamma_cond)  = lin_d(inv_gamma_cond)*12.92;
srgb(~inv_gamma_cond) = 1.055*(lin_d(~inv_gamma_cond).^(1/2.4)) - 0.055;

srgb(srgb<0) = 0;
srgb(srgb>1) = 1;


end