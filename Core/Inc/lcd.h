
#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "stm32l1xx_hal.h"
#include <stdint.h>

/* Modular defines for Stone HMI JSON Commands */

// Common Start and End Markers for Stone HMI Commands
#define CMD_PREFIX 								"ST<{\"cmd_code\":\""
#define CMD_SUFFIX_TYPE 						"\",\"type\":\""
#define CMD_SUFFIX_WIDGET 						"\",\"widget\":\""
#define CMD_SUFFIX_TEXT 						"\",\"text\":\""
#define CMD_SUFFIX_VISIBLE 						"\",\"visible\":"
#define CMD_SUFFIX_END 							"\"}>ET"


// Specific Command Codes
#define CMD_CODE_SET_TEXT "set_text"
#define CMD_CODE_OPEN_WINDOW "open_win"
#define CMD_CODE_SET_VISIBLE "set_visible"

// Widget Types
#define WIDGET_TYPE_WINDOW "window"
#define WIDGET_TYPE_WIDGET "widget"


//#define CMD_PREFIX "ST<{\"cmd_code\":\"open_win\",\"type\":\"window\",\"widget\":\""
//#define CMD_SUFFIX "\"}>ET"

// ===================== Coordinate-to-Label Mapping =====================

// Structure for coordinate-to-label mapping
typedef struct {
    uint16_t x;
    uint16_t y;
    const char *label_name;
} CoordinateLabelMap;

// Predefined coordinate-to-label mapping
extern const CoordinateLabelMap label_mapping[];

// Retrieve label name from coordinates
const char* get_label_name(uint16_t x, uint16_t y);


// ===================== Index-to-Window Mapping =====================

// Structure for index-to-window mapping
typedef struct {
    uint16_t index;
    const char *window_name;
} IndexWindowMap;

// Predefined index-to-window mapping
extern const IndexWindowMap index_mapping[];

// Retrieve window name from index
const char* get_window_name_from_index(uint16_t index);


// Image Index Definitions with New Index Values (Old Index Value Commented)
#define NEW_PATIENT_IMAGE_INDEX        				1  // Old: 11
#define CONFIRM_NEW_PATIENT_IMAGE_INDEX        		2  // Old: 12
#define ERASING_OLD_DATA_IMAGE_INDEX        			3  // Old: 13
#define CLAMP_TUBES_IMAGE_INDEX_1        				4  // Old: 14
#define CLAMP_TUBES_IMAGE_INDEX_2        				5  // Old: 12
#define ALERT_SCREEN_IMAGE_INDEX        				6  // Old: 31
#define ERROR_SCREEN_IMAGE_INDEX        				7  // Old: 31
#define SETTINGS_SYS_1_IMAGE_INDEX        			8  // Old: 33
#define SETTINGS_SYS_2_IMAGE_INDEX        			9  // Old: 34
#define SETTINGS_SHUTDOWN_CONFIRM_IMAGE_INDEX        	10 // Old: 12
#define SHUTDOWN_IMAGE_INDEX        				11 // Old: 13
#define STAND_BY_IMAGE_INDEX        							12 // Old: 13
#define DATA_RETRIEVE_IMAGE_INDEX        						13 // Old: 6
#define RECALIBRATE_SENSOR_IMAGE_INDEX        					14 // Old: 6
#define POWER_ON_SELF_TEST_IMAGE_INDEX        					15 // Old: 10
//#define REMOVE_SENSOR_TUBE_SCREEN_IMAGE_INDEX        	16 // Old: 6
//#define SELF_TEST_SCREEN_IMAGE_INDEX        			17 // Old: 6
//#define CONNECT_LUMEN_SCREEN_IMAGE_INDEX        		18 // Old: 9
//#define START_SUCTION_SCREEN_IMAGE_INDEX        		19 // Old: 8
//#define SUCTION_SCREEN_IMAGE_INDEX        			20 // Old: 13
#define SAVE_SUCTION_SETTINGS_SCREEN_IMAGE_INDEX        		21 // Old: 12
#define SUCTION_SETTINGS_SCREEN_IMAGE_INDEX        				22 // Old: 12
#define CALIBRATION_SETTINGS_SCREEN_IMAGE_INDEX      			23 // Old: 11
#define PAUSE_MAIN_SCREEN_IMAGE_INDEX        					24 // Old: 9
#define PAUSE_CONNECTION_SCREEN_IMAGE_INDEX         			25 // Old: 11
#define JAR_CONNECTION_IMAGE_INDEX        						26 // Old: 6
#define REPLACE_LAVAGE_FLUID_IMAGE_INDEX        		27 // Old: 6
#define SENSOR_PLACEMENT_IMAGE_INDEX        			28 // Old: 6
#define DETACH_PATIENT_IMAGE_INDEX        			29 // Old: 15
#define DETACH_PATIENT_CONFIRM_IMAGE_INDEX          	30 // Old: 17
#define DETACH_PATIENT_STEPS_IMAGE_INDEX        		31 // Old: 6
#define SYSTEM_SHUT_IMAGE_INDEX        				32 // Old: 6
#define PLACE_SENSOR_TUBES_IMAGE_INDEX        		33 // Old: 6
#define CONNECT_SENSOR_JAR_TUBES_IMAGE_INDEX        	34 // Old: 6
#define EMERGENCY_SUCTION_IMAGE_INDEX        		35 // Old: 5
#define WELCOME_SCREEN_IMAGE_INDEX        			36 // Old: 6
#define UNCLAMP_TUBES_IMAGE_INDEX        			37 // Old: 16
#define PARAMETER_SCREEN_IMAGE_INDEX        		38 // Old: 17
#define SAVE_CONFIRMATION_IMAGE_INDEX        		39 // Old: 17
#define BEGIN_SUCTION_IMAGE_INDEX        			40 // Old: 19
#define INSIDE_ET_TUBE_BRUSHING_SUCTION_IMAGE_INDEX	41 // Old: 21
#define ORO_SUCTION_IMAGE_INDEX        			42 // Old: 23
#define SUB_SUCTION_IMAGE_INDEX        			43 // Old: 25
#define IDLE_SCREEN_IMAGE_INDEX        			44 // Old: 26
#define LAVAGE_SPRINKLING_IMAGE_INDEX        		45 // Old: 36
#define LAVAGE_SUCTION_IMAGE_INDEX        			46 // Old: 28
#define PAUSE_SCREEN_IMAGE_INDEX        			47 // Old: 29
#define PAUSE_AND_ALERT_SCREEN_IMAGE_INDEX        		48 // Old: 32
#define LEAKAGE_CHECK_AFTER_PAUSE_IMAGE_INDEX       	49 // Old: 30
#define SETTINGS_SCREEN_1_IMAGE_INDEX        				50 // Old: 12
#define SETTINGS_SCREEN_2_IMAGE_INDEX        				51 // Old: 12
#define BACK_CONFIRMATION_IMAGE_INDEX        		52 // Old: 35
#define PAUSE_LEAKAGE_CHECK_IMAGE_INDEX        		53 // Old: 13
#define DETECTING_SENSOR_IMAGE_INDEX        		54 // Old: 13
#define SETTINGS_SAVE_CONFIRMATION_IMAGE_INDEX      	55 // Old: 12
#define SETTINGS_SUCTION_OPTION_NOTE_IMAGE_INDEX    	56 // Old: 12
#define SETTINGS_EXTENDED_LOG_IMAGE_INDEX           	57 // Old: 0
#define SAVE_SETTINGS_AND_BEGIN_SUCTION_IMAGE_INDEX 	58 // Old: 37
#define ALERT_LOWBAT_SCREEN_IMAGE_INDEX        		59 // Old: 31


//Error definitions
#define ALERT_ORO_BLOOD_DETECTED						0
#define ALERT_SUBGLOTTIC_BLOOD_DETECTED					1
#define ALERT_ORO_PORT_BLOCK_DETECTED					2
#define ALERT_SUBGLOTTIC_PORT_BLOCK_DETECTED			3
#define ALERT_ORO_TUBE_REMOVAL_DETECTED					4
#define ALERT_SUBGLOTTIC_TUBE_REMOVAL_DETECTED			5
#define ALERT_ORO_NO_SECRETIONS_DETECTED				6
#define ALERT_SUBGLOTTIC_NO_SECRETIONS_DETECTED			7
#define ALERT_LEAKAGE_DETECTED							8
#define ALERT_CLAMP_NOT_REMOVED							9
#define ALERT_SENSOR_CALIBRATION_REQUIRED 				10
#define ALERT_SENSOR_CARD_NOT_RESPONDING				11
#define ALERT_REMOVE_TUBES								12
#define ALERT_SENSOR_CARD_CALIBRATION_FAIL				13
#define ALERT_CHECK_SUCTION_SOURCE						14

#define TOTAL_ALERT_MESSAGES 							15


//new defines for icons
#define BOX_YES_ICON_INDEX										1
#define CLEAR_BOX_YES_ICON_INDEX								0
#define BOX_NO_ICON_INDEX										1
#define CLEAR_BOX_NO_ICON_INDEX									0
#define DISPLAY_ICON											1
#define CLEAR_ICON												0

#define BATTERY_0_TO_20_ICON_INDEX_INACTIVE    					0  // Old: 0
#define BATTERY_21_TO_40_ICON_INDEX_INACTIVE   					0  // Old: 1
#define BATTERY_41_TO_60_ICON_INDEX_INACTIVE   					0  // Old: 2
#define BATTERY_61_TO_80_ICON_INDEX_INACTIVE   					0  // Old: 3
#define BATTERY_81_TO_100_ICON_INDEX_INACTIVE  					0  // Old: 4

#define BATTERY_0_TO_20_ICON_INDEX_ACTIVE      					1  // Old: 7
#define BATTERY_21_TO_40_ICON_INDEX_ACTIVE     					1  // Old: 8
#define BATTERY_41_TO_60_ICON_INDEX_ACTIVE     					1  // Old: 9
#define BATTERY_61_TO_80_ICON_INDEX_ACTIVE     					1  // Old: 10
#define BATTERY_81_TO_100_ICON_INDEX_ACTIVE    					1  // Old: 11

#define ROW_BOX_ICON_INDEX										1
#define ROW_CLEAR_ICON_INDEX									0//34



#define UNATTENDED_ALERT_ICON_INDEX								35
#define SELF_TEST_12_ICON_INDEX									14
#define SELF_TEST_24_ICON_INDEX									15
#define SELF_TEST_36_ICON_INDEX									16
#define SELF_TEST_48_ICON_INDEX									17
#define SELF_TEST_60_ICON_INDEX									18
#define SELF_TEST_72_ICON_INDEX									19
#define SELF_TEST_84_ICON_INDEX									20
#define SELF_TEST_100_ICON_INDEX								21
//#define BATTERY_0_TO_20_ICON_INDEX_INACTIVE						0
//#define BATTERY_21_TO_40_ICON_INDEX_INACTIVE					1
//#define BATTERY_41_TO_60_ICON_INDEX_INACTIVE					2
//#define BATTERY_61_TO_80_ICON_INDEX_INACTIVE					3
//#define BATTERY_81_TO_100_ICON_INDEX_INACTIVE					4
//#define BATTERY_0_TO_20_ICON_INDEX_ACTIVE						7
//#define BATTERY_21_TO_40_ICON_INDEX_ACTIVE						8
//#define BATTERY_41_TO_60_ICON_INDEX_ACTIVE						9
//#define BATTERY_61_TO_80_ICON_INDEX_ACTIVE						10
//#define BATTERY_81_TO_100_ICON_INDEX_ACTIVE						11
#define BUZZER_MUTE_ICON_INDEX 									5
#define BUZZER_ICON_INDEX 										6
#define LEAKAGE_TEST_ICON_9										16
#define LEAKAGE_TEST_ICON_8										17
#define LEAKAGE_TEST_ICON_7										18
#define LEAKAGE_TEST_ICON_6										19
#define LEAKAGE_TEST_ICON_5										20
#define LEAKAGE_TEST_ICON_4										21
#define LEAKAGE_TEST_ICON_3										22
#define LEAKAGE_TEST_ICON_2										23
#define LEAKAGE_TEST_ICON_1										24

#define ROW_BOX_ICON_LARGE_INDEX								33
#define ROW_CLEAR_ICON_LARGE_INDEX								34
#define LEFT_ICON_INDEX											14
#define RIGHT_ICON_INDEX										15
#define LEFT_FADED_ICON_INDEX									36
#define RIGHT_FADED_ICON_INDEX									37
#define LEFT_ICON_ERASE_INDEX									38
#define RIGHT_ICON_ERASE_INDEX									39
#define UP_ICON_INDEX											27
#define DOWN_ICON_INDEX											26
#define BOX_EMERGENCY_SUCTION_ICON_INDEX						30
#define CLEAR_BOX_EMERGENCY_SUCTION_ICON_INDEX					31

// X and Y coordinates
#define ROW_1_ICON_X                                            1              // 34
#define ROW_1_ICON_Y                                            1              // 85
#define ROW_2_ICON_X                                            2              // 34
#define ROW_2_ICON_Y                                            2              // 116
#define ROW_3_ICON_X                                            3              // 34
#define ROW_3_ICON_Y                                            3              // 144
#define ROW_4_ICON_X                                            4              // 34
#define ROW_4_ICON_Y                                            4              // 172
#define ROW_5_ICON_X                                            5              // 34
#define ROW_5_ICON_Y                                            5              // 200
#define ROW_6_ICON_X                                            6              // 34
#define ROW_6_ICON_Y                                            6              // 85
#define ROW_7_ICON_X                                            7              // 34
#define ROW_7_ICON_Y                                            7              // 116
#define ROW_8_ICON_X                                            8              // 34
#define ROW_8_ICON_Y                                            8              // 144
#define ROW_9_ICON_X                                            9              // 34
#define ROW_9_ICON_Y                                            9              // 172
#define ROW_10_ICON_X                                           10             // 34
#define ROW_10_ICON_Y                                           10             // 200
#define ROW_1_LEFT_ICON_X                                       11             // 278
#define ROW_1_LEFT_ICON_Y                                       11             // 93
#define ROW_1_RIGHT_ICON_X                                      12             // 329
#define ROW_1_RIGHT_ICON_Y                                      12             // 93
#define ROW_2_LEFT_ICON_X                                       13             // 278
#define ROW_2_LEFT_ICON_Y                                       13             // 121
#define ROW_2_RIGHT_ICON_X                                      14             // 329
#define ROW_2_RIGHT_ICON_Y                                      14             // 121
#define ROW_3_LEFT_ICON_X                                       15             // 278
#define ROW_3_LEFT_ICON_Y                                       15             // 149
#define ROW_3_RIGHT_ICON_X                                      16             // 329
#define ROW_3_RIGHT_ICON_Y                                      16             // 149
#define ROW_4_LEFT_ICON_X                                       17             // 278
#define ROW_4_LEFT_ICON_Y                                       17             // 177
#define ROW_4_RIGHT_ICON_X                                      18             // 329
#define ROW_4_RIGHT_ICON_Y                                      18             // 177
#define ROW_5_LEFT_ICON_X                                       19             // 278
#define ROW_5_LEFT_ICON_Y                                       19             // 205
#define ROW_5_RIGHT_ICON_X                                      20             // 329
#define ROW_5_RIGHT_ICON_Y                                      20             // 205
#define ROW_6_LEFT_ICON_X                                       21             // 278
#define ROW_6_LEFT_ICON_Y                                       21             // 93
#define ROW_6_RIGHT_ICON_X                                      22             // 329
#define ROW_6_RIGHT_ICON_Y                                      22             // 93
#define ROW_7_LEFT_ICON_X                                       23             // 278
#define ROW_7_LEFT_ICON_Y                                       23             // 121
#define ROW_7_RIGHT_ICON_X                                      24             // 329
#define ROW_7_RIGHT_ICON_Y                                      24             // 121
#define ROW_8_LEFT_ICON_X                                       25             // 278
#define ROW_8_LEFT_ICON_Y                                       25             // 149
#define ROW_8_RIGHT_ICON_X                                      26             // 329
#define ROW_8_RIGHT_ICON_Y                                      26             // 149
#define UP_ICON_X                                               27             // 40
#define UP_ICON_Y                                               27             // 80
#define DOWN_ICON_X                                             28             // 40
#define DOWN_ICON_Y                                             28             // 210
#define BUZZER_ICON_X                                           29             // 6
#define BUZZER_ICON_Y                                           29             // 2
#define OPTION_TEXT_X                                         30             // 395
#define OPTION_TEXT_Y                                         30             // 244
#define BACK_TEXT_X                                           31             // 40
#define BACK_TEXT_Y                                           31             // 244
#define PAUSE_TEXT_X                                          32             // 212
#define PAUSE_TEXT_Y                                          32             // 196
#define ALERT_SUCTION_SETTINGS_TEXT_1_X                       33             // 166
#define ALERT_SUCTION_SETTINGS_TEXT_1_Y                       33             // 30
#define ALERT_SUCTION_SETTINGS_TEXT_2_X                       34             // 100
#define ALERT_SUCTION_SETTINGS_TEXT_2_Y                       34             // 100
#define ALERT_SUCTION_SETTINGS_TEXT_3_X                       35             // 140
#define ALERT_SUCTION_SETTINGS_TEXT_3_Y                       35             // 130
#define ALERT_SUCTION_SETTINGS_TEXT_4_X                       36             // 143
#define ALERT_SUCTION_SETTINGS_TEXT_4_Y                       36             // 198
#define CONFIRM_NEW_PATIENT_TEXT1_X                           37             // 134
#define CONFIRM_NEW_PATIENT_TEXT1_Y                           37             // 100
#define CONFIRM_NEW_PATIENT_TEXT2_X                           38             // 80
#define CONFIRM_NEW_PATIENT_TEXT2_Y                           38             // 130
#define CONFIRM_NEW_PATIENT_TEXT3_X                           39             // 148
#define CONFIRM_NEW_PATIENT_TEXT3_Y                           39             // 198
#define ERASING_FLASH_TEXT1_X                                 40             // 64
#define ERASING_FLASH_TEXT1_Y                                 40             // 100
#define ERASING_FLASH_TEXT2_X                                 41             // 156
#define ERASING_FLASH_TEXT2_Y                                 41             // 130
#define START_SUCTION_TEXT_1_X                                42             // 162
#define START_SUCTION_TEXT_1_Y                                42             // 48
#define START_SUCTION_TEXT_2_X                                43             // 118
#define START_SUCTION_TEXT_2_Y                                43             // 196
#define IDLE_SCREEN_TEXT_1_X                                  44             // 60
#define IDLE_SCREEN_TEXT_1_Y                                  44             // 95
#define IDLE_SCREEN_TEXT_2_X                                  45             // 60
#define IDLE_SCREEN_TEXT_2_Y                                  45             // 155
#define IDLE_SCREEN_TEXT_3_X                                  46             // 305
#define IDLE_SCREEN_TEXT_3_Y                                  46             // 102
#define IDLE_SCREEN_TEXT_4_X                                  47             // 351
#define IDLE_SCREEN_TEXT_4_Y                                  47             // 102
#define IDLE_SCREEN_TEXT_5_X                                  48             // 399
#define IDLE_SCREEN_TEXT_5_Y                                  48             // 102
#define IDLE_SCREEN_TEXT_6_X                                  49             // 305
#define IDLE_SCREEN_TEXT_6_Y                                  49             // 162
#define IDLE_SCREEN_TEXT_7_X                                  50             // 351
#define IDLE_SCREEN_TEXT_7_Y                                  50             // 162
#define IDLE_SCREEN_TEXT_8_X                                  51             // 399
#define IDLE_SCREEN_TEXT_8_Y                                  51             // 162
#define IDLE_SCREEN_TEXT_9_X                                  52             // 263
#define IDLE_SCREEN_TEXT_9_Y                                  52             // 161
#define IDLE_SCREEN_NUM_1_X                                   53             // 270
#define IDLE_SCREEN_NUM_1_Y                                   53             // 90
#define IDLE_SCREEN_NUM_2_X                                   54             // 270
#define IDLE_SCREEN_NUM_2_Y                                   54             // 150
#define SETTING_PRESSURE_TEXT_1_X                             55             // 107
#define SETTING_PRESSURE_TEXT_1_Y                             55             // 90
#define SETTING_PRESSURE_TEXT_2_X                             56             // 310
#define SETTING_PRESSURE_TEXT_2_Y                             56             // 146
#define SETTING_PRESSURE_TEXT_3_X                             57             // 200
#define SETTING_PRESSURE_TEXT_3_Y                             57             // 126
#define CURRENT_SETTING_PRESSURE_VAL_X                        58             // 123
#define CURRENT_SETTING_PRESSURE_VAL_Y                        58             // 126
#define SUCTION_TARGET_PRESSURE_VAL_X                         59             // 233
#define SUCTION_TARGET_PRESSURE_VAL_Y                         59             // 126
#define SPRINKILING_TEXT_1_X                                  60             // 114
#define SPRINKILING_TEXT_1_Y                                  60             // 100
#define SPRINKILING_TEXT_2_X                              61             // 170
#define SPRINKILING_TEXT_2_Y                              61             // 130
#define SUCTION_TEXT_1_X                                  62             // 144
#define SUCTION_TEXT_1_Y                                  62             // 90
#define SUCTION_TEXT_2_X                                  63             // 254
#define SUCTION_TEXT_2_Y                                  63             // 146
#define SUCTION_PRESSURE_VAL_X                            64             // 168
#define SUCTION_PRESSURE_VAL_Y                            64             // 126
#define ORAL_SUCTION_TEXT_X                               65             // 188
#define ORAL_SUCTION_TEXT_Y                               65             // 44
#define ORO_SUCTION_TEXT_X                                66             // 134
#define ORO_SUCTION_TEXT_Y                                66             // 44
#define SUBGLOTTIC_SUCTION_TEXT_X                         67             // 152
#define SUBGLOTTIC_SUCTION_TEXT_Y                         67             // 44
#define INSIDE_ET_TUBE_SUCTION_TEXT_X                     68             // 152
#define INSIDE_ET_TUBE_SUCTION_TEXT_Y                     68             // 44
#define BRUSHING_SUCTION_TEXT_X                           69             // 188
#define BRUSHING_SUCTION_TEXT_Y                           69             // 44
#define ORAL_PORT_BLOCK_TEXT_X                            70             // 150
#define ORAL_PORT_BLOCK_TEXT_Y                            70             // 44
#define ORO_PORT_BLOCK_TEXT_X                             71             // 96
#define ORO_PORT_BLOCK_TEXT_Y                             71             // 44
#define SUBGLOTTIC_PORT_BLOCK_TEXT_X                      72             // 114
#define SUBGLOTTIC_PORT_BLOCK_TEXT_Y                      72             // 44
#define ORO_MANDATORY_SUCTION_X                           73             // 22
#define ORO_MANDATORY_SUCTION_Y                           73             // 44
#define LAVAGE_TEXT_X                                     74             // 196
#define LAVAGE_TEXT_Y                                     74             // 44
#define POWER_ON_TEST_X                                   75             // 50
#define POWER_ON_TEST_Y                                   75             // 190
#define SETTINGS_SUCTION_ORO_VAL_X                        76             // 298
#define SETTINGS_SUCTION_ORO_VAL_Y                        76             // 93
#define SETTINGS_SUCTION_SUB_VAL_X                        77             // 298
#define SETTINGS_SUCTION_SUB_VAL_Y                        77             // 93
#define SETTINGS_LAVAGE_VAL_X                             78             // 298
#define SETTINGS_LAVAGE_VAL_Y                             78             // 93
#define SETTINGS_ORO_PORT_BLOCK_VAL_X                     79             // 298
#define SETTINGS_ORO_PORT_BLOCK_VAL_Y                     79             // 149
#define SETTINGS_SUB_PORT_BLOCK_VAL_X                     80             // 298
#define SETTINGS_SUB_PORT_BLOCK_VAL_Y                     80             // 149
#define DETACH_PATIENT_CONFIRM_TEXT_1_X                   81             // 162
#define DETACH_PATIENT_CONFIRM_TEXT_1_Y                   81             // 124
#define DETACH_PATIENT_STEPS_TEXT_1_X                     82             // 90
#define DETACH_PATIENT_STEPS_TEXT_1_Y                     82             // 48
#define DETACH_PATIENT_STEPS_TEXT_2_X                     83             // 90
#define DETACH_PATIENT_STEPS_TEXT_2_Y                     83             // 84
#define DETACH_PATIENT_STEPS_TEXT_3_X                     84             // 90
#define DETACH_PATIENT_STEPS_TEXT_3_Y                     84             // 112
#define DETACH_PATIENT_STEPS_TEXT_4_X                     85             // 90
#define DETACH_PATIENT_STEPS_TEXT_4_Y                     85             // 140
#define DETACH_PATIENT_STEPS_TEXT_5_X                     86             // 90
#define DETACH_PATIENT_STEPS_TEXT_5_Y                     86             // 168
#define DETACH_PATIENT_STEPS_TEXT_6_X                     87             // 90
#define DETACH_PATIENT_STEPS_TEXT_6_Y                     87             // 196
#define STAND_BY_TEXT_1_X                                 88             // 90
#define STAND_BY_TEXT_1_Y                                 88             // 58
#define STAND_BY_TEXT_2_X                                 89             // 80
#define STAND_BY_TEXT_2_Y                                 89             // 76
#define STAND_BY_TEXT_3_X                                 90             // 90
#define STAND_BY_TEXT_3_Y                                 90             // 121
#define STAND_BY_TEXT_4_X                                          91 // 90
#define STAND_BY_TEXT_4_Y                                          91 // 149
#define STAND_BY_TEXT_5_X                                          92 // 280
#define STAND_BY_TEXT_5_Y                                          92 // 58
#define STAND_BY_TEXT_6_X                                          93 // 314
#define STAND_BY_TEXT_6_Y                                          93 // 70
#define STAND_BY_TEXT_7_X                                          94 // 361
#define STAND_BY_TEXT_7_Y                                          94 // 70
#define STAND_BY_TEXT_8_X                                          95 // 408
#define STAND_BY_TEXT_8_Y                                          95 // 70
#define STAND_BY_TEXT_9_X                                          96 // 60
#define STAND_BY_TEXT_9_Y                                          96 // 198
#define SYSTEM_SHUTDOWN_TEXT_1_X                                   97 // 95
#define SYSTEM_SHUTDOWN_TEXT_1_Y                                   97 // 110
#define SYSTEM_SHUTDOWN_TEXT_2_X                                   98 // 130
#define SYSTEM_SHUTDOWN_TEXT_2_Y                                   98 // 198
#define EMERGENCY_SUCTION_TEXT_1_X                                 99 // 50
#define EMERGENCY_SUCTION_TEXT_1_Y                                 99 // 48
#define EMERGENCY_SUCTION_TEXT_2_X                                 100 // 50
#define EMERGENCY_SUCTION_TEXT_2_Y                                 100 // 93
#define EMERGENCY_SUCTION_TEXT_3_X                                 101 // 50
#define EMERGENCY_SUCTION_TEXT_3_Y                                 101 // 121
#define EMERGENCY_SUCTION_TEXT_4_X                                 102 // 50
#define EMERGENCY_SUCTION_TEXT_4_Y                                 102 // 149
#define EMERGENCY_SUCTION_TEXT_5_X                                 103 // 50
#define EMERGENCY_SUCTION_TEXT_5_Y                                 103 // 177
#define EMERGENCY_SUCTION_TEXT_6_X                                 104 // 50
#define EMERGENCY_SUCTION_TEXT_6_Y                                 104 // 213
#define EMERGENCY_SUCTION_BOX_SUCTION_ICON_X                       105 // 34
#define EMERGENCY_SUCTION_BOX_SUCTION_ICON_Y                       105 // 86
#define EMERGENCY_SUCTION_BOX_LAVAGE_ICON_X                        106 // 34
#define EMERGENCY_SUCTION_BOX_LAVAGE_ICON_Y                        106 // 114
#define EMERGENCY_INSIDE_ET_TUBE_BOX_ICON_X                        107 // 34
#define EMERGENCY_INSIDE_ET_TUBE_BOX_ICON_Y                        107 // 142
#define EMERGENCY_BRUSHING_BOX_ICON_X                              108 // 34
#define EMERGENCY_BRUSHING_BOX_ICON_Y                              108 // 170
#define DETECTING_SENSOR_TEXT1_X                                   109 // 120
#define DETECTING_SENSOR_TEXT1_Y                                   109 // 100
#define DETECTING_SENSOR_TEXT2_X                                   110 // 156
#define DETECTING_SENSOR_TEXT2_Y                                   110 // 130
#define RECALIBRATE_SENSOR_TEXT1_X                                 111 // 90
#define RECALIBRATE_SENSOR_TEXT1_Y                                 111 // 100
#define RECALIBRATE_SENSOR_TEXT2_X                                 112 // 156
#define RECALIBRATE_SENSOR_TEXT2_Y                                 112 // 130
#define ENTER_EXTENDED_LOG_ACCESS_TEXT1_X                           113 // 140
#define ENTER_EXTENDED_LOG_ACCESS_TEXT1_Y                           113 // 90
#define ENTER_EXTENDED_LOG_ACCESS_TEXT2_X                           114 // 174
#define ENTER_EXTENDED_LOG_ACCESS_TEXT2_Y                           114 // 120
#define ENTER_EXTENDED_LOG_ACCESS_TEXT3_X                           115 // 100
#define ENTER_EXTENDED_LOG_ACCESS_TEXT3_Y                           115 // 198
#define UNATTENDED_ALERT_ICON_X                                    116 // 198
#define UNATTENDED_ALERT_ICON_Y                                    116 // 244
#define CLAMP_TUBE_TEXT1_X                                         117 // 162
#define CLAMP_TUBE_TEXT1_Y                                         117 // 48
#define CLAMP_TUBE_TEXT2_X                                         118 // 90
#define CLAMP_TUBE_TEXT2_Y                                         118 // 110
#define CLAMP_TUBE_TEXT3_X                                         119 // 120
#define CLAMP_TUBE_TEXT3_Y                                         119 // 130
#define CLAMP_TUBE_TEXT4_X                                         120 // 148
#define CLAMP_TUBE_TEXT4_Y                                         120 // 198
#define CLAMP_TUBE_TEXT5_X                                         121 // 80
#define CLAMP_TUBE_TEXT5_Y                                         121 // 198
#define VERIFY_NEW_PATIENT_BOX_YES_ICON_X                          122 // 182
#define VERIFY_NEW_PATIENT_BOX_YES_ICON_Y                          122 // 94
#define VERIFY_NEW_PATIENT_YES_X                                    123 // 209
#define VERIFY_NEW_PATIENT_YES_Y                                    123 // 96
#define VERIFY_NEW_PATIENT_NO_X                                     124 // 215
#define VERIFY_NEW_PATIENT_NO_Y                                     124 // 139
#define VERIFY_NEW_PATIENT_TEXT1_X                                  125 // 168
#define VERIFY_NEW_PATIENT_TEXT1_Y                                  125 // 48
#define VERIFY_NEW_PATIENT_TEXT2_X                                  126 // 120
#define VERIFY_NEW_PATIENT_TEXT2_Y                                  126 // 198
#define VERIFY_NEW_PATIENT_UP_ICON_X                                127 // 284
#define VERIFY_NEW_PATIENT_UP_ICON_Y                                127 // 98
#define VERIFY_NEW_PATIENT_DOWN_ICON_X                              128 // 284
#define VERIFY_NEW_PATIENT_DOWN_ICON_Y                              128 // 144
//#define VERIFY_NEW_PATIENT_BOX_YES_ICON_X                          129 // 182
//#define VERIFY_NEW_PATIENT_BOX_YES_ICON_Y                          129 // 94
#define VERIFY_NEW_PATIENT_BOX_NO_ICON_X                           130 // 182
#define VERIFY_NEW_PATIENT_BOX_NO_ICON_Y                           130 // 137
//#define VERIFY_NEW_PATIENT_YES_X                                    131 // 209
//#define VERIFY_NEW_PATIENT_YES_Y                                    131 // 96
//#define VERIFY_NEW_PATIENT_NO_X                                     132 // 215
//#define VERIFY_NEW_PATIENT_NO_Y                                     132 // 139
#define VERIFY_PAUSE_LEAKAGE_CHECK_BOX_YES_ICON_X                  133 // 182
#define VERIFY_PAUSE_LEAKAGE_CHECK_BOX_YES_ICON_Y                  133 // 94
#define VERIFY_PAUSE_LEAKAGE_CHECK_YES_X                            134 // 209
#define VERIFY_PAUSE_LEAKAGE_CHECK_YES_Y                                134 // 96
#define VERIFY_PAUSE_LEAKAGE_CHECK_NO_X                             135 // 215
#define VERIFY_PAUSE_LEAKAGE_CHECK_NO_Y                             135 // 139
#define VERIFY_PAUSE_LEAKAGE_CHECK_TEXT1_X                          136 // 108
#define VERIFY_PAUSE_LEAKAGE_CHECK_TEXT1_Y                          136 // 48
#define VERIFY_PAUSE_LEAKAGE_CHECK_TEXT2_X                          137 // 130
#define VERIFY_PAUSE_LEAKAGE_CHECK_TEXT2_Y                          137 // 198
#define VERIFY_PAUSE_LEAKAGE_CHECK_UP_ICON_X                        138 // 284
#define VERIFY_PAUSE_LEAKAGE_CHECK_UP_ICON_Y                        138 // 98
#define VERIFY_PAUSE_LEAKAGE_CHECK_DOWN_ICON_X                      139 // 284
#define VERIFY_PAUSE_LEAKAGE_CHECK_DOWN_ICON_Y                      139 // 144
//#define VERIFY_PAUSE_LEAKAGE_CHECK_BOX_YES_ICON_X                  140 // 182
//#define VERIFY_PAUSE_LEAKAGE_CHECK_BOX_YES_ICON_Y                  140 // 94
#define VERIFY_PAUSE_LEAKAGE_CHECK_BOX_NO_ICON_X                        141 // 182
#define VERIFY_PAUSE_LEAKAGE_CHECK_BOX_NO_ICON_Y                        141 // 137

//#define VERIFY_PAUSE_LEAKAGE_CHECK_YES_X                               142 // 209
//#define VERIFY_PAUSE_LEAKAGE_CHECK_YES_Y                               142 // 96

//#define VERIFY_PAUSE_LEAKAGE_CHECK_NO_X                                143 // 215
//#define VERIFY_PAUSE_LEAKAGE_CHECK_NO_Y                                143 // 139

#define RECTANGLE_BOX_ICON_X                                           144 // 65
#define RECTANGLE_BOX_ICON_Y                                           144 // 80

#define BATTERY_TEXT_X                                                 145 // 410
#define BATTERY_TEXT_Y                                                 145 // 4

#define BATTERY_ICON_X                                                 146 // 450
#define BATTERY_ICON_Y                                                 146 // 5

#define LEAKAGE_TEST_ICON_X                                            147 // 217
#define LEAKAGE_TEST_ICON_Y                                            147 // 92

#define MANDATORY_SUCTION_TEXT_X                                       148 // 272
#define MANDATORY_SUCTION_TEXT_Y                                       148 // 244

#define START_TILE_TEXT_X                                              149 // 157
#define START_TILE_TEXT_Y                                              149 // 244

#define SELF_TEST_ICON_X                                               150 // 217
#define SELF_TEST_ICON_Y                                               150 // 92

#define SELF_TEST_TEXT_1_X                                             151 // 162
#define SELF_TEST_TEXT_1_Y                                             151 // 48

#define SELF_TEST_TEXT_2_X                                             152 // 214
#define SELF_TEST_TEXT_2_Y                                             152 // 150

#define SELF_TEST_TEXT_3_X                                             153 // 254
#define SELF_TEST_TEXT_3_Y                                             153 // 150

#define SELF_TEST_TEXT_4_X                                             154 // 110
#define SELF_TEST_TEXT_4_Y                                             154 // 189

#define SELF_TEST_TEXT_5_X                                             155 // 60
#define SELF_TEST_TEXT_5_Y                                             155 // 198

#define PORT_SETTINGS_CONFIRM_TEXT_R1C1_X                             156 // 18
#define PORT_SETTINGS_CONFIRM_TEXT_R1C1_Y                             156 // 66

#define PORT_SETTINGS_CONFIRM_TEXT_R2C1_X                             157 // 23
#define PORT_SETTINGS_CONFIRM_TEXT_R2C1_Y                             157 // 96

#define PORT_SETTINGS_CONFIRM_TEXT_R3C1_X                             158 // 23
#define PORT_SETTINGS_CONFIRM_TEXT_R3C1_Y                             158 // 126

#define PORT_SETTINGS_CONFIRM_TEXT_R4C1_X                             159 // 23
#define PORT_SETTINGS_CONFIRM_TEXT_R4C1_Y                             159 // 156

#define PORT_SETTINGS_CONFIRM_TEXT_R5C1_X                             160 // 23
#define PORT_SETTINGS_CONFIRM_TEXT_R5C1_Y                             160 // 186

#define PORT_SETTINGS_CONFIRM_TEXT_1_X                                 161 // 105
#define PORT_SETTINGS_CONFIRM_TEXT_1_Y                                 161 // 35

#define PORT_SETTINGS_CONFIRM_TEXT_2_X                                 162 // 30
#define PORT_SETTINGS_CONFIRM_TEXT_2_Y                                 162 // 215

#define PORT_SETTINGS_CONFIRM_TEXT_R1C2_X                             163 // 142
#define PORT_SETTINGS_CONFIRM_TEXT_R1C2_Y                             163 // 66

#define PORT_SETTINGS_CONFIRM_TEXT_R1C3_X                             164 // 208
#define PORT_SETTINGS_CONFIRM_TEXT_R1C3_Y                             164 // 66

#define PORT_SETTINGS_CONFIRM_TEXT_R1C4_X                             165 // 293
#define PORT_SETTINGS_CONFIRM_TEXT_R1C4_Y                             165 // 66

#define PORT_SETTINGS_CONFIRM_TEXT_R1C5_X                             166 // 388
#define PORT_SETTINGS_CONFIRM_TEXT_R1C5_Y                             166 // 66

#define PORT_SETTINGS_CONFIRM_TEXT_R2C2_X                             167 // 145
#define PORT_SETTINGS_CONFIRM_TEXT_R2C2_Y                             167 // 96

#define PORT_SETTINGS_CONFIRM_TEXT_R2C3_X                             168 // 230
#define PORT_SETTINGS_CONFIRM_TEXT_R2C3_Y                             168 // 96

#define PORT_SETTINGS_CONFIRM_TEXT_R2C4_X                             169 // 315
#define PORT_SETTINGS_CONFIRM_TEXT_R2C4_Y                             169 // 96

#define PORT_SETTINGS_CONFIRM_TEXT_R2C5_X                             170 // 400
#define PORT_SETTINGS_CONFIRM_TEXT_R2C5_Y                             170 // 96

#define PORT_SETTINGS_CONFIRM_NUM_R3C23_X                             171 // 130
#define PORT_SETTINGS_CONFIRM_NUM_R3C23_Y                             171 // 126

#define PORT_SETTINGS_CONFIRM_NUM_R3C24_X                             172 // 220
#define PORT_SETTINGS_CONFIRM_NUM_R3C24_Y                             172 // 126

#define PORT_SETTINGS_CONFIRM_NUM_R3C4_X                              173 // 305
#define PORT_SETTINGS_CONFIRM_NUM_R3C4_Y                              173 // 126

#define PORT_SETTINGS_CONFIRM_NUM_R3C5_X                              174 // 390
#define PORT_SETTINGS_CONFIRM_NUM_R3C5_Y                              174 // 126

#define PORT_SETTINGS_CONFIRM_TEXT_R3C23_X                            175 // 160
#define PORT_SETTINGS_CONFIRM_TEXT_R3C23_Y                            175 // 126

#define PORT_SETTINGS_CONFIRM_TEXT_R3C24_X                            176 // 250
#define PORT_SETTINGS_CONFIRM_TEXT_R3C24_Y                            176 // 126

#define PORT_SETTINGS_CONFIRM_TEXT_R3C4_X                             177 // 335
#define PORT_SETTINGS_CONFIRM_TEXT_R3C4_Y                             177 // 126

#define PORT_SETTINGS_CONFIRM_TEXT_R3C5_X                             178 // 420
#define PORT_SETTINGS_CONFIRM_TEXT_R3C5_Y                             178 // 126

#define PORT_SETTINGS_CONFIRM_NUM_R4C233_X                           179 // 145
#define PORT_SETTINGS_CONFIRM_NUM_R4C233_Y                           179 // 156

#define PORT_SETTINGS_CONFIRM_NUM_R4C234_X                           180 // 215
#define PORT_SETTINGS_CONFIRM_NUM_R4C234_Y                           180 // 156

#define PORT_SETTINGS_CONFIRM_NUM_R4C235_X                           181 // 305
#define PORT_SETTINGS_CONFIRM_NUM_R4C235_Y                           181 // 156

#define PORT_SETTINGS_CONFIRM_NUM_R4C5_X                             182 // 390
#define PORT_SETTINGS_CONFIRM_NUM_R4C5_Y                             182 // 156

#define PORT_SETTINGS_CONFIRM_TEXT_R4C234_X                          183 // 250
#define PORT_SETTINGS_CONFIRM_TEXT_R4C234_Y                          183 // 156

#define PORT_SETTINGS_CONFIRM_TEXT_R4C235_X                          184 // 335
#define PORT_SETTINGS_CONFIRM_TEXT_R4C235_Y                          184 // 156

#define PORT_SETTINGS_CONFIRM_TEXT_R4C5_X                            185 // 420
#define PORT_SETTINGS_CONFIRM_TEXT_R4C5_Y                            185 // 156

#define PORT_SETTINGS_CONFIRM_TEXT_R5C2_X                            186 // 145
#define PORT_SETTINGS_CONFIRM_TEXT_R5C2_Y                            186 // 186

#define PORT_SETTINGS_CONFIRM_TEXT_R5C3_X                            187 // 230
#define PORT_SETTINGS_CONFIRM_TEXT_R5C3_Y                            187 // 186

#define PORT_SETTINGS_CONFIRM_TEXT_R5C4_X                            188 // 315
#define PORT_SETTINGS_CONFIRM_TEXT_R5C4_Y                            188 // 186

#define PORT_SETTINGS_CONFIRM_TEXT_R5C5_X                            189 // 400
#define PORT_SETTINGS_CONFIRM_TEXT_R5C5_Y                            189 // 186

#define ALERT_CLEARABLE_TEXT_1_X                                      190 // 166
#define ALERT_CLEARABLE_TEXT_1_Y                                      190 // 48

#define ALERT_CLEARABLE_TEXT_2_X                                      191 // 133
#define ALERT_CLEARABLE_TEXT_2_Y                                      191 // 228

#define ALERT_LOW_BATTERY_TEXT_1_X                                   192 // 154
#define ALERT_LOW_BATTERY_TEXT_1_Y                                   192 // 130

#define ALERT_LOW_BATTERY_TEXT_2_X                                   193 // 162
#define ALERT_LOW_BATTERY_TEXT_2_Y                                   193 // 208

#define ALERT_NON_CLEARABLE_TEXT_1_X                                 194 // 108
#define ALERT_NON_CLEARABLE_TEXT_1_Y                                 194 // 68

#define ALERT_NON_CLEARABLE_TEXT_2_X                                 195 // 114
#define ALERT_NON_CLEARABLE_TEXT_2_Y                                 195 // 150

#define ALERT_NON_CLEARABLE_TEXT_3_X                                 196 // 133
#define ALERT_NON_CLEARABLE_TEXT_3_Y                                 196 // 228

#define ALERT_NON_CLEARABLE_ERROR_CODE_X                             197 // 300
#define ALERT_NON_CLEARABLE_ERROR_CODE_Y                             197 // 68

#define SETTINGS_MAIN_TEXT_1_X                                       198 // 50
#define SETTINGS_MAIN_TEXT_1_Y                                       198 // 48

#define SETTINGS_MAIN_TEXT_2_X                                       199 // 50
#define SETTINGS_MAIN_TEXT_2_Y                                       199 // 93

#define SETTINGS_MAIN_TEXT_3_X                                       200 // 50
#define SETTINGS_MAIN_TEXT_3_Y                                       200 // 121

#define SETTINGS_MAIN_TEXT_4_X                    201 // 50
#define SETTINGS_MAIN_TEXT_4_Y                    201 // 149

#define SETTINGS_MAIN_TEXT_5_X                    202 // 50
#define SETTINGS_MAIN_TEXT_5_Y                    202 // 177

#define SETTINGS_MAIN_TEXT_6_X                    203 // 50
#define SETTINGS_MAIN_TEXT_6_Y                    203 // 205

#define SETTINGS_MAIN_TEXT_7_X                    204 // 50
#define SETTINGS_MAIN_TEXT_7_Y                    204 // 213

#define SETTING_SUCTION_SETTINGS_TEXT_1_X         205 // 50
#define SETTING_SUCTION_SETTINGS_TEXT_1_Y         205 // 48

#define SETTING_SUCTION_SETTINGS_TEXT_2_X         206 // 50
#define SETTING_SUCTION_SETTINGS_TEXT_2_Y         206 // 93

#define SETTING_SUCTION_SETTINGS_NUM_1_X          207 // 298
#define SETTING_SUCTION_SETTINGS_NUM_1_Y          207 // 93

#define SETTING_SUCTION_SETTINGS_TEXT_3_X         208 // 344
#define SETTING_SUCTION_SETTINGS_TEXT_3_Y         208 // 93

#define SETTING_SUCTION_SETTINGS_TEXT_4_X         209 // 50
#define SETTING_SUCTION_SETTINGS_TEXT_4_Y         209 // 121

#define SETTING_SUCTION_SETTINGS_NUM_2_X          210 // 298
#define SETTING_SUCTION_SETTINGS_NUM_2_Y          210 // 121

#define SETTING_SUCTION_SETTINGS_TEXT_5_X         211 // 344
#define SETTING_SUCTION_SETTINGS_TEXT_5_Y         211 // 121

#define SETTING_SUCTION_SETTINGS_TEXT_6_X         212 // 50
#define SETTING_SUCTION_SETTINGS_TEXT_6_Y         212 // 149

#define SETTING_SUCTION_SETTINGS_NUM_3_X          213 // 298
#define SETTING_SUCTION_SETTINGS_NUM_3_Y          213 // 149

#define SETTING_SUCTION_SETTINGS_TEXT_7_X         214 // 344
#define SETTING_SUCTION_SETTINGS_TEXT_7_Y         214 // 149

#define SETTING_SUCTION_SETTINGS_TEXT_8_X         215 // 50
#define SETTING_SUCTION_SETTINGS_TEXT_8_Y         215 // 177

#define SETTING_SUCTION_SETTINGS_NUM_4_X          216 // 298
#define SETTING_SUCTION_SETTINGS_NUM_4_Y          216 // 177

#define SETTING_SUCTION_SETTINGS_TEXT_9_X         217 // 344
#define SETTING_SUCTION_SETTINGS_TEXT_9_Y         217 // 177

#define SETTING_SUCTION_SETTINGS_TEXT_10_X        218 // 50
#define SETTING_SUCTION_SETTINGS_TEXT_10_Y        218 // 215

#define SETTINGS_SUCTION_SETTINGS_CONFIRM_TEXT_1_X 219 // 100
#define SETTINGS_SUCTION_SETTINGS_CONFIRM_TEXT_1_Y 219 // 35

#define SETTINGS_SUCTION_SETTINGS_CONFIRM_TEXT_2_X 220 // 90
#define SETTINGS_SUCTION_SETTINGS_CONFIRM_TEXT_2_Y 220 // 71

#define SETTINGS_SUCTION_SETTINGS_CONFIRM_TEXT_3_X 221 // 90
#define SETTINGS_SUCTION_SETTINGS_CONFIRM_TEXT_3_Y 221 // 94

#define SETTINGS_SUCTION_SETTINGS_CONFIRM_TEXT_4_X 222 // 354
#define SETTINGS_SUCTION_SETTINGS_CONFIRM_TEXT_4_Y 222 // 94

#define SETTINGS_SUCTION_SETTINGS_CONFIRM_TEXT_5_X 223 // 90
#define SETTINGS_SUCTION_SETTINGS_CONFIRM_TEXT_5_Y 223 // 117

#define SETTINGS_SUCTION_SETTINGS_CONFIRM_TEXT_6_X 224 // 70
#define SETTINGS_SUCTION_SETTINGS_CONFIRM_TEXT_6_Y 224 // 198

#define SETTINGS_SUCTION_SETTINGS_CONFIRM_TEXT_7_X 225 // 354
#define SETTINGS_SUCTION_SETTINGS_CONFIRM_TEXT_7_Y 225 // 71

#define SETTINGS_SUCTION_SETTINGS_CONFIRM_TEXT_8_X 226 // 354
#define SETTINGS_SUCTION_SETTINGS_CONFIRM_TEXT_8_Y 226 // 117

#define SETTINGS_SUCTION_SETTINGS_CONFIRM_TEXT_9_X 227 // 90
#define SETTINGS_SUCTION_SETTINGS_CONFIRM_TEXT_9_Y 227 // 141

#define SETTINGS_SUCTION_SETTINGS_CONFIRM_TEXT_10_X 228 // 354
#define SETTINGS_SUCTION_SETTINGS_CONFIRM_TEXT_10_Y 228 // 141

#define SETTINGS_SUCTION_SETTINGS_CONFIRM_NUM_1_X 229 // 324
#define SETTINGS_SUCTION_SETTINGS_CONFIRM_NUM_1_Y 229 // 71

#define SETTINGS_SUCTION_SETTINGS_CONFIRM_NUM_2_X 230 // 324
#define SETTINGS_SUCTION_SETTINGS_CONFIRM_NUM_2_Y 230 // 94

#define SETTINGS_SUCTION_SETTINGS_CONFIRM_NUM_3_X 231 // 324
#define SETTINGS_SUCTION_SETTINGS_CONFIRM_NUM_3_Y 231 // 117

#define SETTINGS_SUCTION_SETTINGS_CONFIRM_NUM_4_X 232 // 324
#define SETTINGS_SUCTION_SETTINGS_CONFIRM_NUM_4_Y 232 // 141

#define SETTING_SUCTION_INTERVAL_CONFIRM_TEXT_1_X 233 // 90
#define SETTING_SUCTION_INTERVAL_CONFIRM_TEXT_1_Y 233 // 48

#define SETTING_SUCTION_INTERVAL_CONFIRM_TEXT_2_X 234 // 90
#define SETTING_SUCTION_INTERVAL_CONFIRM_TEXT_2_Y 234 // 99

#define SETTING_SUCTION_INTERVAL_CONFIRM_TEXT_3_X 235 // 324
#define SETTING_SUCTION_INTERVAL_CONFIRM_TEXT_3_Y 235 // 99

#define SETTING_SUCTION_INTERVAL_CONFIRM_TEXT_4_X 236 // 75
#define SETTING_SUCTION_INTERVAL_CONFIRM_TEXT_4_Y 236 // 198

#define SETTING_SUCTION_INTERVAL_CONFIRM_NUM_1_X 237 // 284
#define SETTING_SUCTION_INTERVAL_CONFIRM_NUM_1_Y 237 // 99

#define SETTINGS_PHARYNGEAL_TEXT_1_X             238 // 50
#define SETTINGS_PHARYNGEAL_TEXT_1_Y             238 // 48

#define SETTINGS_PHARYNGEAL_TEXT_2_X             239 // 50
#define SETTINGS_PHARYNGEAL_TEXT_2_Y             239 // 93

#define SETTINGS_PHARYNGEAL_TEXT_3_X             240 // 50
#define SETTINGS_PHARYNGEAL_TEXT_3_Y             240 // 121

#define SETTINGS_PHARYNGEAL_TEXT_4_X             241 // 344
#define SETTINGS_PHARYNGEAL_TEXT_4_Y             241 // 121

#define SETTINGS_PHARYNGEAL_TEXT_5_X             242 // 50
#define SETTINGS_PHARYNGEAL_TEXT_5_Y             242 // 149

#define SETTINGS_PHARYNGEAL_TEXT_6_X             243 // 50
#define SETTINGS_PHARYNGEAL_TEXT_6_Y             243 // 198

#define SETTINGS_PHARYNGEAL_NUM_1_X              244 // 298
#define SETTINGS_PHARYNGEAL_NUM_1_Y              244 // 121

#define SETTINGS_PHARYNGEAL_CONFIRM_TEXT_1_X     245 // 90
#define SETTINGS_PHARYNGEAL_CONFIRM_TEXT_1_Y     245 // 35

#define SETTINGS_PHARYNGEAL_CONFIRM_TEXT_2_X     246 // 100
#define SETTINGS_PHARYNGEAL_CONFIRM_TEXT_2_Y     246 // 71

#define SETTINGS_PHARYNGEAL_CONFIRM_TEXT_3_X     247 // 100
#define SETTINGS_PHARYNGEAL_CONFIRM_TEXT_3_Y     247 // 94

#define SETTINGS_PHARYNGEAL_CONFIRM_TEXT_4_X     248 // 364
#define SETTINGS_PHARYNGEAL_CONFIRM_TEXT_4_Y     248 // 94

#define SETTINGS_PHARYNGEAL_CONFIRM_TEXT_5_X     249 // 100
#define SETTINGS_PHARYNGEAL_CONFIRM_TEXT_5_Y     249 // 117

#define SETTINGS_PHARYNGEAL_CONFIRM_TEXT_6_X     250 // 80
#define SETTINGS_PHARYNGEAL_CONFIRM_TEXT_6_Y     250 // 198

#define SETTINGS_PHARYNGEAL_CONFIRM_NUM_1_X      251 // 324
#define SETTINGS_PHARYNGEAL_CONFIRM_NUM_1_Y      251 // 71

#define SETTINGS_PHARYNGEAL_CONFIRM_NUM_2_X      252 // 324
#define SETTINGS_PHARYNGEAL_CONFIRM_NUM_2_Y      252 // 94

#define SETTINGS_PHARYNGEAL_CONFIRM_NUM_3_X      253 // 324
#define SETTINGS_PHARYNGEAL_CONFIRM_NUM_3_Y      253 // 117

#define SETTINGS_SUBGLOTTIC_TEXT_1_X             254 // 50
#define SETTINGS_SUBGLOTTIC_TEXT_1_Y             254 // 48

#define SETTINGS_SUBGLOTTIC_TEXT_2_X             255 // 50
#define SETTINGS_SUBGLOTTIC_TEXT_2_Y             255 // 93

#define SETTINGS_SUBGLOTTIC_TEXT_3_X             256 // 50
#define SETTINGS_SUBGLOTTIC_TEXT_3_Y             256 // 121

#define SETTINGS_SUBGLOTTIC_TEXT_4_X    257    // 344
#define SETTINGS_SUBGLOTTIC_TEXT_4_Y    257    // 121

#define SETTINGS_SUBGLOTTIC_TEXT_5_X    258    // 50
#define SETTINGS_SUBGLOTTIC_TEXT_5_Y    258    // 149

#define SETTINGS_SUBGLOTTIC_TEXT_6_X    259    // 50
#define SETTINGS_SUBGLOTTIC_TEXT_6_Y    259    // 198

#define SETTINGS_SUBGLOTTIC_NUM_1_X     260    // 298
#define SETTINGS_SUBGLOTTIC_NUM_1_Y     260    // 121

#define SETTINGS_SUBGLOTTIC_NUM_2_X     261    // 298
#define SETTINGS_SUBGLOTTIC_NUM_2_Y     261    // 149

#define SETTINGS_SUBGLOTTIC_CONFIRM_TEXT_1_X  262    // 90
#define SETTINGS_SUBGLOTTIC_CONFIRM_TEXT_1_Y  262    // 35

#define SETTINGS_SUBGLOTTIC_CONFIRM_TEXT_2_X  263    // 100
#define SETTINGS_SUBGLOTTIC_CONFIRM_TEXT_2_Y  263    // 71

#define SETTINGS_SUBGLOTTIC_CONFIRM_TEXT_3_X  264    // 100
#define SETTINGS_SUBGLOTTIC_CONFIRM_TEXT_3_Y  264    // 94

#define SETTINGS_SUBGLOTTIC_CONFIRM_TEXT_4_X  265    // 364
#define SETTINGS_SUBGLOTTIC_CONFIRM_TEXT_4_Y  265    // 94

#define SETTINGS_SUBGLOTTIC_CONFIRM_TEXT_5_X  266    // 100
#define SETTINGS_SUBGLOTTIC_CONFIRM_TEXT_5_Y  266    // 117

#define SETTINGS_SUBGLOTTIC_CONFIRM_TEXT_6_X  267    // 80
#define SETTINGS_SUBGLOTTIC_CONFIRM_TEXT_6_Y  267    // 198

#define SETTINGS_SUBGLOTTIC_CONFIRM_NUM_1_X   268    // 324
#define SETTINGS_SUBGLOTTIC_CONFIRM_NUM_1_Y   268    // 71

#define SETTINGS_SUBGLOTTIC_CONFIRM_NUM_2_X   269    // 324
#define SETTINGS_SUBGLOTTIC_CONFIRM_NUM_2_Y   269    // 94

#define SETTINGS_SUBGLOTTIC_CONFIRM_NUM_3_X   270    // 324
#define SETTINGS_SUBGLOTTIC_CONFIRM_NUM_3_Y   270    // 117

#define SETTINGS_LAVAGE_TEXT_1_X    271    // 50
#define SETTINGS_LAVAGE_TEXT_1_Y    271    // 48

#define SETTINGS_LAVAGE_TEXT_2_X    272    // 50
#define SETTINGS_LAVAGE_TEXT_2_Y    272    // 93

#define SETTINGS_LAVAGE_TEXT_3_X    273    // 50
#define SETTINGS_LAVAGE_TEXT_3_Y    273    // 121

#define SETTINGS_LAVAGE_TEXT_4_X    274    // 344
#define SETTINGS_LAVAGE_TEXT_4_Y    274    // 121

#define SETTINGS_LAVAGE_TEXT_5_X    275    // 50
#define SETTINGS_LAVAGE_TEXT_5_Y    275    // 213

#define SETTINGS_LAVAGE_TEXT_6_X    276    // 50
#define SETTINGS_LAVAGE_TEXT_6_Y    276    // 149

#define SETTINGS_LAVAGE_TEXT_7_X    277    // 344
#define SETTINGS_LAVAGE_TEXT_7_Y    277    // 149

#define SETTINGS_LAVAGE_TEXT_8_X    278    // 50
#define SETTINGS_LAVAGE_TEXT_8_Y    278    // 177

#define SETTINGS_LAVAGE_TEXT_9_X    279    // 344
#define SETTINGS_LAVAGE_TEXT_9_Y    279    // 177

#define SETTINGS_LAVAGE_NUM_1_X     280    // 298
#define SETTINGS_LAVAGE_NUM_1_Y     280    // 121

#define SETTINGS_LAVAGE_NUM_2_X     281    // 308
#define SETTINGS_LAVAGE_NUM_2_Y     281    // 93

#define SETTINGS_LAVAGE_NUM_3_X     282    // 318
#define SETTINGS_LAVAGE_NUM_3_Y     282    // 121

#define SETTINGS_LAVAGE_NUM_4_X     283    // 298
#define SETTINGS_LAVAGE_NUM_4_Y     283    // 149

#define SETTINGS_LAVAGE_NUM_5_X     284    // 298
#define SETTINGS_LAVAGE_NUM_5_Y     284    // 177

#define SETTINGS_LAVAGE_CONFIRM_TEXT_1_X   285    // 90
#define SETTINGS_LAVAGE_CONFIRM_TEXT_1_Y   285    // 35

#define SETTINGS_LAVAGE_CONFIRM_TEXT_2_X   286    // 80
#define SETTINGS_LAVAGE_CONFIRM_TEXT_2_Y   286    // 71

#define SETTINGS_LAVAGE_CONFIRM_TEXT_3_X   287    // 80
#define SETTINGS_LAVAGE_CONFIRM_TEXT_3_Y   287    // 94

#define SETTINGS_LAVAGE_CONFIRM_TEXT_4_X   288    // 324
#define SETTINGS_LAVAGE_CONFIRM_TEXT_4_Y   288    // 94

#define SETTINGS_LAVAGE_CONFIRM_TEXT_5_X   289    // 80
#define SETTINGS_LAVAGE_CONFIRM_TEXT_5_Y   289    // 198

#define SETTINGS_LAVAGE_CONFIRM_TEXT_6_X   290    // 80
#define SETTINGS_LAVAGE_CONFIRM_TEXT_6_Y   290    // 117

#define SETTINGS_LAVAGE_CONFIRM_TEXT_7_X   291    // 324
#define SETTINGS_LAVAGE_CONFIRM_TEXT_7_Y   291    // 117

#define SETTINGS_LAVAGE_CONFIRM_TEXT_8_X   292    // 80
#define SETTINGS_LAVAGE_CONFIRM_TEXT_8_Y   292    // 140

#define SETTINGS_LAVAGE_CONFIRM_TEXT_9_X   293    // 324
#define SETTINGS_LAVAGE_CONFIRM_TEXT_9_Y   293    // 140

#define SETTINGS_LAVAGE_CONFIRM_NUM_1_X    294    // 284
#define SETTINGS_LAVAGE_CONFIRM_NUM_1_Y    294    // 71

#define SETTINGS_LAVAGE_CONFIRM_NUM_2_X    295    // 284
#define SETTINGS_LAVAGE_CONFIRM_NUM_2_Y    295    // 94

#define SETTINGS_LAVAGE_CONFIRM_NUM_3_X    296    // 284
#define SETTINGS_LAVAGE_CONFIRM_NUM_3_Y    296    // 117

#define SETTINGS_LAVAGE_CONFIRM_NUM_4_X    297    // 284
#define SETTINGS_LAVAGE_CONFIRM_NUM_4_Y    297    // 140

#define SETTINGS_DATA_RETRIVE_TEXT_1_X    298    // 155
#define SETTINGS_DATA_RETRIVE_TEXT_1_Y    298    // 35

#define SETTINGS_DATA_RETRIVE_TEXT_2_X    299    // 150/60
#define SETTINGS_DATA_RETRIVE_TEXT_2_Y    299    // 198

#define SETTINGS_DATA_RETRIVE_UP_ICON_X   300    // 410
#define SETTINGS_DATA_RETRIVE_UP_ICON_Y   300    // 90

#define SETTINGS_DATA_RETRIVE_DOWN_ICON_X  301    // 410
#define SETTINGS_DATA_RETRIVE_DOWN_ICON_Y  301    // 150

#define DATA_RETRIEVE_TIME_X              302    // 148
#define DATA_RETRIEVE_ROW1_Y              302    // 90

#define DATA_RETRIEVE_DATE_X              303    // 40
#define DATA_RETRIEVE_ROW2_Y              303    // 120

#define DATA_RETRIEVE_DATA_X              304    // 250
#define DATA_RETRIEVE_ROW3_Y              304    // 150

#define SETTINGS_QUICK_ASSIST_TEXT_1_X    305    // 50
#define SETTINGS_QUICK_ASSIST_TEXT_1_Y    305    // 48

#define SETTINGS_QUICK_ASSIST_TEXT_2_X    306    // 50
#define SETTINGS_QUICK_ASSIST_TEXT_2_Y    306    // 93

#define SETTINGS_QUICK_ASSIST_TEXT_3_X    307    // 50
#define SETTINGS_QUICK_ASSIST_TEXT_3_Y    307    // 121

#define SETTINGS_QUICK_ASSIST_TEXT_4_X    308    // 50
#define SETTINGS_QUICK_ASSIST_TEXT_4_Y    308    // 149

#define SETTINGS_QUICK_ASSIST_TEXT_5_X    309    // 50
#define SETTINGS_QUICK_ASSIST_TEXT_5_Y    309    // 177

#define SETTINGS_QUICK_ASSIST_TEXT_6_X    310    // 50
#define SETTINGS_QUICK_ASSIST_TEXT_6_Y    310    // 213

#define SETTINGS_COLL_CONT_TEXT_1_X       311    // 60
#define SETTINGS_COLL_CONT_TEXT_1_Y       311    // 80

#define SETTINGS_COLL_CONT_TEXT_2_X       312    // 110
#define SETTINGS_COLL_CONT_TEXT_2_Y       312    // 110

#define SETTINGS_COLL_CONT_TEXT_3_X       313    // 90
#define SETTINGS_COLL_CONT_TEXT_3_Y       313    // 198

#define SETTINGS_REPLACE_LAVAGE_FLUID_TEXT_1_X  314    // 130
#define SETTINGS_REPLACE_LAVAGE_FLUID_TEXT_1_Y  314    // 90

#define SETTINGS_REPLACE_LAVAGE_FLUID_TEXT_2_X  315    // 90
#define SETTINGS_REPLACE_LAVAGE_FLUID_TEXT_2_Y  315    // 198

#define SETTINGS_REPLACE_VAPLUMEN_TEXT_1_X    316    // 100
#define SETTINGS_REPLACE_VAPLUMEN_TEXT_1_Y    316    // 100

#define SETTINGS_REPLACE_VAPLUMEN_TEXT_2_X    317    // 90
#define SETTINGS_REPLACE_VAPLUMEN_TEXT_2_Y    317    // 198

#define SETTINGS_DETACH_PATIENT_STEPS_TEXT_1_X    318    // 50
#define SETTINGS_DETACH_PATIENT_STEPS_TEXT_1_Y    318    // 48

#define SETTINGS_DETACH_PATIENT_STEPS_TEXT_2_X    319    // 50
#define SETTINGS_DETACH_PATIENT_STEPS_TEXT_2_Y    319    // 84

#define SETTINGS_DETACH_PATIENT_STEPS_TEXT_3_X    320    // 50
#define SETTINGS_DETACH_PATIENT_STEPS_TEXT_3_Y    320    // 107/112

#define SETTINGS_DETACH_PATIENT_STEPS_TEXT_4_X    321    // 50
#define SETTINGS_DETACH_PATIENT_STEPS_TEXT_4_Y    321    // 135/140

#define SETTINGS_DETACH_PATIENT_STEPS_TEXT_5_X    322    // 50
#define SETTINGS_DETACH_PATIENT_STEPS_TEXT_5_Y    322    // 163/168

#define SETTINGS_DETACH_PATIENT_STEPS_TEXT_6_X    323    // 50
#define SETTINGS_DETACH_PATIENT_STEPS_TEXT_6_Y    323    // 196

#define SETTINGS_DETACH_PATIENT_STEPS_TEXT_7_X    324    // 90
#define SETTINGS_DETACH_PATIENT_STEPS_TEXT_7_Y    324    // 213

#define SETTINGS_SYSTEM_TEXT_0_X    325    // 50
#define SETTINGS_SYSTEM_TEXT_0_Y    325    // 48

#define SETTINGS_SYSTEM_TEXT_1_X    326    // 50
#define SETTINGS_SYSTEM_TEXT_1_Y    326    // 93

#define SETTINGS_SYSTEM_TEXT_2_X    327    // 50
#define SETTINGS_SYSTEM_TEXT_2_Y    327    // 121

#define SETTINGS_SYSTEM_TEXT_3_X    328    // 50
#define SETTINGS_SYSTEM_TEXT_3_Y    328    // 149

#define SETTINGS_SYSTEM_TEXT_4_X    329    // 50
#define SETTINGS_SYSTEM_TEXT_4_Y    329    // 177

#define SETTINGS_SYSTEM_TEXT_5_X    330    // 50
#define SETTINGS_SYSTEM_TEXT_5_Y    330    // 213

#define SETTINGS_SYSTEM_NUM_1_X                                        331 // 298
#define SETTINGS_SYSTEM_NUM_1_Y                                        331 // 93
#define SETTINGS_SYSTEM_NUM_2_X                                        332 // 298
#define SETTINGS_SYSTEM_NUM_2_Y                                        332 // 121
#define SETTINGS_SYSTEM_NUM_3_X                                        333 // 298
#define SETTINGS_SYSTEM_NUM_3_Y                                        333 // 149
#define SETTINGS_SYSTEM_NUM_4_X                                        334 // 298
#define SETTINGS_SYSTEM_NUM_4_Y                                        334 // 177
#define SETTINGS_SYSTEM_CONFIRM_TEXT_1_X                               335 // 90
#define SETTINGS_SYSTEM_CONFIRM_TEXT_1_Y                               335 // 35
#define SETTINGS_SYSTEM_CONFIRM_TEXT_2_X                               336 // 80
#define SETTINGS_SYSTEM_CONFIRM_TEXT_2_Y                               336 // 71
#define SETTINGS_SYSTEM_CONFIRM_TEXT_3_X                               337 // 80
#define SETTINGS_SYSTEM_CONFIRM_TEXT_3_Y                               337 // 94
#define SETTINGS_SYSTEM_CONFIRM_TEXT_4_X                               338 // 80
#define SETTINGS_SYSTEM_CONFIRM_TEXT_4_Y                               338 // 117
#define SETTINGS_SYSTEM_CONFIRM_TEXT_5_X                               339 // 80
#define SETTINGS_SYSTEM_CONFIRM_TEXT_5_Y                               339 // 140
#define SETTINGS_SYSTEM_CONFIRM_TEXT_6_X                               340 // 80
#define SETTINGS_SYSTEM_CONFIRM_TEXT_6_Y                               340 // 163
#define SETTINGS_SYSTEM_CONFIRM_TEXT_7_X                               341 // 80
#define SETTINGS_SYSTEM_CONFIRM_TEXT_7_Y                               341 // 186
#define SETTINGS_SYSTEM_CONFIRM_TEXT_8_X                               342 // 80
#define SETTINGS_SYSTEM_CONFIRM_TEXT_8_Y                               342 // 209
#define SETTINGS_SYSTEM_CONFIRM_TEXT_9_X                               343 // 90
#define SETTINGS_SYSTEM_CONFIRM_TEXT_9_Y                               343 // 239
#define SETTINGS_SYSTEM_CONFIRM_NUM_1_X                                344 // 324
#define SETTINGS_SYSTEM_CONFIRM_NUM_1_Y                                344 // 71
#define SETTINGS_SYSTEM_CONFIRM_NUM_2_X                                345 // 324
#define SETTINGS_SYSTEM_CONFIRM_NUM_2_Y                                345 // 94
#define SETTINGS_SYSTEM_CONFIRM_NUM_3_X                                346 // 324
#define SETTINGS_SYSTEM_CONFIRM_NUM_3_Y                                346 // 117
#define SETTINGS_SYSTEM_CONFIRM_NUM_4_X                                347 // 324
#define SETTINGS_SYSTEM_CONFIRM_NUM_4_Y                                347 // 140
#define SETTINGS_SYSTEM_CONFIRM_NUM_5_X                                348 // 324
#define SETTINGS_SYSTEM_CONFIRM_NUM_5_Y                                348 // 163
#define SETTINGS_SYSTEM_CONFIRM_NUM_6_X                                349 // 324
#define SETTINGS_SYSTEM_CONFIRM_NUM_6_Y                                349 // 186
#define SETTINGS_SYSTEM_CONFIRM_NUM_7_X                                350 // 324
#define SETTINGS_SYSTEM_CONFIRM_NUM_7_Y                                350 // 209
#define SETTINGS_SYSTEM_SHUTDOWN_CONFIRM_TEXT_1_X                      351 // 125
#define SETTINGS_SYSTEM_SHUTDOWN_CONFIRM_TEXT_1_Y                      351 // 110
#define SETTINGS_SYSTEM_SHUTDOWN_CONFIRM_TEXT_2_X                      352 // 90
#define SETTINGS_SYSTEM_SHUTDOWN_CONFIRM_TEXT_2_Y                      352 // 198
#define PAUSE_MAIN_TEXT_1_X                                            353 // 160
#define PAUSE_MAIN_TEXT_1_Y                                            353 // 48
#define PAUSE_MAIN_TEXT_2_X                                            354 // 140
#define PAUSE_MAIN_TEXT_2_Y                                            354 // 198
#define PAUSE_UNATTENDED_ALERT_TEXT_1_X                                355 // 160
#define PAUSE_UNATTENDED_ALERT_TEXT_1_Y                                355 // 40
#define PAUSE_UNATTENDED_ALERT_TEXT_2_X                                356 // 50
#define PAUSE_UNATTENDED_ALERT_TEXT_2_Y                                356 // 68
#define PAUSE_UNATTENDED_ALERT_TEXT_3_X                                357 // 30
#define PAUSE_UNATTENDED_ALERT_TEXT_3_Y                                357 // 208

// SOME VALUES ARE STILL REMAINING



//other definitions
#define BLACK													0x0001
#define WHITE													0xFFFF
#define BLUE													0x08C5
#define DARKBLUE												0x0843
#define LIGHTBLUE												0x02F3
#define MIDBLUE													0x01CC
#define EXPBLUE													0x0291
#define GREY													0x3A08
#define ORANGE													0xF4A3
#define LIGHTGREY												0x8410
#define MEDGREEN												0x03AE
#define RED														0xF800
#define LIGHT_BLUE												0x2CBF
#define YELLOW													0xFFE0
#define EXMP													0xF945
#define BORDERGREY												0xDEFB
#define CYAN													0x07FF

#define INACTIVE_SCREEN_TOP_TILE_GREY							0x3186
#define ACTIVE_SCREEN_TOP_TILE_BLUE								0x0A4E
#define ACTIVE_SCREEN_PRESSURE_UPDATE_BG_BLUE					0x0863

#define FB_MODE													0xC5
#define F_MODE													0x85

#define HOUR_12_FORMAT											0x12
#define HOUR_12_FORMAT_89										0x18

#define HOUR_8													0x20
#define HOUR_9													0x21

#define ROW1													0
#define ROW2													1
#define ROW3													2
#define ROW4													3
#define ROW5													4
#define ROW6													5
#define ROW7													6
#define ROW8													7
#define ROW9													8
#define ROW10													9

#define FIRMWARE_VERSION_X										380
#define FIRMWARE_VERSION_Y										244

#define RTC_TIME_X												150
#define RTC_TIME_Y												3

#define TOTAL_TYPE_OF_SUCTIONS							2

#define TOTAL_NUM_OF_TUBES								2

#define SUBGLOTTIC_SUCTION								0
#define OROPHARYNGEAL_SUCTION							1
#define CHLORHEXIDINE_SUCTION							2
#define INSIDE_ET_TUBE_SUCTION							3
#define BRUSHING_PROTOCOL								4
#define PORT_BLOCK										5
#define LAVAGE_PRESSURE									6

#define SETTING_TARGET_PRESSURE							0
#define SUCTION_PRESSURE								1

void LCD_Initialization(void);
void open_win(const char* window_name);
void set_visible_icon(const char *icon_name, uint16_t visible);
void set_text(const char* widget_type, const char* widget_name, const char* text);
void set_image(const char* widget_name, const char* image_name);
void LCD_DisplayText(uint8_t ui8TextDisplayMode, uint16_t ui16X, uint16_t ui16Y, const char *pi8String, uint8_t ui8FontIndex, uint16_t ui16FColor, uint16_t ui16BColor);
void LCD_DisplayNumber(uint8_t ui8TextDisplayMode, uint16_t ui16X, uint16_t ui16Y, uint16_t ui16Value, uint8_t ui8FontIndex, uint16_t ui16FColor, uint16_t ui16BColor);
void LCD_DisplayImage(uint16_t ui16index);
void LCD_DisplayIcon(uint16_t ui16X, uint16_t ui16Y, uint16_t ui16Index);
void LCD_DisplayNewPatientSelection(void);
void LCD_DisplayNewPatientSelectionMenu(uint8_t ui8Num);
void LCD_DisplayConfirmNewPatient(void);
void LCD_DisplayFlashErasingScreen(void);
void LCD_DisplayClampTubesMain(void);
void LCD_DisplayClampTubesPause(void);
void LCD_DisplayUnclampTubes(void);
void LCD_DisplayLowBattery(void);
void LCD_DisplayAlertScreen1(void);
void LCD_DisplayAlertScreen2(void);
void LCD_DisplayBatteryCharge(uint8_t ui8BatteryCharge);
void LCD_DisplaySettingSystemMenu(uint8_t ui8Row, uint8_t ui8RightArrowStatus, uint8_t ui8LeftArrowStatus,uint8_t ui8RowIconRefreshFlag);
void LCD_ConfirmParameterAndBeginSuctionScreen(void);
void LCD_DisplayNewMainSettingsPage1(void);
void LCD_DisplayNewMainSettingsPage2(void);
void LCD_DisplayPharyngealPortSuction(void);
void LCD_DisplaySubglotticPortSuction(void);
void LCD_DisplayInsideEtTubeSuction(void);
void LCD_DisplayWaitScreen(void);
void LCD_DisplayBeginSuction(void);
void LCD_DisplayPauseScreen(void);

//extra definitions
#define LCD_HANDSHAKE_CMD										0x00
#define LCD_HEADER												0xAA
#define LCD_CUSTOM_TEXT_DISPLAY_CMD								0x98
#define LCD_FONT_LIBRARY_SELECT_CMD								0x03
#define LCD_SET_FB_COLOR_CMD									0x40
#define LCD_DISPLAY_IMAGE_CMD									0x70
#define LCD_DISPLAY_ICON_CMD									0x99
#define LCD_SET_BRIGHTNESS_CMD									0x5F
#define LCD_FILL_AREA_CMD										0x64
#define LCD_DEFAULT_12X24_TEXT_DISPLAY_CMD						0x55
#define LCD_DEFAULT_8X16_TEXT_DISPLAY_CMD						0x54

#define LCD_FOOTER_LEN											4
#define LCD_HANDSHAKE_CMD_LEN									6
#define LCD_SET_FB_COLOR_CMD_LEN								10
#define LCD_DISPLAY_IMAGE_CMD_LEN								8
#define LCD_DISPLAY_ICON_CMD_LEN								12
#define LCD_SET_BRIGHTNESS_CMD_LEN								7
#define LCD_FILL_AREA_CMD_LEN									12
#define LCD_DISPLAY_REMAINING_TIME_CMD_LEN						20
#define DATA_RETRIEVE_TIME_CMD_LEN								18
#define DATA_RETRIEVE_DATE_CMD_LEN								21//20

#define LCD_8X16_FONT_INDEX										0x21
#define LCD_12X24_FONT_INDEX									0x22
#define LCD_16X32_FONT_INDEX									0x23
#define LCD_24X48_FONT_INDEX									0x24
#define LCD_32X64_FONT_INDEX									0x25

#define LCD_MIN_BRIGHTNESS										0x06
#define LCD_MAX_BRIGHTNESS										0x64
#endif /* INC_LCD_H_ */
