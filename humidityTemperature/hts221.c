/*
 * hts221.c
 *
 *  Created on: 17. 11. 2019
 *      Author: Stancoj
 */

#include "hts221.h"

uint8_t hts221addres = HTS221_DEVICE_ADDRESS_0;

uint8_t hts221_read_byte(uint8_t reg_addr)
{
	uint8_t data = 0;
	return *(i2c_master_read(&data, 1, reg_addr, hts221addres, 0));
}


void hts221_write_byte(uint8_t reg_addr, uint8_t value)
{
	i2c_master_write(value, reg_addr, hts221addres, 0);
}


void hts221_readArray(uint8_t * data, uint8_t reg, uint8_t length)
{
	i2c_master_read(data, length, reg, hts221addres, 0);
}


int8_t hts221_get_temp()
{
	uint8_t temp[2];
	hts221_readArray(temp, HTS221_ADDRESS_T_L, 2);

	return (((int16_t)((temp[1] << 8) | temp[0])) >> 3)  + 25;
}


/*void hts221_get_acc(float* x, float* y, float* z)
{
	uint8_t data[6];
	int16_t xx, yy, zz;

	uint8_t temp;

	//get current scale and use it for final calculation
    temp = hts221_read_byte(HTS221_ADDRESS_CTRL1);

	temp = temp >> 2;
    temp &= 0x03;			//full scale bits extracted

	hts221_readArray(data, HTS221_ADDRESS_ACCX, 6);

	xx = ((uint16_t)data[1]) << 8 | data[0];
	yy = ((uint16_t)data[3]) << 8 | data[2];
	zz = ((uint16_t)data[5]) << 8 | data[4];

	*x = (xx >> 4) / 1000.0f;
	*y = (yy >> 4) / 1000.0f;
	*z = (zz >> 4) / 1000.0f;
}*/

float hts221_get_temperature(void)
{
	uint8_t T0_outArray[2];
	T0_outArray[0]=hts221_read_byte(HTS221_ADDRESS_T0_L);
	T0_outArray[1]=hts221_read_byte(HTS221_ADDRESS_T0_H);
	int16_t T0_out = T0_outArray[0]|T0_outArray[1]<< 8;

	uint8_t T1_outArray[2];
	T1_outArray[0]=hts221_read_byte(HTS221_ADDRESS_T1_L);
	T1_outArray[1]=hts221_read_byte(HTS221_ADDRESS_T1_H);
	int16_t T1_out = T1_outArray[0]|T1_outArray[1]<< 8;

	uint8_t T_outArray[2];
	T_outArray[0]=hts221_read_byte(HTS221_ADDRESS_T_L);
	T_outArray[1]=hts221_read_byte(HTS221_ADDRESS_T_H);
	int16_t T_out = T_outArray[0]|T_outArray[1]<< 8;

	uint8_t H0_T0_outArray[2];
	H0_T0_outArray[0]=hts221_read_byte(HTS221_ADDRESS_H0_T0_L);
	H0_T0_outArray[1]=hts221_read_byte(HTS221_ADDRESS_H0_T0_H);
	int16_t H0_T0_out = H0_T0_outArray[0]|H0_T0_outArray[1]<< 8;

	uint8_t H1_T0_outArray[2];
	H1_T0_outArray[0]=hts221_read_byte(HTS221_ADDRESS_H1_T0_L);
	H1_T0_outArray[1]=hts221_read_byte(HTS221_ADDRESS_H1_T0_H);
	int16_t H1_T0_out = H1_T0_outArray[0]|H1_T0_outArray[1]<< 8;


	uint16_t T0_degC=hts221_read_byte(HTS221_ADDRESS_T0_degC);
	uint16_t T1_degC=hts221_read_byte(HTS221_ADDRESS_T1_degC);

	uint8_t T_msb=hts221_read_byte(HTS221_ADDRESS_T0_T1_call_msb);
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

uint8_t hts221_init(void)
{

	uint8_t status = 1;

	//LIS3MDL_ACC_ON;

	LL_mDelay(100);

	uint8_t val = hts221_read_byte(HTS221_WHO_AM_I_ADDRES);

	if(val == HTS221_WHO_AM_I_VALUE)
	{
		status = 1;
	}
	else			//if the device is not found on one address, try another one
	{
		/*hts221addres = HTS221_DEVICE_ADDRESS_1;
		val = hts221_read_byte(HTS221_WHO_AM_I_ADDRES);
		if(val == HTS221_WHO_AM_I_VALUE)
		{
			status = 1;
		}
		else
		{
			status = 0;
			//return status;
		}*/
		status =0;
		return status;
	}

	//acc device init
	uint8_t ctrl1 = hts221_read_byte(HTS221_ADDRESS_CTRL1);
	ctrl1 &= ~0x07;
	ctrl1 &= ~0x80;
	ctrl1 |= 0x01;
	hts221_write_byte(HTS221_ADDRESS_CTRL1, ctrl1);

	return status;
}
