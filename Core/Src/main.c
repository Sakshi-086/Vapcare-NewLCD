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
  typedef enum {
      SCREEN_NEW_PATIENT_SELECTION,
      SCREEN_CONFIRM_NEW_PATIENT,
	  SCREEN_ERASING_OLD_DATA,
      SCREEN_CLAMP_TUBES_MAIN,
      SCREEN_CLAMP_TUBES_PAUSE,
      SCREEN_UNCLAMP_TUBES,
      SCREEN_CONFIRM_PARAMETER,
      SCREEN_BEGIN_SUCTION,
      SCREEN_SETTINGS,
	  SCREEN_ORO_PORT,
	  SCREEN_SUBGLOT_PORT,
	  SCREEN_ET_PORT,
	  SCREEN_IDLE,
	  SCREEN_PAUSED
  } ScreenState;
  int currentOption = 1;  // Default to Option 1
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
  // Define screen states

  ScreenState currentScreen = SCREEN_NEW_PATIENT_SELECTION;  // Start at New Patient Selection
  ScreenState previousScreen = SCREEN_NEW_PATIENT_SELECTION; // Default to initial screen
  if (currentScreen == SCREEN_NEW_PATIENT_SELECTION)
    {
        LCD_DisplayNewPatientSelection();
    }
  while (1)  // Main Loop
  {
      switch (currentScreen)
      {
          /*
           * New Patient Selection Screen
           */
          case SCREEN_NEW_PATIENT_SELECTION:
              if (KBD_ButtonStatus(BUTTON_UP) == BUTTON_CLICKED)
              {
            	  currentOption = 1;
                  LCD_DisplayNewPatientSelectionMenu(1);  // Highlight Option 1
                  HAL_Delay(300);
              }
              else if (KBD_ButtonStatus(BUTTON_DOWN) == BUTTON_CLICKED)
              {
            	  currentOption = 2;
                  LCD_DisplayNewPatientSelectionMenu(2);  // Highlight Option 2
                  HAL_Delay(300);
              }
              else if (KBD_ButtonStatus(BUTTON_OK) == BUTTON_PRESSED)
              {
            	  if(currentOption == 1)
            	  {
            		  currentScreen = SCREEN_CONFIRM_NEW_PATIENT;  // Go to Confirm New Patient Screen
            		  LCD_DisplayConfirmNewPatient();
            		  HAL_Delay(300);
            	  }
            	  else if (currentOption == 2){
            		  currentScreen = SCREEN_CLAMP_TUBES_MAIN;  // Go to Clamp Tubes Main Screen
            		  LCD_DisplayClampTubesMain();
            		  HAL_Delay(300);
            	  }

              }
              else if (KBD_ButtonStatus(BUTTON_BACK) == BUTTON_PRESSED)
              {
                  LCD_DisplayNewPatientSelection();  // Stay on the same screen
                  HAL_Delay(300);
              }
              else if (KBD_ButtonStatus(BUTTON_SETTINGS) == BUTTON_PRESSED)
              {
                  currentScreen = SCREEN_SETTINGS;  // Go to Settings Screen
                  LCD_DisplayNewMainSettingsPage1();
                  HAL_Delay(300);
              }
              break;

          /*
           * Confirm New Patient Screen
           */
          case SCREEN_CONFIRM_NEW_PATIENT:
              if (KBD_ButtonStatus(BUTTON_OK) == BUTTON_PRESSED)
              {
                  currentScreen = SCREEN_ERASING_OLD_DATA;  // Go to Flash Erasing Screen
                  LCD_DisplayFlashErasingScreen();
                  HAL_Delay(2000);
                  currentScreen = SCREEN_CLAMP_TUBES_MAIN;
                  LCD_DisplayClampTubesMain();
              }
              else if (KBD_ButtonStatus(BUTTON_BACK) == BUTTON_PRESSED)
              {
                  currentScreen = SCREEN_NEW_PATIENT_SELECTION;  // Return to New Patient Selection
                  LCD_DisplayNewPatientSelection();
                  HAL_Delay(300);
              }
              break;

          /*
           * Clamp Tubes Main Screen
           */
          case SCREEN_CLAMP_TUBES_MAIN:
              if (KBD_ButtonStatus(BUTTON_OK) == BUTTON_PRESSED)
              {
                  currentScreen = SCREEN_CLAMP_TUBES_PAUSE;  // Go to Clamp Tubes Pause
                  LCD_DisplayClampTubesPause();
                  HAL_Delay(300);
              }
              else if (KBD_ButtonStatus(BUTTON_BACK) == BUTTON_PRESSED)
              {
                  currentScreen = SCREEN_NEW_PATIENT_SELECTION;  // Return to New Patient Selection
                  LCD_DisplayNewPatientSelection();
                  HAL_Delay(300);
              }
              break;

          /*
           * Clamp Tubes Pause Screen
           */
          case SCREEN_CLAMP_TUBES_PAUSE:
              if (KBD_ButtonStatus(BUTTON_OK) == BUTTON_PRESSED)
              {
                  currentScreen = SCREEN_UNCLAMP_TUBES;  // Go to Unclamp Tubes
                  LCD_DisplayUnclampTubes();
                  HAL_Delay(1000);  // 3-second delay
                  currentScreen = SCREEN_CONFIRM_PARAMETER;  // Go to Confirm Parameter Screen
                  LCD_ConfirmParameterAndBeginSuctionScreen();
                  previousScreen=currentScreen;
              }
              else if (KBD_ButtonStatus(BUTTON_BACK) == BUTTON_PRESSED)
              {
                  currentScreen = SCREEN_CLAMP_TUBES_MAIN;  // Return to Clamp Tubes Main
                  LCD_DisplayClampTubesMain();
                  HAL_Delay(300);
              }
              break;

          /*
           * Confirm Parameter And Begin Suction Screen
           */
          case SCREEN_CONFIRM_PARAMETER:
              if (KBD_ButtonStatus(BUTTON_START_PAUSE) == BUTTON_PRESSED)
              {
                  currentScreen = SCREEN_BEGIN_SUCTION;  // Go to Begin Suction Screen
                  LCD_DisplayBeginSuction();
                  HAL_Delay(300);
              }
              else if (KBD_ButtonStatus(BUTTON_SETTINGS) == BUTTON_PRESSED)
              {
                  currentScreen = SCREEN_SETTINGS;  // Go to Settings Screen
                  LCD_DisplayNewMainSettingsPage1();
                  HAL_Delay(300);
              }
              break;

          /*
           * Begin Suction Screen
           */
          case SCREEN_BEGIN_SUCTION:
              if (KBD_ButtonStatus(BUTTON_START_PAUSE) == BUTTON_PRESSED)
              {
            	  currentScreen = SCREEN_ORO_PORT;
                  LCD_DisplayPharyngealPortSuction();  // Navigate to Pharyngeal Port Suction
//                  HAL_Delay(5000);
//                  LCD_DisplaySubglotticPortSuction();
//                  HAL_Delay(5000);
//                  LCD_DisplayInsideEtTubeSuction();
//                  HAL_Delay(5000);
//                  LCD_DisplayWaitScreen();
              }
              else if (KBD_ButtonStatus(BUTTON_SETTINGS) == BUTTON_PRESSED)
              {
                  currentScreen = SCREEN_SETTINGS;  // Go to Settings Screen
                  LCD_DisplayNewMainSettingsPage1();
                  HAL_Delay(300);
              }
              break;
          /*** oro port*/

          case SCREEN_ORO_PORT:
//        	  LCD_DisplayPharyngealPortSuction();
        	  if (KBD_ButtonStatus(BUTTON_START_PAUSE) == BUTTON_PRESSED)
        	  {
        		  currentScreen= SCREEN_PAUSED;
        		  LCD_DisplayPauseScreen();
        		  HAL_Delay(300);
        	  }
          case SCREEN_PAUSED:
        	  if(KBD_ButtonStatus(BUTTON_START_PAUSE) == BUTTON_PRESSED)
        	  {
        		  currentScreen= SCREEN_ORO_PORT;
        		  LCD_DisplayPharyngealPortSuction();
        		  HAL_Delay(300);
        	  }

          /*
           * Settings Screen
           */
          case SCREEN_SETTINGS:
        	  if (KBD_ButtonStatus(BUTTON_BACK) == BUTTON_PRESSED)
                  {
                      currentScreen = previousScreen;  // Go back to the previous screen
                      switch (previousScreen)
                      {
                          case SCREEN_NEW_PATIENT_SELECTION:
                              LCD_DisplayNewPatientSelection();
                              break;
                          case SCREEN_CONFIRM_NEW_PATIENT:
                              LCD_DisplayConfirmNewPatient();
                              break;
                          case SCREEN_CLAMP_TUBES_MAIN:
                              LCD_DisplayClampTubesMain();
                              break;
                          case SCREEN_CLAMP_TUBES_PAUSE:
                              LCD_DisplayClampTubesPause();
                              break;
                          case SCREEN_UNCLAMP_TUBES:
                              LCD_DisplayUnclampTubes();
                              break;
                          case SCREEN_CONFIRM_PARAMETER:
                              LCD_ConfirmParameterAndBeginSuctionScreen();
                              break;
                          case SCREEN_BEGIN_SUCTION:
                              LCD_DisplayBeginSuction();
                              break;
                          default:
                              // Fallback to New Patient Selection if the previous screen is undefined
                              currentScreen = SCREEN_NEW_PATIENT_SELECTION;
                              LCD_DisplayNewPatientSelection();
                              break;
                      }
                      HAL_Delay(300);
                  }
                  break;

          default:
              // Handle undefined states
              currentScreen = SCREEN_NEW_PATIENT_SELECTION;
              LCD_DisplayNewPatientSelection();
              break;
      }
  }




  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  /* ------------------------ NEW PATIENT ROUTINE------------------------------*/

//   LCD_DisplayNewPatientSelection();
//   LCD_DisplayBatteryCharge(75);
//   // Start with the New Patient Selection Screen
//
//   while (1)  // Main Loop
//   {
//       /*
//        * New Patient Selection Screen
//        */
//       if (KBD_ButtonStatus(BUTTON_UP) == BUTTON_CLICKED)
//       {
//           // Highlight Option 1 in the menu
//           LCD_DisplayNewPatientSelectionMenu(1);
//           HAL_Delay(300);  // Debounce delay
//
//           // Wait for OK button to confirm
////           if (KBD_ButtonStatus(BUTTON_OK) == BUTTON_PRESSED)
////           {
////               LCD_DisplayConfirmNewPatient();  // Navigate to Confirm New Patient Screen
////               HAL_Delay(300);  // Debounce delay
////               continue;  // Restart main loop
////           }
//       }
//       else if (KBD_ButtonStatus(BUTTON_DOWN) == BUTTON_CLICKED)
//       {
//           // Highlight Option 2 in the menu
//           LCD_DisplayNewPatientSelectionMenu(2);
//           HAL_Delay(300);  // Debounce delay
//
//           // Wait for OK button to confirm
//           if (KBD_ButtonStatus(BUTTON_OK) == BUTTON_PRESSED)
//           {
//               LCD_DisplayClampTubesMain();  // Navigate to Clamp Tubes Main Screen
//               HAL_Delay(300);  // Debounce delay
//               continue;  // Restart main loop
//           }
//           else if (KBD_ButtonStatus(BUTTON_BACK) == BUTTON_PRESSED)
//           {
//               LCD_DisplayNewPatientSelection();  // Return to New Patient Selection
//               HAL_Delay(300);  // Debounce delay
//               continue;  // Restart main loop
//           }
//       }
//       else if (KBD_ButtonStatus(BUTTON_SETTINGS) == BUTTON_PRESSED)
//       {
//           LCD_DisplayNewMainSettingsPage1();  // Navigate to Settings Screen
//           HAL_Delay(300);  // Debounce delay
//           continue;  // Restart main loop
//       }
//
//       /*
//        * Clamp Tubes Main Screen
//        */
//       if (KBD_ButtonStatus(BUTTON_OK) == BUTTON_PRESSED)
//       {
//    	   LCD_DisplayConfirmNewPatient();  // Navigate to Clamp Tubes Pause Screen
//           HAL_Delay(300);  // Debounce delay
//
//           // Wait for actions on Clamp Tubes Pause Screen
//           while (1)
//           {
//               if (KBD_ButtonStatus(BUTTON_OK) == BUTTON_PRESSED)
//               {
//            	   LCD_DisplayFlashErasingScreen();  // Navigate to Unclamp Tubes Screen
//                   HAL_Delay(3000);  // 3-second delay
//                   LCD_DisplayClampTubesMain();  // Navigate to Confirm Parameter Screen
//                   break;  // Exit Clamp Tubes Pause loop
//               }
//               else if (KBD_ButtonStatus(BUTTON_BACK) == BUTTON_PRESSED)
//               {
//            	   LCD_DisplayNewPatientSelection();  // Return to Clamp Tubes Main Screen
//                   HAL_Delay(300);  // Debounce delay
//                   continue;  // restart main loop
//               }
//           }
//       }
//       else if (KBD_ButtonStatus(BUTTON_BACK) == BUTTON_PRESSED)
//       {
//           LCD_DisplayNewPatientSelection();  // Return to New Patient Selection
//           HAL_Delay(300);  // Debounce delay
//           continue;  // Restart main loop
//       }
//
//       /*
//        * Confirmation Screen
//        */
//       if (KBD_ButtonStatus(BUTTON_OK) == BUTTON_PRESSED)
//       {
//           LCD_DisplayFlashErasingScreen();  // Navigate to Flash Erasing Screen
//           HAL_Delay(300);  // Debounce delay
//           continue;  // Restart main loop
//       }
//       else if (KBD_ButtonStatus(BUTTON_BACK) == BUTTON_PRESSED)
//       {
//           LCD_DisplayNewPatientSelection();  // Return to New Patient Selection
//           HAL_Delay(300);  // Debounce delay
//           continue;  // Restart main loop
//       }
//
//       /*
//        * Confirm Parameter And Begin Suction Screen
//        */
//       if (KBD_ButtonStatus(BUTTON_START_PAUSE) == BUTTON_PRESSED)
//       {
//           LCD_DisplayBeginSuction();  // Navigate to Begin Suction Screen
//           HAL_Delay(300);  // Debounce delay
//           continue;  // Restart main loop
//       }
//       else if (KBD_ButtonStatus(BUTTON_SETTINGS) == BUTTON_PRESSED)
//       {
//           LCD_DisplayNewMainSettingsPage1();  // Navigate to Settings Screen
//           HAL_Delay(300);  // Debounce delay
//           continue;  // Restart main loop
//       }
//
//       /*
//        * Begin Suction Screen
//        */
//       if (KBD_ButtonStatus(BUTTON_START_PAUSE) == BUTTON_PRESSED)
//       {
//           LCD_DisplayPharyngealPortSuction();  // Navigate to Pharyngeal Port Suction Screen
//           HAL_Delay(300);  // Debounce delay
//           continue;  // Restart main loop
//       }
//       else if (KBD_ButtonStatus(BUTTON_SETTINGS) == BUTTON_PRESSED)
//       {
//           LCD_DisplayNewMainSettingsPage1();  // Navigate to Settings Screen
//           HAL_Delay(300);  // Debounce delay
//           continue;  // Restart main loop
//       }
//   }

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
