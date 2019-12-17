#pragma once 

#include "Gyro.hpp"
#include "Common/MPU9250.h"
#include "timer.hpp"
class NAVIOMPU9250_gyro : public Gyro
{
public:

	NAVIOMPU9250_gyro(MPU9250*);
	void setSettings(setting_type, float);

protected:

	Vector3D<int> getRawData();

private:
	Vector3D<int> raw_tmp;
	Timer* _loop_timer = new Timer();
	MPU9250* _imu;

};