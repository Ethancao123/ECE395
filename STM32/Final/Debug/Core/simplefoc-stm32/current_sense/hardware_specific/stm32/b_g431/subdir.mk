################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/simplefoc-stm32/current_sense/hardware_specific/stm32/b_g431/b_g431_hal.cpp \
../Core/simplefoc-stm32/current_sense/hardware_specific/stm32/b_g431/b_g431_mcu.cpp 

OBJS += \
./Core/simplefoc-stm32/current_sense/hardware_specific/stm32/b_g431/b_g431_hal.o \
./Core/simplefoc-stm32/current_sense/hardware_specific/stm32/b_g431/b_g431_mcu.o 

CPP_DEPS += \
./Core/simplefoc-stm32/current_sense/hardware_specific/stm32/b_g431/b_g431_hal.d \
./Core/simplefoc-stm32/current_sense/hardware_specific/stm32/b_g431/b_g431_mcu.d 


# Each subdirectory must supply rules for building sources it contributes
Core/simplefoc-stm32/current_sense/hardware_specific/stm32/b_g431/%.o Core/simplefoc-stm32/current_sense/hardware_specific/stm32/b_g431/%.su Core/simplefoc-stm32/current_sense/hardware_specific/stm32/b_g431/%.cyclo: ../Core/simplefoc-stm32/current_sense/hardware_specific/stm32/b_g431/%.cpp Core/simplefoc-stm32/current_sense/hardware_specific/stm32/b_g431/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"/Users/ethancao/Documents/GitHub/ECE395/STM32/Final/Core/simplefoc-stm32" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-simplefoc-2d-stm32-2f-current_sense-2f-hardware_specific-2f-stm32-2f-b_g431

clean-Core-2f-simplefoc-2d-stm32-2f-current_sense-2f-hardware_specific-2f-stm32-2f-b_g431:
	-$(RM) ./Core/simplefoc-stm32/current_sense/hardware_specific/stm32/b_g431/b_g431_hal.cyclo ./Core/simplefoc-stm32/current_sense/hardware_specific/stm32/b_g431/b_g431_hal.d ./Core/simplefoc-stm32/current_sense/hardware_specific/stm32/b_g431/b_g431_hal.o ./Core/simplefoc-stm32/current_sense/hardware_specific/stm32/b_g431/b_g431_hal.su ./Core/simplefoc-stm32/current_sense/hardware_specific/stm32/b_g431/b_g431_mcu.cyclo ./Core/simplefoc-stm32/current_sense/hardware_specific/stm32/b_g431/b_g431_mcu.d ./Core/simplefoc-stm32/current_sense/hardware_specific/stm32/b_g431/b_g431_mcu.o ./Core/simplefoc-stm32/current_sense/hardware_specific/stm32/b_g431/b_g431_mcu.su

.PHONY: clean-Core-2f-simplefoc-2d-stm32-2f-current_sense-2f-hardware_specific-2f-stm32-2f-b_g431

