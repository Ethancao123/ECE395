################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/simplefoc-stm32/drivers/BLDCDriver6PWM.cpp 

OBJS += \
./Core/simplefoc-stm32/drivers/BLDCDriver6PWM.o 

CPP_DEPS += \
./Core/simplefoc-stm32/drivers/BLDCDriver6PWM.d 


# Each subdirectory must supply rules for building sources it contributes
Core/simplefoc-stm32/drivers/%.o Core/simplefoc-stm32/drivers/%.su Core/simplefoc-stm32/drivers/%.cyclo: ../Core/simplefoc-stm32/drivers/%.cpp Core/simplefoc-stm32/drivers/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"/Users/ethancao/Documents/GitHub/ECE395/STM32/Final/Core/simplefoc-stm32" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-simplefoc-2d-stm32-2f-drivers

clean-Core-2f-simplefoc-2d-stm32-2f-drivers:
	-$(RM) ./Core/simplefoc-stm32/drivers/BLDCDriver6PWM.cyclo ./Core/simplefoc-stm32/drivers/BLDCDriver6PWM.d ./Core/simplefoc-stm32/drivers/BLDCDriver6PWM.o ./Core/simplefoc-stm32/drivers/BLDCDriver6PWM.su

.PHONY: clean-Core-2f-simplefoc-2d-stm32-2f-drivers

