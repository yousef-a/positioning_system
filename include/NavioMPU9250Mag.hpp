#pragma once 

#include "Mag.hpp"
#include "Common/MPU9250.h"

class NAVIOMPU9250_mag : public Mag
{
public:

	NAVIOMPU9250_mag(MPU9250*);
	void setSettings(setting_type, float);

protected:

	vec_3d<int> getRawData();

private:

	MPU9250* _imu;
};