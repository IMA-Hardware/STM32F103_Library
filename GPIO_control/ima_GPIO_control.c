/**
  ******************************************************************************
  * @file    ima_beep.c
  * @author  Moment
  * @version V1.0
  * @date    2019-9-16
  * @brief   GPIO简单控制应用函数接口
  ******************************************************************************
  * @attention
  *
  * 修改自野火的LED库函数
  *
  ******************************************************************************
  */
  
#include "ima_GPIO_control.h"   

 /**
  * @brief  初始化需要控制的IO
  * @param  无
  * @retval 无
  */
void GPIO_Config(void)
{		
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启LED相关的GPIO外设时钟(初始化多个请用“|”间隔)*/
		RCC_APB2PeriphClockCmd(BEEP_GPIO_CLK , ENABLE);
	
	/******************下面这四个函数，每个IO口都要配置一次******************/
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = BEEP_GPIO_PIN;	

		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化GPIO*/
		GPIO_Init(BEEP_GPIO_PORT, &GPIO_InitStructure);	
	/******************上面这四个函数，每个IO口都要配置一次******************/
	
		/* 关闭所有IO*/
		BEEP_OFF
}

/**************************END OF FILE**********************/
