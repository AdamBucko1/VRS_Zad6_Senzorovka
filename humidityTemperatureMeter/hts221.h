/*
 * hts221.h
 *
 *  Created on: 17. 11. 2019
 *      Author: Stancoj
 */

#include "main.h"
#include "i2c.h"


#define 	HTS221_DEVICE_ADDRESS_0				0xD5
#define 	HTS221_DEVICE_ADDRESS_1				0xD7

#define 	HTS221_WHO_AM_I_VALUE					0x6A
#define 	HTS221_WHO_AM_I_ADDRES					0x0F

#define 	HTS221_ADDRESS_CTRL1					0x10

#define 	HTS221_ADDRESS_ACCX					0x28
#define 	HTS221_ADDRESS_ACCY					0x2A
#define 	HTS221_ADDRESS_ACCZ					0x2C

#define 	HTS221_ADDRESS_TEMP_L					0x20

uint8_t hts221_init(void);
void hts221_get_acc(float* x, float * y, float * z);
uint8_t hts221_read_byte(uint8_t reg_addr);
void hts221_write_byte(uint8_t reg_addr, uint8_t value);
int8_t hts221_get_temp();
