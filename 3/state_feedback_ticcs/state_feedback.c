/*
 * File: state_feedback.c
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

#include "state_feedback.h"
#include "state_feedback_private.h"

/* Exported block signals */
real_T cnt2;                           /* '<S1>/eQEP' */
real_T cnt1;                           /* '<S2>/eQEP' */

/* Block states (auto storage) */
D_Work_state_feedback state_feedback_DWork;

/* Real-time model */
RT_MODEL_state_feedback state_feedback_M_;
RT_MODEL_state_feedback *const state_feedback_M = &state_feedback_M_;

/* Model step function */
void state_feedback_step(void)
{
  /* local block i/o variables */
  uint16_T rtb_DataTypeConversion;
  real_T rtb_Sum1;
  real_T rtb_Gain2;
  real_T rtb_Sum1_i;
  real_T DiscreteTransferFcn1_tmp;
  real_T DiscreteTransferFcn2_tmp;

  /* S-Function (c280xqep): '<S1>/eQEP' */
  {
    cnt2 = EQep2Regs.QPOSCNT;          /*eQEP Position Counter*/
  }

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  rtb_Sum1 = state_feedback_P.Constant1_Value - cnt2;

  /* Gain: '<Root>/Gain2' incorporates:
   *  Gain: '<Root>/Gain1'
   */
  rtb_Gain2 = state_feedback_P.Gain1_Gain * rtb_Sum1 *
    state_feedback_P.Gain2_Gain;

  /* DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn1' */
  DiscreteTransferFcn1_tmp = (rtb_Sum1 -
    state_feedback_P.DiscreteTransferFcn1_DenCoef[1L] *
    state_feedback_DWork.DiscreteTransferFcn1_states) /
    state_feedback_P.DiscreteTransferFcn1_DenCoef[0];

  /* Gain: '<Root>/Gain3' incorporates:
   *  DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn1'
   */
  rtb_Sum1 = (state_feedback_P.DiscreteTransferFcn1_NumCoef[0] *
              DiscreteTransferFcn1_tmp +
              state_feedback_P.DiscreteTransferFcn1_NumCoef[1L] *
              state_feedback_DWork.DiscreteTransferFcn1_states) *
    state_feedback_P.Gain3_Gain;

  /* S-Function (c280xqep): '<S2>/eQEP' */
  {
    cnt1 = EQep1Regs.QPOSCNT;          /*eQEP Position Counter*/
  }

  /* Sum: '<S2>/Sum1' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  rtb_Sum1_i = cnt1 - state_feedback_P.Constant1_Value_m;

  /* DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn2' */
  DiscreteTransferFcn2_tmp = (rtb_Sum1_i -
    state_feedback_P.DiscreteTransferFcn2_DenCoef[1L] *
    state_feedback_DWork.DiscreteTransferFcn2_states) /
    state_feedback_P.DiscreteTransferFcn2_DenCoef[0];

  /* Sum: '<Root>/Sum1' incorporates:
   *  DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn2'
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain4'
   *  Gain: '<Root>/Gain5'
   */
  rtb_Sum1 = (state_feedback_P.Gain_Gain * rtb_Sum1_i *
              state_feedback_P.Gain4_Gain + (rtb_Gain2 + rtb_Sum1)) +
    (state_feedback_P.DiscreteTransferFcn2_NumCoef[0] * DiscreteTransferFcn2_tmp
     + state_feedback_P.DiscreteTransferFcn2_NumCoef[1L] *
     state_feedback_DWork.DiscreteTransferFcn2_states) *
    state_feedback_P.Gain5_Gain;

  /* Saturate: '<Root>/Saturation2' */
  if (rtb_Sum1 >= state_feedback_P.Saturation2_UpperSat) {
    rtb_Sum1 = state_feedback_P.Saturation2_UpperSat;
  } else {
    if (rtb_Sum1 <= state_feedback_P.Saturation2_LowerSat) {
      rtb_Sum1 = state_feedback_P.Saturation2_LowerSat;
    }
  }

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Constant: '<S3>/DutyRatio_Offset'
   *  Gain: '<S3>/DAOutput'
   *  Saturate: '<Root>/Saturation2'
   *  Sum: '<S3>/Sum2'
   */
  rtb_Sum1 = state_feedback_P.DAOutput_Gain * rtb_Sum1 +
    state_feedback_P.DutyRatio_Offset_Value;
  if (rtb_Sum1 < 65536.0) {
    if (rtb_Sum1 >= 0.0) {
      rtb_DataTypeConversion = (uint16_T)rtb_Sum1;
    } else {
      rtb_DataTypeConversion = 0U;
    }
  } else {
    rtb_DataTypeConversion = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S3>/Data Type Conversion' */

  /* S-Function (c280xpwm): '<S3>/ePWM2' */
  {
    EPwm1Regs.TBPRD = (uint16_T)(state_feedback_P.CarryFrequency_Value);
  }

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.half.CMPA = (uint16_T)(rtb_DataTypeConversion);
  }

  /*-- Update CMPB value for ePWM1 --*/
  {
    EPwm1Regs.CMPB = (uint16_T)(rtb_DataTypeConversion);
  }

  /* S-Function (c280xpwm): '<S3>/ePWM3' */
  {
    EPwm2Regs.TBPRD = (uint16_T)(state_feedback_P.CarryFrequency_Value);
  }

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.half.CMPA = (uint16_T)(rtb_DataTypeConversion);
  }

  /*-- Update CMPB value for ePWM2 --*/
  {
    EPwm2Regs.CMPB = (uint16_T)(rtb_DataTypeConversion);
  }

  /* Update for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn1' */
  state_feedback_DWork.DiscreteTransferFcn1_states = DiscreteTransferFcn1_tmp;

  /* Update for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn2' */
  state_feedback_DWork.DiscreteTransferFcn2_states = DiscreteTransferFcn2_tmp;
}

/* Model initialize function */
void state_feedback_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(state_feedback_M, (NULL));

  /* block I/O */

  /* exported global signals */
  cnt2 = 0.0;
  cnt1 = 0.0;

  /* states (dwork) */
  state_feedback_DWork.DiscreteTransferFcn1_states = 0.0;
  state_feedback_DWork.DiscreteTransferFcn2_states = 0.0;

  /* Start for S-Function (c280xqep): '<S1>/eQEP' */
  config_QEP_eQEP2(2147483648U, 32768U, 0, 0, 0, 0, 136, 32768, 119, 0);

  /* Start for S-Function (c280xqep): '<S2>/eQEP' */
  config_QEP_eQEP1(2147483648U, 32768U, 0, 0, 0, 0, 136, 32768, 119, 0);

  /* Start for S-Function (c280xpwm): '<S3>/ePWM2' */

  /*** Initialize ePWM1 modules ***/
  {
    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 3000;

    /* // Time-Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE    = 0;          // Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL   = 3;          // Sync output select
       EPwm1Regs.TBCTL.bit.PRDLD      = 0;          // Shadow select
       EPwm1Regs.TBCTL.bit.PHSEN      = 0;          // Phase load enable
       EPwm1Regs.TBCTL.bit.PHSDIR     = 0;          // Phase Direction
       EPwm1Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
       EPwm1Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FBF) | 0x30;

    /* // Time-Base Phase Register
       EPwm1Regs.TBPHS.half.TBPHS     = 0;          // Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000) | 0x0;
    EPwm1Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /* // Counter-Compare Control Register
       EPwm1Regs.CMPCTL.bit.SHDWAMODE = 0;  // Compare A block operating mode.
       EPwm1Regs.CMPCTL.bit.SHDWBMODE = 0;  // Compare B block operating mode.
       EPwm1Regs.CMPCTL.bit.LOADAMODE = 0;          // Active compare A
       EPwm1Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x5F) | 0x0;
    EPwm1Regs.CMPA.half.CMPA = 1500;
    EPwm1Regs.CMPB = 1500;

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 36;
    EPwm1Regs.AQCTLB.all = 264;

    /* // Action-Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0) | 0x0;

    /* // Action-Qualifier Continuous S/W Force Register Set
       EPwm1Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /* // Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE   = 3;          // Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE    = 0;          // Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL     = 2;          // Polarity Select Control
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x3F) | 0xB;
    EPwm1Regs.DBRED = 102;
    EPwm1Regs.DBFED = 102;

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN     = 0;          // Start of conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASEL    = 1;          // Start of conversion A Select
       EPwm1Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM1SOCA Period Select
       EPwm1Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
       EPwm1Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM1SOCB Period Select
       EPwm1Regs.ETSEL.bit.INTEN      = 0;          // EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSEL     = 1;          // EPWM1INTn Select
       EPwm1Regs.ETPS.bit.INTPRD      = 1;          // EPWM1INTn Period Select
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF0F) | 0x1101;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x3303) | 0x1101;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /* // PWM-Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0;

    /* // Trip-Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA        = 3;          // TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM1B
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xF) | 0xF;

    /* // Trip-Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST       = 0;          // Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x6) | 0x0;
    EDIS;
  }

  /* Start for S-Function (c280xpwm): '<S3>/ePWM3' */

  /*** Initialize ePWM2 modules ***/
  {
    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 3000;

    /* // Time-Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE    = 0;          // Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL   = 3;          // Sync output select
       EPwm2Regs.TBCTL.bit.PRDLD      = 0;          // Shadow select
       EPwm2Regs.TBCTL.bit.PHSEN      = 0;          // Phase load enable
       EPwm2Regs.TBCTL.bit.PHSDIR     = 0;          // Phase Direction
       EPwm2Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
       EPwm2Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FBF) | 0x30;

    /* // Time-Base Phase Register
       EPwm2Regs.TBPHS.half.TBPHS     = 0;          // Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000) | 0x0;
    EPwm2Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /* // Counter-Compare Control Register
       EPwm2Regs.CMPCTL.bit.SHDWAMODE = 0;  // Compare A block operating mode.
       EPwm2Regs.CMPCTL.bit.SHDWBMODE = 0;  // Compare B block operating mode.
       EPwm2Regs.CMPCTL.bit.LOADAMODE = 0;          // Active compare A
       EPwm2Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x5F) | 0x0;
    EPwm2Regs.CMPA.half.CMPA = 1500;
    EPwm2Regs.CMPB = 1500;

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm2Regs.AQCTLA.all = 36;
    EPwm2Regs.AQCTLB.all = 264;

    /* // Action-Qualifier Software Force Register
       EPwm2Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
     */
    EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0) | 0x0;

    /* // Action-Qualifier Continuous S/W Force Register Set
       EPwm2Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
       EPwm2Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
     */
    EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /* // Dead-Band Generator Control Register
       EPwm2Regs.DBCTL.bit.OUT_MODE   = 3;          // Dead Band Output Mode Control
       EPwm2Regs.DBCTL.bit.IN_MODE    = 0;          // Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL     = 2;          // Polarity Select Control
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x3F) | 0xB;
    EPwm2Regs.DBRED = 204;
    EPwm2Regs.DBFED = 204;

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN     = 0;          // Start of conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASEL    = 1;          // Start of conversion A Select
       EPwm2Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM2SOCA Period Select
       EPwm2Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
       EPwm2Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM2SOCB Period Select
       EPwm2Regs.ETSEL.bit.INTEN      = 0;          // EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSEL     = 1;          // EPWM2INTn Select
       EPwm2Regs.ETPS.bit.INTPRD      = 1;          // EPWM2INTn Period Select
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF0F) | 0x1101;
    EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x3303) | 0x1101;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /* // PWM-Chopper Control Register
       EPwm2Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
       EPwm2Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
       EPwm2Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
       EPwm2Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
     */
    EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm2Regs.TZSEL.all = 0;

    /* // Trip-Zone Control Register
       EPwm2Regs.TZCTL.bit.TZA        = 3;          // TZ1 to TZ6 Trip Action On EPWM2A
       EPwm2Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM2B
     */
    EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xF) | 0xF;

    /* // Trip-Zone Enable Interrupt Register
       EPwm2Regs.TZEINT.bit.OST       = 0;          // Trip Zones One Shot Int Enable
       EPwm2Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
     */
    EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x6) | 0x0;
    EDIS;
  }

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn1' */
  state_feedback_DWork.DiscreteTransferFcn1_states =
    state_feedback_P.DiscreteTransferFcn1_InitialSta;

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn2' */
  state_feedback_DWork.DiscreteTransferFcn2_states =
    state_feedback_P.DiscreteTransferFcn2_InitialSta;
}

/* Model terminate function */
void state_feedback_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
