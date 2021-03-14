#include "stdint.h"

#ifndef __AD9850_H
#define __AD9850_H

#define MODE_SEIAL   //串行
//#define MODE_PARALLEL  //并行
/* AD9850 引脚定义 */
#define AD9850_CONTROL_PORT  GPIOA
#define AD9850_FQUD   GPIO_Pin_2
#define AD9850_RST    GPIO_Pin_1
#endif
#ifdef MODE_SEIAL   //串行   
#define AD9850_FQUD_SET    GPIO_WriteBit(AD9850_CONTROL_PORT,AD9850_FQUD,Bit_SET)
#define AD9850_FQUD_CLR    GPIO_WriteBit(AD9850_CONTROL_PORT,AD9850_FQUD,Bit_RESET)
#define AD9850_RST_SET     GPIO_WriteBit(AD9850_CONTROL_PORT,AD9850_RST,Bit_SET)
#define AD9850_RST_CLR     GPIO_WriteBit(AD9850_CONTROL_PORT,AD9850_RST,Bit_RESET)

#ifdef MODE_SEIAL    
extern void AD9850_Reset_Sreial(void) ;
extern void AD9850_Write_Serial(unsigned char W0,double frequence) ;
extern void AD9850_Write_Serial1(void);
#endif

#ifdef MODE_PARALLEL
extern void AD9850_Reset_Parallel(void) ;
extern void AD9850_Write_Parallel(unsigned char W0,unsigned long freq) ;
#endif

#endif /* AD8950_H */

void AD9850_Write_Byte(uint8_t W0,double freq);
void Init_AD9850(void) ;



