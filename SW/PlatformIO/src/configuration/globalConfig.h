/**
 * Global Configuration - defines 
 * 
 * all global defines of the programm. 
 * - the definition of the used pins
 * - definition of the cam features (e.g. resolution)
 * 
 * define the SINGLE_COMPONENTS_TEST when using the single component source files
 * define the ANALYSIS_ON_CAMERA when using the firmware analyse approach
 * @author Tom Seiffert
 */

 
//#define SINGLE_COMPONENTS_TEST //if SingleComponets should be used!
#define ANALYSIS_ON_CAMERA //if firmware analysis is used | ToDO: change to Analyze

/* serial definition (choose usb -> Serial | or bluetooth -> Serial 8)*/
#define CONSOLE Serial



/* ----- pin definitions -----  */

#define ON_BOARD_LED 13

#define ARD_LINE_FINDER1 2
#define ARD_LINE_FINDER2 3

#define OPTICAL_FLOW_LED 23
#define OPTICAL_FLOW_CHIP_SELECT 0 

#define MOTOR_ESC_PIN 29 //
#define SERVO_PIN 28

#define LED_STRIP 14
#define BATTERY_MEASUREMENT 38

#define POTI1 24 //Analogen 10
#define POTI2 25 //Analogen 11

#define CAM_SPI_MISO 12

 //ToDo: remove - avoid i2c IO-Expander
 #define DIPSWITSCH1 4
 #define DIPSWITSCH2 5
 #define DIPSWITSCH3 6
 #define DIPSWITSCH4 7

//IO-Expander pins
#define IO_EX_BUTTON1 8
#define IO_EX_BUTTON2 9

#define IO_EX_DIPSWITCH1 0
#define IO_EX_DIPSWITCH2 1
#define IO_EX_DIPSWITCH3 2
#define IO_EX_DIPSWITCH4 3
#define IO_EX_DIPSWITCH5 4
#define IO_EX_DIPSWITCH6 5
#define IO_EX_DIPSWITCH7 6
#define IO_EX_DIPSWITCH8 7