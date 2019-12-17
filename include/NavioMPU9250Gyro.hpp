#pragma once 

#include "Gyro.hpp"
#include "NineAxisSensor.hpp"

class NAVIOMPU9250_gyro : public Gyro
{
public:

	NAVIOMPU9250_gyro(NineAxisSensor*);
	void setSettings(setting_type, float);

protected:

	Vector3D<int> getRawData();

private:

	NineAxisSensor* _imu;

};