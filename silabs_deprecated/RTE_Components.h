/*
 * Run-Time-Environment Component Configuration File
 *
 * Hand-crafted, based on something auto-generated.
 */
#ifndef RTE_COMPONENTS_H
#define RTE_COMPONENTS_H

/*
 * Define the Device Header File:
 */
#define CMSIS_device_header "em_device.h"

#define __ARM_ARCH_7EM__                1

#define RTE_CMSIS_RTOS2                 /* CMSIS-RTOS2 */
#define RTE_CMSIS_RTOS2_FreeRTOS        /* CMSIS-RTOS2 FreeRTOS */
//#define RTE_Compiler_EventRecorder
#define RTE_Compiler_EventRecorder_DAP
#define RTE_RTOS_FreeRTOS_CONFIG_RTOS2  /* RTOS FreeRTOS Config for CMSIS RTOS2 API */
#define RTE_RTOS_FreeRTOS_CORE          /* RTOS FreeRTOS Core */
#define RTE_RTOS_FreeRTOS_EVENTGROUPS   /* RTOS FreeRTOS Event Groups */
#define RTE_RTOS_FreeRTOS_HEAP_5        /* RTOS FreeRTOS Heap 4 */
#define RTE_RTOS_FreeRTOS_TIMERS        /* RTOS FreeRTOS Timers */

#endif /* RTE_COMPONENTS_H */
