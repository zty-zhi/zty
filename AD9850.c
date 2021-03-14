#include "stm32f10x.h"
#include "AD9850.h"
#include	"SPI_Config.h"
#include "bsp_timer.h"
#include "bsp.h"
uint32_t freq;
//����ʱ
void AD9850_Delay(unsigned int z)
{
    for(;z>0;z--)
    {;}
}

/*******��AD9850д�����ֵĺ���  W0Ϊ��λ������ freqΪƵ�ʿ�����********/
void AD9850_Write_Byte1(uint8_t W0,double freq)
{
	  int i;
	  uint8_t w; 
    uint32_t y;
	  freq=freq*(0x100000000/25000000.0);
		y=freq;
    for(i=0;i<4;i++)     //����ǰ32λ����
	{
		w=(y>>(i*8))&0xFF;
		SPI1_WriteByte(w);
		
	}
	  w = W0 ;                    //������40λ���ݣ�ǰ32λΪƵ�ʿ���λ   ����5λ����λ����λ
    SPI1_WriteByte(w);
	
//    AD9850_FQUD_SET ; //���ƶ�40λ����һ��FQ_UD���弴�ɸ������Ƶ�ʺ���λ 
//    AD9850_Delay(0xFFFF) ;
//    AD9850_FQUD_CLR;

}
void AD9850_Write_Byte2(uint8_t W0,double freq)
{
	  int i;
	  uint8_t w; 
    uint32_t y;
	  freq=freq*(0x100000000/25000000.0);
		y=freq;
    for(i=0;i<4;i++)     //����ǰ32λ����
	{
		w=(y>>(i*8))&0xFF;
		SPI2_WriteByte(w);
		
	}
	  w = W0 ;                    //������40λ���ݣ�ǰ32λΪƵ�ʿ���λ   ����5λ����λ����λ
    SPI2_WriteByte(w);
	
//    AD9850_FQUD_SET ; //���ƶ�40λ����һ��FQ_UD���弴�ɸ������Ƶ�ʺ���λ 
//    AD9850_Delay(0xFFFF) ;
//    AD9850_FQUD_CLR;

}
//*******��AD9850д�����ֺ��� ��Ƶ��ת������  ֱ��д��Ĵ�����**************/
void AD9850_Write_Serial1(void)
{
  SPI_I2S_SendData(SPI1, 0x38);
	bsp_DelayMS(1);
	SPI_I2S_SendData(SPI1, 0x86);
	bsp_DelayMS(1);
	SPI_I2S_SendData(SPI1, 0);
	bsp_DelayMS(1);
	SPI_I2S_SendData(SPI1, 0);
	bsp_DelayMS(1);
	SPI_I2S_SendData(SPI1, 0);
	bsp_DelayMS(1);
	
	AD9850_FQUD_SET ; //���ƶ�40λ����һ��FQ_UD���弴�ɸ������Ƶ�ʺ���λ 
  AD9850_Delay(0xFFFF) ;    
	AD9850_FQUD_CLR;
	
}
   
/*********************************************/
void Init_AD9850(void)      //��ʼ��AD9850
{
#ifdef MODE_SEIAL   //����
	  //����AD9850���õ�����I/O����
	  GPIO_InitTypeDef GPIO_InitStructure ;

//		printf("��AD9850��ʼ��\n\r");

	
	  RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOA, ENABLE );//PORTAʱ��ʹ�� 
	
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_1;  
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOA ,&GPIO_InitStructure) ;

    //��AD9850��λһ��
    AD9850_RST_CLR ;
		AD9850_Delay(0xFFFF);
    AD9850_RST_SET ;
    AD9850_Delay(0xFFFF);
    AD9850_RST_CLR ;
//		delay_ms(30);

		GPIO_ResetBits(GPIOA, GPIO_Pin_2);      //�Ƚ�FQUD�ź������� ʹ�ܴ���ģʽ
		AD9850_Delay(0x1);
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
		AD9850_Delay(0x1);


		GPIO_ResetBits(GPIOA, GPIO_Pin_2);      //�Ƚ�FQUD�ź�������  װ�����ݼĴ����ڲ�������
  	AD9850_Write_Byte1(0,90);

		AD9850_Write_Byte2(0x40,90);
		AD9850_Delay(0x1);
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
		bsp_DelayMS(1);

		GPIO_ResetBits(GPIOA, GPIO_Pin_2);      //�Ƚ�FQUD�ź�
		
		//��AD9850��λһ��
    AD9850_RST_CLR ;
		AD9850_Delay(0xFFFF);
    AD9850_RST_SET ;
    AD9850_Delay(0x00FF);
    AD9850_RST_CLR ;
		
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
		AD9850_Delay(0x001);
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);      //�Ƚ�FQUD�ź�		
		AD9850_Delay(0x001);		
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
		AD9850_Delay(0x001);
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);      //�Ƚ�FQUD�ź�		
		
//		printf("AD9850��ʼ�����\n\r");

#endif

}


