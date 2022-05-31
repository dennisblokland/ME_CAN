#include <inttypes.h>
#include <Arduino.h>

#ifndef TEST_H
#define TEST_H

#ifndef PREPACK
#define PREPACK
#endif

#ifndef POSTPACK
#define POSTPACK
#endif

#ifndef DBCC_TIME_STAMP
#define DBCC_TIME_STAMP
typedef uint32_t dbcc_time_stamp_t; /* Time stamp for message; you decide on units */
#endif

#ifndef DBCC_STATUS_ENUM
#define DBCC_STATUS_ENUM
typedef enum {
	DBCC_SIG_STAT_UNINITIALIZED_E = 0, /* Message never sent/received */
	DBCC_SIG_STAT_OK_E            = 1, /* Message ok */
	DBCC_SIG_STAT_ERROR_E         = 2, /* Encode/Decode/Timestamp/Any error */
} dbcc_signal_status_e;
#endif


typedef PREPACK struct {
	uint16_t RPM; /* scaling 1.0, offset 0.0, units none  */
	int16_t TPS; /* scaling 0.1, offset 0.0, units %  */
	uint16_t MAP; /* scaling 0.0, offset 0.0, units kPa  */
	int16_t IAT; /* scaling 0.1, offset 0.0, units deg C  */
	uint16_t RPM_HardLimit; /* scaling 0.4, offset 0.0, units none  */
	uint16_t Lambda_Trim; /* scaling 0.0, offset 0.0, units none  */
	uint8_t AFRCurr_1; /* scaling 0.1, offset 7.5, units none  */
	uint8_t AFRCurr_2; /* scaling 0.1, offset 7.5, units none  */
	uint8_t AFR_Target; /* scaling 0.1, offset 7.5, units none  */
	uint8_t Fuel_Eth_Perc; /* scaling 0.5, offset 0.0, units %  */
	int16_t IgnAdvAngle; /* scaling 0.1, offset 0.0, units deg  */
	int16_t IgnDwell; /* scaling 0.1, offset 0.0, units ms  */
	int16_t Pri_InjAngle; /* scaling 0.1, offset 0.0, units deg  */
	int16_t Pri_InjPw; /* scaling 0.1, offset 0.0, units ms  */
	int16_t Sec_InjAngle; /* scaling 0.1, offset 0.0, units deg  */
	int16_t Sec_InjPw; /* scaling 0.1, offset 0.0, units ms  */
	uint8_t Pri_InjDuty; /* scaling 0.5, offset 0.0, units %  */
	uint8_t Sec_InjDuty; /* scaling 0.5, offset 0.0, units %  */
	uint8_t Boost_Ctrl_Duty; /* scaling 0.5, offset 0.0, units %  */
	int16_t Oil_T; /* scaling 0.1, offset 0.0, units deg C  */
	int16_t Oil_P; /* scaling 0.1, offset 0.0, units kPa  */
	int16_t CLT; /* scaling 0.1, offset 0.0, units deg C  */
	int16_t VBAT; /* scaling 0.1, offset 0.0, units V  */
	uint16_t MAP_Target; /* scaling 0.0, offset 0.0, units kPa  */
	uint16_t Vehicle_Speed; /* scaling 0.0, offset 0.0, units kph  */
	uint16_t EPS_Ev_Msk; /* scaling 1.0, offset 0.0, units none  */
	uint8_t Gear_Pos; /* scaling 1.0, offset 0.0, units none  */
	uint16_t Knock_Reading; /* scaling 1.0, offset 0.0, units none  */
	uint16_t EGT_1; /* scaling 0.1, offset 0.0, units deg C  */
	int8_t Knock_Ign_Adv_Mod; /* scaling 0.1, offset 0.0, units deg  */
	uint8_t Fuel_Press; /* scaling 5.0, offset 0.0, units kPa  */
	uint8_t Fuel_Temp; /* scaling 1.0, offset 0.0, units deg C  */
	uint16_t EGT_2; /* scaling 0.1, offset 0.0, units deg C  */
	int16_t GPT_1; /* scaling 1.0, offset 0.0, units none  */
	int16_t GPT_2; /* scaling 1.0, offset 0.0, units none  */
	uint16_t Vehicle_Speed_2;
} POSTPACK can_obj;

int unpack_message(can_obj *o, const unsigned long id, byte data[], uint8_t dlc);

#endif
