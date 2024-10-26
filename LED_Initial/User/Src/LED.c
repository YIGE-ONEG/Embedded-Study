#include "LED.h"

static uint8_t Led_init(void)
{
	return 0;
}

static void Led_Toggle(void)
{
	HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
}

void Led_Task_Runnable(void)
{
	static uint8_t task_state;
	static uint32_t key_press_cnt = 0;
	static uint8_t cnt_state = 0;
	if(task_state == 0)
	{
		if(Led_init() == 0)
		{
			task_state = 1;
		}
	}else{
		if(g_E_key_state == KEY_PRESSED )
		{
			cnt_state = 1;
		}else
		{
			cnt_state = 0;
		}
		if(cnt_state == 1)
		{
			key_press_cnt++;
		}else{
			if(key_press_cnt >= LED_FLTP_EVENT_FILTER_TIME)
			{
				Led_Toggle();
			}
			key_press_cnt = 0;
		}
	}
}

