#pragma once 

#include "AttitudeProvider.hpp"
#include "data_filter.hpp"

class AccGyroAttitudeObserver : public AttitudeProvider
{
public:

	AccGyroAttitudeObserver(BodyAccProvider*, BodyRateProvider*);
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