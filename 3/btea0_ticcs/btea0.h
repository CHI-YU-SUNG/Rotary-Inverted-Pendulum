/*
 * File: btea0.h
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

#ifndef RTW_HEADER_btea0_h_
#define RTW_HEADER_btea0_h_
#ifndef btea0_COMMON_INCLUDES_
# define btea0_COMMON_INCLUDES_
#include <stddef.h>
#include "rtwtypes.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "IQmathLib.h"
#endif                                 /* btea0_COMMON_INCLUDES_ */

#include "btea0_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
} D_Work_btea0;

/* Parameters (auto storage) */
struct Parameters_btea0_ {
  real_T Constant1_Value;              /* Expression: 32768
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Gain3_Gain;                   /* Expression: 2*pi/2000
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Kp_Gain;                      /* Expression: KP
                                        * Referenced by: '<Root>/Kp'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<Root>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  real_T Ki_Gain;                      /* Expression: KI
                                        * Referenced by: '<Root>/Ki'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T Kd1000_Gain;                  /* Expression: KD*1000
                                        * Referenced by: '<Root>/Kd*1000'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 12
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -12
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T DAOutput_Gain;                /* Expression: 1400/24
                                        * Referenced by: '<S2>/DAOutput'
                                        */
  real_T DutyRatio_Offset_Value;       /* Expression: 1500
                                        * Referenced by: '<S2>/DutyRatio_Offset'
                                        */
  uint16_T CarryFrequency_Value;       /* Computed Parameter: CarryFrequency_Value
                                        * Referenced by: '<S2>/CarryFrequency'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_btea0 {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_btea0 btea0_P;

/* Block states (auto storage) */
extern D_Work_btea0 btea0_DWork;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T cnt1;                    /* '<S1>/eQEP' */

/* Model entry point functions */
extern void btea0_initialize(void);
extern void btea0_step(void);
extern void btea0_terminate(void);

/* Real-time Model object */
extern RT_MODEL_btea0 *const btea0_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'btea0'
 * '<S1>'   : 'btea0/28x QEPB1'
 * '<S2>'   : 'btea0/PWM1'
 */
#endif                                 /* RTW_HEADER_btea0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
