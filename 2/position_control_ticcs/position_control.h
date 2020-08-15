/*
 * File: position_control.h
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

#ifndef RTW_HEADER_position_control_h_
#define RTW_HEADER_position_control_h_
#ifndef position_control_COMMON_INCLUDES_
# define position_control_COMMON_INCLUDES_
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
#endif                                 /* position_control_COMMON_INCLUDES_ */

#include "position_control_types.h"

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
  uint16_T DataTypeConversion2[2];     /* '<Root>/Data Type Conversion2' */
} BlockIO_position_control;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay1_DSTATE;            /* '<Root>/Unit Delay1' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} D_Work_position_control;

/* Parameters (auto storage) */
struct Parameters_position_control_ {
  real_T PulseGenerator_Amp;           /* Expression: 5
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T Constant1_Value;              /* Expression: 32768
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Gain2_Gain;                   /* Expression: pi*0.001
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T kp1_Gain;                     /* Expression: -15
                                        * Referenced by: '<Root>/kp1'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay1'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T kd_Gain;                      /* Expression: -3
                                        * Referenced by: '<Root>/kd'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 12
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -12
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T DAOutput_Gain;                /* Expression: 1400/24
                                        * Referenced by: '<S3>/DAOutput'
                                        */
  real_T DutyRatio_Offset_Value;       /* Expression: 1500
                                        * Referenced by: '<S3>/DutyRatio_Offset'
                                        */
  real_T Constant1_Value_g;            /* Expression: 32768
                                        * Referenced by: '<S2>/Constant1'
                                        */
  uint16_T CarryFrequency_Value;       /* Computed Parameter: CarryFrequency_Value
                                        * Referenced by: '<S3>/CarryFrequency'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_position_control {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_position_control position_control_P;

/* Block signals (auto storage) */
extern BlockIO_position_control position_control_B;

/* Block states (auto storage) */
extern D_Work_position_control position_control_DWork;

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
extern void position_control_initialize(void);
extern void position_control_step(void);
extern void position_control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_position_control *const position_control_M;

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
 * '<Root>' : 'position_control'
 * '<S1>'   : 'position_control/28x QEPA1'
 * '<S2>'   : 'position_control/28x QEPA2'
 * '<S3>'   : 'position_control/PWM2'
 */
#endif                                 /* RTW_HEADER_position_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
