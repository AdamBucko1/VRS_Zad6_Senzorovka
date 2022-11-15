/*
 * lps22hb.h
 *
 *  Created on: 17. 11. 2019
 *      Author: Stancoj
 */

#include "main.h"
#include "i2c.h"


#define 	LPS22HB_DEVICE_ADDRESS_Write_0			0xB8
#define 	LPS22HB_DEVICE_ADDRESS_Read_0			0xB9

#define 	LPS22HB_DEVICE_ADDRESS_Write_1			0xBA
#define 	LPS22HB_DEVICE_ADDRESS_Read_1			0xBB

#define 	LPS22HB_WHO_AM_I_ADDRES					0x0F
#define 	LPS22HB_WHO_AM_I_VALUE					0xB1

#define 	LPS22HB_ADDRESS_CTRL1					0x10

//*******************PRESSURE********************
#define 	LPS22HB_ADDRESS_PRESS_OUT_XL  			0x28
#define 	LPS22HB_ADDRESS_PRESS_OUT_L  			0x29
#define 	LPS22HB_ADDRESS_PRESS_OUT_H  			0x2A

//*********************HUMIDITY*********************

#define 	LPS22HB_ADDRESS_H_L						0x28
#define 	LPS22HB_ADDRESS_H_H						0x29

#define 	LPS22HB_ADDRESS_H0_rH_x2            	0x30
#define 	LPS22HB_ADDRESS_H1_rH_x2           	 	0x31

#define 	LPS22HB_ADDRESS_H0_T0_L					0x36
#define 	LPS22HB_ADDRESS_H0_T0_H					0x37

#define 	LPS22HB_ADDRESS_H1_T0_L					0x3A
#define 	LPS22HB_ADDRESS_H1_T0_H					0x3B

uint8_t lps22hb_init(void);
uint8_t lps22hb_read_byte(uint8_t reg_addr);
void lps22hb_write_byte(uint8_t reg_addr, uint8_t value);

float lps22hb_get_preassure(void);
