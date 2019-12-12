#pragma once 

#include "AttitudeProvider.hpp"
#include "DataFilter.hpp"
#include "BodyAccProvider.hpp"
#include "BodyRateProvider.hpp"
#include "Acc.hpp"
#include "TimedBlock.hpp"

class AccGyroAttitudeObserver : public AttitudeProvider, public TimedBlock
{
public:
	AccGyroAttitudeObserver(BodyAccProvider*, BodyRateProvider*, block_frequency);
	void setFilterType(DataFilter*, DataFilter*);
	void updateSettings(FilterSettings*, float);
	void receive_msg_data(DataMessage* t_msg) {};
	AttitudeMsg getAttitude();
	void loopInternal();

private:

	const float grav = 1.f;
	float m_val_threshold;
	block_frequency m_bf;

	BodyAccProvider* m_acc;
	BodyRateProvider* m_rate;

	DataFilter* m_pitch_filter;
	DataFilter* m_roll_filter;

	AttitudeMsg m_filtered_attitude;
	AttitudeMsg m_filtered_attitude_temp;
	Vector3D<float> acc_data, gyro_data;

	AttitudeMsg getAccAttitude();
};