EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:switch_array-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 55
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 3050 1300 1100 1150
U 5811D81C
F0 "ic_01" 60
F1 "ic_logic.sch" 60
F2 "V_LOAD_IN" I L 3050 1450 60 
F3 "GND" I L 3050 1650 60 
F4 "V_LOGIC_IN" I L 3050 1550 60 
F5 "SER_OUT" I L 3050 1900 60 
F6 "SER_IN" I L 3050 1800 60 
F7 "SRCLK" I L 3050 2000 60 
F8 "SRCLR" I L 3050 2200 60 
F9 "RCLK" I L 3050 2100 60 
F10 "OE" I L 3050 2300 60 
F11 "OUT_01" I R 4150 1450 60 
F12 "OUT_02" I R 4150 1550 60 
F13 "OUT_03" I R 4150 1650 60 
F14 "OUT_04" I R 4150 1750 60 
F15 "OUT_05" I R 4150 1850 60 
F16 "OUT_06" I R 4150 1950 60 
F17 "OUT_07" I R 4150 2050 60 
F18 "OUT_08" I R 4150 2150 60 
$EndSheet
$Comp
L CONN_02X02 P5
U 1 1 58123F94
P 2250 1100
F 0 "P5" H 2250 1365 50  0000 C CNN
F 1 "PWR" H 2250 1274 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_2x02" H 2250 -100 50  0001 C CNN
F 3 "" H 2250 -100 50  0000 C CNN
	1    2250 1100
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X02 P4
U 1 1 5812B6B5
P 2250 700
F 0 "P4" H 2250 965 50  0000 C CNN
F 1 "PWR" H 2250 874 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_2x02" H 2250 -500 50  0001 C CNN
F 3 "" H 2250 -500 50  0000 C CNN
	1    2250 700 
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P7
U 1 1 5812D4B1
P 9100 5650
F 0 "P7" H 9178 5691 50  0000 L CNN
F 1 "DATA_OUT" H 9178 5600 50  0000 L CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x04" H 9100 5650 50  0001 C CNN
F 3 "" H 9100 5650 50  0000 C CNN
	1    9100 5650
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P1
U 1 1 58132509
P 1450 700
F 0 "P1" V 1415 562 50  0000 R CNN
F 1 "uPWR" V 1324 562 50  0000 R CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x02" H 1450 700 50  0001 C CNN
F 3 "" H 1450 700 50  0000 C CNN
	1    1450 700 
	0    -1   -1   0   
$EndComp
$Comp
L CONN_01X04 P2
U 1 1 5812C33B
P 1200 1950
F 0 "P2" H 1278 1991 50  0000 L CNN
F 1 "DATA_IN" H 1278 1900 50  0000 L CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x04" H 1200 1950 50  0001 C CNN
F 3 "" H 1200 1950 50  0000 C CNN
	1    1200 1950
	-1   0    0    -1  
$EndComp
$Sheet
S 3050 2650 1100 1150
U 581A1347
F0 "ic_02" 60
F1 "ic_logic.sch" 60
F2 "V_LOAD_IN" I L 3050 2800 60 
F3 "GND" I L 3050 3000 60 
F4 "V_LOGIC_IN" I L 3050 2900 60 
F5 "SER_OUT" I L 3050 3250 60 
F6 "SER_IN" I L 3050 3150 60 
F7 "SRCLK" I L 3050 3350 60 
F8 "SRCLR" I L 3050 3550 60 
F9 "RCLK" I L 3050 3450 60 
F10 "OE" I L 3050 3650 60 
F11 "OUT_01" I R 4150 2800 60 
F12 "OUT_02" I R 4150 2900 60 
F13 "OUT_03" I R 4150 3000 60 
F14 "OUT_04" I R 4150 3100 60 
F15 "OUT_05" I R 4150 3200 60 
F16 "OUT_06" I R 4150 3300 60 
F17 "OUT_07" I R 4150 3400 60 
F18 "OUT_08" I R 4150 3500 60 
$EndSheet
$Sheet
S 3050 4000 1100 1150
U 581A63FD
F0 "ic_03" 60
F1 "ic_logic.sch" 60
F2 "V_LOAD_IN" I L 3050 4150 60 
F3 "GND" I L 3050 4350 60 
F4 "V_LOGIC_IN" I L 3050 4250 60 
F5 "SER_OUT" I L 3050 4600 60 
F6 "SER_IN" I L 3050 4500 60 
F7 "SRCLK" I L 3050 4700 60 
F8 "SRCLR" I L 3050 4900 60 
F9 "RCLK" I L 3050 4800 60 
F10 "OE" I L 3050 5000 60 
F11 "OUT_01" I R 4150 4150 60 
F12 "OUT_02" I R 4150 4250 60 
F13 "OUT_03" I R 4150 4350 60 
F14 "OUT_04" I R 4150 4450 60 
F15 "OUT_05" I R 4150 4550 60 
F16 "OUT_06" I R 4150 4650 60 
F17 "OUT_07" I R 4150 4750 60 
F18 "OUT_08" I R 4150 4850 60 
$EndSheet
$Sheet
S 7100 1450 1100 1150
U 581ADE35
F0 "ic_04" 60
F1 "ic_logic.sch" 60
F2 "V_LOAD_IN" I L 7100 1600 60 
F3 "GND" I L 7100 1800 60 
F4 "V_LOGIC_IN" I L 7100 1700 60 
F5 "SER_OUT" I L 7100 2050 60 
F6 "SER_IN" I L 7100 1950 60 
F7 "SRCLK" I L 7100 2150 60 
F8 "SRCLR" I L 7100 2350 60 
F9 "RCLK" I L 7100 2250 60 
F10 "OE" I L 7100 2450 60 
F11 "OUT_01" I R 8200 1600 60 
F12 "OUT_02" I R 8200 1700 60 
F13 "OUT_03" I R 8200 1800 60 
F14 "OUT_04" I R 8200 1900 60 
F15 "OUT_05" I R 8200 2000 60 
F16 "OUT_06" I R 8200 2100 60 
F17 "OUT_07" I R 8200 2200 60 
F18 "OUT_08" I R 8200 2300 60 
$EndSheet
$Sheet
S 7100 2800 1100 1150
U 581ADE48
F0 "ic_05" 60
F1 "ic_logic.sch" 60
F2 "V_LOAD_IN" I L 7100 2950 60 
F3 "GND" I L 7100 3150 60 
F4 "V_LOGIC_IN" I L 7100 3050 60 
F5 "SER_OUT" I L 7100 3400 60 
F6 "SER_IN" I L 7100 3300 60 
F7 "SRCLK" I L 7100 3500 60 
F8 "SRCLR" I L 7100 3700 60 
F9 "RCLK" I L 7100 3600 60 
F10 "OE" I L 7100 3800 60 
F11 "OUT_01" I R 8200 2950 60 
F12 "OUT_02" I R 8200 3050 60 
F13 "OUT_03" I R 8200 3150 60 
F14 "OUT_04" I R 8200 3250 60 
F15 "OUT_05" I R 8200 3350 60 
F16 "OUT_06" I R 8200 3450 60 
F17 "OUT_07" I R 8200 3550 60 
F18 "OUT_08" I R 8200 3650 60 
$EndSheet
$Sheet
S 7100 4150 1100 1150
U 581ADE5B
F0 "ic_06" 60
F1 "ic_logic.sch" 60
F2 "V_LOAD_IN" I L 7100 4300 60 
F3 "GND" I L 7100 4500 60 
F4 "V_LOGIC_IN" I L 7100 4400 60 
F5 "SER_OUT" I L 7100 4750 60 
F6 "SER_IN" I L 7100 4650 60 
F7 "SRCLK" I L 7100 4850 60 
F8 "SRCLR" I L 7100 5050 60 
F9 "RCLK" I L 7100 4950 60 
F10 "OE" I L 7100 5150 60 
F11 "OUT_01" I R 8200 4300 60 
F12 "OUT_02" I R 8200 4400 60 
F13 "OUT_03" I R 8200 4500 60 
F14 "OUT_04" I R 8200 4600 60 
F15 "OUT_05" I R 8200 4700 60 
F16 "OUT_06" I R 8200 4800 60 
F17 "OUT_07" I R 8200 4900 60 
F18 "OUT_08" I R 8200 5000 60 
$EndSheet
$Comp
L CONN_01X24 P6
U 1 1 581C8EE0
P 5600 3150
F 0 "P6" H 5677 3191 50  0000 L CNN
F 1 "OUTPUT 1-24" H 5677 3100 50  0000 L CNN
F 2 "Socket_Strips:Socket_Strip_Straight_2x12" H 5600 3150 50  0001 C CNN
F 3 "" H 5600 3150 50  0000 C CNN
	1    5600 3150
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X24 P8
U 1 1 582A0474
P 9650 3300
F 0 "P8" H 9727 3341 50  0000 L CNN
F 1 "OUTPUT 25-48" H 9727 3250 50  0000 L CNN
F 2 "Socket_Strips:Socket_Strip_Straight_2x12" H 9650 3300 50  0001 C CNN
F 3 "" H 9650 3300 50  0000 C CNN
	1    9650 3300
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5813E6A7
P 5250 2000
F 0 "R1" V 5043 2000 50  0000 C CNN
F 1 "R" V 5134 2000 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 2000 50  0001 C CNN
F 3 "" H 5250 2000 50  0000 C CNN
	1    5250 2000
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 5813EA94
P 5250 2100
F 0 "R2" V 5043 2100 50  0000 C CNN
F 1 "R" V 5134 2100 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 2100 50  0001 C CNN
F 3 "" H 5250 2100 50  0000 C CNN
	1    5250 2100
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 58145122
P 5250 2200
F 0 "R3" V 5043 2200 50  0000 C CNN
F 1 "R" V 5134 2200 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 2200 50  0001 C CNN
F 3 "" H 5250 2200 50  0000 C CNN
	1    5250 2200
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 581453C2
P 5250 2300
F 0 "R4" V 5043 2300 50  0000 C CNN
F 1 "R" V 5134 2300 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 2300 50  0001 C CNN
F 3 "" H 5250 2300 50  0000 C CNN
	1    5250 2300
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 58145662
P 5250 2400
F 0 "R5" V 5043 2400 50  0000 C CNN
F 1 "R" V 5134 2400 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 2400 50  0001 C CNN
F 3 "" H 5250 2400 50  0000 C CNN
	1    5250 2400
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 581458FD
P 5250 2500
F 0 "R6" V 5043 2500 50  0000 C CNN
F 1 "R" V 5134 2500 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 2500 50  0001 C CNN
F 3 "" H 5250 2500 50  0000 C CNN
	1    5250 2500
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 58145B9F
P 5250 2600
F 0 "R7" V 5043 2600 50  0000 C CNN
F 1 "R" V 5134 2600 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 2600 50  0001 C CNN
F 3 "" H 5250 2600 50  0000 C CNN
	1    5250 2600
	0    1    1    0   
$EndComp
$Comp
L R R8
U 1 1 58145E40
P 5250 2700
F 0 "R8" V 5043 2700 50  0000 C CNN
F 1 "R" V 5134 2700 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 2700 50  0001 C CNN
F 3 "" H 5250 2700 50  0000 C CNN
	1    5250 2700
	0    1    1    0   
$EndComp
$Comp
L R R9
U 1 1 581460E4
P 5250 2800
F 0 "R9" V 5043 2800 50  0000 C CNN
F 1 "R" V 5134 2800 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 2800 50  0001 C CNN
F 3 "" H 5250 2800 50  0000 C CNN
	1    5250 2800
	0    1    1    0   
$EndComp
$Comp
L R R10
U 1 1 5814638B
P 5250 2900
F 0 "R10" V 5043 2900 50  0000 C CNN
F 1 "R" V 5134 2900 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 2900 50  0001 C CNN
F 3 "" H 5250 2900 50  0000 C CNN
	1    5250 2900
	0    1    1    0   
$EndComp
$Comp
L R R11
U 1 1 58146635
P 5250 3000
F 0 "R11" V 5043 3000 50  0000 C CNN
F 1 "R" V 5134 3000 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 3000 50  0001 C CNN
F 3 "" H 5250 3000 50  0000 C CNN
	1    5250 3000
	0    1    1    0   
$EndComp
$Comp
L R R12
U 1 1 581468E2
P 5250 3100
F 0 "R12" V 5043 3100 50  0000 C CNN
F 1 "R" V 5134 3100 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 3100 50  0001 C CNN
F 3 "" H 5250 3100 50  0000 C CNN
	1    5250 3100
	0    1    1    0   
$EndComp
$Comp
L R R13
U 1 1 58146B92
P 5250 3200
F 0 "R13" V 5043 3200 50  0000 C CNN
F 1 "R" V 5134 3200 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 3200 50  0001 C CNN
F 3 "" H 5250 3200 50  0000 C CNN
	1    5250 3200
	0    1    1    0   
$EndComp
$Comp
L R R14
U 1 1 58146E45
P 5250 3300
F 0 "R14" V 5043 3300 50  0000 C CNN
F 1 "R" V 5134 3300 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 3300 50  0001 C CNN
F 3 "" H 5250 3300 50  0000 C CNN
	1    5250 3300
	0    1    1    0   
$EndComp
$Comp
L R R15
U 1 1 5814B10F
P 5250 3400
F 0 "R15" V 5043 3400 50  0000 C CNN
F 1 "R" V 5134 3400 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 3400 50  0001 C CNN
F 3 "" H 5250 3400 50  0000 C CNN
	1    5250 3400
	0    1    1    0   
$EndComp
$Comp
L R R16
U 1 1 5814B3C8
P 5250 3500
F 0 "R16" V 5043 3500 50  0000 C CNN
F 1 "R" V 5134 3500 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 3500 50  0001 C CNN
F 3 "" H 5250 3500 50  0000 C CNN
	1    5250 3500
	0    1    1    0   
$EndComp
$Comp
L R R17
U 1 1 5814B684
P 5250 3600
F 0 "R17" V 5043 3600 50  0000 C CNN
F 1 "R" V 5134 3600 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 3600 50  0001 C CNN
F 3 "" H 5250 3600 50  0000 C CNN
	1    5250 3600
	0    1    1    0   
$EndComp
$Comp
L R R18
U 1 1 5814B943
P 5250 3700
F 0 "R18" V 5043 3700 50  0000 C CNN
F 1 "R" V 5134 3700 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 3700 50  0001 C CNN
F 3 "" H 5250 3700 50  0000 C CNN
	1    5250 3700
	0    1    1    0   
$EndComp
$Comp
L R R19
U 1 1 5814BC05
P 5250 3800
F 0 "R19" V 5043 3800 50  0000 C CNN
F 1 "R" V 5134 3800 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 3800 50  0001 C CNN
F 3 "" H 5250 3800 50  0000 C CNN
	1    5250 3800
	0    1    1    0   
$EndComp
$Comp
L R R20
U 1 1 5814BECA
P 5250 3900
F 0 "R20" V 5043 3900 50  0000 C CNN
F 1 "R" V 5134 3900 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 3900 50  0001 C CNN
F 3 "" H 5250 3900 50  0000 C CNN
	1    5250 3900
	0    1    1    0   
$EndComp
$Comp
L R R21
U 1 1 5814C192
P 5250 4000
F 0 "R21" V 5043 4000 50  0000 C CNN
F 1 "R" V 5134 4000 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 4000 50  0001 C CNN
F 3 "" H 5250 4000 50  0000 C CNN
	1    5250 4000
	0    1    1    0   
$EndComp
$Comp
L R R22
U 1 1 5814C45D
P 5250 4100
F 0 "R22" V 5043 4100 50  0000 C CNN
F 1 "R" V 5134 4100 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 4100 50  0001 C CNN
F 3 "" H 5250 4100 50  0000 C CNN
	1    5250 4100
	0    1    1    0   
$EndComp
$Comp
L R R23
U 1 1 5814C72B
P 5250 4200
F 0 "R23" V 5043 4200 50  0000 C CNN
F 1 "R" V 5134 4200 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 4200 50  0001 C CNN
F 3 "" H 5250 4200 50  0000 C CNN
	1    5250 4200
	0    1    1    0   
$EndComp
$Comp
L R R24
U 1 1 5814C9FC
P 5250 4300
F 0 "R24" V 5043 4300 50  0000 C CNN
F 1 "R" V 5134 4300 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5180 4300 50  0001 C CNN
F 3 "" H 5250 4300 50  0000 C CNN
	1    5250 4300
	0    1    1    0   
$EndComp
$Comp
L R R25
U 1 1 5815AD62
P 9300 2150
F 0 "R25" V 9093 2150 50  0000 C CNN
F 1 "R" V 9184 2150 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 2150 50  0001 C CNN
F 3 "" H 9300 2150 50  0000 C CNN
	1    9300 2150
	0    1    1    0   
$EndComp
$Comp
L R R26
U 1 1 5815B74D
P 9300 2250
F 0 "R26" V 9093 2250 50  0000 C CNN
F 1 "R" V 9184 2250 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 2250 50  0001 C CNN
F 3 "" H 9300 2250 50  0000 C CNN
	1    9300 2250
	0    1    1    0   
$EndComp
$Comp
L R R27
U 1 1 5815BA27
P 9300 2350
F 0 "R27" V 9093 2350 50  0000 C CNN
F 1 "R" V 9184 2350 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 2350 50  0001 C CNN
F 3 "" H 9300 2350 50  0000 C CNN
	1    9300 2350
	0    1    1    0   
$EndComp
$Comp
L R R28
U 1 1 5815BD04
P 9300 2450
F 0 "R28" V 9093 2450 50  0000 C CNN
F 1 "R" V 9184 2450 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 2450 50  0001 C CNN
F 3 "" H 9300 2450 50  0000 C CNN
	1    9300 2450
	0    1    1    0   
$EndComp
$Comp
L R R29
U 1 1 5815BFE4
P 9300 2550
F 0 "R29" V 9093 2550 50  0000 C CNN
F 1 "R" V 9184 2550 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 2550 50  0001 C CNN
F 3 "" H 9300 2550 50  0000 C CNN
	1    9300 2550
	0    1    1    0   
$EndComp
$Comp
L R R30
U 1 1 5815C2C7
P 9300 2650
F 0 "R30" V 9093 2650 50  0000 C CNN
F 1 "R" V 9184 2650 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 2650 50  0001 C CNN
F 3 "" H 9300 2650 50  0000 C CNN
	1    9300 2650
	0    1    1    0   
$EndComp
$Comp
L R R31
U 1 1 5815C5AD
P 9300 2750
F 0 "R31" V 9093 2750 50  0000 C CNN
F 1 "R" V 9184 2750 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 2750 50  0001 C CNN
F 3 "" H 9300 2750 50  0000 C CNN
	1    9300 2750
	0    1    1    0   
$EndComp
$Comp
L R R32
U 1 1 5815C896
P 9300 2850
F 0 "R32" V 9093 2850 50  0000 C CNN
F 1 "R" V 9184 2850 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 2850 50  0001 C CNN
F 3 "" H 9300 2850 50  0000 C CNN
	1    9300 2850
	0    1    1    0   
$EndComp
$Comp
L R R33
U 1 1 5815CB82
P 9300 2950
F 0 "R33" V 9093 2950 50  0000 C CNN
F 1 "R" V 9184 2950 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 2950 50  0001 C CNN
F 3 "" H 9300 2950 50  0000 C CNN
	1    9300 2950
	0    1    1    0   
$EndComp
$Comp
L R R34
U 1 1 5815CE71
P 9300 3050
F 0 "R34" V 9093 3050 50  0000 C CNN
F 1 "R" V 9184 3050 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 3050 50  0001 C CNN
F 3 "" H 9300 3050 50  0000 C CNN
	1    9300 3050
	0    1    1    0   
$EndComp
$Comp
L R R35
U 1 1 5815D743
P 9300 3150
F 0 "R35" V 9093 3150 50  0000 C CNN
F 1 "R" V 9184 3150 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 3150 50  0001 C CNN
F 3 "" H 9300 3150 50  0000 C CNN
	1    9300 3150
	0    1    1    0   
$EndComp
$Comp
L R R36
U 1 1 5815DA3C
P 9300 3250
F 0 "R36" V 9093 3250 50  0000 C CNN
F 1 "R" V 9184 3250 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 3250 50  0001 C CNN
F 3 "" H 9300 3250 50  0000 C CNN
	1    9300 3250
	0    1    1    0   
$EndComp
$Comp
L R R37
U 1 1 5815DD34
P 9300 3350
F 0 "R37" V 9093 3350 50  0000 C CNN
F 1 "R" V 9184 3350 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 3350 50  0001 C CNN
F 3 "" H 9300 3350 50  0000 C CNN
	1    9300 3350
	0    1    1    0   
$EndComp
$Comp
L R R38
U 1 1 5815E02F
P 9300 3450
F 0 "R38" V 9093 3450 50  0000 C CNN
F 1 "R" V 9184 3450 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 3450 50  0001 C CNN
F 3 "" H 9300 3450 50  0000 C CNN
	1    9300 3450
	0    1    1    0   
$EndComp
$Comp
L R R39
U 1 1 5815E331
P 9300 3550
F 0 "R39" V 9093 3550 50  0000 C CNN
F 1 "R" V 9184 3550 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 3550 50  0001 C CNN
F 3 "" H 9300 3550 50  0000 C CNN
	1    9300 3550
	0    1    1    0   
$EndComp
$Comp
L R R40
U 1 1 5815E636
P 9300 3650
F 0 "R40" V 9093 3650 50  0000 C CNN
F 1 "R" V 9184 3650 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 3650 50  0001 C CNN
F 3 "" H 9300 3650 50  0000 C CNN
	1    9300 3650
	0    1    1    0   
$EndComp
$Comp
L R R41
U 1 1 58161DC6
P 9300 3750
F 0 "R41" V 9093 3750 50  0000 C CNN
F 1 "R" V 9184 3750 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 3750 50  0001 C CNN
F 3 "" H 9300 3750 50  0000 C CNN
	1    9300 3750
	0    1    1    0   
$EndComp
$Comp
L R R42
U 1 1 581620CD
P 9300 3850
F 0 "R42" V 9093 3850 50  0000 C CNN
F 1 "R" V 9184 3850 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 3850 50  0001 C CNN
F 3 "" H 9300 3850 50  0000 C CNN
	1    9300 3850
	0    1    1    0   
$EndComp
$Comp
L R R43
U 1 1 581623D7
P 9300 3950
F 0 "R43" V 9093 3950 50  0000 C CNN
F 1 "R" V 9184 3950 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 3950 50  0001 C CNN
F 3 "" H 9300 3950 50  0000 C CNN
	1    9300 3950
	0    1    1    0   
$EndComp
$Comp
L R R44
U 1 1 581626E4
P 9300 4050
F 0 "R44" V 9093 4050 50  0000 C CNN
F 1 "R" V 9184 4050 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 4050 50  0001 C CNN
F 3 "" H 9300 4050 50  0000 C CNN
	1    9300 4050
	0    1    1    0   
$EndComp
$Comp
L R R45
U 1 1 581629F4
P 9300 4150
F 0 "R45" V 9093 4150 50  0000 C CNN
F 1 "R" V 9184 4150 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 4150 50  0001 C CNN
F 3 "" H 9300 4150 50  0000 C CNN
	1    9300 4150
	0    1    1    0   
$EndComp
$Comp
L R R46
U 1 1 58162D07
P 9300 4250
F 0 "R46" V 9093 4250 50  0000 C CNN
F 1 "R" V 9184 4250 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 4250 50  0001 C CNN
F 3 "" H 9300 4250 50  0000 C CNN
	1    9300 4250
	0    1    1    0   
$EndComp
$Comp
L R R47
U 1 1 58163021
P 9300 4350
F 0 "R47" V 9093 4350 50  0000 C CNN
F 1 "R" V 9184 4350 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 4350 50  0001 C CNN
F 3 "" H 9300 4350 50  0000 C CNN
	1    9300 4350
	0    1    1    0   
$EndComp
$Comp
L R R48
U 1 1 5816333E
P 9300 4450
F 0 "R48" V 9093 4450 50  0000 C CNN
F 1 "R" V 9184 4450 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9230 4450 50  0001 C CNN
F 3 "" H 9300 4450 50  0000 C CNN
	1    9300 4450
	0    1    1    0   
$EndComp
Connection ~ 2550 1150
Wire Wire Line
	2500 1150 2550 1150
Connection ~ 1950 1300
Wire Wire Line
	1950 1300 2900 1300
Wire Wire Line
	2550 750  2550 1300
Wire Wire Line
	2500 750  2550 750 
Connection ~ 1950 1150
Wire Wire Line
	1950 1150 2000 1150
Wire Wire Line
	2000 750  1950 750 
Connection ~ 1900 1050
Wire Wire Line
	2000 1050 1900 1050
Wire Wire Line
	8400 3750 9150 3750
Wire Wire Line
	8400 4300 8400 3750
Wire Wire Line
	8200 4300 8400 4300
Wire Wire Line
	8500 4400 8200 4400
Wire Wire Line
	8500 3850 8500 4400
Wire Wire Line
	9150 3850 8500 3850
Wire Wire Line
	8600 3950 9150 3950
Wire Wire Line
	8600 4500 8600 3950
Wire Wire Line
	8200 4500 8600 4500
Wire Wire Line
	8700 4600 8200 4600
Wire Wire Line
	8700 4050 8700 4600
Wire Wire Line
	9150 4050 8700 4050
Wire Wire Line
	8800 4150 9150 4150
Wire Wire Line
	8800 4700 8800 4150
Wire Wire Line
	8200 4700 8800 4700
Wire Wire Line
	8900 4800 8200 4800
Wire Wire Line
	8900 4250 8900 4800
Wire Wire Line
	9150 4250 8900 4250
Wire Wire Line
	9000 4900 8200 4900
Wire Wire Line
	9000 4350 9000 4900
Wire Wire Line
	9150 4350 9000 4350
Wire Wire Line
	9100 5000 8200 5000
Wire Wire Line
	9100 4450 9100 5000
Wire Wire Line
	9150 4450 9100 4450
Wire Wire Line
	8200 3650 9150 3650
Wire Wire Line
	9150 3550 8200 3550
Wire Wire Line
	9150 3450 8200 3450
Wire Wire Line
	8200 3350 9150 3350
Wire Wire Line
	8200 3250 9150 3250
Wire Wire Line
	8200 3150 9150 3150
Wire Wire Line
	9150 3050 8200 3050
Wire Wire Line
	8200 2950 9150 2950
Wire Wire Line
	9100 2150 9100 1600
Wire Wire Line
	9000 1700 9000 2250
Wire Wire Line
	8900 1800 8900 2350
Wire Wire Line
	8800 1900 8800 2450
Wire Wire Line
	8700 2000 8700 2550
Wire Wire Line
	8600 2650 8600 2100
Wire Wire Line
	8500 2200 8500 2750
Wire Wire Line
	8400 2850 8400 2300
Wire Wire Line
	8400 2300 8200 2300
Wire Wire Line
	9150 2850 8400 2850
Wire Wire Line
	8500 2750 9150 2750
Wire Wire Line
	8200 2200 8500 2200
Wire Wire Line
	8600 2100 8200 2100
Wire Wire Line
	9150 2650 8600 2650
Wire Wire Line
	8700 2550 9150 2550
Wire Wire Line
	8200 2000 8700 2000
Wire Wire Line
	8800 2450 9150 2450
Wire Wire Line
	8200 1900 8800 1900
Wire Wire Line
	8900 2350 9150 2350
Wire Wire Line
	8200 1800 8900 1800
Wire Wire Line
	9000 2250 9150 2250
Wire Wire Line
	8200 1700 9000 1700
Wire Wire Line
	9100 1600 8200 1600
Wire Wire Line
	9150 2150 9100 2150
Connection ~ 6350 4300
Wire Wire Line
	7100 4300 6350 4300
Connection ~ 6450 4400
Wire Wire Line
	7100 4400 6450 4400
Connection ~ 6550 4500
Wire Wire Line
	7100 4500 6550 4500
Connection ~ 6350 2950
Wire Wire Line
	7100 2950 6350 2950
Connection ~ 6450 3050
Wire Wire Line
	7100 3050 6450 3050
Connection ~ 6550 3150
Wire Wire Line
	7100 3150 6550 3150
Connection ~ 2350 4150
Wire Wire Line
	6350 6100 6350 1600
Wire Wire Line
	2350 6100 6350 6100
Connection ~ 2450 4250
Wire Wire Line
	6450 6000 2450 6000
Connection ~ 2550 4350
Wire Wire Line
	6550 5900 2550 5900
Wire Wire Line
	6250 1950 7100 1950
Wire Wire Line
	6250 5350 6250 1950
Wire Wire Line
	6350 1600 7100 1600
Wire Wire Line
	6450 1700 6450 6000
Wire Wire Line
	7100 1700 6450 1700
Wire Wire Line
	6550 1800 6550 5900
Wire Wire Line
	7100 1800 6550 1800
Connection ~ 2550 3000
Wire Wire Line
	2550 4350 3050 4350
Connection ~ 2450 2900
Wire Wire Line
	2450 4250 3050 4250
Connection ~ 2350 2800
Wire Wire Line
	2350 4150 3050 4150
Connection ~ 2350 1450
Wire Wire Line
	2350 1450 2350 6100
Wire Wire Line
	3050 2800 2350 2800
Connection ~ 2450 1550
Wire Wire Line
	2450 6000 2450 1550
Wire Wire Line
	3050 2900 2450 2900
Connection ~ 2550 1650
Wire Wire Line
	2550 5900 2550 1650
Wire Wire Line
	3050 3000 2550 3000
Connection ~ 2850 4800
Connection ~ 6850 5600
Connection ~ 2750 4900
Connection ~ 6750 5700
Connection ~ 6650 5800
Connection ~ 2650 5000
Wire Wire Line
	2650 5800 8900 5800
Connection ~ 6850 2250
Wire Wire Line
	7100 2150 6850 2150
Connection ~ 6850 3500
Wire Wire Line
	7100 2250 6850 2250
Connection ~ 6750 3700
Wire Wire Line
	6750 2350 7100 2350
Connection ~ 6650 3800
Wire Wire Line
	7100 2450 6650 2450
Connection ~ 6650 5150
Wire Wire Line
	6650 3800 7100 3800
Connection ~ 6850 3600
Wire Wire Line
	7100 3600 6850 3600
Connection ~ 6750 5050
Wire Wire Line
	6750 3700 7100 3700
Connection ~ 6850 4850
Wire Wire Line
	6850 3500 7100 3500
Wire Wire Line
	6650 5150 7100 5150
Wire Wire Line
	6650 2450 6650 5800
Wire Wire Line
	2750 5700 8900 5700
Wire Wire Line
	6750 2350 6750 5700
Wire Wire Line
	7100 5050 6750 5050
Connection ~ 6850 4950
Wire Wire Line
	7100 4950 6850 4950
Wire Wire Line
	2850 5600 8900 5600
Wire Wire Line
	6850 2150 6850 5600
Wire Wire Line
	7100 4850 6850 4850
Wire Wire Line
	6950 5500 8900 5500
Wire Wire Line
	6950 4750 6950 5500
Wire Wire Line
	7100 4750 6950 4750
Wire Wire Line
	6950 4650 7100 4650
Wire Wire Line
	6950 3400 6950 4650
Wire Wire Line
	7100 3400 6950 3400
Wire Wire Line
	6950 3300 7100 3300
Wire Wire Line
	6950 2050 6950 3300
Wire Wire Line
	7100 2050 6950 2050
Wire Wire Line
	2950 5350 6250 5350
Wire Wire Line
	2950 4600 2950 5350
Wire Wire Line
	3050 4600 2950 4600
Wire Wire Line
	4350 3600 5100 3600
Wire Wire Line
	4350 4150 4350 3600
Wire Wire Line
	4150 4150 4350 4150
Wire Wire Line
	4450 4250 4150 4250
Wire Wire Line
	4450 3700 4450 4250
Wire Wire Line
	5100 3700 4450 3700
Wire Wire Line
	4550 3800 5100 3800
Wire Wire Line
	4550 4350 4550 3800
Wire Wire Line
	4150 4350 4550 4350
Wire Wire Line
	4650 4450 4150 4450
Wire Wire Line
	4650 3900 4650 4450
Wire Wire Line
	5100 3900 4650 3900
Wire Wire Line
	4750 4000 5100 4000
Wire Wire Line
	4750 4550 4750 4000
Wire Wire Line
	4150 4550 4750 4550
Wire Wire Line
	4850 4650 4150 4650
Wire Wire Line
	4850 4100 4850 4650
Wire Wire Line
	5100 4100 4850 4100
Wire Wire Line
	4950 4750 4150 4750
Wire Wire Line
	4950 4200 4950 4750
Wire Wire Line
	5100 4200 4950 4200
Wire Wire Line
	5050 4850 4150 4850
Wire Wire Line
	5050 4300 5050 4850
Wire Wire Line
	5100 4300 5050 4300
Wire Wire Line
	4150 3500 5100 3500
Wire Wire Line
	5100 3400 4150 3400
Wire Wire Line
	5100 3300 4150 3300
Wire Wire Line
	4150 3200 5100 3200
Wire Wire Line
	4150 3100 5100 3100
Wire Wire Line
	4150 3000 5100 3000
Wire Wire Line
	5100 2900 4150 2900
Wire Wire Line
	4150 2800 5100 2800
Wire Wire Line
	5050 2000 5050 1450
Wire Wire Line
	4950 1550 4950 2100
Wire Wire Line
	4850 1650 4850 2200
Wire Wire Line
	4750 1750 4750 2300
Wire Wire Line
	4650 1850 4650 2400
Wire Wire Line
	4550 2500 4550 1950
Wire Wire Line
	4450 2050 4450 2600
Wire Wire Line
	4350 2700 4350 2150
Wire Wire Line
	4350 2150 4150 2150
Wire Wire Line
	5100 2700 4350 2700
Wire Wire Line
	4450 2600 5100 2600
Wire Wire Line
	4150 2050 4450 2050
Wire Wire Line
	4550 1950 4150 1950
Wire Wire Line
	5100 2500 4550 2500
Wire Wire Line
	4650 2400 5100 2400
Wire Wire Line
	4150 1850 4650 1850
Wire Wire Line
	4750 2300 5100 2300
Wire Wire Line
	4150 1750 4750 1750
Wire Wire Line
	4850 2200 5100 2200
Wire Wire Line
	4150 1650 4850 1650
Wire Wire Line
	4950 2100 5100 2100
Wire Wire Line
	4150 1550 4950 1550
Wire Wire Line
	5050 1450 4150 1450
Wire Wire Line
	5100 2000 5050 2000
Connection ~ 2650 3650
Connection ~ 2750 3550
Connection ~ 2850 4700
Connection ~ 2850 3450
Wire Wire Line
	2950 3250 3050 3250
Wire Wire Line
	2950 4500 2950 3250
Wire Wire Line
	2650 5000 3050 5000
Wire Wire Line
	2750 4900 3050 4900
Wire Wire Line
	2850 4800 3050 4800
Wire Wire Line
	2850 4700 3050 4700
Wire Wire Line
	2950 4500 3050 4500
Connection ~ 2650 2300
Wire Wire Line
	2650 3650 3050 3650
Connection ~ 2750 2200
Wire Wire Line
	2750 3550 3050 3550
Connection ~ 2850 3350
Wire Wire Line
	2850 3450 3050 3450
Connection ~ 2850 2100
Wire Wire Line
	2850 3350 3050 3350
Wire Wire Line
	2950 3150 3050 3150
Wire Wire Line
	2950 1900 2950 3150
Wire Wire Line
	3050 1900 2950 1900
Connection ~ 1500 1650
Wire Wire Line
	1500 900  1500 1650
Wire Wire Line
	2650 2100 2650 5800
Wire Wire Line
	1400 2100 2650 2100
Wire Wire Line
	2750 2000 2750 5700
Wire Wire Line
	1400 2000 2750 2000
Wire Wire Line
	1400 1900 2850 1900
Connection ~ 1400 1550
Wire Wire Line
	1400 900  1400 1550
Connection ~ 2600 1050
Wire Wire Line
	2500 1050 2600 1050
Connection ~ 2600 1450
Wire Wire Line
	1900 1450 3050 1450
Connection ~ 2850 2000
Wire Wire Line
	2850 2100 3050 2100
Wire Wire Line
	2650 2300 3050 2300
Wire Wire Line
	2750 2200 3050 2200
Wire Wire Line
	2850 1900 2850 5600
Wire Wire Line
	3050 2000 2850 2000
Wire Wire Line
	1400 1800 3050 1800
Wire Wire Line
	2600 650  2600 1450
Wire Wire Line
	2500 650  2600 650 
Wire Wire Line
	1900 650  2000 650 
Wire Wire Line
	1900 650  1900 1450
$Comp
L CONN_01X02 P9
U 1 1 58183BD6
P 3450 750
F 0 "P9" H 3450 1015 50  0000 C CNN
F 1 "GND" H 3450 924 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_2x02" H 3450 -450 50  0001 C CNN
F 3 "" H 3450 -450 50  0000 C CNN
	1    3450 750 
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 950  3200 800 
Connection ~ 3200 950 
Wire Wire Line
	3150 700  3250 700 
Wire Wire Line
	3150 700  3150 950 
Connection ~ 3150 950 
Wire Wire Line
	1400 1550 3050 1550
Wire Wire Line
	1500 1650 3050 1650
Wire Wire Line
	2900 1300 2900 950 
Connection ~ 2550 1300
Wire Wire Line
	1950 750  1950 1300
Wire Wire Line
	3200 800  3250 800 
Wire Wire Line
	2900 950  3200 950 
$EndSCHEMATC
