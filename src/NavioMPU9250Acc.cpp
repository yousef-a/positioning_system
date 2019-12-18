#include "NavioMPU9250Acc.hpp"

NAVIOMPU9250_acc::NAVIOMPU9250_acc(MPU9250* tmp)
{
	_imu = tmp;
}

void NAVIOMPU9250_acc::setSettings(setting_type setting_name, float setting_val)
{
	if(setting_name == SENS)
	{	//TODO: navio library doesn't have getfsr, add!
		setSens(setting_val);
		// setCalibCoeff((float)_imu->getAccelFSR()/16.f);
		// setgWorkingRange(32768.f/((float)_imu->getAccelFSR()));
		setCalibCoeff((float)16/16.f);
		setgWorkingRange(32768.f/16.f);
	}
}

Vector3D<int> NAVIOMPU9250_acc::getRawData()
{
	Vector3D<int> tmp;
	_imu->update();
	_imu->read_raw_accelerometer(&(tmp.x), &(tmp.y), &(tmp.z));
	return tmp;
}