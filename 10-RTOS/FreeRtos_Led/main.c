/* Include files */
#include <stdio.h>
#include <stdlib.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "led.h"

/* The task functions prototype*/
void vTask1( void *pvParameters );
void vTask2( void *pvParameters );
/* Task parameter to be sent to the task function */
const char *pvTask1  = "Task1 is running.";
const char *pvTask2  = "Task2 is running.";
/* Extern functions */
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);
//extern int stdout_init (void);
/*-----------------------------------------------------------*/
/* Global semaphore variable */
SemaphoreHandle_t xSemaphore = NULL; 

int main( void )

{
	
		led_init() ;
	led_on();
	//led_off();

	
	/* Board initializations */
        SystemInit();
/* This function initializes the MCU clock, PLL will be used to generate Main MCU clock */  
	SystemCoreClockUpdate();
/* Initialize the serial I/O(console ), making standard output to be send to USART1 */
	//stdout_init();
	//printf("Initialization is done.\r\n");
	/* Create one of the two tasks. */
	xTaskCreate(vTask1, /* Pointer to the function that implements the task. */
	"Task 1", /* Text name for the task.  This is to facilitate debugging only. */
        configMINIMAL_STACK_SIZE, /* Stack depth in words. */
	(void*)pvTask1,		/* We are not using the task parameter. */
	1,			/* This task will run at priority 1. */
	NULL );		/* We are not using the task handle. */
	
        /* Create the other task in exactly the same way. */
	xTaskCreate( vTask2, "Task 2", configMINIMAL_STACK_SIZE, (void*)pvTask2, 1, NULL );
        /* Create a binary semaphore */
	xSemaphore = xSemaphoreCreateBinary();
	/* make the semaphore token available for the first time */
        xSemaphoreGive( xSemaphore);
	/* Start the scheduler so our tasks start executing. */
	vTaskStartScheduler();
	/* If all is well we will never reach here as the scheduler will now be
	running.  If we do reach here then it is likely that there was insufficient
	heap available for the idle task to be created. */


	for( ;; );
}
/*-----------------------------------------------------------*/
void vTask1( void *pvParameters )
{
char *pcTaskName = (char *) pvParameters;
	/* Task is implemented in an infinite loop. */
	for( ;; )
	{
		/* Take semaphore */
		xSemaphoreTake(xSemaphore,(TickType_t) portMAX_DELAY);
		/* Print out the name of this task. */
	  //	printf( "%s\r\n",pcTaskName );
		led_on() ;
		/* Give semaphore */
		xSemaphoreGive(xSemaphore);
		/* Delay for a period. */
		vTaskDelay( 500 / portTICK_PERIOD_MS );
	}
}
/*-----------------------------------------------------------*/
void vTask2( void *pvParameters )
{
char *pcTaskName = (char *) pvParameters;
	/* Task is implemented in an infinite loop. */
	for( ;; )
	{
		/* Take semaphore */
		xSemaphoreTake(xSemaphore,(TickType_t) portMAX_DELAY);
		/* Print out the name of this task. */
	  //	printf( "%s\r\n",pcTaskName );
		led_off();
		/* Give semaphore */
		xSemaphoreGive(xSemaphore);
		/* Delay for a period. */
		vTaskDelay( 1001 / portTICK_PERIOD_MS );
	}
} 
