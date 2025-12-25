function linear = srgb_to_linear(srgb)

if isa(srgb, 'uint8')
    srgb_d = double(srgb)/255;
else
    srgb_d = double(srgb);
end

linear = zeros(size(srgb_d), 'like', srgb_d);

gamma_cond = (srgb_d <= 0.04045);
linear(gamma_cond) = srgb_d(gamma_cond)/12.92;
linear(~gamma_cond) = ((srgb_d(~gamma_cond)+0.055)/1.055).^2.4;

end