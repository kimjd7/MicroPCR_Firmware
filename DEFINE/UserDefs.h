/****************************************************
 FileName 	:   UserDefs.h
 Date		:	2012.07.27
 Author		:	Yeon June	 
****************************************************/

/** Duplicate check ********************************/
#ifndef __USERDEFS_H__
#define __USERDEFS_H__

/** Includes ***************************************/
#include "./DEFINE/GenericTypeDefs.h"

#define RX_BUFSIZE		64		// Buffer Size
#define TX_BUFSIZE		64

//#define EMULATOR 

typedef struct _RXBUFFER
{
	BYTE cmd;
	
	BYTE currentTargetTemp;
	// for pid params
	BYTE startTemp;
	BYTE targetTemp;

	BYTE pid_p1;
	BYTE pid_p2;
	BYTE pid_p3;
	BYTE pid_p4;
	
	BYTE pid_i1;
	BYTE pid_i2;
	BYTE pid_i3;
	BYTE pid_i4;

	BYTE pid_d1;
	BYTE pid_d2;
	BYTE pid_d3;
	BYTE pid_d4;

	BYTE integralMax_1;
	BYTE integralMax_2;
	BYTE integralMax_3;
	BYTE integralMax_4;

	BYTE ledControl;
	BYTE led_wg;
	BYTE led_r;
	BYTE led_g;
	BYTE led_b;

	BYTE reserved_for_64byte[39];
} RxBuffer;

typedef struct _TXBUFFER
{
	BYTE state;
	// adc value
	BYTE chamber_h;
	BYTE chamber_l;

	// calculated temperature
	BYTE chamber_temp_1;
	BYTE chamber_temp_2;
	BYTE chamber_temp_3;
	BYTE chamber_temp_4;

	BYTE photodiode_h;
	BYTE photodiode_l;
	BYTE currentError;
	
	// For request command
	BYTE request_data;

	BYTE reserved_for_64byte[53];
} TxBuffer;

typedef enum _STATE				//	Device State.
{								//  Used in PCR_Task.c
	STATE_READY = 0x00,
	STATE_RUNNING,
	STATE_PAN_RUNNING,
} STATE;

typedef enum _COMMAND			//	Rx_Buffer[0] = Set Command
{								//  Used in PCR_Task.c
	CMD_READY = 0x00,
	CMD_PCR_RUN,
	CMD_PCR_STOP,
	CMD_FAN_ON,
	CMD_FAN_OFF,
	CMD_BOOTLOADER = 0x55
} COMMAND;

typedef enum _ERROR
{
	ERROR_NO = 0x00,
	ERROR_ASSERT,
} ERROR;

// Temperature Sampling Count
#define SAMPLING_COUNT			10

#define MAX_PID_COUNT			10

#define	A_VAL					8.314242955712037e-004
#define B_VAL					2.620794578770541e-004
#define C_VAL					1.368534674434736e-007

#define Rref					1800.0
#define K						273.15

#define FAN_STOP_TEMPDIF		1
#define INTGRALMAX				2600.0

#endif


