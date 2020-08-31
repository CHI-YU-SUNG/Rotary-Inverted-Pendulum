/*
 * File: modify_test1.c
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

#include "modify_test1.h"
#include "modify_test1_private.h"

/* Exported block signals */
real_T cnt1;                           /* '<S2>/eQEP' */
real_T cnt2;                           /* '<S1>/eQEP' */
boolean_T thre;                        /* '<S4>/AND' */

/* Block signals (auto storage) */
BlockIO_modify_test1 modify_test1_B;

/* Block states (auto storage) */
D_Work_modify_test1 modify_test1_DWork;

/* Real-time model */
RT_MODEL_modify_test1 modify_test1_M_;
RT_MODEL_modify_test1 *const modify_test1_M = &modify_test1_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = -0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  if (u1 == 0.0) {
    y = u0;
  } else if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf
                (u1))))) {
    y = (rtNaN);
  } else {
    tmp = u0 / u1;
    if (u1 <= floor(u1)) {
      y = u0 - floor(tmp) * u1;
    } else {
      if (fabs(tmp - rt_roundd_snf(tmp)) <= DBL_EPSILON * fabs(tmp)) {
        y = 0.0;
      } else {
        y = (tmp - floor(tmp)) * u1;
      }
    }
  }

  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model step function */
void modify_test1_step(void)
{
  /* local block i/o variables */
  uint16_T rtb_DataTypeConversion;
  real_T rtb_Sum1_m;
  real_T rtb_Sum2;
  real_T rtb_Product;
  real_T rtb_Gain;
  real_T rtb_Sum1;
  real_T rtb_DiscreteTransferFcn1;
  real_T rtb_DiscreteTransferFcn2;
  real_T DiscreteTransferFcn1_tmp;
  real_T DiscreteTransferFcn2_tmp;

  /* S-Function (c280xqep): '<S2>/eQEP' */
  {
    cnt1 = EQep1Regs.QPOSCNT;          /*eQEP Position Counter*/
  }

  /* Sum: '<S2>/Sum1' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  rtb_Sum1_m = cnt1 - modify_test1_P.Constant1_Value;

  /* Signum: '<S8>/Sign' */
  if (rtb_Sum1_m < 0.0) {
    rtb_Sum2 = -1.0;
  } else if (rtb_Sum1_m > 0.0) {
    rtb_Sum2 = 1.0;
  } else if (rtb_Sum1_m == 0.0) {
    rtb_Sum2 = 0.0;
  } else {
    rtb_Sum2 = rtb_Sum1_m;
  }

  /* Product: '<S8>/Product' incorporates:
   *  Abs: '<S8>/Abs'
   *  Constant: '<S8>/Constant'
   *  Math: '<S8>/Math Function'
   *  Signum: '<S8>/Sign'
   */
  rtb_Product = rt_modd_snf(fabs(rtb_Sum1_m), modify_test1_P.Constant_Value_f) *
    rtb_Sum2;

  /* Gain: '<S6>/Gain' */
  rtb_Gain = modify_test1_P.Gain_Gain_b * rtb_Product;

  /* DiscreteTransferFcn: '<S6>/Discrete Transfer Fcn1' */
  DiscreteTransferFcn1_tmp = (rtb_Product -
    modify_test1_P.DiscreteTransferFcn1_DenCoef[1L] *
    modify_test1_DWork.DiscreteTransferFcn1_states) /
    modify_test1_P.DiscreteTransferFcn1_DenCoef[0];
  rtb_DiscreteTransferFcn1 = modify_test1_P.DiscreteTransferFcn1_NumCoef[0] *
    DiscreteTransferFcn1_tmp + modify_test1_P.DiscreteTransferFcn1_NumCoef[1L] *
    modify_test1_DWork.DiscreteTransferFcn1_states;

  /* S-Function (c280xqep): '<S1>/eQEP' */
  {
    cnt2 = EQep2Regs.QPOSCNT;          /*eQEP Position Counter*/
  }

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  rtb_Sum1 = modify_test1_P.Constant1_Value_b - cnt2;

  /* DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn2' */
  DiscreteTransferFcn2_tmp = (rtb_Sum1 -
    modify_test1_P.DiscreteTransferFcn2_DenCoef[1L] *
    modify_test1_DWork.DiscreteTransferFcn2_states) /
    modify_test1_P.DiscreteTransferFcn2_DenCoef[0];
  rtb_DiscreteTransferFcn2 = modify_test1_P.DiscreteTransferFcn2_NumCoef[0] *
    DiscreteTransferFcn2_tmp + modify_test1_P.DiscreteTransferFcn2_NumCoef[1L] *
    modify_test1_DWork.DiscreteTransferFcn2_states;

  /* Abs: '<Root>/Abs2' */
  rtb_Sum2 = fabs(rtb_Gain);

  /* Logic: '<S4>/AND' incorporates:
   *  Constant: '<S4>/Lower Limit'
   *  Constant: '<S4>/Upper Limit'
   *  RelationalOperator: '<S4>/Lower Test'
   *  RelationalOperator: '<S4>/Upper Test'
   */
  thre = ((modify_test1_P.LowerLimit_Value <= rtb_Sum2) && (rtb_Sum2 <=
           modify_test1_P.UpperLimit_Value));

  /* Switch: '<Root>/Switch' incorporates:
   *  Fcn: '<S10>/Fcn1'
   *  Fcn: '<S10>/Fcn2'
   *  Fcn: '<S10>/Fcn3'
   *  Fcn: '<S10>/Fcn4'
   *  Fcn: '<S10>/Fcn5'
   *  Fcn: '<S11>/Fcn12'
   *  Gain: '<S10>/Gain1'
   *  Gain: '<S11>/Gain1'
   *  Gain: '<S3>/Gain'
   *  Gain: '<S7>/Gain'
   *  Gain: '<S7>/Gain1'
   *  Gain: '<S7>/Gain2'
   *  Gain: '<S7>/Gain3'
   *  Product: '<S10>/Product'
   *  Signum: '<S11>/Sign1'
   *  Sum: '<S10>/Add1'
   *  Sum: '<S11>/Add3'
   *  Sum: '<S7>/Add2'
   *  Trigonometry: '<S9>/cos'
   */
  if (thre) {
    /* Trigonometry: '<S9>/sin' incorporates:
     *  Gain: '<S9>/Gain4'
     */
    rtb_Sum2 = sin(modify_test1_P.Gain4_Gain * rtb_Gain);

    /* Trigonometry: '<S9>/cos' */
    if (rtb_Sum2 >= 1.0) {
      rtb_Sum2 = 1.0;
    } else {
      if (rtb_Sum2 <= -1.0) {
        rtb_Sum2 = -1.0;
      }
    }

    rtb_Sum2 = ((modify_test1_P.Gain_Gain * asin(rtb_Sum2) +
                 modify_test1_P.Gain1_Gain_n * rtb_DiscreteTransferFcn1) +
                modify_test1_P.Gain_Gain_f * rtb_Sum1 *
                modify_test1_P.Gain2_Gain) + modify_test1_P.Gain3_Gain *
      rtb_DiscreteTransferFcn2;
  } else {
    /* Sum: '<S10>/Add' incorporates:
     *  Constant: '<S10>/Constant'
     */
    rtb_Product = rtb_Gain + modify_test1_P.Constant_Value;

    /* Fcn: '<S11>/Fcn11' */
    rtb_Sum2 = (cos(rtb_Product) - 1.0) * 0.35 + cos(rtb_Product) *
      rtb_DiscreteTransferFcn1;

    /* Signum: '<S11>/Sign1' */
    if (rtb_Sum2 < 0.0) {
      rtb_Sum2 = -1.0;
    } else if (rtb_Sum2 > 0.0) {
      rtb_Sum2 = 1.0;
    } else {
      if (rtb_Sum2 == 0.0) {
        rtb_Sum2 = 0.0;
      }
    }

    rtb_Sum2 = ((((0.0011263999999999998 * sin(rtb_Product) * cos(rtb_Product) *
                   rtb_DiscreteTransferFcn2 * rtb_DiscreteTransferFcn1 +
                   -0.00056319999999999992 * sin(rtb_Product) *
                   rtb_DiscreteTransferFcn1 * rtb_DiscreteTransferFcn1) +
                  0.00042765840636375897 * sin(rtb_Product) * cos(rtb_Product) *
                  cos(rtb_Product) * rt_powd_snf(rtb_DiscreteTransferFcn2, 2.0))
                 + 0.75933665902656078 * cos(rtb_Product) * 0.022 * 0.16 * 9.8 *
                 sin(rtb_Product)) + (((0.0256 * rt_powd_snf(sin(rtb_Product),
      2.0) + 0.0256) * 0.022 + 0.001569) - rt_powd_snf(0.00056319999999999992 *
      cos(rtb_Product), 2.0) * 1348.2540110556831) * (sin(rtb_Product) *
      rt_powd_snf(rtb_DiscreteTransferFcn2, 2.0) + modify_test1_P.Gain1_Gain *
      rtb_Sum2)) * modify_test1_P.Gain1_Gain_l;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_Sum2 >= modify_test1_P.Saturation1_UpperSat) {
    rtb_Sum2 = modify_test1_P.Saturation1_UpperSat;
  } else {
    if (rtb_Sum2 <= modify_test1_P.Saturation1_LowerSat) {
      rtb_Sum2 = modify_test1_P.Saturation1_LowerSat;
    }
  }

  /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
   *  Constant: '<S5>/DutyRatio_Offset'
   *  Gain: '<S5>/DAOutput'
   *  Saturate: '<Root>/Saturation1'
   *  Sum: '<S5>/Sum2'
   */
  rtb_Sum2 = modify_test1_P.DAOutput_Gain * rtb_Sum2 +
    modify_test1_P.DutyRatio_Offset_Value;
  if (rtb_Sum2 < 65536.0) {
    if (rtb_Sum2 >= 0.0) {
      rtb_DataTypeConversion = (uint16_T)rtb_Sum2;
    } else {
      rtb_DataTypeConversion = 0U;
    }
  } else {
    rtb_DataTypeConversion = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S5>/Data Type Conversion' */

  /* S-Function (c280xpwm): '<S5>/ePWM2' */
  {
    EPwm1Regs.TBPRD = (uint16_T)(modify_test1_P.CarryFrequency_Value);
  }

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.half.CMPA = (uint16_T)(rtb_DataTypeConversion);
  }

  /*-- Update CMPB value for ePWM1 --*/
  {
    EPwm1Regs.CMPB = (uint16_T)(rtb_DataTypeConversion);
  }

  /* S-Function (c280xpwm): '<S5>/ePWM3' */
  {
    EPwm2Regs.TBPRD = (uint16_T)(modify_test1_P.CarryFrequency_Value);
  }

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.half.CMPA = (uint16_T)(rtb_DataTypeConversion);
  }

  /*-- Update CMPB value for ePWM2 --*/
  {
    EPwm2Regs.CMPB = (uint16_T)(rtb_DataTypeConversion);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  rtb_Sum2 = floor(rtb_Sum1_m);
  if (rtIsNaN(rtb_Sum2) || rtIsInf(rtb_Sum2)) {
    rtb_Sum2 = 0.0;
  } else {
    rtb_Sum2 = fmod(rtb_Sum2, 65536.0);
  }

  modify_test1_B.DataTypeConversion1[0] = rtb_Sum2 < 0.0 ? (uint16_T)-(int16_T)
    (uint16_T)-rtb_Sum2 : (uint16_T)rtb_Sum2;
  rtb_Sum2 = floor(rtb_Sum1);
  if (rtIsNaN(rtb_Sum2) || rtIsInf(rtb_Sum2)) {
    rtb_Sum2 = 0.0;
  } else {
    rtb_Sum2 = fmod(rtb_Sum2, 65536.0);
  }

  modify_test1_B.DataTypeConversion1[1] = rtb_Sum2 < 0.0 ? (uint16_T)-(int16_T)
    (uint16_T)-rtb_Sum2 : (uint16_T)rtb_Sum2;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion1' */

  /* S-Function (c28xsci_tx): '<Root>/SCI Transmit1' */
  {
    char txString[4];
    byteswap_L8exp(txString, (char *)modify_test1_B.DataTypeConversion1, 2, 2);

    /* Send additional data header */
    {
      char String[1];
      String[0] = 222;
      scia_xmit(String, 1);
    }

    scia_xmit((char*)txString, 4);

    /* Send additional data terminator */
    {
      char String[1];
      String[0] = 253;
      scia_xmit(String, 1);
    }

    SciaRegs.SCIFFTX.bit.TXFFINTCLR = 1;
    SciaRegs.SCIFFTX.bit.TXFFIENA = 1;
    SciaRegs.SCIFFTX.bit.TXFFIL = 0;
  }

  /* Update for DiscreteTransferFcn: '<S6>/Discrete Transfer Fcn1' */
  modify_test1_DWork.DiscreteTransferFcn1_states = DiscreteTransferFcn1_tmp;

  /* Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn2' */
  modify_test1_DWork.DiscreteTransferFcn2_states = DiscreteTransferFcn2_tmp;
}

/* Model initialize function */
void modify_test1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(modify_test1_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &modify_test1_B), 0,
                sizeof(BlockIO_modify_test1));

  /* exported global signals */
  cnt1 = 0.0;
  cnt2 = 0.0;
  thre = FALSE;

  /* states (dwork) */
  modify_test1_DWork.DiscreteTransferFcn1_states = 0.0;
  modify_test1_DWork.DiscreteTransferFcn2_states = 0.0;

  /* Start for S-Function (c280xqep): '<S2>/eQEP' */
  config_QEP_eQEP1(2147483648U, 32768U, 0, 0, 0, 0, 136, 32768, 119, 0);

  /* Start for S-Function (c280xqep): '<S1>/eQEP' */
  config_QEP_eQEP2(2147483648U, 32768U, 0, 0, 0, 0, 136, 32768, 119, 0);

  /* Start for S-Function (c280xpwm): '<S5>/ePWM2' */

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

  /* Start for S-Function (c280xpwm): '<S5>/ePWM3' */

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

  /* InitializeConditions for DiscreteTransferFcn: '<S6>/Discrete Transfer Fcn1' */
  modify_test1_DWork.DiscreteTransferFcn1_states =
    modify_test1_P.DiscreteTransferFcn1_InitialSta;

  /* InitializeConditions for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn2' */
  modify_test1_DWork.DiscreteTransferFcn2_states =
    modify_test1_P.DiscreteTransferFcn2_InitialSta;
}

/* Model terminate function */
void modify_test1_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
