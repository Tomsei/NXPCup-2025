EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_01x02 12V1
U 1 1 66CA69BE
P 1300 900
F 0 "12V1" H 1380 892 50  0000 L CNN
F 1 "12V" H 1380 801 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 1300 900 50  0001 C CNN
F 3 "~" H 1300 900 50  0001 C CNN
	1    1300 900 
	1    0    0    -1  
$EndComp
Text GLabel 1100 900  0    50   Input ~ 0
AKKU_GND
Text GLabel 1100 1000 0    50   Input ~ 0
AKKU_12V
$Comp
L Teensy:Teensy4.1 Teensy4.1
U 1 1 66CA748B
P 3700 6450
F 0 "Teensy4.1" H 3700 9015 50  0000 C CNN
F 1 "Teensy4.1" H 3700 8924 50  0000 C CNN
F 2 "Teensy:Teensy41" H 3300 6850 50  0001 C CNN
F 3 "" H 3300 6850 50  0001 C CNN
	1    3700 6450
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 Motor_ESC1
U 1 1 66CAB3E8
P 2100 2350
F 0 "Motor_ESC1" H 2050 2150 50  0000 L CNN
F 1 "Motor_ESC" H 1200 2050 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 2100 2350 50  0001 C CNN
F 3 "~" H 2100 2350 50  0001 C CNN
	1    2100 2350
	1    0    0    -1  
$EndComp
Text GLabel 1850 2250 0    50   Input ~ 0
Motor_ESC_GND
Text GLabel 1850 2450 0    50   Input ~ 0
Motor_ESC_Data
$Comp
L Connector_Generic:Conn_01x07 OpticalFlow1
U 1 1 66CAD67A
P 11000 900
F 0 "OpticalFlow1" H 11080 942 50  0000 L CNN
F 1 "OpticalFlow" H 10550 450 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x07_P2.54mm_Vertical" H 11000 900 50  0001 C CNN
F 3 "~" H 11000 900 50  0001 C CNN
	1    11000 900 
	1    0    0    -1  
$EndComp
Text GLabel 10750 600  0    50   Input ~ 0
PIM453_Vin(3.3V-5V)
Text GLabel 10750 700  0    50   Input ~ 0
PIM453_CS
Text GLabel 10750 800  0    50   Input ~ 0
PIM453_SCK
Text GLabel 10750 900  0    50   Input ~ 0
PIM453_MOSI
Text GLabel 10750 1000 0    50   Input ~ 0
PIM453_MISO
Text GLabel 10750 1200 0    50   Input ~ 0
PIM453_GND
$Comp
L Connector_Generic:Conn_01x03 Servo1
U 1 1 66CB0F7B
P 2100 3000
F 0 "Servo1" H 2050 2800 50  0000 L CNN
F 1 "Servo" H 1300 2750 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 2100 3000 50  0001 C CNN
F 3 "~" H 2100 3000 50  0001 C CNN
	1    2100 3000
	1    0    0    -1  
$EndComp
Text GLabel 1850 2900 0    50   Input ~ 0
Servo_GND
Text GLabel 1850 3000 0    50   Input ~ 0
Servo_7.2V
Text GLabel 1850 3100 0    50   Input ~ 0
Servo_Data
$Comp
L Connector_Generic:Conn_02x08_Odd_Even Cam_R1
U 1 1 66CB198E
P 4250 2900
F 0 "Cam_R1" H 4300 3417 50  0000 C CNN
F 1 "Cam_R" H 4300 3326 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x08_P2.54mm_Vertical" H 4250 2900 50  0001 C CNN
F 3 "~" H 4250 2900 50  0001 C CNN
	1    4250 2900
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J5
U 1 1 66CB2D95
P 3700 3550
F 0 "J5" V 3900 3550 50  0001 C CNN
F 1 " " V 3800 3550 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 3700 3550 50  0001 C CNN
F 3 "~" H 3700 3550 50  0001 C CNN
	1    3700 3550
	0    1    1    0   
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J7
U 1 1 66CB4313
P 5000 3550
F 0 "J7" V 5200 3550 50  0001 C CNN
F 1 " " V 5100 3550 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 5000 3550 50  0001 C CNN
F 3 "~" H 5000 3550 50  0001 C CNN
	1    5000 3550
	0    1    1    0   
$EndComp
$Comp
L Connector_Generic:Conn_02x08_Odd_Even Cam_L1
U 1 1 66CB713C
P 6450 2900
F 0 "Cam_L1" H 6500 3417 50  0000 C CNN
F 1 "Cam_L" H 6500 3326 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x08_P2.54mm_Vertical" H 6450 2900 50  0001 C CNN
F 3 "~" H 6450 2900 50  0001 C CNN
	1    6450 2900
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J8
U 1 1 66CB7142
P 5900 3550
F 0 "J8" V 6100 3550 50  0001 C CNN
F 1 " " V 6000 3550 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 5900 3550 50  0001 C CNN
F 3 "~" H 5900 3550 50  0001 C CNN
	1    5900 3550
	0    1    1    0   
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J10
U 1 1 66CB7148
P 7200 3550
F 0 "J10" V 7400 3550 50  0001 C CNN
F 1 " " V 7300 3550 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 7200 3550 50  0001 C CNN
F 3 "~" H 7200 3550 50  0001 C CNN
	1    7200 3550
	0    1    1    0   
$EndComp
Text GLabel 4000 2600 1    50   Input ~ 0
Cam_SPI_MOSI
Text GLabel 3900 2700 1    50   Input ~ 0
Cam_SPI_MISO
Text GLabel 3700 2900 1    50   Input ~ 0
Cam_SPI_SS
Text GLabel 3600 3000 1    50   Input ~ 0
Cam_I2C_SCL
Text GLabel 3500 3100 1    50   Input ~ 0
Cam_I2C_SDA
Text GLabel 3400 3200 1    50   Input ~ 0
Cam_ADC
Text GLabel 3300 3300 1    50   Input ~ 0
Cam_3.3V_0
Wire Wire Line
	4000 3350 4000 2600
Wire Wire Line
	4050 2600 4000 2600
Wire Wire Line
	4050 2700 3900 2700
Wire Wire Line
	3900 3350 3900 2700
Wire Wire Line
	3800 3350 3800 2800
Wire Wire Line
	4050 2800 3800 2800
Wire Wire Line
	4050 2900 3700 2900
Wire Wire Line
	3700 2900 3700 3350
Wire Wire Line
	3600 3350 3600 3000
Wire Wire Line
	3600 3000 4050 3000
Wire Wire Line
	4050 3100 3500 3100
Wire Wire Line
	3500 3100 3500 3350
Wire Wire Line
	3400 3350 3400 3200
Wire Wire Line
	4050 3200 3400 3200
Wire Wire Line
	4050 3300 3300 3300
Wire Wire Line
	3300 3300 3300 3350
Text GLabel 4600 2600 1    50   Input ~ 0
Cam_ETH_LED
Text GLabel 4700 2700 1    50   Input ~ 0
Cam_ETH_RXN
Text GLabel 4800 2800 1    50   Input ~ 0
Cam_ETH_RXP
Text GLabel 4900 2900 1    50   Input ~ 0
Cam_ETH_TXN
Text GLabel 5000 3000 1    50   Input ~ 0
Cam_ETH_TXP
Text GLabel 5100 3100 1    50   Input ~ 0
Cam_ON_OFF
Text GLabel 5200 3200 1    50   Input ~ 0
Cam_Raw
Text GLabel 5300 3300 1    50   Input ~ 0
Cam_GND_0
Wire Wire Line
	4550 2600 4600 2600
Wire Wire Line
	4600 3350 4600 2600
Wire Wire Line
	4550 2700 4700 2700
Wire Wire Line
	4700 3350 4700 2700
Wire Wire Line
	4550 2800 4800 2800
Wire Wire Line
	4800 2800 4800 3350
Wire Wire Line
	4550 2900 4900 2900
Wire Wire Line
	4900 2900 4900 3350
Wire Wire Line
	5000 3350 5000 3000
Wire Wire Line
	5000 3000 4550 3000
Wire Wire Line
	4550 3100 5100 3100
Wire Wire Line
	5100 3100 5100 3350
Wire Wire Line
	5200 3350 5200 3200
Wire Wire Line
	5200 3200 4550 3200
Wire Wire Line
	4550 3300 5300 3300
Wire Wire Line
	5300 3300 5300 3350
Wire Wire Line
	6250 2600 6200 2600
Wire Wire Line
	6200 2600 6200 3350
Wire Wire Line
	6250 2700 6100 2700
Wire Wire Line
	6100 2700 6100 3350
Wire Wire Line
	6000 3350 6000 2800
Wire Wire Line
	6000 2800 6250 2800
Wire Wire Line
	6250 2900 5900 2900
Wire Wire Line
	5900 2900 5900 3350
Wire Wire Line
	6250 3000 5800 3000
Wire Wire Line
	5800 3000 5800 3350
Wire Wire Line
	5700 3350 5700 3100
Wire Wire Line
	5700 3100 6250 3100
Wire Wire Line
	6250 3200 5600 3200
Wire Wire Line
	5600 3200 5600 3350
Wire Wire Line
	6250 3300 5500 3300
Wire Wire Line
	5500 3300 5500 3350
Text GLabel 6200 2600 1    50   Input ~ 0
Cam_NC_0
Text GLabel 6100 2700 1    50   Input ~ 0
Cam_NC_1
Text GLabel 6000 2800 1    50   Input ~ 0
Cam_NC_2
Text GLabel 5900 2900 1    50   Input ~ 0
Cam_NC_3
Text GLabel 5800 3000 1    50   Input ~ 0
Cam_GPIO_14
Text GLabel 5700 3100 1    50   Input ~ 0
Cam_GPIO_13
Text GLabel 5600 3200 1    50   Input ~ 0
Cam_SBL
Text GLabel 5500 3300 1    50   Input ~ 0
Cam_3.3V_1
Wire Wire Line
	6750 2600 6800 2600
Wire Wire Line
	6800 2600 6800 3350
Wire Wire Line
	6750 2700 6900 2700
Wire Wire Line
	6900 2700 6900 3350
Wire Wire Line
	6750 2800 7000 2800
Wire Wire Line
	7000 2800 7000 3350
Wire Wire Line
	7100 3350 7100 2900
Wire Wire Line
	7100 2900 6750 2900
Wire Wire Line
	6750 3000 7200 3000
Wire Wire Line
	7200 3000 7200 3350
Wire Wire Line
	7300 3350 7300 3100
Wire Wire Line
	7300 3100 6750 3100
Wire Wire Line
	6750 3200 7400 3200
Wire Wire Line
	7400 3200 7400 3350
Wire Wire Line
	7500 3350 7500 3300
Wire Wire Line
	7500 3300 6750 3300
Text GLabel 6800 2600 1    50   Input ~ 0
Cam_Reset
Text GLabel 6900 2700 1    50   Input ~ 0
Cam_WakeUp
Text GLabel 7000 2800 1    50   Input ~ 0
Cam_GPIO_10
Text GLabel 7100 2900 1    50   Input ~ 0
Cam_GPIO_9
Text GLabel 7200 3000 1    50   Input ~ 0
Cam_GPIO_8
Text GLabel 7400 3200 1    50   Input ~ 0
Cam_Vin(3.6V-5V)
Text GLabel 7500 3300 1    50   Input ~ 0
Cam_GND_1
$Comp
L Connector_Generic:Conn_01x04 Distanz_Messer1
U 1 1 66CDB40C
P 7200 700
F 0 "Distanz_Messer1" H 7280 692 50  0000 L CNN
F 1 "Distanz_Messer" H 6700 350 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 7200 700 50  0001 C CNN
F 3 "~" H 7200 700 50  0001 C CNN
	1    7200 700 
	1    0    0    -1  
$EndComp
Text GLabel 6950 600  0    50   Input ~ 0
SEN0245_Main_Vin(3.3V-5V)
Text GLabel 6950 700  0    50   Input ~ 0
SEN0245_Main_GND
Text GLabel 6950 800  0    50   Input ~ 0
SEN0245_Main_I2C_SCL
Text GLabel 6950 900  0    50   Input ~ 0
SEN0245_Main_I2C_SDA
$Comp
L Connector_Generic:Conn_01x02 DCDC_5V1
U 1 1 66CF2C5C
P 2100 1250
F 0 "DCDC_5V1" H 2050 1050 50  0000 L CNN
F 1 "DCDC_5V" H 1050 1000 50  0000 L CNN
F 2 "Connector_Phoenix_MSTB:PhoenixContact_MSTBA_2,5_2-G_1x02_P5.00mm_Horizontal" H 2100 1250 50  0001 C CNN
F 3 "~" H 2100 1250 50  0001 C CNN
	1    2100 1250
	1    0    0    -1  
$EndComp
Text GLabel 1900 1250 0    50   Input ~ 0
DCDC_Converter_1_Out_GND
Text GLabel 1900 1350 0    50   Input ~ 0
DCDC_Converter_1_Out_5V
Text GLabel 1900 1850 0    50   Input ~ 0
DCDC_Converter_0_Out_7.2V
Text GLabel 1900 1750 0    50   Input ~ 0
DCDC_Converter_0_Out_GND
$Comp
L Connector_Generic:Conn_01x02 DCDC_7.2V1
U 1 1 66CEFBDD
P 2100 1750
F 0 "DCDC_7.2V1" H 2050 1550 50  0000 L CNN
F 1 "DCDC_7.2V" H 950 1500 50  0000 L CNN
F 2 "Connector_Phoenix_MSTB:PhoenixContact_MSTBA_2,5_2-G_1x02_P5.00mm_Horizontal" H 2100 1750 50  0001 C CNN
F 3 "~" H 2100 1750 50  0001 C CNN
	1    2100 1750
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x05 IMU1
U 1 1 66C7CC2B
P 7200 1500
F 0 "IMU1" H 7280 1542 50  0000 L CNN
F 1 "IMU" H 6900 1200 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 7200 1500 50  0001 C CNN
F 3 "~" H 7200 1500 50  0001 C CNN
	1    7200 1500
	1    0    0    -1  
$EndComp
Text GLabel 6950 1300 0    50   Input ~ 0
IMU_Vin(3.3V-5V)
Text GLabel 6950 1400 0    50   Input ~ 0
IMU_GND
$Comp
L Connector_Generic:Conn_01x24 J20
U 1 1 66CE909D
P 5050 5400
F 0 "J20" H 4950 6750 50  0000 L CNN
F 1 " " H 4800 6650 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x24_P2.54mm_Vertical" H 5050 5400 50  0001 C CNN
F 3 "~" H 5050 5400 50  0001 C CNN
	1    5050 5400
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x24 J21
U 1 1 66CED23C
P 2350 5500
F 0 "J21" H 2268 4075 50  0000 C CNN
F 1 " " H 2268 4166 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x24_P2.54mm_Vertical" H 2350 5500 50  0001 C CNN
F 3 "~" H 2350 5500 50  0001 C CNN
	1    2350 5500
	-1   0    0    1   
$EndComp
Text GLabel 8750 700  0    50   Input ~ 0
Display_GND
Wire Wire Line
	2550 4300 2600 4300
Wire Wire Line
	2550 4400 2600 4400
Wire Wire Line
	2600 4600 2550 4600
Wire Wire Line
	2550 4700 2600 4700
Wire Wire Line
	2600 4800 2550 4800
Wire Wire Line
	2600 4900 2550 4900
Wire Wire Line
	2600 5000 2550 5000
Wire Wire Line
	2550 5100 2600 5100
Wire Wire Line
	2600 5200 2550 5200
Wire Wire Line
	2550 5300 2600 5300
Wire Wire Line
	2600 5400 2550 5400
Wire Wire Line
	2550 5500 2600 5500
Wire Wire Line
	2600 5600 2550 5600
Wire Wire Line
	2550 5700 2600 5700
Wire Wire Line
	2600 5800 2550 5800
Wire Wire Line
	2550 5900 2600 5900
Wire Wire Line
	2600 6000 2550 6000
Wire Wire Line
	2550 6100 2600 6100
Wire Wire Line
	2600 6200 2550 6200
Wire Wire Line
	2550 6300 2600 6300
Wire Wire Line
	2600 6400 2550 6400
Wire Wire Line
	2550 6500 2600 6500
Wire Wire Line
	2600 6600 2550 6600
Wire Wire Line
	4800 4300 4850 4300
Wire Wire Line
	4800 4400 4850 4400
Wire Wire Line
	4800 4500 4850 4500
Wire Wire Line
	4850 4600 4800 4600
Wire Wire Line
	4800 4700 4850 4700
Wire Wire Line
	4850 4800 4800 4800
Wire Wire Line
	4800 4900 4850 4900
Wire Wire Line
	4850 5000 4800 5000
Wire Wire Line
	4800 5100 4850 5100
Wire Wire Line
	4850 5200 4800 5200
Wire Wire Line
	4800 5300 4850 5300
Wire Wire Line
	4850 5400 4800 5400
Wire Wire Line
	4800 5500 4850 5500
Wire Wire Line
	4850 5600 4800 5600
Wire Wire Line
	4800 5700 4850 5700
Wire Wire Line
	4850 5800 4800 5800
Wire Wire Line
	4800 5900 4850 5900
Wire Wire Line
	4850 6000 4800 6000
Wire Wire Line
	4850 6100 4800 6100
Wire Wire Line
	4800 6200 4850 6200
Wire Wire Line
	4850 6300 4800 6300
Wire Wire Line
	4800 6400 4850 6400
Wire Wire Line
	4850 6500 4800 6500
Wire Wire Line
	4800 6600 4850 6600
Wire Wire Line
	10750 1100 10800 1100
Wire Wire Line
	6950 1700 7000 1700
Text GLabel 8750 600  0    50   Input ~ 0
Display_Vin(3.3V-5V)
Text GLabel 8750 800  0    50   Input ~ 0
Display_SCL
Text GLabel 8750 900  0    50   Input ~ 0
Display_SDA
$Comp
L Device:R R0
U 1 1 678F7A07
P 1250 650
F 0 "R0" V 1043 650 50  0001 C CNN
F 1 "4k" V 1134 650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P1.90mm_Vertical" V 1180 650 50  0001 C CNN
F 3 "~" H 1250 650 50  0001 C CNN
	1    1250 650 
	0    1    1    0   
$EndComp
$Comp
L Device:R R1
U 1 1 678F84FF
P 1650 650
F 0 "R1" V 1443 650 50  0001 C CNN
F 1 "1k" V 1534 650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P1.90mm_Vertical" V 1580 650 50  0001 C CNN
F 3 "~" H 1650 650 50  0001 C CNN
	1    1650 650 
	0    1    1    0   
$EndComp
Text GLabel 1100 650  0    50   Input ~ 0
AKKU_12V
Text GLabel 1800 650  2    50   Input ~ 0
AKKU_GND
Wire Wire Line
	1850 2350 1900 2350
$Comp
L Connector:Conn_01x01_Male J22
U 1 1 67AE62F4
P 6750 1700
F 0 "J22" H 6722 1632 50  0000 R CNN
F 1 " " H 6722 1723 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 6750 1700 50  0001 C CNN
F 3 "~" H 6750 1700 50  0001 C CNN
	1    6750 1700
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J23
U 1 1 67B0A863
P 10550 1100
F 0 "J23" H 10450 1100 50  0000 R CNN
F 1 " " H 10300 1100 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 10550 1100 50  0001 C CNN
F 3 "~" H 10550 1100 50  0001 C CNN
	1    10550 1100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J24
U 1 1 67B2E429
P 1650 2350
F 0 "J24" H 1600 2350 50  0000 R CNN
F 1 " " H 1450 2350 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 1650 2350 50  0001 C CNN
F 3 "~" H 1650 2350 50  0001 C CNN
	1    1650 2350
	1    0    0    -1  
$EndComp
Text GLabel 3800 2800 1    50   Input ~ 0
Cam_SPI_SCK
Wire Wire Line
	2550 4500 2600 4500
$Comp
L Connector_Generic:Conn_01x04 LichtSchranke_0
U 1 1 673EE162
P 5100 700
F 0 "LichtSchranke_0" H 4700 350 50  0000 L CNN
F 1 "LichtSchranke_0" H 3750 350 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 5100 700 50  0001 C CNN
F 3 "~" H 5100 700 50  0001 C CNN
	1    5100 700 
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 LichtSchranke_1
U 1 1 673EEE79
P 5100 1350
F 0 "LichtSchranke_1" H 4700 1000 50  0000 L CNN
F 1 "LichtSchranke_1" H 3750 1000 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 5100 1350 50  0001 C CNN
F 3 "~" H 5100 1350 50  0001 C CNN
	1    5100 1350
	1    0    0    -1  
$EndComp
Text GLabel 4900 700  0    50   Input ~ 0
AchsenGeschwindigkeitsMessung_0_Vin
Text GLabel 4900 1350 0    50   Input ~ 0
AchsenGeschwindigkeitsMessung_1_Vin
Text GLabel 4900 600  0    50   Input ~ 0
AchsenGeschwindigkeitsMessung_0_GND
Text GLabel 4900 1250 0    50   Input ~ 0
AchsenGeschwindigkeitsMessung_1_GND
Text GLabel 4900 800  0    50   Input ~ 0
AchsenGeschwindigkeitsMessung_0_Data
Text GLabel 4900 1450 0    50   Input ~ 0
AchsenGeschwindigkeitsMessung_1_Data
$Comp
L Connector:Conn_01x01_Male J27
U 1 1 6745061A
P 4700 900
F 0 "J27" H 4672 832 50  0000 R CNN
F 1 " " H 4672 923 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 4700 900 50  0001 C CNN
F 3 "~" H 4700 900 50  0001 C CNN
	1    4700 900 
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J28
U 1 1 6745F6DB
P 4700 1550
F 0 "J28" H 4672 1482 50  0000 R CNN
F 1 " " H 4672 1573 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 4700 1550 50  0001 C CNN
F 3 "~" H 4700 1550 50  0001 C CNN
	1    4700 1550
	1    0    0    -1  
$EndComp
$Comp
L I2CIOExpander:MCP23017-E_SP IOExpander1
U 1 1 674B3080
P 9550 3600
F 0 "IOExpander1" H 9550 4867 50  0000 C CNN
F 1 "IOExpander" H 9550 4776 50  0000 C CNN
F 2 "I2CIOExpander:DIP787W45P254L3556H508Q28" H 9550 3600 50  0001 L BNN
F 3 "" H 9550 3600 50  0001 L BNN
F 4 "Microchip" H 9550 3600 50  0001 L BNN "MF"
F 5 "22889" H 9550 3600 50  0001 L BNN "SNAPEDA_PACKAGE_ID"
F 6 "DIP-28 Microchip" H 9550 3600 50  0001 L BNN "Package"
F 7 "None" H 9550 3600 50  0001 L BNN "Price"
F 8 "https://www.snapeda.com/parts/MCP23017-E/SP/Microchip/view-part/?ref=eda" H 9550 3600 50  0001 L BNN "Check_prices"
F 9 "IPC 7351B" H 9550 3600 50  0001 L BNN "STANDARD"
F 10 "D" H 9550 3600 50  0001 L BNN "PARTREV"
F 11 "https://www.snapeda.com/parts/MCP23017-E/SP/Microchip/view-part/?ref=snap" H 9550 3600 50  0001 L BNN "SnapEDA_Link"
F 12 "MCP23017-E/SP" H 9550 3600 50  0001 L BNN "MP"
F 13 "https://www.snapeda.com/api/url_track_click_mouser/?unipart_id=48605&manufacturer=Microchip&part_name=MCP23017-E/SP&search_term=None" H 9550 3600 50  0001 L BNN "Purchase-URL"
F 14 "\\nI/O Port Expander 16-Bit I2C I'face SDIP-28 | Microchip Technology Inc. MCP23017-E/SP\\n" H 9550 3600 50  0001 L BNN "Description"
F 15 "Microchip" H 9550 3600 50  0001 L BNN "MANUFACTURER"
F 16 "In Stock" H 9550 3600 50  0001 L BNN "Availability"
F 17 "5.08mm" H 9550 3600 50  0001 L BNN "MAXIMUM_PACKAGE_HEIGHT"
	1    9550 3600
	1    0    0    -1  
$EndComp
Text GLabel 8950 3000 0    50   Input ~ 0
I2CIOExpander_SCK
Text GLabel 8950 3100 0    50   Input ~ 0
I2CIOExpander_SDA
Text GLabel 8950 3300 0    50   Input ~ 0
I2CIOExpander_A0
Text GLabel 8950 3400 0    50   Input ~ 0
I2CIOExpander_A1
Text GLabel 8950 3500 0    50   Input ~ 0
I2CIOExpander_A2
Text GLabel 10150 2600 2    50   Input ~ 0
I2CIOExpander_Vin
Text GLabel 10450 3000 2    50   Input ~ 0
I2CIOExpander_INA
Text GLabel 10450 3100 2    50   Input ~ 0
I2CIOExpander_INB
Text GLabel 10450 3900 2    50   Input ~ 0
I2CIOExpander_B2
Text GLabel 10450 4000 2    50   Input ~ 0
I2CIOExpander_B3
Text GLabel 10450 4100 2    50   Input ~ 0
I2CIOExpander_B4
Text GLabel 10450 4200 2    50   Input ~ 0
I2CIOExpander_B5
Text GLabel 10450 4300 2    50   Input ~ 0
I2CIOExpander_B6
Text GLabel 10450 4400 2    50   Input ~ 0
I2CIOExpander_B7
Text GLabel 10150 4700 2    50   Input ~ 0
I2CIOExpander_GND
$Comp
L Switch:SW_DIP_x08 DIP_Switch1
U 1 1 6758FFA1
P 10600 6050
F 0 "DIP_Switch1" H 10600 6717 50  0000 C CNN
F 1 "DIP_Switch" H 10600 6626 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_LongPads" H 10600 6050 50  0001 C CNN
F 3 "~" H 10600 6050 50  0001 C CNN
	1    10600 6050
	1    0    0    -1  
$EndComp
Text GLabel 11050 5750 3    50   Input ~ 0
DIP_GND
Wire Wire Line
	10950 6350 10900 6350
Wire Wire Line
	10900 6250 10950 6250
Connection ~ 10950 6250
Wire Wire Line
	10950 6250 10950 6350
Wire Wire Line
	10950 6150 10900 6150
Connection ~ 10950 6150
Wire Wire Line
	10950 6150 10950 6250
Wire Wire Line
	10900 6050 10950 6050
Connection ~ 10950 6050
Wire Wire Line
	10950 6050 10950 6150
Wire Wire Line
	10950 5950 10900 5950
Connection ~ 10950 5950
Wire Wire Line
	10950 5950 10950 6050
Wire Wire Line
	10900 5850 10950 5850
Connection ~ 10950 5850
Wire Wire Line
	10950 5850 10950 5950
Wire Wire Line
	10950 5750 10900 5750
Connection ~ 10950 5750
Wire Wire Line
	10950 5750 10950 5850
Wire Wire Line
	10900 5650 10950 5650
Wire Wire Line
	10950 5650 10950 5750
Text GLabel 10250 6350 0    50   Input ~ 0
DIP_0
Text GLabel 10250 6250 0    50   Input ~ 0
DIP_1
Text GLabel 10250 6050 0    50   Input ~ 0
DIP_3
Text GLabel 10250 5950 0    50   Input ~ 0
DIP_4
Text GLabel 10250 5850 0    50   Input ~ 0
DIP_5
Text GLabel 10250 5750 0    50   Input ~ 0
DIP_6
Text GLabel 10250 5650 0    50   Input ~ 0
DIP_7
Text GLabel 1450 750  0    50   Input ~ 0
SpannungsMessungAkku
Wire Notes Line
	500  500  2300 500 
Wire Notes Line
	2300 500  2300 1100
Wire Notes Line
	2300 1100 500  1100
Wire Notes Line
	500  1100 500  500 
Wire Notes Line
	500  1650 2300 1650
Wire Notes Line
	2300 2100 500  2100
Wire Notes Line
	500  2100 500  1650
Wire Notes Line
	2300 1650 2300 2100
Wire Wire Line
	11050 5750 10950 5750
Wire Notes Line
	11150 5300 9100 5300
Wire Notes Line
	9100 5300 9100 6500
Wire Notes Line
	9100 6500 11150 6500
Wire Notes Line
	11150 6500 11150 5300
Wire Notes Line
	2500 500  5350 500 
Wire Notes Line
	5350 1850 2500 1850
Wire Notes Line
	2500 1850 2500 500 
Text GLabel 5150 4400 2    50   Input ~ 0
GND
Text GLabel 5150 4500 2    50   Input ~ 0
3.3V
Text GLabel 3300 600  0    50   Input ~ 0
GND
Text GLabel 3300 1250 0    50   Input ~ 0
GND
Text GLabel 3300 700  0    50   Input ~ 0
3.3V
Text GLabel 3300 1350 0    50   Input ~ 0
3.3V
Wire Wire Line
	3300 600  4900 600 
Wire Wire Line
	4900 700  3300 700 
Wire Wire Line
	3300 1250 4900 1250
Wire Wire Line
	4900 1350 3300 1350
Text GLabel 5700 700  0    50   Input ~ 0
GND
Text GLabel 5700 600  0    50   Input ~ 0
3.3V
Wire Wire Line
	5700 600  7000 600 
Wire Wire Line
	5700 700  7000 700 
Text GLabel 5950 5100 2    50   Input ~ 0
I2C_SDA
Text GLabel 5950 5000 2    50   Input ~ 0
I2C_SCL
Text GLabel 5850 900  0    50   Input ~ 0
I2C_SDA
Text GLabel 5850 800  0    50   Input ~ 0
I2C_SCL
Wire Wire Line
	5850 800  7000 800 
Wire Wire Line
	5850 900  7000 900 
Wire Notes Line
	7450 500  7450 1150
Wire Notes Line
	5400 1150 5400 500 
Wire Notes Line
	5400 500  7450 500 
Wire Notes Line
	5400 1150 7450 1150
Text GLabel 5700 1400 0    50   Input ~ 0
GND
Text GLabel 5700 1300 0    50   Input ~ 0
3.3V
Wire Wire Line
	5700 1300 7000 1300
Wire Wire Line
	5700 1400 7000 1400
Wire Wire Line
	5850 1500 7000 1500
Wire Wire Line
	5850 1600 7000 1600
Wire Notes Line
	5400 1200 7450 1200
Wire Notes Line
	7450 1200 7450 1850
Wire Notes Line
	7450 1850 5400 1850
Wire Notes Line
	5400 1850 5400 1200
$Comp
L Connector_Generic:Conn_01x04 Display1
U 1 1 67E7DB53
P 9000 700
F 0 "Display1" H 9080 692 50  0000 L CNN
F 1 "Display" H 8550 400 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 9000 700 50  0001 C CNN
F 3 "~" H 9000 700 50  0001 C CNN
	1    9000 700 
	1    0    0    -1  
$EndComp
Text GLabel 6950 1600 0    50   Input ~ 0
IMU_SDA
Text GLabel 6950 1500 0    50   Input ~ 0
IMU_SCL
Text GLabel 5850 1500 0    50   Input ~ 0
I2C_SCL
Text GLabel 5850 1600 0    50   Input ~ 0
I2C_SDA
Text GLabel 7800 700  0    50   Input ~ 0
GND
Text GLabel 7800 600  0    50   Input ~ 0
3.3V
Text GLabel 7950 800  0    50   Input ~ 0
I2C_SCL
Text GLabel 7950 900  0    50   Input ~ 0
I2C_SDA
Wire Wire Line
	7800 600  8800 600 
Wire Wire Line
	7800 700  8800 700 
Wire Wire Line
	7950 800  8800 800 
Wire Wire Line
	7950 900  8800 900 
Wire Notes Line
	7550 500  9250 500 
Wire Notes Line
	9250 500  9250 1100
Wire Notes Line
	9250 1100 7550 1100
Wire Notes Line
	7550 1100 7550 500 
Text GLabel 9850 1200 0    50   Input ~ 0
GND
Text GLabel 9850 600  0    50   Input ~ 0
3.3V
Text GLabel 1350 5600 0    50   Input ~ 0
SPI0_MOSI
Text GLabel 1350 5500 0    50   Input ~ 0
SPI0_MISO
Text GLabel 5950 5600 2    50   Input ~ 0
SPI0_SCK
Text GLabel 1350 5400 0    50   Input ~ 0
SPI0_CS
Text GLabel 9850 900  0    50   Input ~ 0
SPI1_MOSI
Text GLabel 9850 1000 0    50   Input ~ 0
SPI1_MISO
Text GLabel 9850 800  0    50   Input ~ 0
SPI1_SCK
Text GLabel 9850 700  0    50   Input ~ 0
SPI1_CS
Wire Wire Line
	9850 600  10800 600 
Wire Wire Line
	9850 700  10800 700 
Wire Wire Line
	9850 800  10800 800 
Wire Wire Line
	9850 900  10800 900 
Wire Wire Line
	9850 1000 10800 1000
Wire Wire Line
	9850 1200 10800 1200
Wire Notes Line
	9300 500  9300 1450
Wire Notes Line
	9300 1450 11200 1450
Wire Notes Line
	11200 1450 11200 500 
Wire Notes Line
	11200 500  9300 500 
$Comp
L Connector_Generic:Conn_01x03 LED_Streifen1
U 1 1 682C6B67
P 8950 1400
F 0 "LED_Streifen1" H 9030 1392 50  0000 L CNN
F 1 "LED_Streifen" H 8750 1050 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 8950 1400 50  0001 C CNN
F 3 "~" H 8950 1400 50  0001 C CNN
	1    8950 1400
	1    0    0    -1  
$EndComp
Text GLabel 8700 1300 0    50   Input ~ 0
LED_GND
Text GLabel 8700 1400 0    50   Input ~ 0
LED_5V
Text GLabel 8700 1500 0    50   Input ~ 0
LED_DIN
Text GLabel 11050 6150 3    50   Input ~ 0
GND
Wire Wire Line
	11050 6150 10950 6150
Text GLabel 8250 1300 0    50   Input ~ 0
GND
Wire Wire Line
	8250 1300 8750 1300
Text GLabel 5150 4300 2    50   Input ~ 0
5V
Text GLabel 750  1350 0    50   Input ~ 0
5V
Text GLabel 750  1850 0    50   Input ~ 0
7.2V
Text GLabel 8250 1400 0    50   Input ~ 0
5V
Wire Wire Line
	8250 1400 8750 1400
Wire Notes Line
	7550 1200 9250 1200
Wire Notes Line
	9250 1200 9250 1850
Wire Notes Line
	9250 1850 7550 1850
Wire Notes Line
	7550 1850 7550 1200
Wire Wire Line
	10250 1800 10300 1800
Wire Wire Line
	10450 1950 10450 2000
Wire Wire Line
	10650 1800 10600 1800
Text GLabel 10450 2000 0    50   Input ~ 0
POT_0_Data
Text GLabel 10200 1700 0    50   Input ~ 0
POT_Vin
Text GLabel 10200 1600 0    50   Input ~ 0
POT_GND
$Comp
L Device:R_POT POT_0
U 1 1 67652BC3
P 10450 1800
F 0 "POT_0" H 10381 1846 50  0000 R CNN
F 1 "POT_0" H 10381 1755 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Alpha_RD901F-40-00D_Single_Vertical" H 10450 1800 50  0001 C CNN
F 3 "~" H 10450 1800 50  0001 C CNN
	1    10450 1800
	0    1    1    0   
$EndComp
Wire Wire Line
	10750 1800 10800 1800
Wire Wire Line
	11150 1800 11100 1800
Text GLabel 10950 2100 0    50   Input ~ 0
POT_1_Data
$Comp
L Device:R_POT POT_1
U 1 1 676534D6
P 10950 1800
F 0 "POT_1" H 10881 1846 50  0000 R CNN
F 1 "POT_1" H 10881 1755 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Alpha_RD901F-40-00D_Single_Vertical" H 10950 1800 50  0001 C CNN
F 3 "~" H 10950 1800 50  0001 C CNN
	1    10950 1800
	0    1    1    0   
$EndComp
Wire Wire Line
	10250 1700 10250 1800
Wire Wire Line
	10750 1700 10250 1700
Wire Wire Line
	10750 1700 10750 1800
Wire Wire Line
	10650 1600 10650 1800
Wire Wire Line
	11150 1600 10650 1600
Wire Wire Line
	11150 1600 11150 1800
Connection ~ 10650 1600
Text GLabel 9750 1600 0    50   Input ~ 0
GND
Text GLabel 9750 1700 0    50   Input ~ 0
3.3V
Connection ~ 10250 1700
Wire Wire Line
	9750 1600 10650 1600
Wire Wire Line
	9750 1700 10250 1700
Wire Wire Line
	10950 1950 10950 2100
Wire Notes Line
	9300 1500 11200 1500
Wire Notes Line
	11200 1500 11200 2200
Wire Notes Line
	11200 2200 9300 2200
Wire Notes Line
	9300 2200 9300 1500
Text GLabel 1250 3000 0    50   Input ~ 0
7.2V
Text GLabel 1150 2250 0    50   Input ~ 0
GND
Wire Wire Line
	1150 2250 1900 2250
Wire Wire Line
	1250 3000 1900 3000
Wire Wire Line
	750  1850 1900 1850
Wire Wire Line
	750  1750 1900 1750
Text GLabel 750  1250 0    50   Input ~ 0
GND
Wire Wire Line
	750  1250 1900 1250
Wire Wire Line
	1900 1350 750  1350
Wire Notes Line
	500  1150 2300 1150
Wire Notes Line
	2300 1600 500  1600
Wire Notes Line
	2300 1150 2300 1600
Wire Notes Line
	500  1150 500  1600
Wire Notes Line
	500  2150 2300 2150
Wire Notes Line
	2300 2150 2300 2750
Wire Notes Line
	2300 2750 500  2750
Wire Notes Line
	500  2750 500  2150
Wire Notes Line
	500  2800 2300 2800
Wire Notes Line
	2300 2800 2300 3350
Wire Notes Line
	2300 3350 500  3350
Wire Notes Line
	500  3350 500  2800
Text GLabel 8450 6350 2    50   Input ~ 0
Taster_GND
Text GLabel 8450 6250 2    50   Input ~ 0
GND
$Comp
L Taster:TS02-66-95-BK-260-LCR-D Taster_1
U 1 1 68EB158D
P 7900 6050
F 0 "Taster_1" H 7900 6400 50  0000 C CNN
F 1 "Taster_1" H 7900 6400 50  0000 C CNN
F 2 "Taster:SW_TS02-66-95-BK-260-LCR-D" H 7900 6050 50  0001 L BNN
F 3 "" H 7900 6050 50  0001 L BNN
F 4 "Same Sky" H 7900 6050 50  0001 L BNN "MF"
F 5 "\\n6 x 6 mm, 9.5 mm Actuator Height, 260 gf, Black, Long Crimped, Through Hole, SPST, Tactile Switch\\n" H 7900 6050 50  0001 L BNN "Description"
F 6 "None" H 7900 6050 50  0001 L BNN "Package"
F 7 "None" H 7900 6050 50  0001 L BNN "Price"
F 8 "https://www.snapeda.com/parts/TS02-66-95-BK-260-LCR-D/Same+Sky/view-part/?ref=eda" H 7900 6050 50  0001 L BNN "Check_prices"
F 9 "Manufacturer Recommendations" H 7900 6050 50  0001 L BNN "STANDARD"
F 10 "1.0" H 7900 6050 50  0001 L BNN "PARTREV"
F 11 "https://www.snapeda.com/parts/TS02-66-95-BK-260-LCR-D/Same+Sky/view-part/?ref=snap" H 7900 6050 50  0001 L BNN "SnapEDA_Link"
F 12 "TS02-66-95-BK-260-LCR-D" H 7900 6050 50  0001 L BNN "MP"
F 13 "https://www.snapeda.com/api/url_track_click_mouser/?unipart_id=8666106&manufacturer=Same Sky&part_name=TS02-66-95-BK-260-LCR-D&search_term=switch" H 7900 6050 50  0001 L BNN "Purchase-URL"
F 14 "In Stock" H 7900 6050 50  0001 L BNN "Availability"
F 15 "CUI Devices" H 7900 6050 50  0001 L BNN "MANUFACTURER"
	1    7900 6050
	1    0    0    -1  
$EndComp
$Comp
L Taster:TS02-66-95-BK-260-LCR-D Taster_0
U 1 1 68EB6132
P 7950 5150
F 0 "Taster_0" H 7950 5500 50  0000 C CNN
F 1 "Taster_0" H 7950 5500 50  0000 C CNN
F 2 "Taster:SW_TS02-66-95-BK-260-LCR-D" H 7950 5150 50  0001 L BNN
F 3 "" H 7950 5150 50  0001 L BNN
F 4 "Same Sky" H 7950 5150 50  0001 L BNN "MF"
F 5 "\\n6 x 6 mm, 9.5 mm Actuator Height, 260 gf, Black, Long Crimped, Through Hole, SPST, Tactile Switch\\n" H 7950 5150 50  0001 L BNN "Description"
F 6 "None" H 7950 5150 50  0001 L BNN "Package"
F 7 "None" H 7950 5150 50  0001 L BNN "Price"
F 8 "https://www.snapeda.com/parts/TS02-66-95-BK-260-LCR-D/Same+Sky/view-part/?ref=eda" H 7950 5150 50  0001 L BNN "Check_prices"
F 9 "Manufacturer Recommendations" H 7950 5150 50  0001 L BNN "STANDARD"
F 10 "1.0" H 7950 5150 50  0001 L BNN "PARTREV"
F 11 "https://www.snapeda.com/parts/TS02-66-95-BK-260-LCR-D/Same+Sky/view-part/?ref=snap" H 7950 5150 50  0001 L BNN "SnapEDA_Link"
F 12 "TS02-66-95-BK-260-LCR-D" H 7950 5150 50  0001 L BNN "MP"
F 13 "https://www.snapeda.com/api/url_track_click_mouser/?unipart_id=8666106&manufacturer=Same Sky&part_name=TS02-66-95-BK-260-LCR-D&search_term=switch" H 7950 5150 50  0001 L BNN "Purchase-URL"
F 14 "In Stock" H 7950 5150 50  0001 L BNN "Availability"
F 15 "CUI Devices" H 7950 5150 50  0001 L BNN "MANUFACTURER"
	1    7950 5150
	1    0    0    -1  
$EndComp
Text GLabel 8500 5450 2    50   Input ~ 0
Taster_GND
Text GLabel 8500 5350 2    50   Input ~ 0
GND
Wire Wire Line
	8450 5350 8500 5350
Wire Wire Line
	8500 5450 8500 5350
Wire Wire Line
	8450 6250 8450 6350
Wire Wire Line
	7450 4950 7400 4950
Wire Wire Line
	7400 4950 7400 5050
Wire Wire Line
	7350 5950 7350 5850
Wire Wire Line
	7350 5850 7400 5850
Wire Notes Line
	9000 6500 6550 6500
Wire Notes Line
	6550 6500 6550 4700
Wire Notes Line
	6550 4700 8400 4700
Wire Notes Line
	8400 4700 8400 4900
Wire Notes Line
	8400 4900 9000 4900
Wire Notes Line
	9000 4900 9000 6500
Text GLabel 8900 3700 0    50   Input ~ 0
DIP_0
Text GLabel 8900 3800 0    50   Input ~ 0
DIP_1
$Comp
L Connector_Generic:Conn_01x06 J34
U 1 1 6947932C
P 10350 4100
F 0 "J34" H 10350 3600 50  0000 L CNN
F 1 " " H 10100 3700 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 10350 4100 50  0001 C CNN
F 3 "~" H 10350 4100 50  0001 C CNN
	1    10350 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	10450 3900 10150 3900
Connection ~ 10150 3900
Wire Wire Line
	10150 4000 10450 4000
Connection ~ 10150 4000
Wire Wire Line
	10450 4100 10150 4100
Connection ~ 10150 4100
Wire Wire Line
	10150 4200 10450 4200
Connection ~ 10150 4200
Wire Wire Line
	10450 4300 10150 4300
Connection ~ 10150 4300
Wire Wire Line
	10150 4400 10450 4400
Connection ~ 10150 4400
Wire Wire Line
	8100 3000 8950 3000
Wire Wire Line
	8950 3100 8100 3100
Text GLabel 8150 3300 0    50   Input ~ 0
GND
Text GLabel 10950 2600 2    50   Input ~ 0
3.3V
Wire Wire Line
	8150 3300 8950 3300
Wire Wire Line
	8950 3300 8950 3400
Connection ~ 8950 3300
Connection ~ 8950 3400
Wire Wire Line
	8950 3400 8950 3500
Wire Wire Line
	10950 2600 10150 2600
Text GLabel 10950 4700 2    50   Input ~ 0
GND
Wire Wire Line
	10950 4700 10150 4700
Text GLabel 8950 2800 0    50   Input ~ 0
I2CIOExpander_RST
Text GLabel 8100 2800 0    50   Input ~ 0
3.3V
Wire Wire Line
	8100 2800 8950 2800
$Comp
L Connector_Generic:Conn_01x02 IO_Interupt_Out1
U 1 1 697AE3BC
P 10350 3000
F 0 "IO_Interupt_Out1" H 10350 2650 50  0000 L CNN
F 1 "IO_Interupt_Out" H 10150 2750 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 10350 3000 50  0001 C CNN
F 3 "~" H 10350 3000 50  0001 C CNN
	1    10350 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	10150 3000 10450 3000
Connection ~ 10150 3000
Wire Wire Line
	10150 3100 10450 3100
Connection ~ 10150 3100
Wire Notes Line
	11200 4850 8850 4850
Wire Notes Line
	8850 4850 8850 4550
Wire Notes Line
	8850 4550 7650 4550
Wire Notes Line
	7650 4550 7650 2300
Wire Notes Line
	7650 2300 11200 2300
Wire Notes Line
	11200 2300 11200 4850
Text GLabel 1350 6000 0    50   Input ~ 0
SPI1_MOSI
Text GLabel 1350 4500 0    50   Input ~ 0
SPI1_MISO
Text GLabel 1350 6100 0    50   Input ~ 0
SPI1_SCK
Text GLabel 1350 4400 0    50   Input ~ 0
SPI1_CS
Text GLabel 3850 2050 0    50   Input ~ 0
SPI0_MOSI
Text GLabel 3950 1950 0    50   Input ~ 0
SPI0_MISO
Text GLabel 3750 2200 0    50   Input ~ 0
SPI0_SCK
Text GLabel 3650 2350 0    50   Input ~ 0
SPI0_CS
Wire Wire Line
	3950 1950 4000 1950
Wire Wire Line
	4000 1950 4000 2600
Connection ~ 4000 2600
Wire Wire Line
	3900 2700 3900 2050
Wire Wire Line
	3900 2050 3850 2050
Connection ~ 3900 2700
Wire Wire Line
	3750 2200 3800 2200
Wire Wire Line
	3800 2200 3800 2800
Connection ~ 3800 2800
Wire Wire Line
	3700 2900 3700 2350
Wire Wire Line
	3700 2350 3650 2350
Connection ~ 3700 2900
Text GLabel 7500 2750 1    50   Input ~ 0
GND
Text GLabel 7400 2400 1    50   Input ~ 0
5V
Wire Wire Line
	7500 3300 7500 2750
Connection ~ 7500 3300
Wire Wire Line
	7400 2400 7400 3200
Connection ~ 7400 3200
Wire Notes Line
	7600 3800 7600 1900
Wire Notes Line
	3200 1900 3200 3800
Wire Notes Line
	3200 3800 7600 3800
Wire Notes Line
	3200 1900 7600 1900
Wire Wire Line
	1400 650  1450 650 
Wire Wire Line
	1450 750  1450 650 
Connection ~ 1450 650 
Wire Wire Line
	1450 650  1500 650 
Text GLabel 5950 6100 2    50   Input ~ 0
SpannungsMessungAkku
Wire Wire Line
	1900 2450 1850 2450
Text GLabel 1350 6300 0    50   Input ~ 0
Motor_ESC_Data
Wire Wire Line
	1900 3100 1850 3100
Text GLabel 1350 6200 0    50   Input ~ 0
Servo_Data
Text GLabel 1350 4700 0    50   Input ~ 0
AchsenGeschwindigkeitsMessung_0_Data
Text GLabel 1350 4600 0    50   Input ~ 0
AchsenGeschwindigkeitsMessung_1_Data
Wire Wire Line
	8700 1500 8750 1500
Text GLabel 5950 5500 2    50   Input ~ 0
LED_DIN
Text GLabel 7300 3100 1    50   Input ~ 0
Cam_GPIO_7
Text GLabel 6000 4700 2    50   Input ~ 0
Cam_GPIO_7
NoConn ~ 4800 4150
NoConn ~ 4800 6850
NoConn ~ 4800 6950
NoConn ~ 4800 7050
NoConn ~ 4800 7150
NoConn ~ 4800 7250
NoConn ~ 4800 7350
NoConn ~ 4000 7750
NoConn ~ 3850 7750
NoConn ~ 3700 7750
NoConn ~ 3550 7750
NoConn ~ 3400 7750
NoConn ~ 2600 7450
NoConn ~ 2600 7350
NoConn ~ 2600 7250
NoConn ~ 2600 7150
NoConn ~ 2600 7050
NoConn ~ 2600 6900
NoConn ~ 2600 6800
$Comp
L Connector_Generic:Conn_01x02 OF_LED1
U 1 1 6A199387
P 8950 2050
F 0 "OF_LED1" H 9030 2042 50  0000 L CNN
F 1 "OF_LED" H 8650 2150 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 8950 2050 50  0001 C CNN
F 3 "~" H 8950 2050 50  0001 C CNN
	1    8950 2050
	1    0    0    -1  
$EndComp
Text GLabel 8350 2050 0    50   Input ~ 0
GND
Text GLabel 8350 2150 0    50   Input ~ 0
LED_OpticalFlow
$Comp
L Device:R R2
U 1 1 6A1D2F35
P 8550 2150
F 0 "R2" V 8650 2150 50  0000 C CNN
F 1 "330" V 8434 2150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P1.90mm_Vertical" V 8480 2150 50  0001 C CNN
F 3 "~" H 8550 2150 50  0001 C CNN
	1    8550 2150
	0    1    1    0   
$EndComp
Wire Wire Line
	8700 2150 8750 2150
Wire Wire Line
	8350 2150 8400 2150
Wire Wire Line
	8350 2050 8750 2050
Wire Notes Line
	7650 2250 9250 2250
Wire Notes Line
	9250 2250 9250 1900
Wire Notes Line
	9250 1900 7650 1900
Wire Notes Line
	7650 1900 7650 2250
Text GLabel 6000 4600 2    50   Input ~ 0
LED_OpticalFlow
Wire Wire Line
	4850 4300 5150 4300
Connection ~ 4850 4300
Wire Wire Line
	5150 4400 4850 4400
Connection ~ 4850 4400
Wire Wire Line
	4850 4500 5150 4500
Connection ~ 4850 4500
Text GLabel 8900 4400 0    50   Input ~ 0
DIP_7
Text GLabel 8900 4300 0    50   Input ~ 0
DIP_6
Text GLabel 8900 4200 0    50   Input ~ 0
DIP_5
Text GLabel 8900 4100 0    50   Input ~ 0
DIP_4
Text GLabel 8900 4000 0    50   Input ~ 0
DIP_3
Text GLabel 8900 3900 0    50   Input ~ 0
DIP_2
Text GLabel 10250 6150 0    50   Input ~ 0
DIP_2
Wire Wire Line
	8900 3700 8950 3700
Wire Wire Line
	8950 3800 8900 3800
Wire Wire Line
	8900 3900 8950 3900
Wire Wire Line
	8950 4000 8900 4000
Wire Wire Line
	8900 4100 8950 4100
Wire Wire Line
	8950 4200 8900 4200
Wire Wire Line
	8900 4300 8950 4300
Wire Wire Line
	8950 4400 8900 4400
Wire Wire Line
	10250 5650 10300 5650
Wire Wire Line
	10300 5750 10250 5750
Wire Wire Line
	10250 5850 10300 5850
Wire Wire Line
	10300 5950 10250 5950
Wire Wire Line
	10300 6050 10250 6050
Wire Wire Line
	10250 6150 10300 6150
Wire Wire Line
	10300 6250 10250 6250
Wire Wire Line
	10250 6350 10300 6350
$Comp
L Connector_Generic:Conn_01x04 I2C_Spare_1
U 1 1 6783F1EF
P 1550 3600
F 0 "I2C_Spare_1" H 1500 3200 50  0000 L CNN
F 1 "I2C_Spare1" H 1350 3300 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 1550 3600 50  0001 C CNN
F 3 "~" H 1550 3600 50  0001 C CNN
	1    1550 3600
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 I2C_Spare_0
U 1 1 67840D55
P 2050 3600
F 0 "I2C_Spare_0" H 2000 3200 50  0000 L CNN
F 1 "I2C_Spare0" H 1850 3300 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 2050 3600 50  0001 C CNN
F 3 "~" H 2050 3600 50  0001 C CNN
	1    2050 3600
	1    0    0    -1  
$EndComp
Text GLabel 1100 3600 0    50   Input ~ 0
GND
Text GLabel 1100 3500 0    50   Input ~ 0
3.3V
Text GLabel 1250 3700 0    50   Input ~ 0
I2C_SCL
Text GLabel 1250 3800 0    50   Input ~ 0
I2C_SDA
Wire Wire Line
	1100 3500 1350 3500
Connection ~ 1350 3500
Wire Wire Line
	1350 3500 1850 3500
Wire Wire Line
	1100 3600 1350 3600
Connection ~ 1350 3600
Wire Wire Line
	1350 3600 1850 3600
Wire Wire Line
	1850 3700 1350 3700
Connection ~ 1350 3700
Wire Wire Line
	1350 3700 1250 3700
Wire Wire Line
	1250 3800 1350 3800
Connection ~ 1350 3800
Wire Wire Line
	1350 3800 1850 3800
Wire Notes Line
	500  3400 2300 3400
Wire Notes Line
	2300 3400 2300 4100
Wire Notes Line
	2300 4100 500  4100
Wire Notes Line
	500  4100 500  3400
Text GLabel 8100 3000 0    50   Input ~ 0
I2C_SCL
Text GLabel 8100 3100 0    50   Input ~ 0
I2C_SDA
Text GLabel 7350 5950 0    50   Input ~ 0
I2CIOExpander_B1
Text GLabel 7350 5850 0    50   Input ~ 0
SW_1
Text GLabel 7400 5050 0    50   Input ~ 0
I2CIOExpander_B0
Text GLabel 7400 4950 0    50   Input ~ 0
SW_0
Wire Wire Line
	10150 3800 10950 3800
Text GLabel 10950 3800 2    50   Input ~ 0
SW_1
Text GLabel 10150 3800 2    50   Input ~ 0
I2CIOExpander_B1
Wire Wire Line
	10950 3700 10150 3700
Text GLabel 10950 3700 2    50   Input ~ 0
SW_0
Text GLabel 10150 3700 2    50   Input ~ 0
I2CIOExpander_B0
Wire Wire Line
	7400 6250 8400 6250
Connection ~ 8400 6250
Wire Wire Line
	8400 6250 8450 6250
Text GLabel 750  1750 0    50   Input ~ 0
GND
Text GLabel 1250 2900 0    50   Input ~ 0
GND
Wire Wire Line
	1250 2900 1900 2900
$Comp
L Connector_Generic:Conn_02x06_Odd_Even J40
U 1 1 67BEAA12
P 1950 6000
F 0 "J40" H 2000 6417 50  0000 C CNN
F 1 "_" H 2000 6326 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x06_P2.54mm_Vertical" H 1950 6000 50  0001 C CNN
F 3 "~" H 1950 6000 50  0001 C CNN
	1    1950 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 6000 2550 6000
Connection ~ 2550 6000
Wire Wire Line
	2550 6100 2250 6100
Connection ~ 2550 6100
$Comp
L Connector_Generic:Conn_02x03_Odd_Even J41
U 1 1 67CDE99F
P 1950 5500
F 0 "J41" H 2000 5817 50  0000 C CNN
F 1 "_" H 2000 5726 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" H 1950 5500 50  0001 C CNN
F 3 "~" H 1950 5500 50  0001 C CNN
	1    1950 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 5400 2550 5400
Connection ~ 2550 5400
Wire Wire Line
	2550 5500 2250 5500
Connection ~ 2550 5500
Wire Wire Line
	2250 5600 2550 5600
Connection ~ 2550 5600
Wire Wire Line
	2250 4500 2550 4500
Connection ~ 2550 4500
Wire Wire Line
	2550 4400 2250 4400
Connection ~ 2550 4400
Wire Wire Line
	5150 5000 4850 5000
Connection ~ 4850 5000
Wire Wire Line
	4850 5100 5150 5100
Connection ~ 4850 5100
$Comp
L Connector_Generic:Conn_02x04_Odd_Even J42
U 1 1 680E1AE5
P 1950 4500
F 0 "J42" H 2000 4817 50  0000 C CNN
F 1 "_" H 2000 4726 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x04_P2.54mm_Vertical" H 1950 4500 50  0001 C CNN
F 3 "~" H 1950 4500 50  0001 C CNN
	1    1950 4500
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x02_Odd_Even J43
U 1 1 6813188F
P 5350 5000
F 0 "J43" H 5400 5217 50  0000 C CNN
F 1 "_" H 5400 5126 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x02_P2.54mm_Vertical" H 5350 5000 50  0001 C CNN
F 3 "~" H 5350 5000 50  0001 C CNN
	1    5350 5000
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x02_Odd_Even J44
U 1 1 681982BC
P 5350 5500
F 0 "J44" H 5400 5717 50  0000 C CNN
F 1 "_" H 5400 5626 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x02_P2.54mm_Vertical" H 5350 5500 50  0001 C CNN
F 3 "~" H 5350 5500 50  0001 C CNN
	1    5350 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 5600 4850 5600
Connection ~ 4850 5600
$Comp
L Connector_Generic:Conn_01x03 J46
U 1 1 681B623F
P 1550 5500
F 0 "J46" H 1468 5175 50  0000 C CNN
F 1 "_" H 1468 5266 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 1550 5500 50  0001 C CNN
F 3 "~" H 1550 5500 50  0001 C CNN
	1    1550 5500
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J48
U 1 1 681B7CC6
P 5850 5500
F 0 "J48" H 5800 5600 50  0000 L CNN
F 1 "_" H 5800 5400 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5850 5500 50  0001 C CNN
F 3 "~" H 5850 5500 50  0001 C CNN
	1    5850 5500
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 J45
U 1 1 681BAF90
P 1550 6100
F 0 "J45" H 1468 5575 50  0000 C CNN
F 1 "_" H 1468 5666 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 1550 6100 50  0001 C CNN
F 3 "~" H 1550 6100 50  0001 C CNN
	1    1550 6100
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J47
U 1 1 681BDAB3
P 1550 4600
F 0 "J47" H 1468 4175 50  0000 C CNN
F 1 "_" H 1468 4266 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 1550 4600 50  0001 C CNN
F 3 "~" H 1550 4600 50  0001 C CNN
	1    1550 4600
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J50
U 1 1 681D8EF8
P 5850 5000
F 0 "J50" H 5930 4992 50  0000 L CNN
F 1 "_" H 5930 4901 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5850 5000 50  0001 C CNN
F 3 "~" H 5850 5000 50  0001 C CNN
	1    5850 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 4400 1750 4400
Connection ~ 1750 4400
Wire Wire Line
	1750 4500 1350 4500
Connection ~ 1750 4500
Wire Wire Line
	1350 5400 1750 5400
Connection ~ 1750 5400
Wire Wire Line
	1750 5500 1350 5500
Connection ~ 1750 5500
Wire Wire Line
	1350 5600 1750 5600
Connection ~ 1750 5600
Wire Wire Line
	1750 6000 1350 6000
Connection ~ 1750 6000
Wire Wire Line
	1350 6100 1750 6100
Connection ~ 1750 6100
Wire Wire Line
	5650 5000 5950 5000
Connection ~ 5650 5000
Wire Wire Line
	5950 5100 5650 5100
Connection ~ 5650 5100
Wire Wire Line
	5950 5600 5650 5600
Connection ~ 5650 5600
$Comp
L Connector:Conn_01x01_Male J51
U 1 1 6845747E
P 1700 2550
F 0 "J51" H 1650 2550 50  0000 R CNN
F 1 " " H 1500 2550 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 1700 2550 50  0001 C CNN
F 3 "~" H 1700 2550 50  0001 C CNN
	1    1700 2550
	1    0    0    -1  
$EndComp
Text GLabel 1350 5800 0    50   Input ~ 0
POT_0_Data
Text GLabel 1350 5900 0    50   Input ~ 0
POT_1_Data
Wire Wire Line
	2250 4600 2550 4600
Connection ~ 2550 4600
Wire Wire Line
	2550 4700 2250 4700
Connection ~ 2550 4700
Wire Wire Line
	1350 4600 1750 4600
Connection ~ 1750 4600
Wire Wire Line
	1750 4700 1350 4700
Connection ~ 1750 4700
Wire Wire Line
	2250 5800 2550 5800
Connection ~ 2550 5800
Wire Wire Line
	2550 5900 2250 5900
Connection ~ 2550 5900
Wire Wire Line
	2250 6200 2550 6200
Connection ~ 2550 6200
Wire Wire Line
	2250 6300 2550 6300
Connection ~ 2550 6300
Wire Wire Line
	1750 6300 1350 6300
Connection ~ 1750 6300
Wire Wire Line
	1350 6200 1750 6200
Connection ~ 1750 6200
Wire Wire Line
	1750 5900 1350 5900
Connection ~ 1750 5900
Wire Wire Line
	1350 5800 1750 5800
Connection ~ 1750 5800
$Comp
L Connector_Generic:Conn_02x02_Odd_Even J49
U 1 1 68964F9D
P 5350 4600
F 0 "J49" H 5400 4817 50  0000 C CNN
F 1 "_" H 5400 4726 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x02_P2.54mm_Vertical" H 5350 4600 50  0001 C CNN
F 3 "~" H 5350 4600 50  0001 C CNN
	1    5350 4600
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J52
U 1 1 68964FA3
P 5850 4600
F 0 "J52" H 5850 4700 50  0000 L CNN
F 1 "_" H 5930 4501 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5850 4600 50  0001 C CNN
F 3 "~" H 5850 4600 50  0001 C CNN
	1    5850 4600
	1    0    0    -1  
$EndComp
Connection ~ 5650 4600
Connection ~ 5650 4700
Wire Wire Line
	5650 4600 6000 4600
Wire Wire Line
	5650 4700 6000 4700
Wire Wire Line
	5150 4600 4850 4600
Connection ~ 4850 4600
Wire Wire Line
	4850 4700 5150 4700
Connection ~ 4850 4700
Wire Wire Line
	5950 5500 5650 5500
Connection ~ 5650 5500
Wire Wire Line
	4850 5500 5150 5500
Connection ~ 4850 5500
$Comp
L Connector_Generic:Conn_02x01 J53
U 1 1 68AAED73
P 5350 6100
F 0 "J53" H 5400 6317 50  0000 C CNN
F 1 "_" H 5400 6226 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x01_P2.54mm_Vertical" H 5350 6100 50  0001 C CNN
F 3 "~" H 5350 6100 50  0001 C CNN
	1    5350 6100
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J54
U 1 1 68AAED79
P 5850 6100
F 0 "J54" H 5800 6200 50  0000 L CNN
F 1 "_" H 5800 6000 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 5850 6100 50  0001 C CNN
F 3 "~" H 5850 6100 50  0001 C CNN
	1    5850 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 6100 5650 6100
Connection ~ 5650 6100
Wire Wire Line
	5150 6100 4850 6100
Connection ~ 4850 6100
Wire Notes Line
	5350 500  5350 1850
$Sheet
S 15650 6800 4650 3350
U 6724FDF5
F0 "Sheet6724FDF4" 50
F1 "file6724FDF4.sch" 50
$EndSheet
$EndSCHEMATC
