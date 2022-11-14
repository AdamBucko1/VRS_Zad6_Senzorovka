/*
 * lps22hb.h
 *
 *  Created on: 17. 11. 2019
 *      Author: Stancoj
 */

#include "main.h"
#include "i2c.h"


#define 	LPS22HB_DEVICE_ADDRESS_0				0xBE
#define 	LPS22HB_DEVICE_ADDRESS_1				0xBF

#define 	LPS22HB_WHO_AM_I_VALUE					0x6A
#define 	LPS22HB_WHO_AM_I_ADDRES					0x0F

#define 	LPS22HB_ADDRESS_CTRL1					0x10

#define 	LPS22HB_ADDRESS_ACCX					0x28
#define 	LPS22HB_ADDRESS_ACCY					0x2A
#define 	LPS22HB_ADDRESS_ACCZ					0x2C

#define 	LPS22HB_ADDRESS_TEMP_L					0x20

uint8_t lps22hb_init(void);
void lps22hb_get_acc(float* x, float * y, float * z);
uint8_t lps22hb_read_byte(uint8_t reg_addr);
void lps22hb_write_byte(uint8_t reg_addr, uint8_t value);
int8_t lps22hb_get_temp();
