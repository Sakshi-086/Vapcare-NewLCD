
#ifndef INC_CONFIG_H_
#define INC_CONFIG_H_

#include "main.h"
#include "adc.h"
#include "lcd.h"
#include "i2c.h"
#include "kbd.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "vapcare.h"
#include "gpio.h"

#include <stdio.h>
#include <string.h>


#define MAJOR_VERSION							'2'
#define MINOR_VERSION							'2'
#define TEMP_VERSION							'5'
//#define EMERGENCY_VERSION						'7'

#define TRUE									1
#define FALSE									0

#define ON										1
#define OFF										0

#define OPENED									1
#define CLOSED									0

#define POWER_ON_DELAY							10					//1000ms

#define UART_TX_RX_TIMEOUT						1000				//in ms
#define SPI_TX_RX_TIMEOUT						10000				//in ms
#define I2C_TX_RX_TIMEOUT						1000				//in ms
#define ADC_TIMEOUT								1000				//in ms

//KBD Related Definitions
#define KBD1_PIN										GPIO_PIN_8
#define KBD1_PORT										GPIOE_BASE

#define KBD2_PIN										GPIO_PIN_7
#define KBD2_PORT										GPIOE_BASE

#define KBD3_PIN										GPIO_PIN_0
#define KBD3_PORT										GPIOB_BASE

#define KBD4_PIN										GPIO_PIN_5
#define KBD4_PORT										GPIOC_BASE

#define KBD5_PIN										GPIO_PIN_4
#define KBD5_PORT										GPIOC_BASE

#define KBD6_PIN										GPIO_PIN_3
#define KBD6_PORT										GPIOA_BASE

#define KBD7_PIN										GPIO_PIN_4
#define KBD7_PORT										GPIOA_BASE

#define KBD8_PIN										GPIO_PIN_5
#define KBD8_PORT										GPIOA_BASE

#define KBD9_PIN										GPIO_PIN_6
#define KBD9_PORT										GPIOA_BASE

#define KBD10_PIN										GPIO_PIN_7
#define KBD10_PORT										GPIOA_BASE

#define AC_LED_PIN										GPIO_PIN_2
#define AC_LED_PORT										GPIOC

#define BATT_LED_PIN									GPIO_PIN_3
#define BATT_LED_PORT									GPIOC

#define BUTTON_CONFIDENCE_LEVEL							100
#define BUTTON_CONFIDENCE_LEVEL_SUCTION					3

#define NUMBER_OF_BUTTONS								10

/*******************************************************************/
#define HSP_OPTION										0
#define PRESSURE_STEP_OPTION							1
#define TIME_INTERVAL_STEP_OPTION						2
#define LST_OPTION										3
#define ATM_OPTION										4

#define FLASH_STATUS_DEFAULT							0x12345678

#define HSP_MIN											(int32_t)45
#define HSP_DEFAULT										(int32_t)225
#define HSP_MAX											(int32_t)280

#define ATM_MIN											(int32_t)500
#define ATM_DEFAULT										(int32_t)800
#define ATM_MAX											(int32_t)950

#define POF_MIN											(int32_t)0
#define POF_DEFAULT										(int32_t)0
#define POF_MAX											(int32_t)100

#define SPOF_MIN										(int32_t)0
#define SPOF_DEFAULT									(int32_t)0
#define SPOF_MAX										(int32_t)100

#define LSInit_MIN										(int32_t)5
#define LSInit_DEFAULT									(int32_t)23
#define LSInit_MAX										(int32_t)30

#define LSCont_MIN										(int32_t)5
#define LSCont_DEFAULT									(int32_t)7
#define LSCont_MAX										(int32_t)15

#define PRESSURE_STEP_MIN								(int32_t)1
#define PRESSURE_STEP_DEFAULT							(int32_t)5
#define PRESSURE_STEP_MAX								(int32_t)10

#define TIME_INTERVAL_STEP_MIN							(int32_t)1
#define TIME_INTERVAL_STEP_DEFAULT						(int32_t)10
#define TIME_INTERVAL_STEP_MAX							(int32_t)10

#define LST_MIN											(int32_t)10
#define LST_DEFAULT										(int32_t)15
#define LST_MAX											(int32_t)15//(int32_t)30


#define FLASH_STATUS_INDEX							0
#define HSP_INDEX									1
#define ATM_INDEX									2
#define PRESSURE_STEP_INDEX							3
#define TIME_INTERVAL_STEP_INDEX					4
#define LST_INDEX									5
#define ORAL_SUCTION_STATUS_INDEX					6
#define OROPHARYNGEAL_SUCTION_STATUS_INDEX			7
#define SUBGLOTTIC_SUCTION_STATUS_INDEX				8
#define LAVAGE_STATUS_INDEX							9
#define	SETTINGS_ORAL_PORT_BLOCK_INDEX				10
#define SETTINGS_ORO_PORT_BLOCK_INDEX				11
#define SETTINGS_SUB_PORT_BLOCK_INDEX				12
#define OSP_INDEX									13
#define SSP_INDEX									14
#define STI_INDEX									15
#define LTI_INDEX									16
#define POF_INDEX									17
#define SPOF_INDEX									18
#define LSInit_INDEX								19
#define LSCont_INDEX								20
#define INSIDE_ET_TUBE_STATUS_INDEX					21
#define INSIDE_ET_TUBE_PRESSURE_INDEX				22
#define BRUSHING_PROTOCOL_STATUS_INDEX				23
#define BRUSHING_PROTOCOL_PRESSURE_INDEX			24
#define ON_DEMAND_STOP_TIME_INDEX					25

#define SETTINGS_BUFFER_LEN							26

#define SETTINGS_HSP									0
#define SETTINGS_LST									1
#define SETTINGS_PRESSURE_STEP							2
#define SETTINGS_TIME_INTERVAL_STEP						3
#define SETTINGS_ATM									4
#define SETTINGS_POF									5
#define SETTINGS_SPOF									6



extern volatile uint32_t vui32DelayTimerCount;
extern volatile uint8_t vui8DelayTimeoutFlag;

extern volatile uint32_t vui32DisplayTimerCount;
extern volatile uint8_t vui8DisplayTimeoutFlag;
extern uint8_t ui8WriteLogBusyFlag;
#endif /* INC_CONFIG_H_ */
