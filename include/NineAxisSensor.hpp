#pragma once 

#include "Acc.hpp"
#include "Gyro.hpp"
#include "Mag.hpp"

class NineAxisSensor
{
public:
	virtual void updateReadings() = 0;
	virtual void getAccelReadings(Vector3D<int>&) = 0;
	virtual void getGyroReadings(Vector3D<int>&) = 0;
	virtual void getMagReadings(Vector3D<int>&) = 0;
	virtual Acc* getAcc() = 0;
	virtual Gyro* getGyro() = 0;
	virtual Mag* getMag() = 0;
	virtual void setSettings(sens_type, setting_type, int) = 0;
};