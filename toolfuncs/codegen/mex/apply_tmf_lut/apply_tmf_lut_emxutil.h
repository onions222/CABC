/*
 * apply_tmf_lut_emxutil.h
 *
 * Code generation for function 'apply_tmf_lut_emxutil'
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
void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
                              int32_T oldNumel,
                              const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_uint8_T(const emlrtStack *sp, emxArray_uint8_T *emxArray,
                               int32_T oldNumel,
                               const emlrtRTEInfo *srcLocation);

void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

void emxFree_uint8_T(const emlrtStack *sp, emxArray_uint8_T **pEmxArray);

void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                    const emlrtRTEInfo *srcLocation);

void emxInit_uint8_T(const emlrtStack *sp, emxArray_uint8_T **pEmxArray,
                     const emlrtRTEInfo *srcLocation);

/* End of code generation (apply_tmf_lut_emxutil.h) */
