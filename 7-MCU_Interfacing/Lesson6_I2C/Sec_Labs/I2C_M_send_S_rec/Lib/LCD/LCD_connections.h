/*
 * LCD_connections.h
 *
 * Created: 14/10/2022 02:08:05
 *  Author: MAshr
 */ 


#ifndef LCD_CONNECTIONS_H_
#define LCD_CONNECTIONS_H_
#include "LCD.h"

LCD_Connections_t LCD1_object={
	LCD1_PORT,
	{Port_B ,3},
	{Port_B ,2},
	{Port_B ,1},
};
LCD_Connections_t LCD2_object={
	LCD2_PORT,
	{Port_B ,7},
	{Port_B ,6},
	{Port_B ,5},
};





#endif /* LCD_CONNECTIONS_H_ */