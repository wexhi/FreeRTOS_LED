# FreeRTOS_LED
## 1.����1 ʵ�ֺ�����Ч��������ʱ���� pwm��
> ʹ�ö�ʱ��TIM1Ƶ��2 ʵ��pwm����ͨ���ı�ռ�ձ�ʵ�ֺ�����Ч��
> �߼�Ϊ����ռ�ձȵ����ӣ����������ӣ�����ռ�ձȵļ�С�������ȼ�С  
> �������£�
```c
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
```
## 2.ʹ�ÿ������Ͽ��ؽ��п��صƲ�����ʹ�ÿ������Ͽ��ؽ����л�����ɫ�Ĳ��������ж� ��
> ʹ���ж�ʵ�ֿ��صƲ�����ͨ����������PB2���жϣ���PB2���ŵ�ƽ�����仯ʱ�������жϣ�ִ���жϺ�����ʵ�ֿ��صƲ���
> �������£�
```c
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)//�жϻص�����
{
	if (GPIO_Pin == KEY_Pin)
	{
		LED_G_Toggle();
	}
}
```
## 3.ʹ�� freertos ���� RG ������ɫ�ĵƣ���freertos��
> ʹ��freertosʵ��������ɫ�ĵƣ�ͨ�������������񣬷ֱ����������ɫ�ĵƣ�ʵ�����ֵ��Բ�ͬƵ����˸
> �������£�
```c
void StartTask_LED_R(void const * argument)
{
  for(;;)
  {
      LED_R_Toggle(500);
    osDelay(1);
  }
}
```
```c
void StartTask_LED_G(void const * argument)
{
  for(;;)
  {
      LED_G_Toggle();
      HAL_Delay(1000);
    osDelay(1);
  }
}
```
## 4.��ע
>��Ϊû���ҵ��������ϵ����ƣ�����ʹ���̵ƴ�������
>����û��ʵ���õ������壬���÷ֳ�������Ŀд����˿��ܻ���bug�������߼�������Ӧ��û������

##5.Visual GDBʹ�÷���
>1.������û��ʹ��keil���룬ʹ�õ���STM32CubeMX���ɵĹ��̣�ʹ�õı�������arm-none-eabi-gcc  
>2.ʹ��Visual GDB�����Visual Studio���е��ԣ�������Ҫ��װVisual GDB�������װ��ַΪhttps://visualgdb.com/  
>3.��װ�ò����ֱ�����м�����¼��  
>4.����ϸ�ڿɲο�Bվ��Ƶhttps://www.bilibili.com/video/BV1NV411U7Bq/?spm_id_from=333.880.my_history.page.click&vd_source=cd7bff178b79967cd653b46af7fbb681

