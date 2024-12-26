#include <config.h>

uint8_t ui8AlertMessage;


void LCD_Initialization(void)
{
//	HAL_Delay(2000);
}

// ===================== Coordinate-to-Label Mapping =====================

const CoordinateLabelMap label_mapping[] = {
	{BUZZER_ICON_X, BUZZER_ICON_Y, "BUZZER_ICON"},
	{BUZZER_ICON_X, BUZZER_ICON_Y, "BUZZER_MUTE_ICON"},
    {VERIFY_NEW_PATIENT_BOX_YES_ICON_X, VERIFY_NEW_PATIENT_BOX_YES_ICON_Y, "YES_ICON"},
    {VERIFY_NEW_PATIENT_BOX_NO_ICON_X, VERIFY_NEW_PATIENT_BOX_NO_ICON_Y, "NO_ICON"},
    {VERIFY_NEW_PATIENT_YES_X, VERIFY_NEW_PATIENT_YES_Y, "YES_LABEL"},
	{VERIFY_NEW_PATIENT_NO_X, VERIFY_NEW_PATIENT_NO_Y, "NO_LABEL"},
	{VERIFY_NEW_PATIENT_TEXT1_X, VERIFY_NEW_PATIENT_TEXT1_Y, "VERIFY_NEW_PATIENT_TEXT1_LABEL"},
	{VERIFY_NEW_PATIENT_TEXT2_X, VERIFY_NEW_PATIENT_TEXT2_Y, "VERIFY_NEW_PATIENT_TEXT2_LABEL"},
	{CONFIRM_NEW_PATIENT_TEXT1_X, CONFIRM_NEW_PATIENT_TEXT1_Y, "CONFIRM_NEW_PATIENT_TEXT1_LABEL"},
	{CONFIRM_NEW_PATIENT_TEXT2_X, CONFIRM_NEW_PATIENT_TEXT2_Y, "CONFIRM_NEW_PATIENT_TEXT2_LABEL"},
	{CONFIRM_NEW_PATIENT_TEXT3_X, CONFIRM_NEW_PATIENT_TEXT3_Y, "CONFIRM_NEW_PATIENT_TEXT3_LABEL"},
	{ALERT_CLEARABLE_TEXT_1_X,ALERT_CLEARABLE_TEXT_1_Y, "AlertMessages_1_LABEL"},
	{ALERT_CLEARABLE_TEXT_2_X,ALERT_CLEARABLE_TEXT_2_Y,"AlertMessages_2_LABEL"},
	{ALERT_NON_CLEARABLE_ERROR_CODE_X, ALERT_NON_CLEARABLE_ERROR_CODE_Y,"ERROR_CODE_LABEL"},
	{SETTINGS_SYSTEM_NUM_1_X, SETTINGS_SYSTEM_NUM_1_Y,"SETTINGS_SYS_1_NUM_1_LABEL"},
	{SETTINGS_SYSTEM_NUM_2_X, SETTINGS_SYSTEM_NUM_2_Y,"SETTINGS_SYS_1_NUM_2_LABEL"},
	{SETTINGS_SYSTEM_NUM_3_X, SETTINGS_SYSTEM_NUM_3_Y,"SETTINGS_SYS_1_NUM_3_LABEL"},
	{SETTINGS_SYSTEM_NUM_4_X, SETTINGS_SYSTEM_NUM_4_Y,"SETTINGS_SYS_1_NUM_4_LABEL"},
	{ROW_1_LEFT_ICON_X, ROW_1_LEFT_ICON_Y, "LEFT_ARR_ICON1"},
	{ROW_1_RIGHT_ICON_X, ROW_1_RIGHT_ICON_Y, "RIGHT_ARR_ICON1"},

	{ROW_2_LEFT_ICON_X, ROW_2_LEFT_ICON_Y, "LEFT_ARR_ICON2"},
	{ROW_2_RIGHT_ICON_X, ROW_2_RIGHT_ICON_Y, "RIGHT_ARR_ICON2"},

	{ROW_3_LEFT_ICON_X, ROW_3_LEFT_ICON_Y, "LEFT_ARR_ICON3"},
	{ROW_3_RIGHT_ICON_X, ROW_3_RIGHT_ICON_Y, "RIGHT_ARR_ICON3"},

	{ROW_4_LEFT_ICON_X, ROW_4_LEFT_ICON_Y, "LEFT_ARR_ICON4"},
	{ROW_4_RIGHT_ICON_X, ROW_4_RIGHT_ICON_Y, "RIGHT_ARR_ICON4"},

	{ROW_5_LEFT_ICON_X, ROW_5_LEFT_ICON_Y, "LEFT_ARR_ICON5"},
	{ROW_5_RIGHT_ICON_X, ROW_5_RIGHT_ICON_Y, "RIGHT_ARR_ICON5"},

	{ROW_6_LEFT_ICON_X, ROW_6_LEFT_ICON_Y, "LEFT_ARR_ICON6"},
	{ROW_6_RIGHT_ICON_X, ROW_6_RIGHT_ICON_Y, "RIGHT_ARR_ICON6"},

	{ROW_7_LEFT_ICON_X, ROW_7_LEFT_ICON_Y, "LEFT_ARR_ICON7"},
	{ROW_7_RIGHT_ICON_X, ROW_7_RIGHT_ICON_Y, "RIGHT_ARR_ICON7"},

	{ROW_8_LEFT_ICON_X, ROW_8_LEFT_ICON_Y, "LEFT_ARR_ICON8"},
	{ROW_8_RIGHT_ICON_X, ROW_8_RIGHT_ICON_Y, "RIGHT_ARR_ICON8"},
	{ROW_1_ICON_X, ROW_1_ICON_Y, "ROW_1_ICON"},
	{ROW_2_ICON_X, ROW_2_ICON_Y, "ROW_2_ICON"},
	{ROW_3_ICON_X, ROW_3_ICON_Y, "ROW_3_ICON"},
	{ROW_4_ICON_X, ROW_4_ICON_Y, "ROW_4_ICON"},
	{ROW_5_ICON_X, ROW_5_ICON_Y, "ROW_5_ICON"},
	{ROW_6_ICON_X, ROW_6_ICON_Y, "ROW_6_ICON"},
	{ROW_7_ICON_X, ROW_7_ICON_Y, "ROW_7_ICON"},
	{ROW_8_ICON_X, ROW_8_ICON_Y, "ROW_8_ICON"}

};

const char* get_label_name(uint16_t x, uint16_t y) {
    for (int i = 0; i < sizeof(label_mapping) / sizeof(label_mapping[0]); i++) {
        if (label_mapping[i].x == x && label_mapping[i].y == y) {
            return label_mapping[i].label_name;
        }
    }
    return NULL; // Return NULL if no label matches the coordinates
}

// Function to send set text command to a widget
void set_text(const char* widget_type, const char* widget_name, const char* text) {
    // Construct JSON command
    char json_command[256] = {0};

    snprintf(json_command, sizeof(json_command), "%s%s%s%s%s%s%s%s",
             CMD_PREFIX, CMD_CODE_SET_TEXT, CMD_SUFFIX_TYPE, widget_type,
             CMD_SUFFIX_WIDGET, widget_name, CMD_SUFFIX_TEXT, text);
    strncat(json_command, CMD_SUFFIX_END, sizeof(json_command) - strlen(json_command) - 1);

    // Send the constructed command over USART
    USART_SendCommand(json_command);
}

void LCD_DisplayText(uint8_t ui8TextDisplayMode, uint16_t ui16X, uint16_t ui16Y, const char *pi8String, uint8_t ui8FontIndex, uint16_t ui16FColor, uint16_t ui16BColor) {
    // Retrieve the label name based on coordinates
    const char *label_name = get_label_name(ui16X, ui16Y);

    // Check if the label exists for the given coordinates
    if (label_name == NULL) {
        // Handle error if no matching label is found
        return;
    }

    // Call set_text to set the text for the widget (label)
    set_text("label",label_name, pi8String);
}


// Function to display a number on the LCD
void LCD_DisplayNumber(uint8_t ui8TextDisplayMode, uint16_t ui16X, uint16_t ui16Y, uint16_t ui16Value, uint8_t ui8FontIndex, uint16_t ui16FColor, uint16_t ui16BColor) {
    char value_str[16]; // Buffer to store the number as a string
    snprintf(value_str, sizeof(value_str), "%u", ui16Value); // Convert number to string

    // Retrieve the label name based on coordinates
    const char* label_name = get_label_name(ui16X, ui16Y);

    // Check if the label exists for the given coordinates
    if (label_name == NULL) {
        // Handle error if no matching label is found
        return;
    }

    // Call set_value to update the widget's value
    set_text("label", label_name, value_str);
}

// Function to set the visibility of a widget (icon)
void set_visible(const char* widget_name, uint8_t visible) {
    char json_command[256] = {0};

    // Construct the JSON command for set_visible
    snprintf(json_command, sizeof(json_command),
             "ST<{\"cmd_code\":\"set_visible\",\"type\":\"widget\",\"widget\":\"%s\",\"visible\":%s}>ET",
             widget_name, (visible == 1) ? "true" : "false");

    // Send the JSON command using USART
    USART_SendCommand(json_command);
}




void LCD_DisplayIcon(uint16_t ui16X, uint16_t ui16Y, uint16_t ui16Index) {
	//Get label name from coordinates
    const char *icon_name = get_label_name(ui16X, ui16Y);

    // Check if the icon name is found for the given coordinates
    if (icon_name == NULL) {
        // Handle error: No icon found for these coordinates
        USART_SendCommand("ST<{\"cmd_code\":\"error\",\"message\":\"No Icon Found\"}>ET");
        return;
    }

    // Call set_visible function to update visibility
    set_visible(icon_name,ui16Index);
}

// ===================== Index-to-Window Mapping =====================

const IndexWindowMap index_mapping[] = {
		{POWER_ON_SELF_TEST_IMAGE_INDEX, "home_page"},
		{NEW_PATIENT_IMAGE_INDEX, "NEW_PATIENT_WIN"},
		{CONFIRM_NEW_PATIENT_IMAGE_INDEX, "CONFIRM_NEW_PATIENT_WIN"},
	    {ERASING_OLD_DATA_IMAGE_INDEX, "ERASING_OLD_DATA_WIN"},
		{CLAMP_TUBES_IMAGE_INDEX_1, "LEAKAGE_TEST_WIN"},
		{ALERT_SCREEN_IMAGE_INDEX, "ALERT_WIN"},
		{ALERT_LOWBAT_SCREEN_IMAGE_INDEX, "ALERT_LOWBAT_WIN"},
		{ERROR_SCREEN_IMAGE_INDEX, "ERROR_WIN"},
		{SETTINGS_SCREEN_1_IMAGE_INDEX, "SETTINGS_SYS_1_WIN"},
		{SETTINGS_SCREEN_2_IMAGE_INDEX, "SETTINGS_SYS_2_WIN"},
		{SETTINGS_SHUTDOWN_CONFIRM_IMAGE_INDEX, "SETTINGS_SHUTDOWN_CONFIRM_WIN"},
		{SHUTDOWN_IMAGE_INDEX, "SHUTDOWN_WIN"},
		{STAND_BY_IMAGE_INDEX, "STAND_BY_WIN"},
		{RECALIBRATE_SENSOR_IMAGE_INDEX, "RECALIBRATE_SENSOR_WIN"},
		{CLAMP_TUBES_IMAGE_INDEX_1, "LEAKAGE_TEST_WIN"},
		{CLAMP_TUBES_IMAGE_INDEX_2, "LEAKAGE_TEST_2_WIN"},
		{UNCLAMP_TUBES_IMAGE_INDEX, "UNCLAMP_TUBES_WIN"},
		{SETTINGS_SAVE_CONFIRMATION_IMAGE_INDEX, "SETTINGS_SAVE_CONFIRMATION_WIN"}

};


const char* get_window_name_from_index(uint16_t index) {
    for (int i = 0; i < sizeof(index_mapping) / sizeof(index_mapping[0]); i++) {
        if (index_mapping[i].index == index) {
            return index_mapping[i].window_name;
        }
    }
    return NULL; // Return NULL if no matching window is found
}

// Function to send open window command for a specific widget
void open_win(const char* widget) {
    // Construct JSON command
    char json_command[256] = {0};

    snprintf(json_command, sizeof(json_command), "%s%s%s%s%s%s",
             CMD_PREFIX, CMD_CODE_OPEN_WINDOW, CMD_SUFFIX_TYPE, WIDGET_TYPE_WINDOW,
             CMD_SUFFIX_WIDGET, widget);
    strncat(json_command, CMD_SUFFIX_END, sizeof(json_command) - strlen(json_command) - 1);

    // Send the constructed command over USART
    USART_SendCommand(json_command);
}

void set_image(const char* widget_name, const char* image_name) {
    char json_command[256] = {0}; // Buffer for the JSON command

    // Construct the JSON command for setting the image
    snprintf(json_command, sizeof(json_command),
             "ST<{\"cmd_code\":\"set_image\",\"type\":\"image\",\"widget\":\"%s\",\"image\":\"%s\"}>ET",
             widget_name, image_name);

    // Send the JSON command using USART
    USART_SendCommand(json_command);
}

void LCD_DisplayImage(uint16_t ui16index) {
    // Get window name from index
    const char *window_name = get_window_name_from_index(ui16index);

    if (window_name == NULL) {
        // Handle invalid index case
        USART_SendCommand("ST<{\"cmd_code\":\"error\",\"message\":\"Invalid Index\"}>ET");
        return;
    }

    // Open the window using open_win
    open_win(window_name);
}

//===============================================================================
//
//void LCD_DisplayScreenStandby(void)
//{
//
//	ui8PrevRow = ROW1;
//}
//
//void LCD_DisplayScreenStandbyMenu(uint8_t ui8Row)
//{
//	switch(ui8PrevRow)
//	{
//		case ROW1:
//			LCD_DisplayIcon(ROW_2_ICON_X, ROW_2_ICON_Y, ROW_CLEAR_ICON_INDEX);
//			break;
//		case ROW2:
//			LCD_DisplayIcon(ROW_3_ICON_X, ROW_3_ICON_Y, ROW_CLEAR_ICON_INDEX);
//			break;
//	}
//
//	if(ui8Row == ROW1)
//	{
//		LCD_DisplayIcon(ROW_2_ICON_X, ROW_2_ICON_Y, ROW_BOX_ICON_INDEX);							//2nd Row with Box
//		ui8PrevRow = ROW1;
//	}
//	else if(ui8Row == ROW2)
//	{
//		LCD_DisplayIcon(ROW_3_ICON_X, ROW_3_ICON_Y, ROW_BOX_ICON_INDEX);							//3rd Row with Box
//		ui8PrevRow = ROW2;
//	}
//}
void LCD_IntToString(char *pi8Str, uint16_t ui16Num, uint8_t ui8Format)
{
    uint16_t ui16Index, ui16Reminder, ui16Length = 0;

    ui16Length = 3;
    for(ui16Index = 0; ui16Index < ui16Length; ui16Index++)
    {
    	ui16Reminder = ui16Num % 10;
    	ui16Num = ui16Num / 10;
        pi8Str[ui16Length - (ui16Index + 1)] = ui16Reminder + '0';
    }

    if(ui8Format == TRUE)
    {
		if(pi8Str[0] == '0')
		{
			pi8Str[0] = ' ';
			if(pi8Str[1] == '0')
			{
				pi8Str[1] = ' ';
			}
		}
    }
}

void LCD_DisplayNewPatientSelection(void)
{
	LCD_DisplayImage(NEW_PATIENT_IMAGE_INDEX);
}

void LCD_DisplayNewPatientSelectionMenu(uint8_t ui8Num)
{
	if(ui8Num == 1)
	{
		LCD_DisplayIcon(VERIFY_NEW_PATIENT_BOX_NO_ICON_X, VERIFY_NEW_PATIENT_BOX_NO_ICON_Y, CLEAR_BOX_NO_ICON_INDEX);
		LCD_DisplayIcon(VERIFY_NEW_PATIENT_BOX_YES_ICON_X, VERIFY_NEW_PATIENT_BOX_YES_ICON_Y, BOX_YES_ICON_INDEX);
	}
	else
	{
		LCD_DisplayIcon(VERIFY_NEW_PATIENT_BOX_YES_ICON_X, VERIFY_NEW_PATIENT_BOX_YES_ICON_Y, CLEAR_BOX_YES_ICON_INDEX);
		LCD_DisplayIcon(VERIFY_NEW_PATIENT_BOX_NO_ICON_X, VERIFY_NEW_PATIENT_BOX_NO_ICON_Y, BOX_NO_ICON_INDEX);
	}
}

void LCD_DisplayConfirmNewPatient(void)
{
	LCD_DisplayImage(CONFIRM_NEW_PATIENT_IMAGE_INDEX);
}

void LCD_DisplayFlashErasingScreen(void)
{
	LCD_DisplayImage(ERASING_OLD_DATA_IMAGE_INDEX);
}

void LCD_DisplayClampTubesMain(void)
{
	LCD_DisplayImage(CLAMP_TUBES_IMAGE_INDEX_1);
}

void LCD_DisplayClampTubesPause(void)
{
	LCD_DisplayImage(CLAMP_TUBES_IMAGE_INDEX_2);
}

void LCD_DisplayUnclampTubes(void)
{
	LCD_DisplayImage(UNCLAMP_TUBES_IMAGE_INDEX);
}

void LCD_DisplayLowBattery(void)
{
	LCD_DisplayImage(ALERT_LOWBAT_SCREEN_IMAGE_INDEX);
}

/*
 * Display Alert/Error functions
*/
char pui8AlertMessages_1[][40] =  { "Blood Detected - Oropharyngeal",
									"Blood Detected - Subglottic",
									"Port Blocked - Oropharyngeal",
									"Port Blocked - Subglottic",
									"Check Sensing Unit Tube - Oropharyngeal",
									"Check Sensing Unit Tube - Subglottic",
									"No Secretions - Oropharyngeal",
									"No Secretions - Subglottic",
									"Leakage Found In System",
									"Clamp Not Removed",
									"Sensing Unit Calibration Required",
									"Sensing Unit Not Connected",
									"Remove Sensing Unit Tubes",
									"Calibration Failed",
									"Low Pressure In System"
									};


char pui8AlertMessages_2[][40] =  { "Blood Detected - Oropharyngeal",
									"Blood Detected - Subglottic",
									"Refer User Manual To Handle Alert",
									"Refer User Manual To Handle Alert",
									"Check Sensing Unit Tube - Oropharyngeal",
									"Check Sensing Unit Tube - Subglottic",
									"Check VAPLumen Placement",
									"Check VAPLumen Placement",
									"Check Tubings For Leakage",
									"Unclamp Tubes",
									"Sensing Unit Calibration Required",
									"Check Sensing Unit Connection",
									"Remove Sensing Unit Tubes",
									"Calibration Failed",
									"Check Suction Source"
									};

void LCD_DisplayAlertScreen1(void)
{
	LCD_DisplayImage(ALERT_SCREEN_IMAGE_INDEX);
	for(uint8_t ui8AlertMessage = 0; ui8AlertMessage < TOTAL_ALERT_MESSAGES; ui8AlertMessage++)
	{
	    // Display messages from both arrays
	    LCD_DisplayText(F_MODE, ALERT_CLEARABLE_TEXT_1_X, ALERT_CLEARABLE_TEXT_1_Y, pui8AlertMessages_1[ui8AlertMessage], LCD_12X24_FONT_INDEX, BLACK, WHITE);
	    LCD_DisplayText(F_MODE, ALERT_CLEARABLE_TEXT_2_X, ALERT_CLEARABLE_TEXT_2_Y, pui8AlertMessages_2[ui8AlertMessage], LCD_12X24_FONT_INDEX, BLACK, WHITE);

	    // Optional: Add a delay between each message display (e.g., 3 seconds)
	    HAL_Delay(3000);  // Assuming delay_ms() is defined to create a 3-second delay
	}
}

void LCD_DisplayAlertScreen2(void)
{
	LCD_DisplayImage(ERROR_SCREEN_IMAGE_INDEX);
	for(uint8_t ui8AlertMessage = 0; ui8AlertMessage < TOTAL_ALERT_MESSAGES; ui8AlertMessage++)
	{
		LCD_DisplayNumber(F_MODE, ALERT_NON_CLEARABLE_ERROR_CODE_X, ALERT_NON_CLEARABLE_ERROR_CODE_Y, ui8AlertMessage, LCD_12X24_FONT_INDEX, BLACK, WHITE);
		HAL_Delay(3000);  // Assuming delay_ms is a function that causes a delay in milliseconds
	}
//	LCD_DisplayNumber(FB_MODE, ALERT_NON_CLEARABLE_ERROR_CODE_X, ALERT_NON_CLEARABLE_ERROR_CODE_Y, ui8AlertMessage, LCD_24X48_FONT_INDEX, BLACK, CYAN);
}

void LCD_DisplayBatteryCharge(uint8_t ui8BatteryCharge) {
    char image_label_name[16], image_name[16],label_name[16];

    for (uint8_t widget_index = 1; widget_index <= 60; widget_index++) {
        snprintf(image_label_name, sizeof(image_label_name), "BATTERY%u", widget_index);
        snprintf(label_name,sizeof(label_name),"BATTLABEL%u", widget_index);

        if ((ui8BatteryCharge >= 0) && (ui8BatteryCharge <= 20)) {
            snprintf(image_name, sizeof(image_name), "bat1");
        } else if ((ui8BatteryCharge >= 21) && (ui8BatteryCharge <= 40)) {
            snprintf(image_name, sizeof(image_name), "bat2");
        } else if ((ui8BatteryCharge >= 41) && (ui8BatteryCharge <= 60)) {
            snprintf(image_name, sizeof(image_name), "bat3");
        } else if ((ui8BatteryCharge >= 61) && (ui8BatteryCharge <= 80)) {
            snprintf(image_name, sizeof(image_name), "bat4");
        } else {
            snprintf(image_name, sizeof(image_name), "bat5");
        }

        // Update the battery icon
        set_image(image_label_name, image_name);
        char value_str[8]; // Buffer to store the number as a string
        LCD_IntToString(value_str, ui8BatteryCharge, TRUE);
//        snprintf(value_str, sizeof(value_str), "%u", ui8BatteryCharge); // Convert number to string
        set_text("label", label_name, value_str);
    }
}



