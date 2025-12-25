function [st_i, state_out] = advanced_temporal_filter(s_i, state_in)
% ADVANCED_TEMPORAL_FILTER 模拟 Apple 专利 (US10199011) 中的
% 时间滤波器，包含 Case 1-4 的逻辑。
%
%   用法:
%       % 1. (在循环外) 初始化状态
%       state.params = ...;
%       state.fifo_queue = ...;
%
%       % 2. (在循环内) 逐帧调用
%       [st_i, state] = advanced_temporal_filter(s_i, state);
%
%   Inputs:
%       s_i        - (scalar) 当前帧的瞬时斜率 s(i)
%       state_in   - (struct) 包含滤波器当前状态的结构体
%
%   Outputs:
%       st_i       - (scalar) 平滑后的过渡斜率 st(i)
%       state_out  - (struct) 包含滤波器*更新后*状态的结构体

    % -----------------------------------------------------------------
    % (A) 从 state_in 结构体中“解包”当前状态
    % -----------------------------------------------------------------
    fifo_queue     = state_in.fifo_queue;
    current_length = state_in.current_length;
    current_case   = state_in.current_case;
    params         = state_in.params;
    
    % -----------------------------------------------------------------
    % (B) 正常逐帧处理 (逻辑与之前相同)
    % -----------------------------------------------------------------
    
    % 1. 获取上一帧的平均值 (st(i-1))
    st_prev = mean(fifo_queue);
    
    % 2. 确定新 Case 和新 Length [cite: 1027-1033]
    if s_i > st_prev * (1 + params.pth_md)
        % Case I: 变暗很多 (例如，s_i > 1.3 * st_prev)
        new_case = 1;
        new_length = params.len_tmd;
    elseif s_i > st_prev
        % Case II: 变暗一些 (s_i > st_prev)
        new_case = 2;
        new_length = params.len_td;
    elseif s_i < st_prev * (1 - params.pth_mb)
        % Case III: 变亮很多 (例如，s_i < 0.7 * st_prev)
        new_case = 3;
        new_length = params.len_tmb;
    else
        % Case IV: 变亮一些 (s_i <= st_prev)
        new_case = 4;
        new_length = params.len_tb;
    end
    
    % 3. 检查是否发生“过渡” (FIG. 13, Block 244)
    if new_case ~= current_case
        % “过渡”发生了！(例如，从 Case II 切换到 Case III)
        
        % 模拟 Block 250 & 252:
        % 用“旧的”平均值 (st_prev) 填满“新的”FIFO 队列
        fifo_queue = ones(1, new_length) * st_prev; 
        
        % 更新状态
        current_length = new_length;
        current_case = new_case;
    end
    
    % 4. 标准 FIFO 操作 (Block 246 / 254)
    fifo_queue(1) = []; % 出队 (Pop oldest)
    fifo_queue(end+1) = s_i; % 入队 (Add new)
    
    % 5. 计算新的平均值 (Block 248 / 256)
    st_i = mean(fifo_queue);

    % -----------------------------------------------------------------
    % (C) 将更新后的状态“打包”到 state_out 结构体中
    % -----------------------------------------------------------------
    state_out.fifo_queue     = fifo_queue;
    state_out.current_length = current_length;
    state_out.current_case   = current_case;
    state_out.params         = params; % (params 结构体通常不变, 但我们保持传递)
end