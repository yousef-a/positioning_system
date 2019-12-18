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
	Vector3D<int> tmp;
	_imu->updateReadings();
	_imu->getMagReadings(tmp);
	return tmp;
}