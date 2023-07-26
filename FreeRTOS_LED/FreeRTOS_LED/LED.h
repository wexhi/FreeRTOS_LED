#pragma once
//定义头文件
#ifndef _LED_H_
#include "gpio.h"
#include "stm32f4xx_hal.h"
#include "main.h"
#include "tim.h"
#define _LED_H_
//定义开关灯函数
void LED_R_ON(void);
void LED_R_OFF(void);
void LED_G_ON(void);
void LED_G_OFF(void);
void LED_R_Toggle(int time);
void LED_G_Toggle(void);

//定义呼吸灯函数
void LED_R_Breath(void);

#endif
