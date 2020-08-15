/*
 * File: speed_control_data.c
 *
 * Code generated for Simulink model 'speed_control'.
 *
 * Model version                  : 1.352
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Thu Aug 13 22:44:35 2020
 *
 * Target selection: idelink_ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "speed_control.h"
#include "speed_control_private.h"

/* Block parameters (auto storage) */
Parameters_speed_control speed_control_P = {
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  32768.0,                             /* Expression: 32768
                                        * Referenced by: '<S1>/Constant1'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<Root>/Gain'
                                        */
  2.3561944901923448,                  /* Expression: 0.75*pi
                                        * Referenced by: '<Root>/Constant1'
                                        */
  -3.0,                                /* Expression: -3
                                        * Referenced by: '<Root>/kp'
                                        */
  0.001,                               /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  -15.0,                               /* Expression: -15
                                        * Referenced by: '<Root>/ki'
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
