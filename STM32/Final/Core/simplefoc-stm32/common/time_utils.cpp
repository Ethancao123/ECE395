#include "time_utils.h"

// function buffering delay() 
// arduino uno function doesn't work well with interrupts
void _delay(unsigned long ms){
#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega328PB__)  || defined(__AVR_ATmega2560__) || defined(__AVR_ATmega32U4__)
  // if arduino uno and other atmega328p chips
  // use while instad of delay, 
  // due to wrong measurement based on changed timer0
  unsigned long t = _micros() + ms*1000;
  while( _micros() < t ){}; 
#else
  // regular micros
  HAL_Delay(ms);
#endif
}

void DWT_Init(void) {
        CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
        DWT->CYCCNT = 0;
        DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
    }
// function buffering _micros() 
// arduino function doesn't work well with interrupts
unsigned long _micros(){
#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega328PB__)  || defined(__AVR_ATmega2560__) || defined(__AVR_ATmega32U4__)
// if arduino uno and other atmega328p chips
    //return the value based on the prescaler
    if((TCCR0B & 0b00000111) == 0x01) return (micros()/32);
    else return (micros());
#else
  // regular micros
//  return micros();

    // Then, read microseconds

    return DWT->CYCCNT / (HAL_RCC_GetHCLKFreq() / 1000000);
#endif
}
