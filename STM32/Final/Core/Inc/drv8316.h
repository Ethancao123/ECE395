/*
 * drv8316.h
 *
 *  Created on: Apr 28, 2025
 *      Author: ethancao
 */

#ifndef INC_DRV8316_H_
#define INC_DRV8316_H_

class Driver {
public:
	Driver(SPI_HandleTypeDef* _spi, GPIO_TypeDef *_sleepPort,
			uint16_t _sleepPin, GPIO_TypeDef *_scsPort, uint16_t _scsPin);
	void init();
	void reset();
	uint8_t* writeReg(uint16_t addr, uint16_t data);
	uint8_t* readReg(uint16_t addr);
private:
	uint8_t TX_Buffer[3];
	uint8_t RX_Buffer[3];
	SPI_HandleTypeDef* spi;
	GPIO_TypeDef* sleepPort;
	uint16_t sleepPin;
	GPIO_TypeDef* scsPort;
	uint16_t scsPin;
};

#endif /* INC_DRV8316_H_ */
