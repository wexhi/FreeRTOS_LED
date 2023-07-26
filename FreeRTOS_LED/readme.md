# freeRTOS点亮LED灯，并闪烁
## 1. 硬件
> 使用大疆开发板A型，观察原理图找到红色LED灯引脚PE10,绿色LED灯引脚PF14，但没找到蓝色LED灯引脚，所以只点亮红色和绿色LED灯。
## 2. 软件
> 使用STM32CubeMX生成工程，配置好时钟，GPIO，FreeRTOS，生成工程后，修改main.c文件，添加任务，编译下载，即可点亮LED灯。
## 3. 代码
> 代码如下：
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