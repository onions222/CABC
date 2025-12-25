/*
 * apply_tmf_lut.h
 *
 * Code generation for function 'apply_tmf_lut'
 *
 */

#pragma once

/* Include files */
#include "apply_tmf_lut_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void apply_tmf_lut(const emlrtStack *sp, const emxArray_uint8_T *img_rgb,
                   const struct0_T *state, const real_T nodes_lin[65],
                   emxArray_uint8_T *img_out_rgb, real_T psnr_val_data[],
                   int32_T psnr_val_size[2]);

emlrtCTX emlrtGetRootTLSGlobal(void);

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData);

/* End of code generation (apply_tmf_lut.h) */
