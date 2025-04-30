/*
 * drv8316.cpp
 *
 *  Created on: Apr 28, 2025
 *      Author: ethancao
 */
#include "stm32g4xx_hal.h"
#include "drv8316.h"

Driver::Driver(SPI_HandleTypeDef* _spi, GPIO_TypeDef *_sleepPort,
	uint16_t _sleepPin, GPIO_TypeDef *_scsPort, uint16_t _scsPin) {
	spi = _spi;
	sleepPort = _sleepPort;
	sleepPin = _sleepPin;
	scsPort = _scsPort;
	scsPin = _scsPin;
	return;
}

void Driver::init() {
	reset();
}

void Driver::reset() {
	HAL_GPIO_WritePin(sleepPort, sleepPin, GPIO_PIN_RESET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(scsPort, scsPin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(sleepPort, sleepPin, GPIO_PIN_SET);
}


uint8_t* Driver::writeReg(uint16_t addr, uint16_t data) {
	uint16_t mode = 1;
	addr <<= 11;
	mode <<= 15;
	uint16_t calc = (mode & 0x8000) | (addr & 0x7E00) | (data & 0x00FF);
	uint16_t parity = 0;

	while(calc) {
		parity ^= (calc & 1);
		calc >>= 1;
	}
	parity <<= 8;

	uint16_t txData = mode | addr | parity | (data & 0x00FF);
	TX_Buffer[0] = txData >> 8;
	TX_Buffer[1] = txData & 0xFF;
	TX_Buffer[2] = 0;
	HAL_GPIO_WritePin(scsPort, scsPin, GPIO_PIN_RESET);
	HAL_Delay(1);
	HAL_StatusTypeDef status = HAL_SPI_TransmitReceive(spi, (uint8_t*)TX_Buffer, (uint8_t*)RX_Buffer, 2, 100000);
	HAL_GPIO_WritePin(scsPort, scsPin, GPIO_PIN_SET);
	return RX_Buffer;
}

uint8_t* Driver::readReg(uint16_t addr) {
	uint16_t mode = 0;
	const uint16_t data = 0;
	addr <<= 11;
	mode <<= 15;
	uint16_t calc = (mode & 0x8000) | (addr & 0x7E00) | (data & 0x00FF);
	uint16_t parity = 0;

	while(calc) {
		parity ^= (calc & 1);
		calc >>= 1;
	}
	parity <<= 8;

	uint16_t txData = mode | addr | parity | (data & 0x00FF);
	TX_Buffer[0] = txData >> 8;
	TX_Buffer[1] = txData & 0xFF;
	TX_Buffer[2] = 0;
	HAL_GPIO_WritePin(scsPort, scsPin, GPIO_PIN_RESET);
	HAL_Delay(1);
	HAL_StatusTypeDef status = HAL_SPI_TransmitReceive(spi, (uint8_t*)TX_Buffer, (uint8_t*)RX_Buffer, 2, 100000);
	HAL_GPIO_WritePin(scsPort, scsPin, GPIO_PIN_SET);
	HAL_Delay(1);
	return RX_Buffer;
}


