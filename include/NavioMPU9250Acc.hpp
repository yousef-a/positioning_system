#pragma once 

#include "Acc.hpp"
#include "Common/MPU9250.h"

class NAVIOMPU9250_acc : public Acc
{
public:

	NAVIOMPU9250_acc(MPU9250*);
	void setSettings(setting_type, float);

protected:

	Vector3D<int> getRawData();
	
private:

	MPU9250* _imu;
	
};