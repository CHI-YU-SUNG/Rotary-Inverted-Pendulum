/*
 * File: DSP28xx_SciUtil.c
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

#include "DSP28xx_SciUtil.h"

/* Transmit character(s) from the SCIa*/
void scia_xmit(char* pmsg, int msglen)
{
  int i;
  for (i = 0; i < msglen; i++) {
    while (SciaRegs.SCIFFTX.bit.TXFFST == 16) {
    }                                  /* The buffer is full;*/

    SciaRegs.SCITXBUF= pmsg[i];
  }

  while (SciaRegs.SCIFFTX.bit.TXFFST != 0) {
  }
}

int byteswap_L8exp(char* outdata, char* inport ,int inportWidth, int typeLen)
{
  int i,j;
  int k = 0;
  int numWrd = (inportWidth * typeLen)/2;/* number of words (16 bit length) to send*/

  /* Little Endian, 8bit swap */
  for (i = 0; i < numWrd; i++) {
    for (j = 0; j < 2; j++) {
      outdata[k++] = inport[i] >>(8*j);
    }
  }

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
