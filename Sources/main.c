/* ###################################################################
**     Filename    : main.c
**     Processor   : S32K1xx
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.00
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including necessary module. Cpu.h contains other modules needed for compiling.*/
#include "Cpu.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>

volatile int exit_code = 0;
volatile int bufferCounter = 0;
volatile int temCounter = 0;

#define DWT_CTR  ((volatile uint32_t *) 0XE0001000)
/* User includes (#include below this line is not maintained by Processor Expert) */

void canTaskFunction(void *pvParameters){

  for(;;){
  	bufferCounter = temCounter++;
  }
}

void spiTaskFunction(void *pvParameters){

  for(;;){
  	bufferCounter = temCounter--;
  }
}

/*! 
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif

  *DWT_CTR |= ( 1 << 0 );
  SEGGER_SYSVIEW_Conf();
  SEGGER_SYSVIEW_Start();

  TaskHandle_t taskHandleT;
  BaseType_t status = xTaskCreate(canTaskFunction, "CAN_HANDLER", 100, "HI", 3, &taskHandleT);
  configASSERT( status == pdPASS);

  TaskHandle_t taskHandleM;
  status = xTaskCreate(spiTaskFunction, "SPI_HANDLER", 100, "HI", 3, &taskHandleM);
  configASSERT( status == pdPASS);
  vTaskStartScheduler();

  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;) {
    if(exit_code != 0) {
      break;
    }
  }
  return exit_code;
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.1 [05.21]
**     for the NXP S32K series of microcontrollers.
**
** ###################################################################
*/
