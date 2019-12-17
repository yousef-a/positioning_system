#pragma once 

#include "Mag.hpp"
#include "NineAxisSensor.hpp"

class NAVIOMPU9250_mag : public Mag
{
public:

	NAVIOMPU9250_mag(NineAxisSensor*);
	void setSettings(setting_type, float);

protected:

	Vector3D<int> getRawData();

private:

	NineAxisSensor* _imu;
};