#include "NavioMPU9250Mag.hpp"

NAVIOMPU9250_mag::NAVIOMPU9250_mag(MPU9250* tmp)
{
	_imu = tmp;
	setSens(0.15);
}

void NAVIOMPU9250_mag::setSettings(setting_type setting_name, float setting_val)
{
	if(setting_name == SENS)
	{
		setSens(setting_val);
	}
}

vec_3d<int> NAVIOMPU9250_mag::getRawData()
{
	vec_3d<int> tmp;
	_imu->update();
	_imu->read_raw_magnetometer(&(tmp.x), &(tmp.y), &(tmp.z));
	return tmp;
}