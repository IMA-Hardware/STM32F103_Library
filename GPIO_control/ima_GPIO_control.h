#ifndef __LED_H
#define	__LED_H


#include "stm32f10x.h"


/* 定义外设连接的GPIO端口, 用户只需要修改下面的代码即可改变控制的外设引脚 */
// LED1
#define LED1_GPIO_PORT    	GPIOB			              /* GPIO端口 */
#define LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO端口时钟 */
#define LED1_GPIO_PIN		GPIO_Pin_5			        /* 连接到SCL时钟线的GPIO */

// BEEP
#define BEEP_GPIO_PORT    	GPIOB			              /* GPIO端口 */
#define BEEP_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO端口时钟 */
#define BEEP_GPIO_PIN		GPIO_Pin_8			        /* 连接到SCL时钟线的GPIO */

/*  开关的宏定义   */
#define LED_ON_STATE  0
#define LED_OFF_STATE 1

#define BEEP_ON_STATE 1
#define BEEP_OFF_STATE 0

/* 使用标准的固件库控制IO的宏*/
#define LED1(a)	if (a==LED_ON_STATE)	\
					GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN)

#define BEEP(a)	if (a==BEEP_OFF_STATE)	\
					GPIO_SetBits(BEEP_GPIO_PORT,BEEP_GPIO_PIN);\
					else		\
					GPIO_ResetBits(BEEP_GPIO_PORT,BEEP_GPIO_PIN)

/* 直接操作寄存器的方法控制IO */
#define	digitalHi(p,i)		 {p->BSRR=i;}	 //输出为高电平		
#define digitalLo(p,i)		 {p->BRR=i;}	 //输出低电平
#define digitalToggle(p,i) {p->ODR ^=i;} //输出反转状态


/* 定义控制IO的宏（引用上面的宏） */
#define LED1_TOGGLE		 digitalToggle(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_OFF		   digitalHi(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_ON			   digitalLo(LED1_GPIO_PORT,LED1_GPIO_PIN)

#define BEEP_TOGGLE		 digitalToggle(BEEP_GPIO_PORT,BEEP_GPIO_PIN)
#define BEEP_OFF		   digitalLo(BEEP_GPIO_PORT,BEEP_GPIO_PIN)
#define BEEP_ON			   digitalHi(BEEP_GPIO_PORT,BEEP_GPIO_PIN)

void GPIO_Config(void);

#endif /* __LED_H */
