#pragma once 

#include "ThreeAxisSensor.hpp"

class NineAxisSensor
{
public:

	virtual ThreeAxisSensor* getAcc() = 0;
	virtual ThreeAxisSensor* getGyro() = 0;
	virtual ThreeAxisSensor* getMag() = 0;
	virtual void setSettings(sens_type, setting_type, int) = 0;

};