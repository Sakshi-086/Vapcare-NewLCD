/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "config.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t ui8DisplayDone = FALSE;
uint8_t ui8NewPatientStatus = TRUE;
uint8_t ui8NewTubeStatus = TRUE;
uint8_t ui8SuctionPerformedStatus = FALSE;
uint8_t ui8SuctionStatusFlag = OFF;
int32_t i32TempHSP = HSP_DEFAULT;                  // High System Pressure
int32_t i32TempLST = LST_DEFAULT;                  // Lavage Settling Time
int32_t i32TempPressureStep = PRESSURE_STEP_DEFAULT; // Pressure Step
int32_t i32TempTimeIntervalStep = TIME_INTERVAL_STEP_DEFAULT; // Time Interval Step
int32_t i32TempOSP;
int32_t i32TempSSP;
int32_t i32TempSTI;
int32_t i32TempLTI;
int32_t i32TempIETP;
int32_t i32TempIETS;
int32_t i32TempBP;
int32_t i32TempBS;
int32_t i32TempST;



uint8_t ui8CalibrationSettingsOption = HSP_OPTION;

int32_t pi32SettingsBuffer[SETTINGS_BUFFER_LEN];
int32_t i32TempOroPortBlockSettingsStatus;
int32_t i32TempSubgloticPortBlockSettingsStatus;

int32_t i32TempOroSuctionStat;
int32_t i32TempSubglotticSuctionStat;
int32_t i32TempLavageStat;

int32_t i32TempHSP;
int32_t i32TempATM;
int32_t i32TempPOF;
int32_t i32TempSPOF;
int32_t i32TempPressureStep;
int32_t i32TempTimeIntervalStep;
int32_t i32TempLST;
int32_t i32TempLSInit;
int32_t i32TempLSCont;

uint8_t ui8Row = ROW1; // Current active row
uint8_t ui8PrevRow = ROW1;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

//uint8_t WaitForUserSelection(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  KBD_Init();
  LCD_Initialization();
  MX_ADC_Init();
  MX_I2C1_Init();
  MX_I2C2_Init();
  MX_SPI1_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_TIM11_Init();
  MX_UART5_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
//  /* USER CODE BEGIN 2 */
  HAL_Delay(5000); //Fixed Delay
  LCD_DisplayNewPatientSelection();
  HAL_Delay(3000);
  LCD_DisplayBatteryCharge(20);
  HAL_Delay(3000);
  LCD_DisplayBatteryCharge(65);
  HAL_Delay(3000);
  LCD_DisplayBatteryCharge(75);
  HAL_Delay(3000);
  LCD_DisplayBatteryCharge(85);
  HAL_Delay(3000);
  LCD_DisplayBatteryCharge(100);
  HAL_Delay(5000);
  LCD_DisplayConfirmNewPatient();
  HAL_Delay(3000);
  LCD_DisplayBatteryCharge(20);
  HAL_Delay(3000);
  LCD_DisplayBatteryCharge(65);
  HAL_Delay(3000);
  LCD_DisplayBatteryCharge(75);
  HAL_Delay(3000);
  LCD_DisplayBatteryCharge(85);
  HAL_Delay(3000);
  LCD_DisplayBatteryCharge(100);
  HAL_Delay(3000);




//  LCD_DisplayIcon(VERIFY_NEW_PATIENT_BOX_NO_ICON_X, VERIFY_NEW_PATIENT_BOX_NO_ICON_Y, BOX_NO_ICON_INDEX);
//  HAL_Delay(5000);
//  LCD_DisplayConfirmNewPatient();
//  LCD_DisplayImage(ERROR_SCREEN_IMAGE_INDEX);
//  HAL_Delay(3000);
//  LCD_DisplayNumber(F_MODE,ALERT_NON_CLEARABLE_ERROR_CODE_X, ALERT_NON_CLEARABLE_ERROR_CODE_Y,ui8AlertMessage, LCD_12X24_FONT_INDEX, BLACK, WHITE);

//  LCD_DisplayNewPatientSelection();

//  LCD_DisplayImage(CONFIRM_NEW_PATIENT_IMAGE_INDEX);
//  HAL_Delay(5000);
//  LCD_DisplayImage(ERASING_OLD_DATA_IMAGE_INDEX);
//  HAL_Delay(5000);
//  LCD_DisplayImage(LEAKAGE_TEST_IMAGE_INDEX);
//  HAL_Delay(5000);
//  LCD_DisplayImage(ALERT_SCREEN_IMAGE_INDEX);
//  HAL_Delay(3000);
//  LCD_DisplayText(F_MODE, ALERT_CLEARABLE_MESSAGE_3_X_1,ALERT_CLEARABLE_MESSAGE_3_Y_1,"Sensing Unit Not Connected", LCD_12X24_FONT_INDEX, BLACK, WHITE);
//  HAL_Delay(3000);
//  LCD_DisplayText(F_MODE, ALERT_CLEARABLE_MESSAGE_3_X_2,ALERT_CLEARABLE_MESSAGE_3_Y_2,"Check Sensing Unit Connection", LCD_12X24_FONT_INDEX, BLACK, WHITE);
//  HAL_Delay(5000);
//  LCD_DisplayImage(STAND_BY_IMAGE_INDEX);
//  HAL_Delay(5000);
//  LCD_DisplayImage(ERROR_SCREEN_IMAGE_INDEX);
//  HAL_Delay(5000);
//  LCD_DisplayImage(SETTINGS_SCREEN_1_IMAGE_INDEX);
//  HAL_Delay(5000);
//  LCD_DisplayImage(SETTINGS_SCREEN_2_IMAGE_INDEX);
//  HAL_Delay(5000);
//  LCD_DisplayImage(SETTINGS_SHUTDOWN_CONFIRM_IMAGE_INDEX);
//  HAL_Delay(5000);
//  LCD_DisplayImage(SHUTDOWN_IMAGE_INDEX);
//  HAL_Delay(5000);
//  LCD_DisplayImage(STAND_BY_IMAGE_INDEX);
//  HAL_Delay(5000);
//  LCD_DisplayImage(DATA_RETRIEVE_IMAGE_INDEX);
//  HAL_Delay(5000);
//  LCD_DisplayImage(RECALIBRATE_SENSOR_IMAGE_INDEX);
//  HAL_Delay(5000);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

/* -------------------------------SETTINGS PAGE TESTING-------------------------*/
//  LCD_DisplayImage(SETTINGS_SCREEN_1_IMAGE_INDEX);
//  LCD_DisplayIcon(ROW_1_ICON_X, ROW_1_ICON_Y, CLEAR_ICON);
//  LCD_DisplayNumber(FB_MODE, SETTINGS_SYSTEM_NUM_1_X, SETTINGS_SYSTEM_NUM_1_Y, i32TempHSP, LCD_8X16_FONT_INDEX, BLACK, WHITE);
//  LCD_DisplayNumber(FB_MODE, SETTINGS_SYSTEM_NUM_2_X, SETTINGS_SYSTEM_NUM_2_Y, i32TempLST, LCD_8X16_FONT_INDEX, BLACK, WHITE);
//  LCD_DisplayNumber(FB_MODE, SETTINGS_SYSTEM_NUM_3_X, SETTINGS_SYSTEM_NUM_3_Y, i32TempPressureStep, LCD_8X16_FONT_INDEX, BLACK, WHITE);
//  LCD_DisplayNumber(FB_MODE, SETTINGS_SYSTEM_NUM_4_X, SETTINGS_SYSTEM_NUM_4_Y, i32TempTimeIntervalStep, LCD_8X16_FONT_INDEX, BLACK, WHITE);
//  // Main interaction loop
//  while (1)
//  {
//      // Handle UP Button Press
//      if (KBD_ButtonStatus(BUTTON_UP) == BUTTON_CLICKED)
//      {
//          // Change row based on current active row (ui8Row)
//          if (ui8Row == ROW1)
//          {
//              ui8Row = ROW4;  // Wrap around to ROW4
//              LCD_DisplayIcon(ROW_4_ICON_X, ROW_4_ICON_Y, (ui8Row == ROW4) ? DISPLAY_ICON:CLEAR_ICON);
//          }
//          else if (ui8Row == ROW2)
//          {
//
//              ui8Row = ROW1;  // Move to previous row (ROW1)
//              LCD_DisplayIcon(ROW_1_ICON_X, ROW_1_ICON_Y, (ui8Row == ROW1) ? DISPLAY_ICON:CLEAR_ICON);
//          }
//          else if (ui8Row == ROW3)
//          {
//
//              ui8Row = ROW2;  // Move to previous row (ROW2)
//              LCD_DisplayIcon(ROW_2_ICON_X, ROW_2_ICON_Y,(ui8Row == ROW2) ? DISPLAY_ICON:CLEAR_ICON);
//          }
//          else if (ui8Row == ROW4)
//          {
//
//              ui8Row = ROW3;  // Move to previous row (ROW3)
//              LCD_DisplayIcon(ROW_3_ICON_X,ROW_3_ICON_Y, (ui8Row == ROW3) ? DISPLAY_ICON:CLEAR_ICON);
//          }
//
//          HAL_Delay(300);  // Debounce delay
//      }
//
//      // Handle DOWN Button Press
//      if (KBD_ButtonStatus(BUTTON_DOWN) == BUTTON_CLICKED)
//      {
//          // Change row based on current active row (ui8Row)
//          if (ui8Row == ROW1)
//          {
//              ui8Row = ROW2;  // Move to next row (ROW2)
//              LCD_DisplayIcon(ROW_2_ICON_X,ROW_2_ICON_Y, (ui8Row == ROW2) ? DISPLAY_ICON:CLEAR_ICON);
//          }
//          else if (ui8Row == ROW2)
//          {
//              ui8Row = ROW3;  // Move to next row (ROW3)
//              LCD_DisplayIcon(ROW_3_ICON_X, ROW_3_ICON_Y, (ui8Row == ROW3) ? DISPLAY_ICON:CLEAR_ICON);
//          }
//          else if (ui8Row == ROW3)
//          {
//              ui8Row = ROW4;  // Move to next row (ROW4)
//              LCD_DisplayIcon(ROW_4_ICON_X, ROW_4_ICON_Y, (ui8Row == ROW4) ? DISPLAY_ICON:CLEAR_ICON);
//          }
//          else if (ui8Row == ROW4)
//          {
//              ui8Row = ROW1;  // Wrap around to ROW1
//              LCD_DisplayIcon(ROW_1_ICON_X, ROW_1_ICON_Y, (ui8Row == ROW1) ? DISPLAY_ICON:CLEAR_ICON);
//          }
//
//          HAL_Delay(300);  // Debounce delay
//      }
//
//      // Handle LEFT Button Press (Decrement value based on active row)
//      if (KBD_ButtonStatus(BUTTON_LEFT) == BUTTON_CLICKED)
//      {
//          if (ui8Row == ROW1 && i32TempHSP > HSP_MIN)
//          {
//
//              i32TempHSP--;  // Decrease High System Pressure
//              LCD_DisplayNumber(FB_MODE, SETTINGS_SYSTEM_NUM_1_X, SETTINGS_SYSTEM_NUM_1_Y, i32TempHSP, LCD_8X16_FONT_INDEX, BLACK, WHITE);
//              LCD_DisplayIcon(ROW_1_LEFT_ICON_X, ROW_1_LEFT_ICON_Y, (i32TempHSP <= HSP_MIN) ? CLEAR_ICON : DISPLAY_ICON);
//              LCD_DisplayIcon(ROW_1_RIGHT_ICON_X, ROW_1_RIGHT_ICON_Y, (i32TempHSP >= HSP_MAX) ? CLEAR_ICON : DISPLAY_ICON);
//              HAL_Delay(300);  // Debounce delay
//          }
//          else if (ui8Row == ROW2 && i32TempLST > LST_MIN)
//          {
//
//              i32TempLST--;  // Decrease Lavage Settling Time
//              LCD_DisplayNumber(FB_MODE, SETTINGS_SYSTEM_NUM_2_X, SETTINGS_SYSTEM_NUM_2_Y, i32TempLST, LCD_8X16_FONT_INDEX, BLACK, WHITE);
//              LCD_DisplayIcon(ROW_2_LEFT_ICON_X, ROW_2_LEFT_ICON_Y, (i32TempLST <= LST_MIN) ? CLEAR_ICON : DISPLAY_ICON);
//              LCD_DisplayIcon(ROW_2_RIGHT_ICON_X, ROW_2_RIGHT_ICON_Y, (i32TempLST >= LST_MAX) ? CLEAR_ICON : DISPLAY_ICON);
//              HAL_Delay(300);  // Debounce delay
//          }
//          else if (ui8Row == ROW3 && i32TempPressureStep > PRESSURE_STEP_MIN)
//          {
//
//              i32TempPressureStep--;  // Decrease Pressure Step
//              LCD_DisplayNumber(FB_MODE, SETTINGS_SYSTEM_NUM_3_X, SETTINGS_SYSTEM_NUM_3_Y, i32TempPressureStep, LCD_8X16_FONT_INDEX, BLACK, WHITE);
//              LCD_DisplayIcon(ROW_3_LEFT_ICON_X, ROW_3_LEFT_ICON_Y, (i32TempPressureStep <= PRESSURE_STEP_MIN) ? CLEAR_ICON : DISPLAY_ICON);
//              LCD_DisplayIcon(ROW_3_RIGHT_ICON_X, ROW_3_RIGHT_ICON_Y, (i32TempPressureStep >= PRESSURE_STEP_MAX) ? CLEAR_ICON : DISPLAY_ICON);
//              HAL_Delay(300);  // Debounce delay
//          }
//          else if (ui8Row == ROW4 && i32TempTimeIntervalStep > TIME_INTERVAL_STEP_MIN)
//          {
//              i32TempTimeIntervalStep--;  // Decrease Time Interval Step
//              LCD_DisplayNumber(FB_MODE, SETTINGS_SYSTEM_NUM_4_X, SETTINGS_SYSTEM_NUM_4_Y, i32TempTimeIntervalStep, LCD_8X16_FONT_INDEX, BLACK, WHITE);
//              LCD_DisplayIcon(ROW_4_LEFT_ICON_X, ROW_4_LEFT_ICON_Y, (i32TempTimeIntervalStep <= TIME_INTERVAL_STEP_MIN) ? CLEAR_ICON : DISPLAY_ICON);
//              LCD_DisplayIcon(ROW_4_RIGHT_ICON_X, ROW_4_RIGHT_ICON_Y, (i32TempTimeIntervalStep >= TIME_INTERVAL_STEP_MAX) ? CLEAR_ICON : DISPLAY_ICON);
//              HAL_Delay(300);  // Debounce delay
//          }
//      }
//
//      // Handle RIGHT Button Press (Increment value based on active row)
//      if (KBD_ButtonStatus(BUTTON_RIGHT) == BUTTON_CLICKED)
//      {
//          if (ui8Row == ROW1 && i32TempHSP < HSP_MAX)
//          {
//              i32TempHSP++;  // Increase High System Pressure
//              LCD_DisplayNumber(FB_MODE, SETTINGS_SYSTEM_NUM_1_X, SETTINGS_SYSTEM_NUM_1_Y, i32TempHSP, LCD_8X16_FONT_INDEX, BLACK, WHITE);
//              LCD_DisplayIcon(ROW_1_LEFT_ICON_X, ROW_1_LEFT_ICON_Y, (i32TempHSP <= HSP_MIN) ? CLEAR_ICON : DISPLAY_ICON);
//              LCD_DisplayIcon(ROW_1_RIGHT_ICON_X, ROW_1_RIGHT_ICON_Y, (i32TempHSP >= HSP_MAX) ? CLEAR_ICON : DISPLAY_ICON);
//              HAL_Delay(300);  // Debounce delay
//          }
//          else if (ui8Row == ROW2 && i32TempLST < LST_MAX)
//          {
//              i32TempLST++;  // Increase Lavage Settling Time
//              LCD_DisplayNumber(FB_MODE, SETTINGS_SYSTEM_NUM_2_X, SETTINGS_SYSTEM_NUM_2_Y, i32TempLST, LCD_8X16_FONT_INDEX, BLACK, WHITE);
//              LCD_DisplayIcon(ROW_2_LEFT_ICON_X, ROW_2_LEFT_ICON_Y, (i32TempLST <= LST_MIN) ? CLEAR_ICON : DISPLAY_ICON);
//              LCD_DisplayIcon(ROW_2_RIGHT_ICON_X, ROW_2_RIGHT_ICON_Y, (i32TempLST >= LST_MAX) ? CLEAR_ICON : DISPLAY_ICON);
//              HAL_Delay(300);  // Debounce delay
//          }
//          else if (ui8Row == ROW3 && i32TempPressureStep < PRESSURE_STEP_MAX)
//          {
//              i32TempPressureStep++;  // Increase Pressure Step
//              LCD_DisplayNumber(FB_MODE, SETTINGS_SYSTEM_NUM_3_X, SETTINGS_SYSTEM_NUM_3_Y, i32TempPressureStep, LCD_8X16_FONT_INDEX, BLACK, WHITE);
//              LCD_DisplayIcon(ROW_3_LEFT_ICON_X, ROW_3_LEFT_ICON_Y, (i32TempPressureStep <= PRESSURE_STEP_MIN) ? CLEAR_ICON : DISPLAY_ICON);
//              LCD_DisplayIcon(ROW_3_RIGHT_ICON_X, ROW_3_RIGHT_ICON_Y, (i32TempPressureStep >= PRESSURE_STEP_MAX) ? CLEAR_ICON : DISPLAY_ICON);
//              HAL_Delay(300);  // Debounce delay
//          }
//          else if (ui8Row == ROW4 && i32TempTimeIntervalStep < TIME_INTERVAL_STEP_MAX)
//          {
//              i32TempTimeIntervalStep++;  // Increase Time Interval Step
//              LCD_DisplayNumber(FB_MODE, SETTINGS_SYSTEM_NUM_4_X, SETTINGS_SYSTEM_NUM_4_Y, i32TempTimeIntervalStep, LCD_8X16_FONT_INDEX, BLACK, WHITE);
//              LCD_DisplayIcon(ROW_4_LEFT_ICON_X, ROW_4_LEFT_ICON_Y, (i32TempTimeIntervalStep <= TIME_INTERVAL_STEP_MIN) ? CLEAR_ICON : DISPLAY_ICON);
//              LCD_DisplayIcon(ROW_4_RIGHT_ICON_X, ROW_4_RIGHT_ICON_Y, (i32TempTimeIntervalStep >= TIME_INTERVAL_STEP_MAX) ? CLEAR_ICON : DISPLAY_ICON);
//              HAL_Delay(300);  // Debounce delay
//          }
//      }
//
//      // Handle BACK Button Press (Exit without saving)
//      if (KBD_ButtonStatus(BUTTON_BACK) == BUTTON_CLICKED)
//      {
//          break;  // Exit the loop or navigate to the previous screen
//      }
//
//      // Handle OK Button Press (Save settings and exit)
//      if (KBD_ButtonStatus(BUTTON_OK) == BUTTON_CLICKED)
//      {
//          // Save settings logic here
//          LCD_DisplayImage(SETTINGS_SAVE_CONFIRMATION_IMAGE_INDEX);
//          break;  // Exit the loop and save settings
//      }
//  }


//  while (1)  // Main Loop
//  {
//      // Handle LEFT Button Press: Decrease i32TempHSP
//      if (KBD_ButtonStatus(BUTTON_LEFT) == BUTTON_PRESSED)
//      {
//          if ((i32TempHSP - i32TempPressureStep) >= HSP_MIN)
//          {
//              i32TempHSP -= i32TempPressureStep;  // Decrease value
//              LCD_DisplayNumber(FB_MODE, SETTINGS_SYSTEM_NUM_1_X, SETTINGS_SYSTEM_NUM_1_Y, i32TempHSP, LCD_8X16_FONT_INDEX, BLACK, WHITE);
//              HAL_Delay(300);  // Debounce delay
//          }
//      }
//
//      // Handle RIGHT Button Press: Increase i32TempHSP
//      else if (KBD_ButtonStatus(BUTTON_RIGHT) == BUTTON_PRESSED)
//      {
//          if ((i32TempHSP + i32TempPressureStep) <= HSP_MAX)
//          {
//              i32TempHSP += i32TempPressureStep;  // Increase value
//              LCD_DisplayNumber(FB_MODE, SETTINGS_SYSTEM_NUM_1_X, SETTINGS_SYSTEM_NUM_1_Y, i32TempHSP, LCD_8X16_FONT_INDEX, BLACK, WHITE);
//              HAL_Delay(300);  // Debounce delay
//          }
//
//          // Increment Pressure Step until max is reached
//          if (i32TempPressureStep < PRESSURE_STEP_MAX)
//          {
//              i32TempPressureStep++;  // Gradual step increase
//          }
//      }
//
//      // Handle BACK Button Press: Break out of the loop or navigate back
//      if (KBD_ButtonStatus(BUTTON_BACK) == BUTTON_PRESSED)
//      {
//          break;  // Exit the loop or navigate to the previous screen
//      }
//  }

 /* ------------------------ NEW PATIENT ROUTINE------------------------------*/

//  LCD_DisplayNewPatientSelection();
//
//  while (1)  // Main Loop
//  {
//      /*
//       * Handle UP and DOWN Button Clicks on the New Patient Selection Screen
//       */
//      if (KBD_ButtonStatus(BUTTON_UP) == BUTTON_CLICKED)
//      {
//          ui8NewPatientStatus = TRUE;
//          ui8NewTubeStatus = TRUE;
//
//          // Highlight option 1 in the menu
//          LCD_DisplayNewPatientSelectionMenu(1);
//          HAL_Delay(300);  // Debounce delay
//      }
//      else if (KBD_ButtonStatus(BUTTON_SETTINGS)== BUTTON_PRESSED)
//      {
//    	  LCD_DisplayImage(SETTINGS_SCREEN_1_IMAGE_INDEX);
//      }
//      else if (KBD_ButtonStatus(BUTTON_DOWN) == BUTTON_CLICKED)
//      {
//          ui8NewPatientStatus = FALSE;
//          ui8NewTubeStatus = FALSE;
//
//          // Highlight option 2 in the menu
//          LCD_DisplayNewPatientSelectionMenu(2);
//          HAL_Delay(300);  // Debounce delay
//
//          // Wait for OK button to navigate to Clamp Tubes Main
//          while (1)
//          {
//              if (KBD_ButtonStatus(BUTTON_OK) == BUTTON_PRESSED)
//              {
//                  LCD_DisplayClampTubesMain();  // Navigate to Clamp Tubes Main
//                  HAL_Delay(300);  // Debounce delay
//
//                  // Handle actions on Clamp Tubes Main Screen
//                  while (1)
//                  {
//                      if (KBD_ButtonStatus(BUTTON_OK) == BUTTON_PRESSED)
//                      {
//                          LCD_DisplayClampTubesPause();  // Navigate to Clamp Tubes Pause
//                          HAL_Delay(300);  // Debounce delay
//
//                          // Handle actions on Clamp Tubes Pause Screen
//                          while (1)
//                          {
//                              if (KBD_ButtonStatus(BUTTON_BACK) == BUTTON_PRESSED)
//                              {
//                                  LCD_DisplayClampTubesMain();  // Return to Clamp Tubes Main
//                                  HAL_Delay(300);  // Debounce delay
//                                  break;  // Exit Clamp Tubes Pause loop
//                              }
//                              else if (KBD_ButtonStatus(BUTTON_OK) == BUTTON_PRESSED)
//                              {
//                                  LCD_DisplayUnclampTubes();  // Navigate to Unclamp Tubes Screen
//                                  HAL_Delay(300);  // Debounce delay
//                                  break;  // Exit Clamp Tubes Pause loop
//                              }
//                          }
//                          break;  // Exit Clamp Tubes Main loop after navigating
//                      }
//                      else if (KBD_ButtonStatus(BUTTON_BACK) == BUTTON_PRESSED)
//                      {
//                          LCD_DisplayNewPatientSelection();  // Return to New Patient Selection
//                          HAL_Delay(300);  // Debounce delay
//                          break;  // Exit Clamp Tubes Main loop
//                      }
//                  }
//                  break;  // Exit DOWN button handling loop
//              }
//              else if (KBD_ButtonStatus(BUTTON_BACK) == BUTTON_PRESSED)
//              {
//                  LCD_DisplayNewPatientSelection();  // Go back to New Patient Selection
//                  HAL_Delay(300);  // Debounce delay
//                  break;  // Exit the loop
//              }
//          }
//      }
//
//      /*
//       * Handle OK Button Press
//       */
//      if (KBD_ButtonStatus(BUTTON_OK) == BUTTON_PRESSED)
//      {
//          LCD_DisplayConfirmNewPatient();  // Open confirmation screen
//
//          // Wait for further user commands on the confirmation screen
//          while (1)
//          {
//              if (KBD_ButtonStatus(BUTTON_OK) == BUTTON_PRESSED)
//              {
//                  LCD_DisplayFlashErasingScreen();  // Navigate to Flash Erasing Screen
//                  HAL_Delay(300);
//                  break;  // Exit the inner loop
//              }
//
//              if (KBD_ButtonStatus(BUTTON_BACK) == BUTTON_PRESSED)
//              {
//                  LCD_DisplayNewPatientSelection();  // Return to New Patient Selection
//                  HAL_Delay(300);
//                  break;  // Exit the inner loop
//              }
//          }
//      }
//
//      /*
//       * Handle BACK Button Press
//       */
//      if (KBD_ButtonStatus(BUTTON_BACK) == BUTTON_PRESSED)
//      {
//          LCD_DisplayNewPatientSelection();  // Return to New Patient Selection
//          HAL_Delay(300);  // Debounce delay
//      }
//  }

    /* USER CODE BEGIN 3 */

  /* USER CODE END 3 */
}

/***/


/**
  * @brief System Clock Configuration
  * @retval None
  */

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL4;
  RCC_OscInitStruct.PLL.PLLDIV = RCC_PLL_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
