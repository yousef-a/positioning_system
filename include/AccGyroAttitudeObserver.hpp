#pragma once 

#include "AttitudeProvider.hpp"
#include "DataFilter.hpp"
#include "BodyAccProvider.hpp"
#include "BodyRateProvider.hpp"

class AccGyroAttitudeObserver : public AttitudeProvider
{
public:

	AccGyroAttitudeObserver(std::string, block_type, BodyAccProvider*, BodyRateProvider*);
	void setFilterType(DataFilter*, DataFilter*);
	void updateSettings(FilterSettings*, float);
	AttitudeMsg getAttitude();

private:

	const float grav = 1.f;
	float m_val_threshold;

	BodyAccProvider* m_acc;
	BodyRateProvider* m_rate;

	DataFilter* m_pitch_filter;
	DataFilter* m_roll_filter;

	AttitudeMsg filtered_attitude;
	vec_3d<float> acc_data, gyro_data;

	AttitudeMsg getAccAttitude();
};