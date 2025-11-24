
# CABC Simulation: Linear RGB  + Piecewise TMF 

This repo reproduces a Content‑Adaptive Backlight Control (CABC) pipeline inspired by **US10199011** and adds practical engineering fixes to avoid color shifts (especially red darkening) and startup brightening. 

## Files

- `create_test_video.m` — 生成测试视频 `my_test_video.mp4` ;
- `advanced_temporal_filter.m` — 时间滤波器，包含 4 个 case 的变换;
- `method`后缀说明 ：
  - `no_lut`: 不使用 lut 插值，每个点计算生成；
  - `65_lut`: 使用 65 个点作为节点，其余点通过插值生成；
  - `simple_case`: 使用简单的 2 种 case（变化快和变化慢）；
  - `4cases`：按照专利提到的四种情况 （变暗很多，变暗一些，变亮很多，变亮一些）
- `main_proc`: 专利实现，但效果不好



## Quick Start

```matlab
% 1) (Optional) Generate the synthetic demo video
create_test_video

% 2) One‑click CABC with comparison video + backlight plot
method3_4cases_65lut.m

% Outputs (in the working directory):
%   my_test_video_cabc_compare.mp4
%   my_test_video_cabc_backlight.png
```



---

## Algorithm Overview

- 该架构的“混合空间处理”流程 7 如下：
  1. **(Step 1) 帧缓冲空间 (FB Space)**：在非线性的FB空间中采样图像，生成直方图，并找到关键点 $k_{FB}(i)$ 和 $m_{FB}(i)$。*此步骤处理海量像素数据，但计算简单。*
  2. **(Step 2) 去伽马 (De-gamma)**：**仅将 $k_{FB}(i)$ 和 $m_{FB}(i)$ 这几个标量值**（而不是整帧图像）通过 `DE-GAMMA` 模块转换到线性空间，得到 $k(i)$ 和 $m(i)$
  3. **(Step 3) 线性空间 (Linear Space)**：在线性空间中进行所有“昂贵”的数学计算：
     - 计算目标TMF斜率 $s(i)$ 和 $s_2$ 7。
     - 将 $s(i)$ 送入 `TEMPORAL FILTER，得到平滑后的斜率 $st(i)$。
     - 计算背光值 $\beta = 1 / st(i)$。
     - 计算最终TMF的查找表（LUT）7。
  4. **(Step 4) 加伽马 (En-gamma)**：将计算出的TMF查找表（例如仅65个点 7）通过 `EN-GAMMA` 模块转换回FB空间。
  5. **(Step 5) 帧缓冲空间 (FB Space)**：`TMF UNIT 模块使用这个（例如65点的）FB空间LUT，对**整帧**图像进行（低成本的）分段线性插值补偿。



---

## Parameters 

| Parameter | Meaning | Typical |
|---|---|---|
| `P_mod_target` | Fraction of pixels allowed in distortion segment | 0.005–0.02 (use 0.01 for UI/solid colors) |
| `s2` | Distortion‑segment slope | 0.3–0.5 |
| `p_max_guard` | Guard percentile for mass clipping | 0.98–0.995 |
| `p_m_top` | Robust top percentile for `m` | 0.999–0.9995 |
| `B_min` | Backlight floor | 0.15–0.25 |
| `B_max_rate` | Backlight ceiling | ≤ 1.0 |
| `ma_window` / `alpha_iir` | Temporal smoothing | 4–8 / 0.4–0.7 |
| `bar_height_frac` | Backlight bar height in comparison video | 0.03–0.07 |
| `APPLY_BL_IN_VIEW` | Multiply processed panel by backlight in the comparison video | true (recommended) |
| `CAP_VIS_TO_ID` | Visualization cap \($s_t \cdot B_{\mathrm{vis}} \le 1$\) | true (recommended) |
| `ENFORCE_NO_BRIGHTENING` | Algorithm cap \($s \le 1/B_{\min}$\) | true (recommended for ramps/UI) |

---

=======
# CABC

