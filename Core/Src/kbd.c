#include "config.h"

uint32_t ui32ButtonDebounce = BUTTON_CONFIDENCE_LEVEL;

uint16_t ui16KBDGpioPins[] =
{
	KBD1_PIN,	KBD2_PIN,	KBD3_PIN,	KBD4_PIN,	KBD5_PIN,
	KBD6_PIN,	KBD7_PIN,	KBD8_PIN,	KBD9_PIN,	KBD10_PIN
};

uint32_t ui32KBDGpioPorts[] =
{
	KBD1_PORT,	KBD2_PORT,	KBD3_PORT,	KBD4_PORT,	KBD5_PORT,
	KBD6_PORT,	KBD7_PORT,	KBD8_PORT,	KBD9_PORT,	KBD10_PORT
};

void KBD_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	uint8_t ui8Index;

	/* KBD GPIO Configuration --------------------------------------------------*/

	for(ui8Index = 0; ui8Index < NUMBER_OF_BUTTONS; ui8Index++)
	{
		GPIO_InitStructure.Pin = ui16KBDGpioPins[ui8Index];
		GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
		GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
		GPIO_InitStructure.Pull = GPIO_NOPULL;
		HAL_GPIO_Init((GPIO_TypeDef *)ui32KBDGpioPorts[ui8Index], &GPIO_InitStructure);
	}

	GPIO_InitStructure.Pin = AC_LED_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(AC_LED_PORT, &GPIO_InitStructure);
	AC_LED_OFF;

	GPIO_InitStructure.Pin = BATT_LED_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(BATT_LED_PORT, &GPIO_InitStructure);
	BATT_LED_OFF;
}

uint16_t KBD_Get()
{
	uint16_t ui16KeyStatus = 0;
	uint8_t ui8Index;

	for(ui8Index = 0; ui8Index < NUMBER_OF_BUTTONS; ui8Index++)
	{
		if(HAL_GPIO_ReadPin((GPIO_TypeDef *)ui32KBDGpioPorts[ui8Index], ui16KBDGpioPins[ui8Index]) == GPIO_PIN_RESET)
		{
			ui16KeyStatus = ui16KeyStatus | ((uint16_t)0x01) << ui8Index;
		}
	}

	return ui16KeyStatus;
}

uint8_t KBD_ButtonStatus(uint8_t ui8ButtonNum)
{
    static uint32_t ui32PressConfidenceLevel[NUMBER_OF_BUTTONS] = {0};
    static uint32_t ui32ReleaseConfidenceLevel[NUMBER_OF_BUTTONS] = {0};
    static uint8_t ui8TriggerPressed[NUMBER_OF_BUTTONS] = {0};
    uint16_t ui16ButtonMask = 0x01;

    ui16ButtonMask = ui16ButtonMask << ui8ButtonNum;

    if ((KBD_Get() & ui16ButtonMask) == ui16ButtonMask)  // Button is pressed
    {
        ui32ReleaseConfidenceLevel[ui8ButtonNum] = 0;
        ui32PressConfidenceLevel[ui8ButtonNum]++;

        if (ui32PressConfidenceLevel[ui8ButtonNum] > ui32ButtonDebounce)
        {
            if (!ui8TriggerPressed[ui8ButtonNum])
            {
                ui8TriggerPressed[ui8ButtonNum] = 1;
                return BUTTON_PRESSED;
            }
        }
    }
    else  // Button is released
    {
        ui32ReleaseConfidenceLevel[ui8ButtonNum]++;
        ui32PressConfidenceLevel[ui8ButtonNum] = 0;

        if (ui32ReleaseConfidenceLevel[ui8ButtonNum] > ui32ButtonDebounce)
        {
            if (ui8TriggerPressed[ui8ButtonNum])
            {
                ui8TriggerPressed[ui8ButtonNum] = 0;
                return BUTTON_CLICKED;
            }
        }
    }

    return BUTTON_NOT_CLICKED;
}

