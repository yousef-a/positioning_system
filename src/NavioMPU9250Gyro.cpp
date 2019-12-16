#include "NavioMPU9250Gyro.hpp"

NAVIOMPU9250_gyro::NAVIOMPU9250_gyro(MPU9250* tmp)
{
	_imu = tmp;
	_loop_timer->tick();
	_imu->update();
	_imu->read_raw_gyroscope(&(raw_tmp.x), &(raw_tmp.y), &(raw_tmp.z));
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
	
	int consumed_time = _loop_timer->tockMicroSeconds();
	if(consumed_time < 1000000){
		return raw_tmp;
	}else{
		_imu->update();
		_imu->read_raw_gyroscope(&(raw_tmp.x), &(raw_tmp.y), &(raw_tmp.z));
		_loop_timer->tick();
		return raw_tmp;
	}
	
}