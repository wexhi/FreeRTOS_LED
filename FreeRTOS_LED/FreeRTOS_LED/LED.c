#include "LED.h"

void LED_R_ON(void)
{
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);
}

void LED_R_OFF(void)
{
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 1000);
}

void LED_R_Toggle(int time)
{
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 1000);
	HAL_Delay(time);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);
	HAL_Delay(time);
}

void LED_G_ON(void)
{
	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET);
}

void LED_G_OFF(void)
{
	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_SET);
}

void LED_G_Toggle(void)
{
	HAL_GPIO_TogglePin(LED_G_GPIO_Port, LED_G_Pin);
}

//�����ƺ���
void LED_R_Breath(void)
{
	while (1)
	{
		int i = 0;
		for (i = 0; i < 1000; i++)
		{
			__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, i);
			HAL_Delay(20);
		}
		for (i = 1000; i > 0; i--)
		{
			__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, i);
			HAL_Delay(20);
		}    
	}
}