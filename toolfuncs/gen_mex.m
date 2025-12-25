% generate_mex.m 脚本用于将颜色转换函数及 apply_tmf_lut 编译为 MEX
% 请确保已安装 MATLAB Coder 和支持的 C 编译器

%% 1. 定义输入属性
% 基础转换函数的输入：支持 MxNx3 图像和 1x1 标量
% 使用 double(0) 作为模板，[Inf Inf 3] 允许大小变化
example_input_simple = coder.typeof(double(0), [Inf Inf 3], [true true true]);

% apply_tmf_lut 的参数 1: img_rgb (uint8 图像)
img_rgb_type = coder.typeof(uint8(0), [Inf Inf 3], [true true true]);
v_channel_type = coder.typeof(double(0), [Inf Inf], [true true]);

% apply_tmf_lut 的参数 2: node (1x65 double)
node_type = coder.typeof(double(0), [1 65], [false false]);

% apply_tmf_lut 的参数 3: state (结构体)
% 重要：在 codegen 中，结构体的字段顺序和类型必须与函数内部定义严格一致
state = struct();
state.st_i   = double(0);
state.t2_i   = double(0);
state.s2     = double(0);
state.hist   = zeros(64, 1);
state.BL     = double(0);
state.kp_lin = double(0);
state.m_lin  = double(0);
state.s_i    = double(0);
state_type = coder.typeof(state);

params = struct();
params.nbins      = double(0);
params.clip_ratio = double(0);
params.alpha_fast = double(0);
params.alpha_slow = double(0);
params.s2         = double(0);
params.P_mod      = double(0);
params.clip_ratio = double(0);
params_type = coder.typeof(params);
%% 2. 配置 MEX 构建选项
cfg = coder.config('mex');
cfg.GenerateReport = true; 
% 启用动态内存分配，这对于处理不同分辨率的图像非常重要
% cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays'; 

%% 3. 运行编译命令
fprintf('--- 开始生成 MEX 流程 ---\n');

% % 编译颜色转换子函数
% % 注意：即使 apply_tmf_lut 会调用它们，单独编译它们也有助于快速调试类型问题
% try
%     fprintf('正在生成 srgb_to_linear_mex...\n');
%     codegen -config cfg srgb_to_linear -args {example_input_simple}
%     fprintf('正在生成 linear_to_srgb_mex...\n');
%     codegen -config cfg linear_to_srgb -args {example_input_simple}
% catch ME
%     fprintf('子函数编译失败，请检查 .m 文件中是否存在变量类型覆盖（如 a = double(a)）。\n');
%     rethrow(ME);
% end

% 编译主函数 apply_tmf_lut
fprintf('正在生成 apply_tmf_lut_mex...\n');
try
    % 如果 apply_tmf_lut 内部调用了上述两个函数，codegen 会自动分析它们
    codegen -config cfg apply_tmf_lut -args {img_rgb_type, state_type, node_type}
    fprintf('\n[成功] 所有 MEX 文件已生成。\n');
catch ME
    fprintf('\n[错误] apply_tmf_lut 编译失败。\n');
    fprintf('错误原因：%s\n', ME.message);
    fprintf('提示：请确保在 apply_tmf_lut 内部没有对 img_rgb 等输入变量进行类型重赋值。\n');
end

% 编译主函数 cabc_process_frame
fprintf('正在生成 cabc_process_frame...\n');
try
    % 如果 apply_tmf_lut 内部调用了上述两个函数，codegen 会自动分析它们
    codegen -config cfg cabc_process_frame -args {v_channel_type, state_type, params_type}
    fprintf('\n[成功] 所有 MEX 文件已生成。\n');
catch ME
    fprintf('\n[错误] cabc_process_frame 编译失败。\n');
    fprintf('错误原因：%s\n', ME.message);
    fprintf('提示：请确保在 cabc_process_frame 内部没有对 img_rgb 等输入变量进行类型重赋值。\n');
end



% %% 4. 验证与演示
% if exist('apply_tmf_lut_mex', 'file') == 3
%     % 构造符合类型的测试数据
%     test_img = uint8(rand(480, 640, 3) * 255);
%     test_node = rand(1, 65);
%     test_state = state; % 使用模板构造
% 
%     fprintf('\n正在测试 apply_tmf_lut_mex...\n');
%     [out, psnr] = apply_tmf_lut_mex(test_img, test_state, test_node);
%     fprintf('测试通过！输出 PSNR: %.2f dB\n', psnr);
% end