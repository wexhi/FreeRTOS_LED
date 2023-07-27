# FreeRTOS_LED
## 1.任务1 实现呼吸灯效果；（定时器及 pwm）
> 使用定时器TIM1频道2 实现pwm波，通过改变占空比实现呼吸灯效果
> 逻辑为随着占空比的增加，灯亮度增加，随着占空比的减小，灯亮度减小  
> 代码如下：
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
## 2.使用开发板上开关进行开关灯操作，使用开发板上开关进行切换灯颜色的操作；（中断 ）
> 使用中断实现开关灯操作，通过设置引脚PB2的中断，当PB2引脚电平发生变化时，触发中断，执行中断函数，实现开关灯操作
> 代码如下：
```c
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)//中断回调函数
{
	if (GPIO_Pin == KEY_Pin)
	{
		LED_G_Toggle();
	}
}
```
## 3.使用 freertos 点亮 RG 两种颜色的灯；（freertos）
> 使用freertos实现两种颜色的灯，通过创建两个任务，分别控制两种颜色的灯，实现两种灯以不同频率闪烁
> 代码如下：
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
## 4.备注
>因为没有找到开发板上的蓝灯，所以使用绿灯代替蓝灯
>并且没有实际拿到开发板，懒得分成三个项目写，因此可能会有bug，不过逻辑上来讲应该没有问题

##5.Visual GDB使用方法
>1.本代码没有使用keil编译，使用的是STM32CubeMX生成的工程，使用的编译器是arm-none-eabi-gcc  
>2.使用Visual GDB，结合Visual Studio进行调试，首先需要安装Visual GDB插件，安装网址为https://visualgdb.com/  
>3.安装好插件后，直接运行即可烧录。  
>4.具体细节可参考B站视频https://www.bilibili.com/video/BV1NV411U7Bq/?spm_id_from=333.880.my_history.page.click&vd_source=cd7bff178b79967cd653b46af7fbb681

