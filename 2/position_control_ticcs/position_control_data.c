/*
 * File: position_control_data.c
 *
 * Code generated for Simulink model 'position_control'.
 *
 * Model version                  : 1.350
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Thu Aug 13 22:56:28 2020
 *
 * Target selection: idelink_ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "position_control.h"
#include "position_control_private.h"

/* Block parameters (auto storage) */
Parameters_position_control position_control_P = {
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  5000.0,                              /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  2500.0,                              /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  32768.0,                             /* Expression: 32768
                                        * Referenced by: '<S1>/Constant1'
                                        */
  0.0031415926535897933,               /* Expression: pi*0.001
                                        * Referenced by: '<Root>/Gain2'
                                        */
  -15.0,                               /* Expression: -15
                                        * Referenced by: '<Root>/kp1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay1'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<Root>/Gain1'
                                        */
  -3.0,                                /* Expression: -3
                                        * Referenced by: '<Root>/kd'
                                        */
  12.0,                                /* Expression: 12
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  -12.0,                               /* Expression: -12
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  58.333333333333336,                  /* Expression: 1400/24
                                        * Referenced by: '<S3>/DAOutput'
                                        */
  1500.0,                              /* Expression: 1500
                                        * Referenced by: '<S3>/DutyRatio_Offset'
                                        */
  32768.0,                             /* Expression: 32768
                                        * Referenced by: '<S2>/Constant1'
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
