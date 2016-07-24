#ifndef CAN_H
#define CAN_H

#define BASE_ADDRESS 0x400		// this is the default address the WaveSculptor uses
#define DRIVE_ADDRESS 0x100		// no default stated for WaveSculptor so I made this up

// these are broadcast from the motor controller
typedef enum BROADCAST_ID {								// interval
	Ident_Info = BASE_ADDRESS + 0x00,					// 1sec
	Status_Info = BASE_ADDRESS + 0x01,					// 200ms
	Bus_Meas = BASE_ADDRESS + 0x02,						// 200ms
	Velocity_Meas = BASE_ADDRESS + 0x03,				// 200ms
	Phase_Current_Meas = BASE_ADDRESS + 0x04,			// 200ms
	Motor_Voltage_Vector_Meas = BASE_ADDRESS + 0x05,	// 200ms
	Motor_Current_Vector_Meas = BASE_ADDRESS + 0x06,	// 200ms
	BackEMF_Meas_Predict = BASE_ADDRESS + 0x07,			// 200ms
	Voltage_15V_Rail_Meas = BASE_ADDRESS + 0x08,		// 1sec 15V
	Voltage_33V_19V_Rail_Meas = BASE_ADDRESS + 0x09,	// 1sec 3.3V & 1.9V
#ifndef WS20
	RESERVED0 = BASE_ADDRESS + 0x0A,
#endif
	Heat_Sink_Motor_Temp = BASE_ADDRESS + 0x0B,			// 1sec
	DSP_Board_Temp = BASE_ADDRESS + 0x0C,				// 1sec
#ifndef WS20
	RESERVED1 = BASE_ADDRESS + 0x0D,
#endif
	Odom_and_AmpHours_Meas = BASE_ADDRESS + 0x0E,		// 1sec
#ifndef WS20
	Slip_Speed_Meas = BASE_ADDRESS + 0x17,				// 200ms
#endif
#ifdef WS20
	Air_in_CPU_Temp_Meas = BASE_ADDRESS + 0x0C;			// 5sec
	Air_out_CAP_Temp_Meas = BASE_ADDRESS + 0x0D
#endif
};



typedef enum DRIVE_COMMAND {
	/*
	 * Motor Current - Bits 63-32 - Units % - Desired Motor Current set point as a % of max current setting
	 * Motor Velocit - Bits 31-0  - Units rpm - Desired Motor velocity set point in rpm
	 */
	Motor_Drive_Command = DRIVE_ADDRESS + 0x01,

	/*
	 * Bus Current - Bits 63-32 - Units % - Desired set point of curent drawn from the bus as a % of
	 * 										absolute bus current limit.
	 * Reserved - Bits 31-0
	 */
	Motor_Power_Command = DRIVE_ADDRESS + 0x02,

	/*
	 * Unused - Bits 63-0 - Send a command from this address to reset the software in the Inverter
	 *
	 */
	Reset_Command = DRIVE_ADDRESS + 0x03,
};

#endif
