/*
 * File: state_feedback_data.c
 *
 * Code generated for Simulink model 'state_feedback'.
 *
 * Model version                  : 1.284
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Mon Aug 17 19:53:06 2020
 *
 * Target selection: idelink_ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "state_feedback.h"
#include "state_feedback_private.h"

/* Block parameters (auto storage) */
Parameters_state_feedback state_feedback_P = {
  32768.0,                             /* Expression: 32768
                                        * Referenced by: '<S1>/Constant1'
                                        */
  0.0031415926535897933,               /* Expression: 2*pi/2000
                                        * Referenced by: '<Root>/Gain1'
                                        */
  -3.2210791893937825,                 /* Expression: K1
                                        * Referenced by: '<Root>/Gain2'
                                        */

  /*  Expression: [3.14 -3.14]
   * Referenced by: '<Root>/Discrete Transfer Fcn1'
   */
  { 3.14, -3.14 },

  /*  Expression: [1 -0.7788]
   * Referenced by: '<Root>/Discrete Transfer Fcn1'
   */
  { 1.0, -0.7788 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Discrete Transfer Fcn1'
                                        */
  -3.5090877868891512,                 /* Expression: K3
                                        * Referenced by: '<Root>/Gain3'
                                        */
  32768.0,                             /* Expression: 32768
                                        * Referenced by: '<S2>/Constant1'
                                        */
  0.0031415926535897933,               /* Expression: 2*pi/2000
                                        * Referenced by: '<Root>/Gain'
                                        */
  -99.592291402301058,                 /* Expression: K2
                                        * Referenced by: '<Root>/Gain4'
                                        */

  /*  Expression: [3.14 -3.14]
   * Referenced by: '<Root>/Discrete Transfer Fcn2'
   */
  { 3.14, -3.14 },

  /*  Expression: [1 -0.7788]
   * Referenced by: '<Root>/Discrete Transfer Fcn2'
   */
  { 1.0, -0.7788 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Discrete Transfer Fcn2'
                                        */
  -8.6143127433839251,                 /* Expression: K4
                                        * Referenced by: '<Root>/Gain5'
                                        */
  12.0,                                /* Expression: 12
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  -12.0,                               /* Expression: -12
                                        * Referenced by: '<Root>/Saturation2'
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
