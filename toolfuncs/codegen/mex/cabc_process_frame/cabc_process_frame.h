/*
 * cabc_process_frame.h
 *
 * Code generation for function 'cabc_process_frame'
 *
 */

#pragma once

/* Include files */
#include "cabc_process_frame_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void cabc_process_frame(const emlrtStack *sp, const emxArray_real_T *frame,
                        struct0_T *state, const struct1_T *params);

emlrtCTX emlrtGetRootTLSGlobal(void);

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData);

/* End of code generation (cabc_process_frame.h) */
