/*
 * File: btea0_data.c
 *
 * Code generated for Simulink model 'btea0'.
 *
 * Model version                  : 1.298
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Fri Aug 14 20:42:29 2020
 *
 * Target selection: idelink_ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "btea0.h"
#include "btea0_private.h"

/* Block parameters (auto storage) */
Parameters_btea0 btea0_P = {
  32768.0,                             /* Expression: 32768
                                        * Referenced by: '<S1>/Constant1'
                                        */
  0.0031415926535897933,               /* Expression: 2*pi/2000
                                        * Referenced by: '<Root>/Gain3'
                                        */
  -212.63536212584182,                 /* Expression: KP
                                        * Referenced by: '<Root>/Kp'
                                        */
  0.001,                               /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  -166.54369991058002,                 /* Expression: KI
                                        * Referenced by: '<Root>/Ki'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  -18799.388549130843,                 /* Expression: KD*1000
                                        * Referenced by: '<Root>/Kd*1000'
                                        */
  12.0,                                /* Expression: 12
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  -12.0,                               /* Expression: -12
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  58.333333333333336,                  /* Expression: 1400/24
                                        * Referenced by: '<S2>/DAOutput'
                                        */
  1500.0,                              /* Expression: 1500
                                        * Referenced by: '<S2>/DutyRatio_Offset'
                                        */
  3000U                                /* Computed Parameter: CarryFrequency_Value
                                        * Referenced by: '<S2>/CarryFrequency'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
