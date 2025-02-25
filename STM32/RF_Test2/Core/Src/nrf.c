/*
 * nrf.c
 *
 *  Created on: Feb 23, 2025
 *      Author: ethancao
 */

#include "nrf.h"


SPI_HandleTypeDef bus;
bool isTX;

void setCS(bool state){
	HAL_GPIO_WritePin(CSN_GPIO_Port, CSN_Pin, state);
}

void setCE(bool state){
	HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, state);
}


void nrf_init(SPI_HandleTypeDef bus_, bool isTX_) {
	bus = bus_;
	isTX = isTX_;
	nrf_reset();

	//set FIFO depth to 1

	//set ptx, prx mode
	if(isTX){
		write_register(NRF24L01P_REG_TX_ADDR, WIRELESS_ADDR);
		uint8_t new_config = read_register(NRF24L01P_REG_CONFIG);
		new_config &= 0xFE;
		write_register(NRF24L01P_REG_CONFIG, new_config);
	} else {
		write_register(NRF24L01P_REG_RX_ADDR_P0, WIRELESS_ADDR);
		uint8_t new_config = read_register(NRF24L01P_REG_CONFIG);
		new_config |= 1 << 0;
		write_register(NRF24L01P_REG_CONFIG, new_config);
	}

	//power up
	uint8_t new_config = read_register(NRF24L01P_REG_CONFIG);
	new_config |= 1 << 1;
	write_register(NRF24L01P_REG_CONFIG, new_config);

	//set RX pipe width
	write_register(NRF24L01P_REG_RX_PW_P0, PAYLOAD_LEN);
	//set RF channel
	write_register(NRF24L01P_REG_RF_CH, 15);
	//set data rate
//	uint8_t new_rf_setup = read_register(NRF24L01P_REG_RF_SETUP) & 0xD7;
//	write_register(NRF24L01P_REG_RF_SETUP, new_rf_setup);
	//set tx power
//	new_rf_setup = read_register(NRF24L01P_REG_RF_SETUP) & 0xF9;
//	new_rf_setup |= (0x3 << 1);
//	write_register(NRF24L01P_REG_RF_SETUP, new_rf_setup);
	//set crc length
	//default should work
	//set address width
	//default should work
	//set auto retransmit count
	//default should work
	//set retransmit delay
	//default should work
	setCE(1);
}

uint8_t nrf_reset() {
	setCS(1);
	setCE(0);
	// Reset registers
	// Reset registers
	write_register(NRF24L01P_REG_CONFIG, 0x08);
	write_register(NRF24L01P_REG_EN_AA, 0x3F);
	write_register(NRF24L01P_REG_EN_RXADDR, 0x03);
	write_register(NRF24L01P_REG_SETUP_AW, 0x03);
	write_register(NRF24L01P_REG_SETUP_RETR, 0x03);
	write_register(NRF24L01P_REG_RF_CH, 0x02);
    write_register(NRF24L01P_REG_RF_SETUP, 0x07);
    write_register(NRF24L01P_REG_STATUS, 0x7E);
    write_register(NRF24L01P_REG_RX_PW_P0, 0x00);
    write_register(NRF24L01P_REG_RX_PW_P0, 0x00);
    write_register(NRF24L01P_REG_RX_PW_P1, 0x00);
    write_register(NRF24L01P_REG_RX_PW_P2, 0x00);
    write_register(NRF24L01P_REG_RX_PW_P3, 0x00);
    write_register(NRF24L01P_REG_RX_PW_P4, 0x00);
    write_register(NRF24L01P_REG_RX_PW_P5, 0x00);
    write_register(NRF24L01P_REG_FIFO_STATUS, 0x11);
    write_register(NRF24L01P_REG_DYNPD, 0x00);
    write_register(NRF24L01P_REG_FEATURE, 0x00);
	return nrf_status();
}

uint8_t nrf_status() {
	uint8_t command = NRF24L01P_CMD_NOP;
	uint8_t status;
	setCS(0);
	HAL_SPI_TransmitReceive(&bus, &command, &status, 1, 2000);
	setCS(1);
	return status;
}

uint8_t nrf_tx(uint8_t* payload){
	//clear TX FIFO
	uint8_t command = NRF24L01P_CMD_FLUSH_TX;
	uint8_t status;
	setCS(0);
	HAL_SPI_TransmitReceive(&bus, &command, &status, 1, 2000);
	setCS(1);
	//clear max_rt
	write_register(NRF24L01P_REG_STATUS, 0b00010000);
	//place in TX FIFO
	if(isTX){
		//W_TX_PAYLOAD command
		command = NRF24L01P_CMD_W_TX_PAYLOAD;
	} else {
		//W_ACK_PAYLOAD command
		command = NRF24L01P_CMD_W_ACK_PAYLOAD;
	}
	setCS(0);
	HAL_SPI_TransmitReceive(&bus, &command, &status, 1, 2000);
	HAL_SPI_Transmit(&bus, payload, PAYLOAD_LEN, 2000);
	setCS(1);
	return status;
}

uint8_t nrf_rx(uint8_t* payload){
	//check RX FIFO
	uint8_t command = NRF24L01P_CMD_R_RX_PAYLOAD;
	uint8_t status;
	setCS(0);
	HAL_SPI_TransmitReceive(&bus, &command, &status, 1, 2000);
	HAL_SPI_Receive(&bus, payload, PAYLOAD_LEN, 2000);
	setCS(1);
	return status;
}

static uint8_t read_register(uint8_t reg) {
	uint8_t command = NRF24L01P_CMD_R_REGISTER | reg;
	uint8_t status;
	uint8_t read_val;

	setCS(0);
	HAL_SPI_TransmitReceive(&bus, &command, &status, 1, 2000);
	HAL_SPI_Receive(&bus, &read_val, 1, 2000);
    setCS(1);

	return read_val;
}

static uint8_t write_register(uint8_t reg, uint8_t value) {
	uint8_t command = NRF24L01P_CMD_W_REGISTER | reg;
	uint8_t status;
	uint8_t write_val = value;

	setCS(0);
	HAL_SPI_TransmitReceive(&bus, &command, &status, 1, 2000);
	HAL_SPI_Transmit(&bus, &write_val, 1, 2000);
	setCS(1);

	return write_val;
}
