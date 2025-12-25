/*
 * interp1.h
 *
 * Code generation for function 'interp1'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void interp1Linear(const emlrtStack *sp, const real_T y[65],
                   const real_T xi[256], const real_T varargin_1[65],
                   real_T yi[256]);

/* End of code generation (interp1.h) */
