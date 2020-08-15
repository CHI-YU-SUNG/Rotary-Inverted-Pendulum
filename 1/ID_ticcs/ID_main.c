/*
 * File: ID_main.c
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

#include "ID.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "ID_private.h"
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
  ID_step();

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
  rtmSetErrorStatus(ID_M, 0);
  ID_initialize();
  config_schedulerTimer();
  noErr =
    rtmGetErrorStatus(ID_M) == (NULL);
  enable_interrupts();
  while (noErr ) {
    noErr =
      rtmGetErrorStatus(ID_M) == (NULL);
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  ID_terminate();
  disable_interrupts();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
