#include "stm32f10x.h"
#include "AD9850.h"
#include	"SPI_Config.h"
#include "bsp_timer.h"
#include "bsp.h"
uint32_t freq;
//短延时
void AD9850_Delay(unsigned int z)
{
    for(;z>0;z--)
    {;}
}

/*******给AD9850写控制字的函数  W0为相位控制字 freq为频率控制字********/
void AD9850_Write_Byte1(uint8_t W0,double freq)
{
	  int i;
	  uint8_t w; 
    uint32_t y;
	  freq=freq*(0x100000000/25000000.0);
		y=freq;
    for(i=0;i<4;i++)     //发送前32位数据
	{
		w=(y>>(i*8))&0xFF;
		SPI1_WriteByte(w);
		
	}
	  w = W0 ;                    //共传送40位数据，前32位为频率控制位   后面5位是相位控制位
    SPI1_WriteByte(w);
	
//    AD9850_FQUD_SET ; //当移动40位后，用一个FQ_UD脉冲即可更新输出频率和相位 
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
    for(i=0;i<4;i++)     //发送前32位数据
	{
		w=(y>>(i*8))&0xFF;
		SPI2_WriteByte(w);
		
	}
	  w = W0 ;                    //共传送40位数据，前32位为频率控制位   后面5位是相位控制位
    SPI2_WriteByte(w);
	
//    AD9850_FQUD_SET ; //当移动40位后，用一个FQ_UD脉冲即可更新输出频率和相位 
//    AD9850_Delay(0xFFFF) ;
//    AD9850_FQUD_CLR;

}
//*******给AD9850写控制字函数 （频率转控制字  直接写入寄存器）**************/
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
	
	AD9850_FQUD_SET ; //当移动40位后，用一个FQ_UD脉冲即可更新输出频率和相位 
  AD9850_Delay(0xFFFF) ;    
	AD9850_FQUD_CLR;
	
}
   
/*********************************************/
void Init_AD9850(void)      //初始化AD9850
{
#ifdef MODE_SEIAL   //串行
	  //配置AD9850所用的三个I/O引脚
	  GPIO_InitTypeDef GPIO_InitStructure ;

//		printf("进AD9850初始化\n\r");

	
	  RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOA, ENABLE );//PORTA时钟使能 
	
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_1;  
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOA ,&GPIO_InitStructure) ;

    //对AD9850复位一下
    AD9850_RST_CLR ;
		AD9850_Delay(0xFFFF);
    AD9850_RST_SET ;
    AD9850_Delay(0xFFFF);
    AD9850_RST_CLR ;
//		delay_ms(30);

		GPIO_ResetBits(GPIOA, GPIO_Pin_2);      //先将FQUD信号上升沿 使能串行模式
		AD9850_Delay(0x1);
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
		AD9850_Delay(0x1);


		GPIO_ResetBits(GPIOA, GPIO_Pin_2);      //先将FQUD信号上升沿  装载数据寄存器内部的数据
  	AD9850_Write_Byte1(0,90);

		AD9850_Write_Byte2(0x40,90);
		AD9850_Delay(0x1);
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
		bsp_DelayMS(1);

		GPIO_ResetBits(GPIOA, GPIO_Pin_2);      //先将FQUD信号
		
		//对AD9850复位一下
    AD9850_RST_CLR ;
		AD9850_Delay(0xFFFF);
    AD9850_RST_SET ;
    AD9850_Delay(0x00FF);
    AD9850_RST_CLR ;
		
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
		AD9850_Delay(0x001);
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);      //先将FQUD信号		
		AD9850_Delay(0x001);		
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
		AD9850_Delay(0x001);
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);      //先将FQUD信号		
		
//		printf("AD9850初始化完成\n\r");

#endif

}


