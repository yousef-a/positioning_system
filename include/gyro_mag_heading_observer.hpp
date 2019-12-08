#pragma once 

#include "HeadingProvider.hpp"

class GyroMagHeadingObserver : public HeadingProvider
{
public:

	GyroMagHeadingObserver(AttitudeProvider*, BodyRateProvider*, CompassProvider*);
	void setSettings(FilterSettings*);
	HeadingMsg getHeading();

private:

	AttitudeProvider* m_att_provider;
	BodyRateProvider* m_rate_provider;
	CompassProvider* m_compass;

	Filter* heading_filter;

	HeadingMsg filtered_heading;
	vec_3d<float> m_mag_data, m_gyro_data;

	HeadingMsg m_mag_heading;
	float heading_rate;

	HeadingMsg getMagHeading(AttitudeMsg);
};