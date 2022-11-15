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

#define 	HTS221_WHO_AM_I_VALUE				0xBC
#define 	HTS221_WHO_AM_I_ADDRES				0x0F

#define 	HTS221_ADDRESS_CTRL1				0x20

//*******************TEMPERATURE********************

#define 	HTS221_ADDRESS_T_L					0x2A
#define 	HTS221_ADDRESS_T_H					0x2B

#define 	HTS221_ADDRESS_T0_L					0x3C
#define 	HTS221_ADDRESS_T0_H					0x3D

#define 	HTS221_ADDRESS_T1_L					0x3E
#define 	HTS221_ADDRESS_T1_H					0x3F

#define 	HTS221_ADDRESS_T0_degC				0x32
#define 	HTS221_ADDRESS_T1_degC				0x33

#define 	HTS221_ADDRESS_T0_T1_call_msb		0x35

//*********************HUMIDITY*********************

#define 	HTS221_ADDRESS_H_L					0x28
#define 	HTS221_ADDRESS_H_H					0x29

#define 	HTS221_ADDRESS_H0_rH_x2             0x30
#define 	HTS221_ADDRESS_H1_rH_x2             0x31

#define 	HTS221_ADDRESS_H0_T0_L				0x36
#define 	HTS221_ADDRESS_H0_T0_H				0x37

#define 	HTS221_ADDRESS_H1_T0_L				0x3A
#define 	HTS221_ADDRESS_H1_T0_H				0x3B

uint8_t hts221_init(void);
//void hts221_get_acc(float* x, float * y, float * z);
float hts221_get_temperature(void);
float hts221_get_humidity(void);
void hts221_get_hum(float* humValue);
uint8_t hts221_read_byte(uint8_t reg_addr);
void hts221_write_byte(uint8_t reg_addr, uint8_t value);
int8_t hts221_get_temp();
