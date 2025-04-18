
#include "../../hardware_api.h"

#if defined(_STM32_DEF_) and !defined(ARDUINO_B_G431B_ESC1) 

#include "stm32_mcu.h"

#define _ADC_VOLTAGE 3.3f
#define _ADC_RESOLUTION 1024.0f

void configurePinAsInput(GPIO_TypeDef* port, uint16_t pin) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(port, &GPIO_InitStruct);
}

// function reading an ADC value and returning the read voltage
void* _configureADCInline(const void* driver_params, GPIO_TypeDef* portA, uint8_t pinA,
		GPIO_TypeDef* portB, uint8_t pinB, GPIO_TypeDef* portC, uint8_t pinC){
  _UNUSED(driver_params);

  if( pinA != -1 )
	  configurePinAsInput(portA, pinA);
  if( pinB != -1 )
	  configurePinAsInput(portB, pinB);
  if( pinC != -1 )
	  configurePinAsInput(portC, pinC);

  Stm32CurrentSenseParams* params = new Stm32CurrentSenseParams {
    .pins = { pinA, pinB, pinC },
    .adc_voltage_conv = (_ADC_VOLTAGE)/(_ADC_RESOLUTION)
  };

  return params;
}

uint16_t analogReadSTM32(ADC_HandleTypeDef* hadc, uint32_t channel) {
    ADC_ChannelConfTypeDef sConfig = {0};

    sConfig.Channel = channel;
    sConfig.Rank = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLETIME_12CYCLES_5;

    // Configure ADC channel
    HAL_ADC_ConfigChannel(hadc, &sConfig);

    // Start conversion
    HAL_ADC_Start(hadc);

    // Wait for conversion complete
    HAL_ADC_PollForConversion(hadc, HAL_MAX_DELAY);

    // Read the value
    uint16_t value = HAL_ADC_GetValue(hadc);

    HAL_ADC_Stop(hadc);
    return value;
}

// function reading an ADC value and returning the read voltage
__attribute__((weak))  float _readADCVoltageInline(ADC_HandleTypeDef* hadc, uint32_t channel, const void* cs_params){
  uint32_t raw_adc = analogReadSTM32(hadc, channel);
  return raw_adc * ((Stm32CurrentSenseParams*)cs_params)->adc_voltage_conv;
}

#endif
