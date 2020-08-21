/*
 * File: state_feedback.h
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

#ifndef RTW_HEADER_state_feedback_h_
#define RTW_HEADER_state_feedback_h_
#ifndef state_feedback_COMMON_INCLUDES_
# define state_feedback_COMMON_INCLUDES_
#include <stddef.h>
#include "rtwtypes.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "IQmathLib.h"
#endif                                 /* state_feedback_COMMON_INCLUDES_ */

#include "state_feedback_types.h"

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
  real_T DiscreteTransferFcn1_states;  /* '<Root>/Discrete Transfer Fcn1' */
  real_T DiscreteTransferFcn2_states;  /* '<Root>/Discrete Transfer Fcn2' */
} D_Work_state_feedback;

/* Parameters (auto storage) */
struct Parameters_state_feedback_ {
  real_T Constant1_Value;              /* Expression: 32768
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2*pi/2000
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: K1
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T DiscreteTransferFcn1_NumCoef[2];/* Expression: [3.14 -3.14]
                                          * Referenced by: '<Root>/Discrete Transfer Fcn1'
                                          */
  real_T DiscreteTransferFcn1_DenCoef[2];/* Expression: [1 -0.7788]
                                          * Referenced by: '<Root>/Discrete Transfer Fcn1'
                                          */
  real_T DiscreteTransferFcn1_InitialSta;/* Expression: 0
                                          * Referenced by: '<Root>/Discrete Transfer Fcn1'
                                          */
  real_T Gain3_Gain;                   /* Expression: K3
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Constant1_Value_m;            /* Expression: 32768
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Gain_Gain;                    /* Expression: 2*pi/2000
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain4_Gain;                   /* Expression: K2
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T DiscreteTransferFcn2_NumCoef[2];/* Expression: [3.14 -3.14]
                                          * Referenced by: '<Root>/Discrete Transfer Fcn2'
                                          */
  real_T DiscreteTransferFcn2_DenCoef[2];/* Expression: [1 -0.7788]
                                          * Referenced by: '<Root>/Discrete Transfer Fcn2'
                                          */
  real_T DiscreteTransferFcn2_InitialSta;/* Expression: 0
                                          * Referenced by: '<Root>/Discrete Transfer Fcn2'
                                          */
  real_T Gain5_Gain;                   /* Expression: K4
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 12
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -12
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  real_T DAOutput_Gain;                /* Expression: 1400/24
                                        * Referenced by: '<S3>/DAOutput'
                                        */
  real_T DutyRatio_Offset_Value;       /* Expression: 1500
                                        * Referenced by: '<S3>/DutyRatio_Offset'
                                        */
  uint16_T CarryFrequency_Value;       /* Computed Parameter: CarryFrequency_Value
                                        * Referenced by: '<S3>/CarryFrequency'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_state_feedback {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_state_feedback state_feedback_P;

/* Block states (auto storage) */
extern D_Work_state_feedback state_feedback_DWork;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T cnt2;                    /* '<S1>/eQEP' */
extern real_T cnt1;                    /* '<S2>/eQEP' */

/* Model entry point functions */
extern void state_feedback_initialize(void);
extern void state_feedback_step(void);
extern void state_feedback_terminate(void);

/* Real-time Model object */
extern RT_MODEL_state_feedback *const state_feedback_M;

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
 * '<Root>' : 'state_feedback'
 * '<S1>'   : 'state_feedback/28x QEPA'
 * '<S2>'   : 'state_feedback/28x QEPB'
 * '<S3>'   : 'state_feedback/PWM1'
 */
#endif                                 /* RTW_HEADER_state_feedback_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
