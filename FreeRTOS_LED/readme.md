# freeRTOS����LED�ƣ�����˸
## 1. Ӳ��
> ʹ�ô󽮿�����A�ͣ��۲�ԭ��ͼ�ҵ���ɫLED������PE10,��ɫLED������PF14����û�ҵ���ɫLED�����ţ�����ֻ������ɫ����ɫLED�ơ�
## 2. ���
> ʹ��STM32CubeMX���ɹ��̣����ú�ʱ�ӣ�GPIO��FreeRTOS�����ɹ��̺��޸�main.c�ļ���������񣬱������أ����ɵ���LED�ơ�
## 3. ����
> �������£�
```c
void StartTask_LED_G(void const * argument)
{
  /* USER CODE BEGIN StartTask_LED_G */
  /* Infinite loop */
  for(;;)
  {
      LED_G_Toggle();
      HAL_Delay(1000);
    osDelay(1);
  }
  /* USER CODE END StartTask_LED_G */
}
```
```c