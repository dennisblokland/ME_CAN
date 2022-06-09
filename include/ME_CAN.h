#include <inttypes.h>
#include <Arduino.h>
template<class T>
class SensorData {
	public:
		SensorData(String unit){
			Unit = unit;
		}
		SensorData(){

		}
		bool Updated = true;
		T GetValue(){
			Updated = false;
			return _value;
		}
		void SetValue(T value){
			_value = value;
			Updated = true;
		}
		String Unit = "";
	private: 
		T _value;
};
class ME_CAN
{
	public:
		SensorData<uint16_t> RPM; /* Engine RPM, units none  */
		SensorData<float_t> TPS = SensorData<float_t>("%"); /* Throttle position sensor, units %  */
		SensorData<float_t> MAP = SensorData<float_t>("kPa"); /* Manifold air pressure, units kPa  */
		SensorData<float_t> IAT = SensorData<float_t>("°C"); /* Intake air temperature, units deg C  */
		SensorData<float_t> RPM_HardLimit; /* Engine RPM limit, units none  */
		SensorData<float_t> Lambda_Trim; /* Lambda Trim, units none  */
		SensorData<float_t> AFRCurr_1; /* Current Air Fuel ratio 1, units none  */
		SensorData<float_t> AFRCurr_2; /* Current Air Fuel ratio 2, units none  */
		SensorData<float_t> AFR_Target; /* Air Fuel target, units none  */
		SensorData<float_t> Fuel_Eth_Perc = SensorData<float_t>("%"); /* Ethanol percentage in fuel, units %  */
		SensorData<float_t> IgnAdvAngle = SensorData<float_t>("°"); /* Ignition angle advance, units deg  */
		SensorData<float_t> IgnDwell = SensorData<float_t>("ms");  /* Ignition dwell time, units ms  */
		SensorData<float_t> Pri_InjAngle = SensorData<float_t>("°");  /* Primary injectors angle, units deg  */
		SensorData<float_t> Pri_InjPw = SensorData<float_t>("ms");  /* Primary injectors pulse width, units ms  */
		SensorData<float_t> Sec_InjAngle = SensorData<float_t>("°");  /* Secondary injectors angle, units deg  */
		SensorData<float_t> Sec_InjPw = SensorData<float_t>("ms");  /* Secondary injectors pulse width, units ms  */
		SensorData<float_t> Pri_InjDuty = SensorData<float_t>("%"); /* Primary injectors duty cycle, units %  */
		SensorData<float_t> Sec_InjDuty = SensorData<float_t>("%"); /* Secondary injectors duty cycle, units %  */
		SensorData<float_t> Boost_Ctrl_Duty = SensorData<float_t>("%"); /* Boost control duty cycle, units %  */
		SensorData<float_t> Oil_TEMP = SensorData<float_t>("°C"); /* Oil temperature, units deg C  */
		SensorData<float_t> Oil_PRESS = SensorData<float_t>("kPa"); /* Oil pressure, units kPa  */
		SensorData<float_t> COOL_TEMP = SensorData<float_t>("°C"); /* Coolant temperature, units deg C  */
		SensorData<float_t> VBAT = SensorData<float_t>("V");   /* Battery coltage, units V  */
		SensorData<float_t> MAP_Target= SensorData<float_t>("kPa"); /* MAP target pressure, units kPa  */
		SensorData<float_t> Vehicle_Speed = SensorData<float_t>("km/h"); /* Vehicle speed, units kph  */
		SensorData<uint16_t> EPS_Ev_Msk; /* Protection module was triggered, units none  */
		SensorData<uint8_t> Gear_Pos; /* Current gear position, units none  */
		SensorData<uint16_t> Knock_Reading; /* Knock reading, units none  */
		SensorData<float_t> Knock_Ign_Adv_Mod = SensorData<float_t>("°");  /* Knock ignition advance modifier, units deg  */
		SensorData<float_t> Fuel_Press = SensorData<float_t>("kPa"); /* Fuel pressure, units kPa  */
		SensorData<float_t> Fuel_Temp = SensorData<float_t>("°C"); /* Fuel temperature, units deg C  */
		SensorData<float_t> EGT_1 = SensorData<float_t>("°C"); /* Exhaust gas temperature 1, units deg C  */
		SensorData<float_t> EGT_2 = SensorData<float_t>("°C"); /* Exhaust gas temperature 2, units deg C  */
		SensorData<int16_t> GPT_1; /* General Purpose Table 1, units none  */
		SensorData<int16_t> GPT_2; /* General Purpose Table 2, units none  */
		SensorData<uint16_t> Vehicle_Speed_2 = SensorData<uint16_t>("km/h");  /* Vehicle speed 2, units kph  */
	private:
		int unpack_can_0x300_ME1_1(byte data[], uint8_t dlc);
		int unpack_can_0x301_ME1_2(byte data[], uint8_t dlc);
		int unpack_can_0x302_ME1_3(byte data[], uint8_t dlc);
		int unpack_can_0x303_ME1_4(byte data[], uint8_t dlc);
		int unpack_can_0x304_ME1_5(byte data[], uint8_t dlc);
		int unpack_can_0x305_ME1_6(byte data[], uint8_t dlc);
		int unpack_can_0x306_ME1_7(byte data[], uint8_t dlc);
		int unpack_can_0x307_ME1_8(byte data[], uint8_t dlc);
		int unpack_can_0x340_ME1_In_1(byte data[], uint8_t dlc);
	public:
		int unpack_message(const unsigned long id, byte data[], uint8_t dlc);
};
