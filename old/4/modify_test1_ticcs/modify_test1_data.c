/*
 * File: modify_test1_data.c
 *
 * Code generated for Simulink model 'modify_test1'.
 *
 * Model version                  : 1.310
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Thu Aug 20 19:11:43 2020
 *
 * Target selection: idelink_ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "modify_test1.h"
#include "modify_test1_private.h"

/* Block parameters (auto storage) */
Parameters_modify_test1 modify_test1_P = {
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S10>/Constant'
                                        */
  3356.25,                             /* Expression: 1/0.16*k
                                        * Referenced by: '<S11>/Gain1'
                                        */
  0.65582371458551947,                 /* Expression: 1/Rho(4)
                                        * Referenced by: '<S10>/Gain1'
                                        */
  -3.5090877868891512,                 /* Expression: K3
                                        * Referenced by: '<S7>/Gain3'
                                        */
  -3.2210791893937825,                 /* Expression: K1
                                        * Referenced by: '<S7>/Gain2'
                                        */
  -8.6143127433839251,                 /* Expression: K4
                                        * Referenced by: '<S7>/Gain1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S9>/Gain4'
                                        */
  -99.592291402301058,                 /* Expression: K2
                                        * Referenced by: '<S7>/Gain'
                                        */
  32768.0,                             /* Expression: 32768
                                        * Referenced by: '<S2>/Constant1'
                                        */
  2000.0,                              /* Expression: 2000
                                        * Referenced by: '<S8>/Constant'
                                        */
  0.0031415926535897933,               /* Expression: 2*pi/2000
                                        * Referenced by: '<S6>/Gain'
                                        */

  /*  Expression: [3.14 -3.14]
   * Referenced by: '<S6>/Discrete Transfer Fcn1'
   */
  { 3.14, -3.14 },

  /*  Expression: [1 -0.7788]
   * Referenced by: '<S6>/Discrete Transfer Fcn1'
   */
  { 1.0, -0.7788 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Discrete Transfer Fcn1'
                                        */
  32768.0,                             /* Expression: 32768
                                        * Referenced by: '<S1>/Constant1'
                                        */
  0.0031415926535897933,               /* Expression: 2*pi/2000
                                        * Referenced by: '<S3>/Gain'
                                        */

  /*  Expression: [3.14 -3.14]
   * Referenced by: '<S3>/Discrete Transfer Fcn2'
   */
  { 3.14, -3.14 },

  /*  Expression: [1 -0.7788]
   * Referenced by: '<S3>/Discrete Transfer Fcn2'
   */
  { 1.0, -0.7788 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Discrete Transfer Fcn2'
                                        */
  2.8797932657906435,                  /* Expression: lowlimit
                                        * Referenced by: '<S4>/Lower Limit'
                                        */
  3.4033920413889427,                  /* Expression: uplimit
                                        * Referenced by: '<S4>/Upper Limit'
                                        */
  12.0,                                /* Expression: 12
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  -12.0,                               /* Expression: -12
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  58.333333333333336,                  /* Expression: 1400/24
                                        * Referenced by: '<S5>/DAOutput'
                                        */
  1500.0,                              /* Expression: 1500
                                        * Referenced by: '<S5>/DutyRatio_Offset'
                                        */
  3000U                                /* Computed Parameter: CarryFrequency_Value
                                        * Referenced by: '<S5>/CarryFrequency'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
