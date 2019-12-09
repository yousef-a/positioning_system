#pragma once 

#include "NineAxisSensor.hpp"
#include "Common/MPU9250.h"
#include "NavioMPU9250Acc.hpp"
#include "NavioMPU9250Gyro.hpp"
#include "NavioMPU9250Mag.hpp"

//TODO: this assumes modifactions to the navio_library, don't use with the original one
class NAVIOMPU9250_sensor : public NineAxisSensor
{
public:

	NAVIOMPU9250_sensor();

	ThreeAxisSensor* getAcc();
	ThreeAxisSensor* getGyro();
	ThreeAxisSensor* getMag();
	void setSettings(sens_type, setting_type, int);
	

private:

	MPU9250 _imu;
	ThreeAxisSensor* _acc = new NAVIOMPU9250_acc(&_imu);
	ThreeAxisSensor* _gyro = new NAVIOMPU9250_gyro(&_imu);
	ThreeAxisSensor* _mag = new NAVIOMPU9250_mag(&_imu);
};