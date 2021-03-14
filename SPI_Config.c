#include "stm32f10x_spi.h"
#include "stdint.h"
#include "SPI_Config.h"
#include "bsp_timer.h"

void SPI1_Init(void)  //SPI1����
{
    GPIO_InitTypeDef  GPIO_InitStructure;
	  SPI_InitTypeDef SPI_InitStructure;
	
	  RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOA, ENABLE );//PORTAʱ��ʹ�� 
    RCC_APB2PeriphClockCmd(	RCC_APB2Periph_SPI1,  ENABLE );//SPI1ʱ��ʹ��
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 |GPIO_Pin_7;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //PA5/7����������� 
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;    
	  GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	  GPIO_Init(GPIOA, &GPIO_InitStructure);
	

	  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  //����SPI�������˫�������ģʽ:SPI����Ϊ˫��˫��ȫ˫��
	  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;		//����SPI����ģʽ:����Ϊ��SPI
	  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;		//����SPI�����ݴ�С:SPI���ͽ���8λ֡�ṹ
	  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;		//����ͬ��ʱ�ӵĿ���״̬Ϊ�ߵ�ƽ
	  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;	//����ͬ��ʱ�ӵĵڶ��������أ��������½������ݱ�����
	  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;		//NSS�ź���Ӳ����NSS�ܽţ����������ʹ��SSIλ������:�ڲ�NSS�ź���SSIλ����
	  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;		//���岨����Ԥ��Ƶ��ֵ:������Ԥ��ƵֵΪ256
	  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_LSB;	//ָ�����ݴ����MSBλ����LSBλ��ʼ:���ݴ����LSBλ��ʼ
	  SPI_InitStructure.SPI_CRCPolynomial = 7;	//CRCֵ����Ķ���ʽ
	  SPI_Init(SPI1, &SPI_InitStructure);  //����SPI_InitStruct��ָ���Ĳ�����ʼ������SPIx�Ĵ���
 
	  SPI_Cmd(SPI1, ENABLE); //ʹ��SPI����
	
	  SPI1_WriteByte(0xff);//��������

	
}

void SPI2_Init(void)  //SPI1����
{
    GPIO_InitTypeDef  GPIO_InitStructure;
	  SPI_InitTypeDef SPI_InitStructure;
	
	  RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOB, ENABLE );//PORTAʱ��ʹ�� 
    RCC_APB1PeriphClockCmd(	RCC_APB1Periph_SPI2,  ENABLE );//SPI1ʱ��ʹ��
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 |GPIO_Pin_15;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //PA5/7����������� 
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;    
	  GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOA
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	  GPIO_Init(GPIOB, &GPIO_InitStructure);

	
	  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  //����SPI�������˫�������ģʽ:SPI����Ϊ˫��˫��ȫ˫��
	  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;		//����SPI����ģʽ:����Ϊ��SPI
	  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;		//����SPI�����ݴ�С:SPI���ͽ���8λ֡�ṹ
	  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;		//����ͬ��ʱ�ӵĿ���״̬Ϊ�ߵ�ƽ
	  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;	//����ͬ��ʱ�ӵĵڶ��������أ��������½������ݱ�����
	  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;		//NSS�ź���Ӳ����NSS�ܽţ����������ʹ��SSIλ������:�ڲ�NSS�ź���SSIλ����
	  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;		//���岨����Ԥ��Ƶ��ֵ:������Ԥ��ƵֵΪ256
	  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_LSB;	//ָ�����ݴ����MSBλ����LSBλ��ʼ:���ݴ����LSBλ��ʼ
	  SPI_InitStructure.SPI_CRCPolynomial = 7;	//CRCֵ����Ķ���ʽ
	  SPI_Init(SPI2, &SPI_InitStructure);  //����SPI_InitStruct��ָ���Ĳ�����ʼ������SPIx�Ĵ���
 
	  SPI_Cmd(SPI2, ENABLE); //ʹ��SPI����
	
	  SPI2_WriteByte(0xff);//��������

	
}

//SPI �ٶ����ú���
//SpeedSet:
//SPI_BaudRatePrescaler_2   2��Ƶ   
//SPI_BaudRatePrescaler_8   8��Ƶ   
//SPI_BaudRatePrescaler_16  16��Ƶ  
//SPI_BaudRatePrescaler_256 256��Ƶ 
  
void SPI1_SetSpeed(u8 SPI_BaudRatePrescaler)  //
{
  assert_param(IS_SPI_BAUDRATE_PRESCALER(SPI_BaudRatePrescaler));
	SPI1->CR1&=0XFFC7;
	SPI1->CR1|=SPI_BaudRatePrescaler;	//����SPI1�ٶ� 
	SPI_Cmd(SPI1,ENABLE); 
 
} 
void SPI2_SetSpeed(u8 SPI_BaudRatePrescaler)  //
{
  assert_param(IS_SPI_BAUDRATE_PRESCALER(SPI_BaudRatePrescaler));
	SPI2->CR1&=0XFFC7;
	SPI2->CR1|=SPI_BaudRatePrescaler;	//����SPI2�ٶ� 
	SPI_Cmd(SPI2,ENABLE); 
 
}



void  SPI1_WriteByte(uint8_t TxData)   //SPI  д�ֽں��� 
{		
				 	
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET); //�ȴ��������ݿձ�־λ���
			  
	SPI_I2S_SendData(SPI1, TxData); //ͨ������SPIx����һ������
	bsp_DelayUS(1);
 					    
}

void  SPI2_WriteByte(uint8_t TxData)   //SPI  д�ֽں��� 
{		
				 	
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET); //�ȴ��������ݿձ�־λ���
			  
	SPI_I2S_SendData(SPI2, TxData); //ͨ������SPIx����һ������
	bsp_DelayUS(1);
 					    
}

