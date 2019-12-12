/*
 * FreeRTOS Kernel V10.2.1
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/******************************************************************************
    See http://www.freertos.org/a00110.html for an explanation of the
    definitions contained in this file.
******************************************************************************/

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 * http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/

#include "em_device.h"

extern uint32_t SystemCoreClock;

/* Cortex M33 port configuration. */
#define configENABLE_MPU                                0
#define configENABLE_FPU                                1
#define configENABLE_TRUSTZONE                          0
#define configRUN_FREERTOS_SECURE_ONLY                  1

// Replace the SysTick_Handler in port.c with xPortSysTickHandler and have
// cmsis_os2.c SysTick_Handler call xPortSysTickHandler because it needs to
// handle overflows for osKernelGetSysTimerCount to work correctly
#define SysTick_Handler xPortSysTickHandler

/* Constants related to the behaviour or the scheduler. */
#define configUSE_PORT_OPTIMISED_TASK_SELECTION         0
#define configUSE_PREEMPTION                            1
#define configUSE_TIME_SLICING                          1
#define configMAX_PRIORITIES                            ( 56 ) // osPriorityISR
#define configIDLE_SHOULD_YIELD                         1
#define configUSE_16_BIT_TICKS                          0 /* Only for 8 and 16-bit hardware. */

/* Constants that describe the hardware and memory usage. */
#define configCPU_CLOCK_HZ                              SystemCoreClock
#define configMINIMAL_STACK_SIZE                        ( ( uint16_t ) 1024 )
//#define configMINIMAL_SECURE_STACK_SIZE               ( 1024 )
#define configMAX_TASK_NAME_LEN                         ( 12 )
#define configTOTAL_HEAP_SIZE                           ( ( size_t ) ( 40 * 1024 ) )

/* Constants that build features in or out. */
#define configUSE_MUTEXES                               1
#define configUSE_TICKLESS_IDLE                         1
#define configEXPECTED_IDLE_TIME_BEFORE_SLEEP           2
#define configUSE_APPLICATION_TASK_TAG                  0
#define configUSE_NEWLIB_REENTRANT                      0
#define configUSE_CO_ROUTINES                           0
#define configUSE_COUNTING_SEMAPHORES                   1
#define configUSE_RECURSIVE_MUTEXES                     1
#define configUSE_QUEUE_SETS                            0
#define configUSE_TASK_NOTIFICATIONS                    1
#define configUSE_TRACE_FACILITY                        1

/* Constants that define which hook (callback) functions should be used. */
#define configUSE_IDLE_HOOK                             0
#define configUSE_TICK_HOOK                             0
#define configUSE_MALLOC_FAILED_HOOK                    0

/* Constants provided for debugging and optimisation assistance. */
#define configCHECK_FOR_STACK_OVERFLOW                  2
//#define configASSERT( x )                             if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }
#define configASSERT( x )   if( ( x ) == 0 ) { __ASM volatile("cpsid i" : : : "memory"); while(1) ; }
#define configQUEUE_REGISTRY_SIZE                       0

/* Software timer definitions. */
#define configUSE_TIMERS                                1
#define configTIMER_TASK_PRIORITY                       ( 40 ) // osPriorityHigh
#define configTIMER_QUEUE_LENGTH                        60
#define configTIMER_TASK_STACK_DEPTH                    ( configMINIMAL_STACK_SIZE  )

/* Set the following definitions to 1 to include the API function, or zero
 * to exclude the API function.  NOTE:  Setting an INCLUDE_ parameter to 0 is
 * only necessary if the linker does not automatically remove functions that are
 * not referenced anyway. */
#define INCLUDE_vTaskPrioritySet                        1
#define INCLUDE_uxTaskPriorityGet                       1
#define INCLUDE_vTaskDelete                             1
#define INCLUDE_vTaskCleanUpResources                   0
#define INCLUDE_vTaskSuspend                            1
#define INCLUDE_vTaskDelayUntil                         1
#define INCLUDE_vTaskDelay                              1
#define INCLUDE_uxTaskGetStackHighWaterMark             1
#define INCLUDE_xTaskGetIdleTaskHandle                  0
#define INCLUDE_eTaskGetState                           1
#define INCLUDE_xTaskResumeFromISR                      0
#define INCLUDE_xTaskGetCurrentTaskHandle               1
#define INCLUDE_xTaskGetSchedulerState                  1
#define INCLUDE_xSemaphoreGetMutexHolder                1
#define INCLUDE_xTimerPendFunctionCall                  1

/* This demo makes use of one or more example stats formatting functions.  These
 * format the raw data provided by the uxTaskGetSystemState() function in to
 * human readable ASCII form.  See the notes in the implementation of vTaskList()
 * within FreeRTOS/Source/tasks.c for limitations. */
#define configUSE_STATS_FORMATTING_FUNCTIONS            1

/* Dimensions a buffer that can be used by the FreeRTOS+CLI command interpreter.
 * See the FreeRTOS+CLI documentation for more information:
 * http://www.FreeRTOS.org/FreeRTOS-Plus/FreeRTOS_Plus_CLI/ */
#define configCOMMAND_INT_MAX_OUTPUT_SIZE               2048

/* Interrupt priority configuration follows...................... */

/* Use the system definition, if there is one. */
#ifdef __NVIC_PRIO_BITS
    #define configPRIO_BITS                             __NVIC_PRIO_BITS
#else
    #warning Assuming __NVIC_PRIO_BITS 4
    #define configPRIO_BITS                             4
#endif

/* The lowest interrupt priority that can be used in a call to a "set priority"
 * function. */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY         0x07

/* The highest interrupt priority that can be used by any interrupt service
 * routine that makes calls to interrupt safe FreeRTOS API functions.  DO NOT
 * CALL INTERRUPT SAFE FREERTOS API FUNCTIONS FROM ANY INTERRUPT THAT HAS A
 * HIGHER PRIORITY THAN THIS! (higher priorities are lower numeric values). */
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY    5

/* Interrupt priorities used by the kernel port layer itself.  These are generic
 * to all Cortex-M ports, and do not rely on any particular library functions. */
#define configKERNEL_INTERRUPT_PRIORITY                 ( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << ( 8 - configPRIO_BITS ) )

/* !!!! configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!
 * See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY            ( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << ( 8 - configPRIO_BITS ) )

/* The #ifdef guards against the file being included from IAR assembly files. */
#ifndef __IASMARM__

    /* Constants related to the generation of run time stats. */
    #define configGENERATE_RUN_TIME_STATS               0
    #define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS()
    #define portGET_RUN_TIME_COUNTER_VALUE()            0
    #define configTICK_RATE_HZ                          ( ( TickType_t ) 1000 )

#endif /* __IASMARM__ */

/* Enable static allocation. */
#define configSUPPORT_STATIC_ALLOCATION                 1

#define configSUPPORT_DYNAMIC_ALLOCATION                1

#define configTASK_RETURN_ADDRESS                       0
#define configINCLUDE_FREERTOS_TASK_C_ADDITIONS_H       1
#define configENABLE_BACKWARD_COMPATIBILITY             1

//-----------------------------------------------------------------------------
// TICKLESS IDLE functionality seems to be missing from M33 portmacro.h files
// for no apparent reason, so we add it here until it becomes available
// upstream or an alternative is developed
//-----------------------------------------------------------------------------
/* Tickless idle/low power functionality. */
#ifndef portSUPPRESS_TICKS_AND_SLEEP
    typedef uint32_t TickType_t; // Actually in portmacro.h and assumes configUSE_16_BIT_TICKS=0
    extern void vPortSuppressTicksAndSleep( TickType_t xExpectedIdleTime );
    #define portSUPPRESS_TICKS_AND_SLEEP( xExpectedIdleTime ) vPortSuppressTicksAndSleep( xExpectedIdleTime )
#endif
//-----------------------------------------------------------------------------

#endif /* FREERTOS_CONFIG_H */
