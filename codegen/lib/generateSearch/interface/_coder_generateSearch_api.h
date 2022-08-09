/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_generateSearch_api.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 10-Aug-2022 00:12:05
 */

#ifndef _CODER_GENERATESEARCH_API_H
#define _CODER_GENERATESEARCH_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void MEXGlobalSyncInFunction(const emlrtStack *sp);

void MEXGlobalSyncOutFunction(boolean_T skipDirtyCheck);

void generateSearch(uint8_T x, uint8_T y, uint8_T car, uint8_T route[2]);

void generateSearch_api(const mxArray *const prhs[3], const mxArray **plhs);

void generateSearch_atexit(void);

void generateSearch_initialize(void);

void generateSearch_terminate(void);

void generateSearch_xil_shutdown(void);

void generateSearch_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_generateSearch_api.h
 *
 * [EOF]
 */
