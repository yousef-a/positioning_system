#pragma once 

#include "Acc.hpp"
#include "NineAxisSensor.hpp"

class NAVIOMPU9250_acc : public Acc
{
public:

	NAVIOMPU9250_acc(NineAxisSensor*);
	void setSettings(setting_type, float);

protected:

	Vector3D<int> getRawData();
	
private:

	NineAxisSensor* _imu;
	
};