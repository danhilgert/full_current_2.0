#ifndef R2D_H
#define R2D_H
#include "stm32f4xx.h"

// used for GPIO alternate function
#define R2D_SDO GPIO_PinSource11	// PC11
#define R2D_SDI GPIO_PinSource12	// PC12
#define R2D_SCK GPIO_PinSource10	// PC10

// Map R2D pins to MCU (DIRECTION IS WITH REFENCE TO MCU)
#define A0 GPIO_Pin_6		// PB6 - OUTPUT
#define A1 GPIO_Pin_7		// PB7 - OUTPUT
#define DOS GPIO_Pin_5		// PB5 - INPUT
#define LOT GPIO_Pin_7		// PD7 - INPUT
#define NWR GPIO_Pin_5		// PD5 - INPUT
#define NReset GPIO_Pin_6	// PD6 - OUTPUT
#define NSample GPIO_Pin_0	// PD0 - OUTPUT
#define RES0 GPIO_Pin_0		// PE1 - OUTPUT
#define RES1 GPIO_Pin_1		// PE0 - OUTPUT

// register addresses
#define POS_HIGH_ADR 0x80				// RO D15-D8
#define POS_LOW_ADR 0x81				// RO D7-D0
#define VEL_HIGH_ADR 0x82				// RO D15-D8
#define VEL_LOW_ADR 0x83				// RO D7-D0
#define LOS_THRESH_ADR 0x88				// RW D7-D0
#define DOS_OVERRANGE_THRESH_ADR 0x89	// RW D7-D0
#define DOS_MISMATCH_THREST_ADR 0x8A	// RW D7-D0
#define DOS_RESET_MAX_THRESH_ADR 0x8B	// RW D7-D0
#define DOS_RESET_MIN_THRESH_ADR 0x8C	// RW D7-D0
#define LOT_HIGH_THRESH_ADR 0x8D		// RW D7-D0
#define LOT_LOW_THRESH_ADR 0x8E			// RW D7-D0
#define EXCITATION_FREQ_ADR 0x91		// RW D7-D0
#define CONTROL_ADR 0x92				// RW D7-D0
#define SOFT_RESET_ADR 0xF0				// WO D7-D0
#define FAULT_ADR 0xFF					// RO D7-D0


// control Register defines
// power up value = 0x7E
#define ADDRESS_DATA_BIT 0x80		// OR to set - i dont think we set this bit
#define RESERVED 0x40				// OR to set
#define PHASE_LOCK_RANGE_360 0xDF	// AND to clear bit
#define PHASE_LOCK_RANGE_44 0x20	// OR to set
#define DISABLE_HYSTERESIS 0xEF		// AND to clear bit
#define ENABLE_HYSTERESIS 0x10		// OR to set
#define RESOLUTION_10BIT 0x00		// OR to set
#define RESOLUTION_12BIT 0x01		// OR to set
#define RESOLUTION_14BIT 0x02		// OR to set
#define RESOLUTION_16BIT 0x03		// OR to set


// fault register defines
#define SIN_COS_INPUTS_CLIPPED 0x80
#define SIN_COS_INPUTS_BELOW_LOST_THRESH 0x40
#define SIN_COS_INPUTS_EXCEED_DOS_OVERRANGE 0x20
#define SIN_COS_INPUTS_EXCEED_DOS_MISMATCH 0x10
#define TRACKING_ERROR_EXCEEDS_LOT 0x08
#define VELOCITY_EXCEEDS_MAXIMUM_TRACKING_RATE 0x04
#define PHASE_ERROR_EXCEEDS_PHASE_RANGE 0x02
#define CONFIGURATION_PARITY_ERROr 0x01


void init_R2D_spi(void);

#endif
