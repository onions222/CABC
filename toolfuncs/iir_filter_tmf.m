function tmf_final = iir_filter_tmf(tmf_target, tmf_prev, kp_lin, m_lin, params)
    % 时域 IIR 滤波
    
    
    if tmf_target > tmf_prev
        % TMF 增益变大，背光变暗
        alpha = params.alpha_slow;
    else
        % TMF 增益变小 
        alpha = params.alpha_fast;
    end
    
    % IIR 公式
    tmf_final = alpha * tmf_target + (1 - alpha) * tmf_prev;

    if tmf_final * kp_lin >= m_lin
        tmf_final = 1/kp_lin;
    end
end