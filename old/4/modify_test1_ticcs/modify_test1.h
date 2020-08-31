/*
 * File: modify_test1.h
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

#ifndef RTW_HEADER_modify_test1_h_
#define RTW_HEADER_modify_test1_h_
#ifndef modify_test1_COMMON_INCLUDES_
# define modify_test1_COMMON_INCLUDES_
#include <math.h>
#include <stddef.h>
#include <float.h>
#include <string.h>
#include "rtwtypes.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "IQmathLib.h"
#include "DSP28xx_SciUtil.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#endif                                 /* modify_test1_COMMON_INCLUDES_ */

#include "modify_test1_types.h"

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
} BlockIO_modify_test1;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTransferFcn1_states;  /* '<S6>/Discrete Transfer Fcn1' */
  real_T DiscreteTransferFcn2_states;  /* '<S3>/Discrete Transfer Fcn2' */
} D_Work_modify_test1;

/* Parameters (auto storage) */
struct Parameters_modify_test1_ {
  real_T Constant_Value;               /* Expression: pi
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/0.16*k
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: 1/Rho(4)
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T Gain3_Gain;                   /* Expression: K3
                                        * Referenced by: '<S7>/Gain3'
                                        */
  real_T Gain2_Gain;                   /* Expression: K1
                                        * Referenced by: '<S7>/Gain2'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: K4
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T Gain4_Gain;                   /* Expression: -1
                                        * Referenced by: '<S9>/Gain4'
                                        */
  real_T Gain_Gain;                    /* Expression: K2
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Constant1_Value;              /* Expression: 32768
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant_Value_f;             /* Expression: 2000
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 2*pi/2000
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T DiscreteTransferFcn1_NumCoef[2];/* Expression: [3.14 -3.14]
                                          * Referenced by: '<S6>/Discrete Transfer Fcn1'
                                          */
  real_T DiscreteTransferFcn1_DenCoef[2];/* Expression: [1 -0.7788]
                                          * Referenced by: '<S6>/Discrete Transfer Fcn1'
                                          */
  real_T DiscreteTransferFcn1_InitialSta;/* Expression: 0
                                          * Referenced by: '<S6>/Discrete Transfer Fcn1'
                                          */
  real_T Constant1_Value_b;            /* Expression: 32768
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 2*pi/2000
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T DiscreteTransferFcn2_NumCoef[2];/* Expression: [3.14 -3.14]
                                          * Referenced by: '<S3>/Discrete Transfer Fcn2'
                                          */
  real_T DiscreteTransferFcn2_DenCoef[2];/* Expression: [1 -0.7788]
                                          * Referenced by: '<S3>/Discrete Transfer Fcn2'
                                          */
  real_T DiscreteTransferFcn2_InitialSta;/* Expression: 0
                                          * Referenced by: '<S3>/Discrete Transfer Fcn2'
                                          */
  real_T LowerLimit_Value;             /* Expression: lowlimit
                                        * Referenced by: '<S4>/Lower Limit'
                                        */
  real_T UpperLimit_Value;             /* Expression: uplimit
                                        * Referenced by: '<S4>/Upper Limit'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 12
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -12
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T DAOutput_Gain;                /* Expression: 1400/24
                                        * Referenced by: '<S5>/DAOutput'
                                        */
  real_T DutyRatio_Offset_Value;       /* Expression: 1500
                                        * Referenced by: '<S5>/DutyRatio_Offset'
                                        */
  uint16_T CarryFrequency_Value;       /* Computed Parameter: CarryFrequency_Value
                                        * Referenced by: '<S5>/CarryFrequency'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_modify_test1 {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_modify_test1 modify_test1_P;

/* Block signals (auto storage) */
extern BlockIO_modify_test1 modify_test1_B;

/* Block states (auto storage) */
extern D_Work_modify_test1 modify_test1_DWork;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T cnt1;                    /* '<S2>/eQEP' */
extern real_T cnt2;                    /* '<S1>/eQEP' */
extern boolean_T thre;                 /* '<S4>/AND' */

/* Model entry point functions */
extern void modify_test1_initialize(void);
extern void modify_test1_step(void);
extern void modify_test1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_modify_test1 *const modify_test1_M;

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
 * '<Root>' : 'modify_test1'
 * '<S1>'   : 'modify_test1/28x QEPA1'
 * '<S2>'   : 'modify_test1/28x QEPB1'
 * '<S3>'   : 'modify_test1/Arm1'
 * '<S4>'   : 'modify_test1/Balance Interval 150~210 degree'
 * '<S5>'   : 'modify_test1/PWM1'
 * '<S6>'   : 'modify_test1/Pendulum 1'
 * '<S7>'   : 'modify_test1/State-feedback control'
 * '<S8>'   : 'modify_test1/Subsystem'
 * '<S9>'   : 'modify_test1/Subsystem1'
 * '<S10>'  : 'modify_test1/swing up '
 * '<S11>'  : 'modify_test1/swing up /alpha double prime1'
 */
#endif                                 /* RTW_HEADER_modify_test1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
