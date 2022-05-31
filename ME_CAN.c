/* Generated by DBCC, see <https://github.com/howerj/dbcc> */
#include "ME_CAN.h"
#include <inttypes.h>
#include <assert.h>

#define UNUSED(X) ((void)(X))

static inline uint64_t reverse_byte_order(uint64_t x) {
	x = (x & 0x00000000FFFFFFFF) << 32 | (x & 0xFFFFFFFF00000000) >> 32;
	x = (x & 0x0000FFFF0000FFFF) << 16 | (x & 0xFFFF0000FFFF0000) >> 16;
	x = (x & 0x00FF00FF00FF00FF) << 8  | (x & 0xFF00FF00FF00FF00) >> 8;
	return x;
}

static inline int print_helper(int r, int print_return_value) {
	return ((r >= 0) && (print_return_value >= 0)) ? r + print_return_value : -1;
}



static int unpack_can_0x300_ME1_1(can_obj *o, byte data[], uint8_t dlc) {
	assert(o);
	assert(dlc <= 8);
	if (dlc < 8)
		return -1;
	/* RPM: start-bit 0, length 16, endianess intel, scaling 1, offset 0 */
	o->RPM = (data[0] << 8) + (data[1] & 0xff);
	/* TPS: start-bit 16, length 16, endianess intel, scaling 0.1, offset 0 */
	o->TPS = (data[2] << 8) + (data[3] & 0xff);
	/* MAP: start-bit 32, length 16, endianess intel, scaling 0.01, offset 0 */
	o->MAP = (data[4] << 8) + (data[5] & 0xff);
	/* IAT: start-bit 48, length 16, endianess intel, scaling 0.1, offset 0 */
	o->IAT = (data[6] << 8) + (data[7] & 0xff);
	return 0;
}


static int unpack_can_0x301_ME1_2(can_obj *o, byte data[], uint8_t dlc) {
	assert(o);
	assert(dlc <= 8);
	if (dlc < 8)
		return -1;
	/* RPM_HardLimit: start-bit 0, length 16, endianess intel, scaling 0.4, offset 0 */
	o->RPM_HardLimit = (data[0] << 8) + (data[1] & 0xff);
	/* Lambda_Trim: start-bit 32, length 16, endianess intel, scaling 0.01, offset 0 */
	o->Lambda_Trim =  (data[5] << 8) + (data[6] & 0xff);
	/* AFRCurr_1: start-bit 16, length 8, endianess intel, scaling 0.05, offset 7.5 */
	o->AFRCurr_1 = data[2] & 0xff;
	/* AFRCurr_2: start-bit 24, length 8, endianess intel, scaling 0.05, offset 7.5 */
	o->AFRCurr_2 = data[3] & 0xff;
	/* AFR_Target: start-bit 48, length 8, endianess intel, scaling 0.05, offset 7.5 */
	o->AFR_Target = data[4] & 0xff;
	/* Fuel_Eth_Perc: start-bit 56, length 8, endianess intel, scaling 0.5, offset 0 */
	o->Fuel_Eth_Perc = data[7] & 0xff;
	return 0;
}

static int unpack_can_0x302_ME1_3(can_obj *o, byte data[], uint8_t dlc) {
	assert(o);
	assert(dlc <= 8);
	if (dlc < 8)
		return -1;
	/* IgnAdvAngle: start-bit 0, length 16, endianess intel, scaling 0.1, offset 0 */
	o->IgnAdvAngle = (data[0] << 8) + (data[1] & 0xff);
	/* IgnDwell: start-bit 16, length 16, endianess intel, scaling 0.1, offset 0 */
	o->IgnDwell = (data[2] << 8) + (data[3] & 0xff);
	/* Pri_InjAngle: start-bit 32, length 16, endianess intel, scaling 0.1, offset 0 */
	o->Pri_InjAngle = (data[4] << 8) + (data[5] & 0xff);
	/* Pri_InjPw: start-bit 48, length 16, endianess intel, scaling 0.1, offset 0 */
	o->Pri_InjPw = (data[6] << 8) + (data[7] & 0xff);
	return 0;
}

static int unpack_can_0x303_ME1_4(can_obj *o, byte data[], uint8_t dlc) {
	assert(o);
	assert(dlc <= 8);
	if (dlc < 8)
		return -1;
	/* Sec_InjAngle: start-bit 16, length 16, endianess intel, scaling 0.1, offset 0 */
	o->Sec_InjAngle = (data[2] << 8) + (data[3] & 0xff);
	/* Sec_InjPw: start-bit 32, length 16, endianess intel, scaling 0.1, offset 0 */
	o->Sec_InjPw = (data[4] << 8) + (data[5] & 0xff);
	/* Pri_InjDuty: start-bit 0, length 8, endianess intel, scaling 0.5, offset 0 */
	o->Pri_InjDuty = data[0] & 0xff;
	/* Sec_InjDuty: start-bit 8, length 8, endianess intel, scaling 0.5, offset 0 */
	o->Sec_InjDuty = data[1] & 0xff;
	/* Boost_Ctrl_Duty: start-bit 48, length 8, endianess intel, scaling 0.5, offset 0 */
	o->Boost_Ctrl_Duty = data[6] & 0xff;
	return 0; 
}

static int unpack_can_0x304_ME1_5(can_obj *o, byte data[], uint8_t dlc) {
	assert(o);
	assert(dlc <= 8);
	if (dlc < 8)
		return -1;
	o->Oil_T = (data[0] << 8) + (data[1] & 0xff);
	/* Oil_P: start-bit 16, length 16, endianess intel, scaling 0.1, offset 0 */
	o->Oil_P = (data[2] << 8) + (data[3] & 0xff);
	/* CLT: start-bit 32, length 16, endianess intel, scaling 0.1, offset 0 */
	o->CLT = (data[4] << 8) + (data[5] & 0xff);
	/* VBAT: start-bit 48, length 16, endianess intel, scaling 0.1, offset 0 */
	o->VBAT = (data[6] << 8) + (data[7] & 0xff);
	return 0;
}

static int unpack_can_0x305_ME1_6(can_obj *o, byte data[], uint8_t dlc) {
	assert(o);
	assert(dlc <= 8);
	if (dlc < 8)
		return -1;
	/* MAP_Target: start-bit 8, length 16, endianess intel, scaling 0.01, offset 0 */
	o->MAP_Target = (data[1] << 8) + (data[2] & 0xff);
	/* Vehicle_Speed: start-bit 24, length 16, endianess intel, scaling 0.008, offset 0 */
	o->Vehicle_Speed = (data[3] << 8) + (data[4] & 0xff);
	/* EPS_Ev_Msk: start-bit 40, length 16, endianess intel, scaling 1, offset 0 */
	o->EPS_Ev_Msk = (data[5] << 8) + (data[6] & 0xff);
	/* Gear_Pos: start-bit 0, length 8, endianess intel, scaling 1, offset 0 */
	o->Gear_Pos = data[0] & 0xff;
	return 0;
}

static int unpack_can_0x306_ME1_7(can_obj *o, byte data[], uint8_t dlc) {
	assert(o);
	assert(dlc <= 8);
	if (dlc < 8)
		return -1;
	/* Knock_Reading: start-bit 0, length 16, endianess intel, scaling 1, offset 0 */
	o->Knock_Reading = (data[0] << 8) + (data[1] & 0xff);
	/* EGT_1: start-bit 40, length 16, endianess intel, scaling 0.1, offset 0 */
	o->EGT_1 = (data[5] << 8) + (data[6] & 0xff);
	/* Knock_Ign_Adv_Mod: start-bit 16, length 8, endianess intel, scaling 0.1, offset 0 */
	o->Knock_Ign_Adv_Mod = data[2] & 0xff;;
	/* Fuel_Press: start-bit 24, length 8, endianess intel, scaling 5, offset 0 */
	o->Fuel_Press = data[3] & 0xff;
	/* Fuel_Temp: start-bit 32, length 8, endianess intel, scaling 1, offset 0 */
	o->Fuel_Temp = data[4] & 0xff;
	return 0;
}

static int unpack_can_0x307_ME1_8(can_obj *o, byte data[], uint8_t dlc) {
	assert(o);
	assert(dlc <= 8);
	if (dlc < 8)
		return -1;
	/* EGT_2: start-bit 0, length 16, endianess intel, scaling 0.1, offset 0 */
	o->EGT_2 = (data[0] << 8) + (data[1] & 0xff);
	/* GPT_1: start-bit 16, length 16, endianess intel, scaling 1, offset 0 */
	o->GPT_1 = (data[2] << 8) + (data[3] & 0xff);
	/* GPT_2: start-bit 32, length 16, endianess intel, scaling 1, offset 0 */
	o->GPT_2 = (data[4] << 8) + (data[5] & 0xff);

	return 0;
}

static int unpack_can_0x340_ME1_In_1(can_obj *o, byte data[], uint8_t dlc) {
	assert(o);
	assert(dlc <= 8);
	if (dlc < 8)
		return -1;
	/* Vehicle_Speed: start-bit 0, length 16, endianess intel, scaling 0.008, offset 0 */
	o->Vehicle_Speed = (data[0] << 8) + (data[1] & 0xff);
	return 0;
}


int unpack_message(can_obj *o, const unsigned long id, byte data[], uint8_t dlc) {
	assert(o);
	assert(id < (1ul << 29)); /* 29-bit CAN ID is largest possible */
	assert(dlc <= 8);         /* Maximum of 8 bytes in a CAN packet */
	switch (id) {
	case 0x300: return unpack_can_0x300_ME1_1(o, data, dlc);
	case 0x301: return unpack_can_0x301_ME1_2(o, data, dlc);
	case 0x302: return unpack_can_0x302_ME1_3(o, data, dlc);
	case 0x303: return unpack_can_0x303_ME1_4(o, data, dlc);
	case 0x304: return unpack_can_0x304_ME1_5(o, data, dlc);
	case 0x305: return unpack_can_0x305_ME1_6(o, data, dlc);
	case 0x306: return unpack_can_0x306_ME1_7(o, data, dlc);
	case 0x307: return unpack_can_0x307_ME1_8(o, data, dlc);
	case 0x340: return unpack_can_0x340_ME1_In_1(o, data, dlc);
	default: break; 
	}
	return -1; 
}



