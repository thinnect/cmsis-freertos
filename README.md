# cmsis-freertos

Minimal bundle of CMSIS_5 components to get CMSIS-FreeRTOS running.

CMSIS_5: https://github.com/ARM-software/CMSIS_5

# FreeRTOS

Use the FreeRTOS version from:
CMSIS-FreeRTOS: https://github.com/ARM-software/CMSIS-FreeRTOS

# EFR32 configurations

efr32xg1x: RTE_Components header and sample FreeRTOSConfig.h for EFR32 Series 1.
efr32xg2x: RTE_Components header and sample FreeRTOSConfig.h for EFR32 Series 2.

Also make sure `_RTE_` gets define somewhere or add `CFLAGS += -D_RTE` to Makefile.
