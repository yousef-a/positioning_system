#pragma once 

#include "Gyro.hpp"
#include "Common/MPU9250.h"

class NAVIOMPU9250_gyro : public Gyro
{
public:

	NAVIOMPU9250_gyro(MPU9250*);
	void setSettings(setting_type, float);

protected:

	Vector3D<int> getRawData();

private:

	MPU9250* _imu;

};