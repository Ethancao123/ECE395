/*
 * drv8316.h
 *
 *  Created on: Apr 28, 2025
 *      Author: ethancao
 */

#ifndef INC_MAGSENSOR_H_
#define INC_MAGSENSOR_H_

class Encoder {
public:
	Encoder(I2C_HandleTypeDef *_i2c);
	float getAngle();
	void zero();
private:
	I2C_HandleTypeDef* i2c;
	static const uint8_t MT6701_ADDR = 0b0000110 << 1; // Use 8-bit address
	static const uint8_t REG_TEMP = 0x00;
	uint8_t error = 0;
	float val;
	HAL_StatusTypeDef ret;
	uint8_t buf[2];
	float angleOffset = 0;
};
#endif
