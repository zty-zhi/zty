#ifndef __SPI_Config_H
#define __SPI_Config_H
#include "stdint.h"

void SPI1_Init(void);			 //��ʼ��SPI��
void SPI1_SetSpeed(uint8_t SpeedSet); //����SPI�ٶ�   
void SPI1_WriteByte(uint8_t TxData);

void SPI2_WriteByte(uint8_t TxData);   //SPI  д�ֽں��� 
void SPI2_Init(void);			 //��ʼ��SPI��
void SPI2_SetSpeed(uint8_t SpeedSet); //����SPI�ٶ� 
#endif
