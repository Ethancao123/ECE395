
#ifndef STM32_CURRENTSENSE_MCU_DEF
#define STM32_CURRENTSENSE_MCU_DEF
#include "../../hardware_api.h"
#include "../../../common/foc_utils.h"
#include "stm32g4xx_hal_tim.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "stm32g4xx_hal.h"

#ifdef __cplusplus
}
#endif

#if defined(_STM32_DEF_) 

// generic implementation of the hardware specific structure
// containing all the necessary current sense parameters
// will be returned as a void pointer from the _configureADCx functions
// will be provided to the _readADCVoltageX() as a void pointer
typedef struct Stm32CurrentSenseParams {
  int pins[3] = {(int)NOT_SET};
  float adc_voltage_conv;
  ADC_HandleTypeDef* adc_handle = nullptr;
  TIM_HandleTypeDef timer_handle;
} Stm32CurrentSenseParams;

#endif
#endif
