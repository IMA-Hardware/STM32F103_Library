/**
  ******************************************************************************
  * @file    ima_beep.c
  * @author  Moment
  * @version V1.0
  * @date    2019-9-16
  * @brief   GPIO�򵥿���Ӧ�ú����ӿ�
  ******************************************************************************
  * @attention
  *
  * �޸���Ұ���LED�⺯��
  *
  ******************************************************************************
  */
  
#include "ima_GPIO_control.h"   

 /**
  * @brief  ��ʼ����Ҫ���Ƶ�IO
  * @param  ��
  * @retval ��
  */
void GPIO_Config(void)
{		
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*����LED��ص�GPIO����ʱ��(��ʼ��������á�|�����)*/
		RCC_APB2PeriphClockCmd(BEEP_GPIO_CLK , ENABLE);
	
	/******************�������ĸ�������ÿ��IO�ڶ�Ҫ����һ��******************/
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = BEEP_GPIO_PIN;	

		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(BEEP_GPIO_PORT, &GPIO_InitStructure);	
	/******************�������ĸ�������ÿ��IO�ڶ�Ҫ����һ��******************/
	
		/* �ر�����IO*/
		BEEP_OFF
}

/**************************END OF FILE**********************/
