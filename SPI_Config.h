#ifndef __SPI_Config_H
#define __SPI_Config_H
#include "stdint.h"

void SPI1_Init(void);			 //初始化SPI口
void SPI1_SetSpeed(uint8_t SpeedSet); //设置SPI速度   
void SPI1_WriteByte(uint8_t TxData);

void SPI2_WriteByte(uint8_t TxData);   //SPI  写字节函数 
void SPI2_Init(void);			 //初始化SPI口
void SPI2_SetSpeed(uint8_t SpeedSet); //设置SPI速度 
#endif
