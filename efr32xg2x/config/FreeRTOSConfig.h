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
 *
 * See http://www.freertos.org/a00110.html.
 *----------------------------------------------------------*/

#include <stdint.h>

#include "em_device.h"

extern uint32_t SystemCoreClock;

/* Cortex M33 port configuration. */
#define configENABLE_MPU                                0
#define configENABLE_FPU                                1
#define configENABLE_TRUSTZONE                          0
#define configRUN_FREERTOS_SECURE_ONLY                  1

//  <o>Minimal stack size [words] <0-65535>
//  <i> Stack for idle task and default task stack in words.
//  <i> Default: 128
#define configMINIMAL_STACK_SIZE                ((uint16_t)(512))
#define configMINIMAL_SECURE_STACK_SIZE         (2*configMINIMAL_STACK_SIZE)

//  <o>Total heap size [bytes] <0-0xFFFFFFFF>
//  <i> Heap memory size in bytes.
//  <i> Default: 8192
#define configTOTAL_HEAP_SIZE                   ((size_t)(36*1024)) //32 initially

//  <o>Kernel tick frequency [Hz] <0-0xFFFFFFFF>
//  <i> Kernel tick rate in Hz.
//  <i> Default: 1000
#define configTICK_RATE_HZ                      ((TickType_t)1000)

//  <o>Timer task stack depth [words] <0-65535>
//  <i> Stack for timer task in words.
//  <i> Default: 80
#define configTIMER_TASK_STACK_DEPTH            (configMINIMAL_STACK_SIZE)

//  <o>Timer task priority <0-56>
//  <i> Timer task priority.
//  <i> Default: 40 (High)
#define configTIMER_TASK_PRIORITY               (40) // osPriorityHigh

//  <o>Timer queue length <0-1024>
//  <i> Timer command queue length.
//  <i> Default: 5
#define configTIMER_QUEUE_LENGTH                (60)

//  <q>Use time slicing
//  <i> Enable setting to use timeslicing.
//  <i> Default: 1
#define configUSE_TIME_SLICING                  1

//  <q>Idle should yield
//  <i> Control Yield behaviour of the idle task.
//  <i> Default: 1
#define configIDLE_SHOULD_YIELD                 1

//  <o>Check for stack overflow
//    <0=>Disable <1=>Method one <2=>Method two
//  <i> Enable or disable stack overflow checking.
//  <i> Callback function vApplicationStackOverflowHook implementation is required when stack checking is enabled.
//  <i> Default: 0
#define configCHECK_FOR_STACK_OVERFLOW          2

//  <o>Record stack high address
//  <i> When set to 1 the stack start address is saved into each task's TCB (assuming stack grows down).
//  <i> Default: 0
#define configRECORD_STACK_HIGH_ADDRESS         1

//  <q>Use idle hook
//  <i> Enable callback function call on each idle task iteration.
//  <i> Callback function vApplicationIdleHook implementation is required when idle hook is enabled.
//  <i> Default: 0
#define configUSE_IDLE_HOOK                     0

//  <q>Use tick hook
//  <i> Enable callback function call during each tick interrupt.
//  <i> Callback function vApplicationTickHook implementation is required when tick hook is enabled.
//  <i> Default: 0
#define configUSE_TICK_HOOK                     0

//  <q>Use deamon task startup hook
//  <i> Enable callback function call when timer service starts.
//  <i> Callback function vApplicationDaemonTaskStartupHook implementation is required when deamon task startup hook is enabled.
//  <i> Default: 0
#define configUSE_DAEMON_TASK_STARTUP_HOOK      0

//  <q>Use malloc failed hook
//  <i> Enable callback function call when out of dynamic memory.
//  <i> Callback function vApplicationMallocFailedHook implementation is required when malloc failed hook is enabled.
//  <i> Default: 0
#define configUSE_MALLOC_FAILED_HOOK            0

/* Defines needed by FreeRTOS to implement CMSIS RTOS2 API. Do not change! */
#define configCPU_CLOCK_HZ                      (SystemCoreClock)
#define configSUPPORT_STATIC_ALLOCATION         1
#define configSUPPORT_DYNAMIC_ALLOCATION        1
#define configUSE_PREEMPTION                    1
#define configUSE_TIMERS                        1
#define configUSE_MUTEXES                       1
#define configUSE_RECURSIVE_MUTEXES             1
#define configUSE_COUNTING_SEMAPHORES           1
#define configUSE_TASK_NOTIFICATIONS            1
#define configUSE_TRACE_FACILITY                1
#define configUSE_16_BIT_TICKS                  0
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 0
#define configMAX_PRIORITIES                    (56) // osPriorityISR

/* Defines that include FreeRTOS functions which implement CMSIS RTOS2 API. Do not change! */
#define INCLUDE_xEventGroupSetBitsFromISR       1
#define INCLUDE_xSemaphoreGetMutexHolder        1
#define INCLUDE_vTaskDelay                      1
#define INCLUDE_vTaskDelayUntil                 1
#define INCLUDE_vTaskDelete                     1
#define INCLUDE_xTaskGetCurrentTaskHandle       1
#define INCLUDE_xTaskGetSchedulerState          1
#define INCLUDE_uxTaskGetStackHighWaterMark     1
#define INCLUDE_uxTaskPriorityGet               1
#define INCLUDE_vTaskPrioritySet                1
#define INCLUDE_eTaskGetState                   1
#define INCLUDE_vTaskSuspend                    1
#define INCLUDE_xTimerPendFunctionCall          1

#define configASSERT( x )                               if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }

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

/* Sleep management configuration */
#ifndef configUSE_TICKLESS_IDLE
#define configUSE_TICKLESS_IDLE                         1
#endif//configUSE_TICKLESS_IDLE
#ifndef configEXPECTED_IDLE_TIME_BEFORE_SLEEP
#define configEXPECTED_IDLE_TIME_BEFORE_SLEEP           2
#endif//configEXPECTED_IDLE_TIME_BEFORE_SLEEP

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

/* Map the FreeRTOS port interrupt handlers to their CMSIS standard names. */
// Replace the SysTick_Handler in port.c with xPortSysTickHandler and have
// cmsis_os2.c SysTick_Handler call xPortSysTickHandler because it needs to
// handle overflows for osKernelGetSysTimerCount to work correctly
#define SysTick_Handler xPortSysTickHandler

#endif /* FREERTOS_CONFIG_H */
