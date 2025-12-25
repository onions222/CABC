/*
 * interp1.c
 *
 * Code generation for function 'interp1'
 *
 */

/* Include files */
#include "interp1.h"
#include "rt_nonfinite.h"
#include "omp.h"

/* Function Definitions */
void interp1Linear(const emlrtStack *sp, const real_T y[65],
                   const real_T xi[256], const real_T varargin_1[65],
                   real_T yi[256])
{
  jmp_buf *volatile emlrtJBStack;
  real_T maxx;
  real_T minx;
  real_T r;
  real_T yi_tmp;
  int32_T high_i;
  int32_T i;
  int32_T interp1Linear_numThreads;
  int32_T k;
  int32_T low_i;
  int32_T low_ip1;
  int32_T mid_i;
  for (i = 0; i < 256; i++) {
    yi[i] = rtNaN;
  }
  minx = varargin_1[0];
  maxx = varargin_1[64];
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  interp1Linear_numThreads = emlrtAllocRegionTLSs(
      sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(interp1Linear_numThreads) private(        \
        r, low_i, low_ip1, high_i, mid_i, yi_tmp)

  for (k = 0; k < 256; k++) {
    r = xi[k];
    if ((!(r > maxx)) && (!(r < minx))) {
      low_i = 1;
      low_ip1 = 2;
      high_i = 65;
      while (high_i > low_ip1) {
        mid_i = (low_i + high_i) >> 1;
        if (xi[k] >= varargin_1[mid_i - 1]) {
          low_i = mid_i;
          low_ip1 = mid_i + 1;
        } else {
          high_i = mid_i;
        }
      }
      r = varargin_1[low_i - 1];
      r = (xi[k] - r) / (varargin_1[low_i] - r);
      if (r == 0.0) {
        yi[k] = y[low_i - 1];
      } else if (r == 1.0) {
        yi[k] = y[low_i];
      } else {
        yi_tmp = y[low_i - 1];
        if (yi_tmp == y[low_i]) {
          yi[k] = yi_tmp;
        } else {
          yi[k] = (1.0 - r) * yi_tmp + r * y[low_i];
        }
      }
    }
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
}

/* End of code generation (interp1.c) */
