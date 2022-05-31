################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/adc_init.c \
../Core/Inc/afficheur.c \
../Core/Inc/buzzer.c \
../Core/Inc/led.c 

OBJS += \
./Core/Inc/adc_init.o \
./Core/Inc/afficheur.o \
./Core/Inc/buzzer.o \
./Core/Inc/led.o 

C_DEPS += \
./Core/Inc/adc_init.d \
./Core/Inc/afficheur.d \
./Core/Inc/buzzer.d \
./Core/Inc/led.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/%.o: ../Core/Inc/%.c Core/Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DSTM32L053xx -DUSE_FULL_LL_DRIVER -DHSE_VALUE=8000000 -DHSE_STARTUP_TIMEOUT=100 -DLSE_STARTUP_TIMEOUT=5000 -DLSE_VALUE=32768 -DMSI_VALUE=2097000 -DHSI_VALUE=16000000 -DLSI_VALUE=37000 -DVDD_VALUE=3300 -DPREFETCH_ENABLE=0 -DINSTRUCTION_CACHE_ENABLE=1 -DDATA_CACHE_ENABLE=1 -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Inc

clean-Core-2f-Inc:
	-$(RM) ./Core/Inc/adc_init.d ./Core/Inc/adc_init.o ./Core/Inc/afficheur.d ./Core/Inc/afficheur.o ./Core/Inc/buzzer.d ./Core/Inc/buzzer.o ./Core/Inc/led.d ./Core/Inc/led.o

.PHONY: clean-Core-2f-Inc

