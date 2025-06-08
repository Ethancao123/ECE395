/*
 * magsensor.cpp
 *
 *  Created on: Apr 30, 2025
 *      Author: ethancao
 */
#include "stm32g4xx_hal.h"
#include "magsensor.h"

Encoder::Encoder(I2C_HandleTypeDef* _i2c) {
	i2c = _i2c;
	buf[0] = 0x30;
	ret = HAL_I2C_Master_Transmit(i2c, MT6701_ADDR, buf, 1, HAL_MAX_DELAY);
	if ( ret != HAL_OK )
	  error = 1;
	else
	  ret = HAL_I2C_Master_Receive(i2c, MT6701_ADDR, buf, 1, HAL_MAX_DELAY);

}

float Encoder::getAngle() {
	buf[0] = 0x03;
  	ret = HAL_I2C_Master_Transmit(i2c, MT6701_ADDR, buf, 1, HAL_MAX_DELAY);
  	if ( ret != HAL_OK ) {
  	  error = 1;
  	} else {
  	   // Read 2 bytes from the temperature register
  	   ret = HAL_I2C_Master_Receive(i2c, MT6701_ADDR, buf, 2, HAL_MAX_DELAY);
  	   if ( ret != HAL_OK ) {
  	      error = 2;
  	   } else {
  	      //Combine the bytes
  	      val = ((int16_t)buf[0] << 6) | ((int16_t)buf[1] >> 2);
  	      val *= 0.02197265625; //360/16384
  	      val -= angleOffset;
  	      if(val < 0)
  	    	  val += 360;
  	      return val;
  	   }
  	}
  	return -1;
  }

void Encoder::zero() {
	angleOffset = getAngle();
}
