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
Sheet 2 55
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
S 5650 1850 600  600 
U 58120C2A
F0 "switch_02" 60
F1 "bjt_switch.sch" 60
F2 "SIGNAL_IN" I L 5650 2250 60 
F3 "V_IN" I L 5650 1950 60 
F4 "V_OUT" I R 6250 2050 60 
F5 "GND" I L 5650 2350 60 
$EndSheet
Wire Wire Line
	4850 1150 5650 1150
Wire Wire Line
	5650 1550 5350 1550
Wire Wire Line
	5350 1250 5350 7150
Wire Wire Line
	5550 1950 5650 1950
Connection ~ 5550 1150
Wire Wire Line
	5650 2350 5350 2350
Connection ~ 5350 2350
Wire Wire Line
	4700 1450 5650 1450
$Sheet
S 5650 2650 600  600 
U 58120C57
F0 "switch_03" 60
F1 "bjt_switch.sch" 60
F2 "SIGNAL_IN" I L 5650 3050 60 
F3 "V_IN" I L 5650 2750 60 
F4 "V_OUT" I R 6250 2850 60 
F5 "GND" I L 5650 3150 60 
$EndSheet
Wire Wire Line
	5550 2750 5650 2750
Wire Wire Line
	5350 3150 5650 3150
$Sheet
S 5650 3450 600  600 
U 58120C6C
F0 "switch_04" 60
F1 "bjt_switch.sch" 60
F2 "SIGNAL_IN" I L 5650 3850 60 
F3 "V_IN" I L 5650 3550 60 
F4 "V_OUT" I R 6250 3650 60 
F5 "GND" I L 5650 3950 60 
$EndSheet
$Sheet
S 5650 4250 600  600 
U 58120C7E
F0 "switch_05" 60
F1 "bjt_switch.sch" 60
F2 "SIGNAL_IN" I L 5650 4650 60 
F3 "V_IN" I L 5650 4350 60 
F4 "V_OUT" I R 6250 4450 60 
F5 "GND" I L 5650 4750 60 
$EndSheet
Wire Wire Line
	5550 3550 5650 3550
Wire Wire Line
	5350 3950 5650 3950
Wire Wire Line
	5550 4350 5650 4350
Wire Wire Line
	5350 4750 5650 4750
Wire Wire Line
	4850 3850 5650 3850
$Sheet
S 5650 5050 600  600 
U 58120C97
F0 "switch_06" 60
F1 "bjt_switch.sch" 60
F2 "SIGNAL_IN" I L 5650 5450 60 
F3 "V_IN" I L 5650 5150 60 
F4 "V_OUT" I R 6250 5250 60 
F5 "GND" I L 5650 5550 60 
$EndSheet
Wire Wire Line
	5550 5150 5650 5150
Wire Wire Line
	5350 5550 5650 5550
$Sheet
S 5650 5850 600  600 
U 58120CAC
F0 "switch_07" 60
F1 "bjt_switch.sch" 60
F2 "SIGNAL_IN" I L 5650 6250 60 
F3 "V_IN" I L 5650 5950 60 
F4 "V_OUT" I R 6250 6050 60 
F5 "GND" I L 5650 6350 60 
$EndSheet
Wire Wire Line
	5550 5950 5650 5950
Wire Wire Line
	5350 6350 5650 6350
$Sheet
S 5650 6650 600  600 
U 58120CC1
F0 "switch_08" 60
F1 "bjt_switch.sch" 60
F2 "SIGNAL_IN" I L 5650 7050 60 
F3 "V_IN" I L 5650 6750 60 
F4 "V_OUT" I R 6250 6850 60 
F5 "GND" I L 5650 7150 60 
$EndSheet
Wire Wire Line
	5550 6750 5650 6750
Wire Wire Line
	5350 7150 5650 7150
Wire Wire Line
	5550 1150 5550 6750
Text HLabel 4850 1150 0    60   Input ~ 0
V_LOAD_IN
Connection ~ 5550 1950
Connection ~ 5550 2750
Connection ~ 5550 3550
Connection ~ 5550 4350
Connection ~ 5550 5150
Connection ~ 5550 5950
Connection ~ 5350 3150
Connection ~ 5350 3950
Connection ~ 5350 4750
Connection ~ 5350 6350
Connection ~ 5350 5550
Wire Wire Line
	4650 3700 4700 3700
Wire Wire Line
	4700 3700 4700 1450
Wire Wire Line
	5650 2250 4750 2250
Wire Wire Line
	4750 2250 4750 3800
Wire Wire Line
	4750 3800 4650 3800
Wire Wire Line
	5650 3050 4800 3050
Wire Wire Line
	4800 3050 4800 3900
Wire Wire Line
	4800 3900 4650 3900
Wire Wire Line
	4850 3850 4850 4000
Wire Wire Line
	4850 4000 4650 4000
Wire Wire Line
	4650 4400 4700 4400
Wire Wire Line
	4700 4400 4700 7050
Wire Wire Line
	4700 7050 5650 7050
Wire Wire Line
	4650 4300 4750 4300
Wire Wire Line
	4750 4300 4750 6250
Wire Wire Line
	4750 6250 5650 6250
Wire Wire Line
	4800 5450 5650 5450
Wire Wire Line
	4650 4200 4800 4200
Wire Wire Line
	4800 4200 4800 5450
Wire Wire Line
	4650 4100 4850 4100
Wire Wire Line
	4850 4100 4850 4650
Wire Wire Line
	4850 4650 5650 4650
Text HLabel 4850 1250 0    60   Input ~ 0
GND
Connection ~ 5350 1550
Text HLabel 3000 3150 0    60   Input ~ 0
V_LOGIC_IN
Wire Wire Line
	3650 3600 3650 3150
Wire Wire Line
	3650 3150 3000 3150
Text HLabel 3000 4750 0    60   Input ~ 0
GND
Wire Wire Line
	3000 4750 3650 4750
Wire Wire Line
	3650 4750 3650 4700
Text HLabel 3000 5050 0    60   Input ~ 0
SER_OUT
Wire Wire Line
	4650 4600 4650 5050
Wire Wire Line
	4650 5050 3000 5050
Text HLabel 3000 3700 0    60   Input ~ 0
SER_IN
Wire Wire Line
	3000 3700 3250 3700
Text HLabel 3000 3900 0    60   Input ~ 0
SRCLK
Text HLabel 3000 4000 0    60   Input ~ 0
SRCLR
Text HLabel 3000 4200 0    60   Input ~ 0
RCLK
$Comp
L 74HC595 U1
U 1 1 58120D18
P 3950 4150
AR Path="/5811D81C/58120D18" Ref="U1"  Part="1" 
AR Path="/581A1347/58120D18" Ref="U2"  Part="1" 
AR Path="/581A63FD/58120D18" Ref="U3"  Part="1" 
AR Path="/581ADE35/58120D18" Ref="U4"  Part="1" 
AR Path="/581ADE48/58120D18" Ref="U5"  Part="1" 
AR Path="/581ADE5B/58120D18" Ref="U6"  Part="1" 
F 0 "U6" H 3950 4916 50  0000 C CNN
F 1 "74HC595" H 3950 4825 50  0000 C CNN
F 2 "SMD_Packages:SO-16-N" H 3950 4150 50  0001 C CNN
F 3 "" H 3950 4150 50  0000 C CNN
	1    3950 4150
	1    0    0    -1  
$EndComp
Text HLabel 3000 4300 0    60   Input ~ 0
OE
Wire Wire Line
	3250 3900 3000 3900
Wire Wire Line
	3000 4000 3250 4000
Wire Wire Line
	3250 4200 3000 4200
Wire Wire Line
	3000 4300 3250 4300
Wire Wire Line
	4850 1250 5350 1250
Text HLabel 7450 1250 2    60   Input ~ 0
OUT_01
Wire Wire Line
	6250 1250 7450 1250
Text HLabel 7450 1350 2    60   Input ~ 0
OUT_02
Text HLabel 7450 1450 2    60   Input ~ 0
OUT_03
Text HLabel 7450 1550 2    60   Input ~ 0
OUT_04
Text HLabel 7450 1650 2    60   Input ~ 0
OUT_05
Text HLabel 7450 1750 2    60   Input ~ 0
OUT_06
Text HLabel 7450 1850 2    60   Input ~ 0
OUT_07
Text HLabel 7450 1950 2    60   Input ~ 0
OUT_08
Wire Wire Line
	6250 2050 6400 2050
Wire Wire Line
	6250 2850 6500 2850
Wire Wire Line
	6500 2850 6500 1450
Wire Wire Line
	6500 1450 7450 1450
Wire Wire Line
	6250 3650 6600 3650
Wire Wire Line
	6600 3650 6600 1550
Wire Wire Line
	6600 1550 7450 1550
Wire Wire Line
	6250 4450 6700 4450
Wire Wire Line
	6700 4450 6700 1650
Wire Wire Line
	6700 1650 7450 1650
Wire Wire Line
	6400 2050 6400 1350
$Sheet
S 5650 1050 600  600 
U 58120C18
F0 "switch_01" 60
F1 "bjt_switch.sch" 60
F2 "SIGNAL_IN" I L 5650 1450 60 
F3 "V_IN" I L 5650 1150 60 
F4 "V_OUT" I R 6250 1250 60 
F5 "GND" I L 5650 1550 60 
$EndSheet
Wire Wire Line
	6400 1350 7450 1350
Wire Wire Line
	6250 5250 6800 5250
Wire Wire Line
	6800 5250 6800 1750
Wire Wire Line
	6800 1750 7450 1750
Wire Wire Line
	6250 6050 6900 6050
Wire Wire Line
	6900 6050 6900 1850
Wire Wire Line
	6900 1850 7450 1850
Wire Wire Line
	6250 6850 7000 6850
Wire Wire Line
	7000 6850 7000 1950
Wire Wire Line
	7000 1950 7450 1950
$Comp
L C C1
U 1 1 581C3974
P 3150 3350
AR Path="/5811D81C/581C3974" Ref="C1"  Part="1" 
AR Path="/581A1347/581C3974" Ref="C2"  Part="1" 
AR Path="/581A63FD/581C3974" Ref="C3"  Part="1" 
AR Path="/581ADE35/581C3974" Ref="C4"  Part="1" 
AR Path="/581ADE48/581C3974" Ref="C5"  Part="1" 
AR Path="/581ADE5B/581C3974" Ref="C6"  Part="1" 
F 0 "C6" H 3265 3396 50  0000 L CNN
F 1 "C" H 3265 3305 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 3188 3200 50  0001 C CNN
F 3 "" H 3150 3350 50  0000 C CNN
	1    3150 3350
	1    0    0    -1  
$EndComp
Text HLabel 3000 3550 0    60   Input ~ 0
GND
Wire Wire Line
	3150 3200 3150 3150
Connection ~ 3150 3150
Wire Wire Line
	3150 3500 3150 3550
Wire Wire Line
	3150 3550 3000 3550
$EndSCHEMATC
