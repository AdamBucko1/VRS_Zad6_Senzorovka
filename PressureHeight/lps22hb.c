/*
 * lps22hb.c
 *
 *  Created on: 17. 11. 2019
 *      Author: Stancoj
 */

#include "../PressureHeight/lps22hb.h"

uint8_t lps22hbaddres = LPS22HB_DEVICE_ADDRESS_Read_0;

uint8_t lps22hb_read_byte(uint8_t reg_addr)
{
	uint8_t data = 0;
	return *(i2c_master_read(&data, 1, reg_addr, lps22hbaddres, 0));
}


void lps22hb_write_byte(uint8_t reg_addr, uint8_t value)
{
	i2c_master_write(value, reg_addr, lps22hbaddres, 0);
}


void lps22hb_readArray(uint8_t * data, uint8_t reg, uint8_t length)
{
	i2c_master_read(data, length, reg, lps22hbaddres, 0);
}

/*
int8_t lps22hb_get_temp()
{
	uint8_t temp[2];
	lps22hb_readArray(temp, LPS22HB_ADDRESS_T_L, 2);

	return (((int16_t)((temp[1] << 8) | temp[0])) >> 3)  + 25;
}*/


/*
float lps22hb_get_temperature(void)
{
	uint8_t T0_outArray[2];
	T0_outArray[0]=lps22hb_read_byte(LPS22HB_ADDRESS_T0_L);
	T0_outArray[1]=lps22hb_read_byte(LPS22HB_ADDRESS_T0_H);
	int16_t T0_out = T0_outArray[0]|T0_outArray[1]<< 8;

	uint8_t T1_outArray[2];
	T1_outArray[0]=lps22hb_read_byte(LPS22HB_ADDRESS_T1_L);
	T1_outArray[1]=lps22hb_read_byte(LPS22HB_ADDRESS_T1_H);
	int16_t T1_out = T1_outArray[0]|T1_outArray[1]<< 8;

	uint8_t T_outArray[2];
	T_outArray[0]=lps22hb_read_byte(LPS22HB_ADDRESS_T_L);
	T_outArray[1]=lps22hb_read_byte(LPS22HB_ADDRESS_T_H);
	int16_t T_out = T_outArray[0]|T_outArray[1]<< 8;

	uint8_t H0_T0_outArray[2];
	H0_T0_outArray[0]=lps22hb_read_byte(LPS22HB_ADDRESS_H0_T0_L);
	H0_T0_outArray[1]=lps22hb_read_byte(LPS22HB_ADDRESS_H0_T0_H);
	int16_t H0_T0_out = H0_T0_outArray[0]|H0_T0_outArray[1]<< 8;

	uint8_t H1_T0_outArray[2];
	H1_T0_outArray[0]=lps22hb_read_byte(LPS22HB_ADDRESS_H1_T0_L);
	H1_T0_outArray[1]=lps22hb_read_byte(LPS22HB_ADDRESS_H1_T0_H);
	int16_t H1_T0_out = H1_T0_outArray[0]|H1_T0_outArray[1]<< 8;


	uint16_t T0_degC=lps22hb_read_byte(LPS22HB_ADDRESS_T0_degC);
	uint16_t T1_degC=lps22hb_read_byte(LPS22HB_ADDRESS_T1_degC);

	uint8_t T_msb=lps22hb_read_byte(LPS22HB_ADDRESS_T0_T1_call_msb);
	uint8_t T0_msb=T_msb & 0x3;
	uint8_t T1_msb=T_msb>>2 & 0x3;


	T0_degC |= T0_msb<<8;
	T1_degC |= T1_msb<<8;

	float deltaY=T1_degC-T0_degC;
	float deltaX=T1_out-T0_out;

	float k=deltaY/deltaX;
	//q=y-kx
	float q=T0_degC-k*T0_out;
	//y=kx+q
	float temperatureCalc=k*T_out+q;
	temperatureCalc=temperatureCalc/8;
	return temperatureCalc;

	}

float lps22hb_get_humidity(void)
{
	uint8_t H0_T0_outArray[2];
	H0_T0_outArray[0]=lps22hb_read_byte(LPS22HB_ADDRESS_H0_T0_L);
	H0_T0_outArray[1]=lps22hb_read_byte(LPS22HB_ADDRESS_H0_T0_H);
	int16_t H0_T0_out = H0_T0_outArray[0]|H0_T0_outArray[1]<< 8;

	uint8_t H1_T0_outArray[2];
	H1_T0_outArray[0]=lps22hb_read_byte(LPS22HB_ADDRESS_H1_T0_L);
	H1_T0_outArray[1]=lps22hb_read_byte(LPS22HB_ADDRESS_H1_T0_H);
	int16_t H1_T0_out = H1_T0_outArray[0]|H1_T0_outArray[1]<< 8;

	uint8_t H_T_outArray[2];
	H_T_outArray[0]=lps22hb_read_byte(LPS22HB_ADDRESS_H_L);
	H_T_outArray[1]=lps22hb_read_byte(LPS22HB_ADDRESS_H_H);
	int16_t H_T_out = H_T_outArray[0]|H_T_outArray[1]<< 8;

	uint8_t H0_RH=lps22hb_read_byte(LPS22HB_ADDRESS_H0_rH_x2);
	uint8_t H1_RH=lps22hb_read_byte(LPS22HB_ADDRESS_H1_rH_x2);

	float deltaY=H1_RH-H0_RH;
	float deltaX=H1_T0_out-H0_T0_out;
	float k=deltaY/deltaX;
	float q=H0_RH-k*H0_T0_out;
	float humidityCalc=k*H_T_out+q;
	humidityCalc=humidityCalc/2;

	return humidityCalc;
	}*/

float lps22hb_get_preassure(){
	int32_t pressure;
	uint8_t pressOut[3];
	float pressureCalc;
	pressOut[1]=lps22hb_read_byte(LPS22HB_ADDRESS_PRESS_OUT_XL);
	pressOut[2]=lps22hb_read_byte(LPS22HB_ADDRESS_PRESS_OUT_L);
	pressOut[3]=lps22hb_read_byte(LPS22HB_ADDRESS_PRESS_OUT_H);

	pressure=pressOut[1]|pressOut[2]<<8;
	pressure=pressure|pressOut[3]<<16;
	if (pressure && 1<<23){
		pressureCalc=-pressure;
	}
	else{
	pressureCalc=pressure;
	}
	pressureCalc=pressureCalc/4096;
	return pressureCalc;
}

uint8_t lps22hb_init(void)
{

	uint8_t status = 1;

	//LIS3MDL_ACC_ON;

	LL_mDelay(100);

	uint8_t val = lps22hb_read_byte(LPS22HB_WHO_AM_I_ADDRES);

	if(val == LPS22HB_WHO_AM_I_VALUE)
	{
		status = 1;
	}
	else			//if the device is not found on one address, try another one
	{
		lps22hbaddres = LPS22HB_DEVICE_ADDRESS_Read_1;
		val = lps22hb_read_byte(LPS22HB_WHO_AM_I_ADDRES);
		if(val == LPS22HB_WHO_AM_I_VALUE)
		{
			status = 1;
		}
		else
		{
			status = 0;
			return status;
		}
		status =0;
		return status;
	}

	//acc device init
	uint8_t ctrl1 = lps22hb_read_byte(LPS22HB_ADDRESS_CTRL1);
	ctrl1 &= 0x00;
	ctrl1 |= 0x18;
	lps22hb_write_byte(LPS22HB_ADDRESS_CTRL1, ctrl1);

	return status;
}
