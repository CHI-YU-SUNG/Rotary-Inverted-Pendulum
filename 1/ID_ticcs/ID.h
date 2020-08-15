/*
 * File: ID.h
 *
 * Code generated for Simulink model 'ID'.
 *
 * Model version                  : 1.295
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Thu Aug 13 22:21:10 2020
 *
 * Target selection: idelink_ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ID_h_
#define RTW_HEADER_ID_h_
#ifndef ID_COMMON_INCLUDES_
# define ID_COMMON_INCLUDES_
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "DSP2833x_Device.h"
#include "DSP28xx_SciUtil.h"
#include "DSP2833x_Examples.h"
#include "IQmathLib.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#endif                                 /* ID_COMMON_INCLUDES_ */

#include "ID_types.h"

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
} BlockIO_ID;

/* Parameters (auto storage) */
struct Parameters_ID_ {
  real_T Constant1_Value;              /* Expression: 32768
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant1_Value_g;            /* Expression: 32768
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 5
                                        * Referenced by: '<Root>/Constant'
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
  uint16_T CarryFrequency_Value;       /* Computed Parameter: CarryFrequency_Value
                                        * Referenced by: '<S3>/CarryFrequency'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ID {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_ID ID_P;

/* Block signals (auto storage) */
extern BlockIO_ID ID_B;

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

/* Model entry point functions */
extern void ID_initialize(void);
extern void ID_step(void);
extern void ID_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ID *const ID_M;

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
 * '<Root>' : 'ID'
 * '<S1>'   : 'ID/28x QEPA'
 * '<S2>'   : 'ID/28x QEPB'
 * '<S3>'   : 'ID/PWM1'
 */
#endif                                 /* RTW_HEADER_ID_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
