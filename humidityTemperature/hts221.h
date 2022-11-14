/*
 * hts221.h
 *
 *  Created on: 17. 11. 2019
 *      Author: Stancoj
 */

#include "main.h"
#include "i2c.h"


#define 	HTS221_DEVICE_ADDRESS_0				0xBE
#define 	HTS221_DEVICE_ADDRESS_1				0xBF

#define 	HTS221_WHO_AM_I_VALUE					0xBC
#define 	HTS221_WHO_AM_I_ADDRES					0x0F

#define 	HTS221_ADDRESS_CTRL1					0x20

//#define 	HTS221_ADDRESS_ACCX					0x28
//#define 	HTS221_ADDRESS_ACCY					0x2A
//#define 	HTS221_ADDRESS_ACCZ					0x2C
#define 	HTS221_ADDRESS_HUM_L				0x28
#define 	HTS221_ADDRESS_HUM_H				0x29

#define 	HTS221_ADDRESS_T_L				0x2A
#define 	HTS221_ADDRESS_T_H				0x2B

#define 	HTS221_ADDRESS_H0_T0_L				0x3C
#define 	HTS221_ADDRESS_H0_T0_H				0x3D

#define 	HTS221_ADDRESS_H1_T0_L				0x3A
#define 	HTS221_ADDRESS_H1_T0_H				0x3B

#define 	HTS221_ADDRESS_T0_L				0x3C
#define 	HTS221_ADDRESS_T0_H				0x3D

#define 	HTS221_ADDRESS_T1_L				0x3E
#define 	HTS221_ADDRESS_T1_H				0x3F


//#define 	HTS221_ADDRESS_TEMP_L					0x20

uint8_t hts221_init(void);
//void hts221_get_acc(float* x, float * y, float * z);
void hts221_get_hum(float* humValue);
uint8_t hts221_read_byte(uint8_t reg_addr);
void hts221_write_byte(uint8_t reg_addr, uint8_t value);
int8_t hts221_get_temp();
