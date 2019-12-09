#include "NavioMPU9250Gyro.hpp"

NAVIOMPU9250_gyro::NAVIOMPU9250_gyro(MPU9250* tmp)
{
	_imu = tmp;
}

void NAVIOMPU9250_gyro::setSettings(setting_type setting_name, float setting_val)
{
	if(setting_name == SENS)
	{
		setSens(setting_val);
	}
}

vec_3d<int> NAVIOMPU9250_gyro::getRawData()
{
	vec_3d<int> tmp;
	_imu->update();
	_imu->read_raw_gyroscope(&(tmp.x), &(tmp.y), &(tmp.z));
	return tmp;
}