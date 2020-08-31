/*
 * File: speed_control.h
 *
 * Code generated for Simulink model 'speed_control'.
 *
 * Model version                  : 1.353
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Mon Aug 31 15:34:46 2020
 *
 * Target selection: idelink_ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_speed_control_h_
#define RTW_HEADER_speed_control_h_
#ifndef speed_control_COMMON_INCLUDES_
# define speed_control_COMMON_INCLUDES_
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "IQmathLib.h"
#include "DSP28xx_SciUtil.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#endif                                 /* speed_control_COMMON_INCLUDES_ */

#include "speed_control_types.h"

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

/* Block signals (auto storage) */
typedef struct {
  uint16_T DataTypeConversion1[2];     /* '<Root>/Data Type Conversion1' */
} BlockIO_speed_control;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
} D_Work_speed_control;

/* Parameters (auto storage) */
struct Parameters_speed_control_ {
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T Constant1_Value;              /* Expression: 32768
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Gain_Gain;                    /* Expression: pi
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0.75*pi
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T kp_Gain;                      /* Expression: -94
                                        * Referenced by: '<Root>/kp'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<Root>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  real_T ki_Gain;                      /* Expression: -516.6
                                        * Referenced by: '<Root>/ki'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T DAOutput_Gain;                /* Expression: 1400/24
                                        * Referenced by: '<S3>/DAOutput'
                                        */
  real_T DutyRatio_Offset_Value;       /* Expression: 1500
                                        * Referenced by: '<S3>/DutyRatio_Offset'
                                        */
  real_T Constant1_Value_a;            /* Expression: 32768
                                        * Referenced by: '<S2>/Constant1'
                                        */
  uint16_T CarryFrequency_Value;       /* Computed Parameter: CarryFrequency_Value
                                        * Referenced by: '<S3>/CarryFrequency'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_speed_control {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_speed_control speed_control_P;

/* Block signals (auto storage) */
extern BlockIO_speed_control speed_control_B;

/* Block states (auto storage) */
extern D_Work_speed_control speed_control_DWork;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T cnt1;                    /* '<S1>/eQEP' */
extern real_T cnt2;                    /* '<S2>/eQEP' */

/* Model entry point functions */
extern void speed_control_initialize(void);
extern void speed_control_step(void);
extern void speed_control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_speed_control *const speed_control_M;

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
 * '<Root>' : 'speed_control'
 * '<S1>'   : 'speed_control/28x QEPA'
 * '<S2>'   : 'speed_control/28x QEPA3'
 * '<S3>'   : 'speed_control/PWM1'
 */
#endif                                 /* RTW_HEADER_speed_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
