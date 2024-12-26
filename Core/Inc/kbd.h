#ifndef _KBD_H
#define _KBD_H

#define BUTTON_PRESSED						0
#define BUTTON_CLICKED						1
#define BUTTON_NOT_CLICKED					2

#define BUTTON_OK							4
#define BUTTON_UP							2
#define BUTTON_DOWN							3
#define BUTTON_LEFT							9
#define BUTTON_RIGHT						1
#define BUTTON_BACK							5
#define BUTTON_START_PAUSE					6
#define BUTTON_SETTINGS						8
#define BUTTON_EMERGENCY_SUCTION_LAVAGE		7
#define BUTTON_MUTE							0

#define AC_LED_ON							HAL_GPIO_WritePin(AC_LED_PORT, AC_LED_PIN, GPIO_PIN_SET);		//LEDCTRL1 = 1
#define AC_LED_OFF							HAL_GPIO_WritePin(AC_LED_PORT, AC_LED_PIN, GPIO_PIN_RESET);		//LEDCTRL1 = 1

#define BATT_LED_ON							HAL_GPIO_WritePin(BATT_LED_PORT, BATT_LED_PIN, GPIO_PIN_SET);		//LEDCTRL1 = 1
#define BATT_LED_OFF						HAL_GPIO_WritePin(BATT_LED_PORT, BATT_LED_PIN, GPIO_PIN_RESET);	//LEDCTRL1 = 1

void KBD_Init(void);
uint16_t KBD_Get();
uint8_t KBD_ButtonStatus(uint8_t ui8ButtonNum);

#endif
