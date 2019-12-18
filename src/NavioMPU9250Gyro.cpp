#include "NavioMPU9250Gyro.hpp"

NAVIOMPU9250_gyro::NAVIOMPU9250_gyro(NineAxisSensor* tmp)
{
	_imu = tmp;
	_imu->updateReadings();
}

void NAVIOMPU9250_gyro::setSettings(setting_type setting_name, float setting_val)
{
	if(setting_name == SENS)
	{
		setSens(setting_val);
	}
}

Vector3D<int> NAVIOMPU9250_gyro::getRawData()
{
	_imu->updateReadings();
	return _imu->getGyroReadings();
}