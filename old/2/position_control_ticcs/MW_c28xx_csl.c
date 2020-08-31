#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "DSP2833x_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "position_control.h"
#include "position_control_private.h"

void rt_OneStep(void);

/*-----------------------------------------------------------------------------
 * void config_schedulerTimer(void)
 *
 * Abstract:
 *      This function configures scheduler timer
 */
void config_schedulerTimer(void)
{
  InitCpuTimers();

  /* Configure CPU-Timer 0 to interrupt every 0.001 sec. */
  /* Parameters:  Timer Pointer, CPU Freq in MHz, Period in usec. */
  ConfigCpuTimer(&CpuTimer0, 150.0, 0.001 * 1000000);
  StartCpuTimer0();
}

void disableWatchdog(void)
{
  int *WatchdogWDCR = (void *) 0x7029;
  asm(" EALLOW ");
  *WatchdogWDCR = 0x0068;
  asm(" EDIS ");
}

interrupt void TINT0_isr(void)
{
  volatile unsigned int PIEIER1_stack_save = PieCtrlRegs.PIEIER1.all;
  PieCtrlRegs.PIEIER1.all &= ~64;      /*disable group1 lower/equal priority interrupts*/
  asm(" RPT #5 || NOP");               /*wait 5 cycles        */
  IFR &= ~1;                           /*eventually disable lower/equal priority pending interrupts*/
  PieCtrlRegs.PIEACK.all = 1;          /*ACK to allow other interrupts from the same group to fire*/
  IER |= 1;
  EINT;                                /*global interrupt enable*/
  rt_OneStep();
  DINT;                                /* disable global interrupts during context switch, CPU will enable global interrupts after exiting ISR    */
  PieCtrlRegs.PIEIER1.all = PIEIER1_stack_save;/*restore PIEIER register that was modified*/
}

void enable_interrupts()
{
  EALLOW;
  PieVectTable.TINT0 = &TINT0_isr;     /* Hook interrupt to the ISR*/
  EDIS;
  PieCtrlRegs.PIEIER1.bit.INTx7 = 1;   /* Enable interrupt TINT0*/
  IER |= M_INT1;

  /* Enable global Interrupts and higher priority real-time debug events:*/
  EINT;                                /* Enable Global interrupt INTM*/
  ERTM;                                /* Enable Global realtime interrupt DBGM*/
}

void disable_interrupts()
{
  IER &= M_INT1;                       /* Disable Global INT1 (CPU Interrupt 1)*/
  DINT;                                /* Disable Global interrupt INTM*/
}

void init_SCI(void)
{                                      /* initialize SCI & FIFO registers */
  EALLOW;

  /*
   * Initialize SCI_A with following parameters:
   *    BaudRate              : 114329
   *    CharacterLengthBits   : 8
   *    EnableLoopBack        : 0
   *    NumberOfStopBits      : 1
   *    ParityMode            : None
   *    SuspensionMode        : Free_run
   *    CommMode              : Raw_data
   */
  SciaRegs.SCICCR.bit.STOPBITS = 0;    /*Number of stop bits. (0: One stop bit, 1: Two stop bits)*/
  SciaRegs.SCICCR.bit.PARITY = 0;      /*Parity mode (0: Odd parity, 1: Even parity)*/
  SciaRegs.SCICCR.bit.PARITYENA = 0;   /*Enable Pary Mode */
  SciaRegs.SCICCR.bit.LOOPBKENA = 0;   /*Loop Back enable*/
  SciaRegs.SCICCR.bit.ADDRIDLE_MODE = 0;/*ADDR/IDLE Mode control*/
  SciaRegs.SCICCR.bit.SCICHAR = 7;     /*Character length*/
  SciaRegs.SCICTL1.bit.RXERRINTENA = 0;/*Disable receive error interrupt*/
  SciaRegs.SCICTL1.bit.SWRESET = 1;    /*Software reset*/
  SciaRegs.SCICTL1.bit.TXENA = 1;      /* SCI transmitter enable*/
  SciaRegs.SCICTL1.bit.RXENA = 0;      /* SCI receiver enable*/
  SciaRegs.SCIHBAUD = 0U;
  SciaRegs.SCILBAUD = 40U;

  /*Free run, continue SCI operation regardless of suspend*/
  SciaRegs.SCIPRI.bit.FREE = 1;        /* Free emulation mode control*/
  SciaRegs.SCIPRI.bit.SOFT = 0;        /* Interrupt priority select*/
  SciaRegs.SCIFFCT.bit.ABDCLR = 0;
  SciaRegs.SCIFFCT.bit.CDC = 0;
  SciaRegs.SCIFFTX.bit.SCIRST = 1;     /* SCI reset rx/tx channels*/
  SciaRegs.SCIFFTX.bit.SCIFFENA = 1;   /* SCI FIFO enhancements are enabled.*/
  SciaRegs.SCIFFTX.bit.TXFIFOXRESET = 1;/* Re-enable transmit FIFO operation.*/
  SciaRegs.SCIFFRX.bit.RXFIFORESET = 1;/* Re-enable receive FIFO operation.*/
  EDIS;
}

void init_SCI_GPIO(void)
{
  EALLOW;
  GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0;  /*Enable pull-up for GPIO29*/
  GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 1; /*Configure GPIO29 as SCITXDA*/
  EDIS;
}
