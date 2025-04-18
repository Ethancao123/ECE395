################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/simplefoc-stm32/common/foc_utils.cpp \
../Core/simplefoc-stm32/common/lowpass_filter.cpp \
../Core/simplefoc-stm32/common/pid.cpp \
../Core/simplefoc-stm32/common/time_utils.cpp 

OBJS += \
./Core/simplefoc-stm32/common/foc_utils.o \
./Core/simplefoc-stm32/common/lowpass_filter.o \
./Core/simplefoc-stm32/common/pid.o \
./Core/simplefoc-stm32/common/time_utils.o 

CPP_DEPS += \
./Core/simplefoc-stm32/common/foc_utils.d \
./Core/simplefoc-stm32/common/lowpass_filter.d \
./Core/simplefoc-stm32/common/pid.d \
./Core/simplefoc-stm32/common/time_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Core/simplefoc-stm32/common/%.o Core/simplefoc-stm32/common/%.su Core/simplefoc-stm32/common/%.cyclo: ../Core/simplefoc-stm32/common/%.cpp Core/simplefoc-stm32/common/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"/Users/ethancao/Documents/GitHub/ECE395/STM32/Final/Core/simplefoc-stm32" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-simplefoc-2d-stm32-2f-common

clean-Core-2f-simplefoc-2d-stm32-2f-common:
	-$(RM) ./Core/simplefoc-stm32/common/foc_utils.cyclo ./Core/simplefoc-stm32/common/foc_utils.d ./Core/simplefoc-stm32/common/foc_utils.o ./Core/simplefoc-stm32/common/foc_utils.su ./Core/simplefoc-stm32/common/lowpass_filter.cyclo ./Core/simplefoc-stm32/common/lowpass_filter.d ./Core/simplefoc-stm32/common/lowpass_filter.o ./Core/simplefoc-stm32/common/lowpass_filter.su ./Core/simplefoc-stm32/common/pid.cyclo ./Core/simplefoc-stm32/common/pid.d ./Core/simplefoc-stm32/common/pid.o ./Core/simplefoc-stm32/common/pid.su ./Core/simplefoc-stm32/common/time_utils.cyclo ./Core/simplefoc-stm32/common/time_utils.d ./Core/simplefoc-stm32/common/time_utils.o ./Core/simplefoc-stm32/common/time_utils.su

.PHONY: clean-Core-2f-simplefoc-2d-stm32-2f-common

