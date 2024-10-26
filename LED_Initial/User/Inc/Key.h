#ifndef __KEY_H__
#define	__KEY_H__


#include "main.h"


#define	KEY_FILTER_TIME	10

typedef enum{
	KEY_RELEASED=0,
	KEY_PRESSED
}KeyState;

extern uint8_t g_E_key_state;
extern void Key_Task_Runnable(void);

#endif

