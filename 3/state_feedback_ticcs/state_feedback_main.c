/*
 * File: state_feedback_main.c
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
#include "rtwtypes.h"
#include "state_feedback_private.h"
#include "c2000_main.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include <stdlib.h>
#include <stdio.h>

void init_board(void);
void enable_interrupts(void);
void config_schedulerTimer(void);
void disable_interrupts(void);
volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;

/* Function: rt_OneStep -------------------------------------------
 *
 * Abstract:
 *      Perform one step of the model.  Single-tasking implementation.
 */
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against
   * preemption.
   */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  asm(" SETC INTM");
  PieCtrlRegs.PIEIER1.all |= (1 << 6);
  asm(" CLRC INTM");
  state_feedback_step();

  /* Get model outputs here */
  asm(" SETC INTM");
  PieCtrlRegs.PIEIER1.all &= ~(1 << 6);
  asm(" RPT #5 || NOP");
  IFR &= 0xFFFE;
  PieCtrlRegs.PIEACK.all = 0x1;
  asm(" CLRC INTM");
  OverrunFlag--;
}

/* Function: main -------------------------------------------
 *
 * Abstract:
 *      Entry point into the code.
 */
void main(void)
{
  volatile boolean_T noErr;
  init_board();
  rtmSetErrorStatus(state_feedback_M, 0);
  state_feedback_initialize();
  config_schedulerTimer();
  noErr =
    rtmGetErrorStatus(state_feedback_M) == (NULL);
  enable_interrupts();
  while (noErr ) {
    noErr =
      rtmGetErrorStatus(state_feedback_M) == (NULL);
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  state_feedback_terminate();
  disable_interrupts();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
