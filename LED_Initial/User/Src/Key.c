#include"Key.h"

uint8_t g_E_key_state = KEY_RELEASED;

static uint8_t Key_init(void)
{
	return 0;
}

static uint8_t Key_GetState(void)
{
	if(HAL_GPIO_ReadPin(KEY_GPIO_Port,KEY_Pin) == 1)
	{
		return 1;
	}else{
		return 0;
	}
}

void Key_Task_Runnable(void)
{
	static uint8_t task_state = 0;
	uint8_t pin_state = GPIO_PIN_RESET;
	if(task_state == 0)
	{
		if(Key_init()==0)
		{
			task_state = 1;
		}
	}else{
		pin_state = Key_GetState();
		if(pin_state == 0)
		{
			if(g_E_key_state == KEY_RELEASED )
			{
				HAL_Delay(KEY_FILTER_TIME);
				pin_state = Key_GetState();
				if(pin_state == 0)
				{
					g_E_key_state = KEY_PRESSED;
				}else{
					g_E_key_state = KEY_RELEASED;
				}
			}
		}else{
			g_E_key_state = KEY_RELEASED;
		}
	}
}

