################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/simplefoc-stm32/common/base_classes/CurrentSense.cpp \
../Core/simplefoc-stm32/common/base_classes/FOCMotor.cpp \
../Core/simplefoc-stm32/common/base_classes/Sensor.cpp 

OBJS += \
./Core/simplefoc-stm32/common/base_classes/CurrentSense.o \
./Core/simplefoc-stm32/common/base_classes/FOCMotor.o \
./Core/simplefoc-stm32/common/base_classes/Sensor.o 

CPP_DEPS += \
./Core/simplefoc-stm32/common/base_classes/CurrentSense.d \
./Core/simplefoc-stm32/common/base_classes/FOCMotor.d \
./Core/simplefoc-stm32/common/base_classes/Sensor.d 


# Each subdirectory must supply rules for building sources it contributes
Core/simplefoc-stm32/common/base_classes/%.o Core/simplefoc-stm32/common/base_classes/%.su Core/simplefoc-stm32/common/base_classes/%.cyclo: ../Core/simplefoc-stm32/common/base_classes/%.cpp Core/simplefoc-stm32/common/base_classes/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"/Users/ethancao/Documents/GitHub/ECE395/STM32/Final/Core/simplefoc-stm32" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-simplefoc-2d-stm32-2f-common-2f-base_classes

clean-Core-2f-simplefoc-2d-stm32-2f-common-2f-base_classes:
	-$(RM) ./Core/simplefoc-stm32/common/base_classes/CurrentSense.cyclo ./Core/simplefoc-stm32/common/base_classes/CurrentSense.d ./Core/simplefoc-stm32/common/base_classes/CurrentSense.o ./Core/simplefoc-stm32/common/base_classes/CurrentSense.su ./Core/simplefoc-stm32/common/base_classes/FOCMotor.cyclo ./Core/simplefoc-stm32/common/base_classes/FOCMotor.d ./Core/simplefoc-stm32/common/base_classes/FOCMotor.o ./Core/simplefoc-stm32/common/base_classes/FOCMotor.su ./Core/simplefoc-stm32/common/base_classes/Sensor.cyclo ./Core/simplefoc-stm32/common/base_classes/Sensor.d ./Core/simplefoc-stm32/common/base_classes/Sensor.o ./Core/simplefoc-stm32/common/base_classes/Sensor.su

.PHONY: clean-Core-2f-simplefoc-2d-stm32-2f-common-2f-base_classes

