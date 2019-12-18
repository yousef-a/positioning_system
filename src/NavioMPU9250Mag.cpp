#include "NavioMPU9250Mag.hpp"

NAVIOMPU9250_mag::NAVIOMPU9250_mag(NineAxisSensor* tmp)
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

Vector3D<int> NAVIOMPU9250_mag::getRawData()
{
	_imu->updateReadings();
	return _imu->getMagReadings();
}