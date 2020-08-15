/*
 * File: ID_data.c
 *
 * Code generated for Simulink model 'ID'.
 *
 * Model version                  : 1.295
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Thu Aug 13 22:21:10 2020
 *
 * Target selection: idelink_ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ID.h"
#include "ID_private.h"

/* Block parameters (auto storage) */
Parameters_ID ID_P = {
  32768.0,                             /* Expression: 32768
                                        * Referenced by: '<S2>/Constant1'
                                        */
  32768.0,                             /* Expression: 32768
                                        * Referenced by: '<S1>/Constant1'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/Constant'
                                        */
  12.0,                                /* Expression: 12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -12.0,                               /* Expression: -12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  58.333333333333336,                  /* Expression: 1400/24
                                        * Referenced by: '<S3>/DAOutput'
                                        */
  1500.0,                              /* Expression: 1500
                                        * Referenced by: '<S3>/DutyRatio_Offset'
                                        */
  3000U                                /* Computed Parameter: CarryFrequency_Value
                                        * Referenced by: '<S3>/CarryFrequency'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
