#pragma once 

#include "ThreeAxisSensor.hpp"
#include "BodyAccProvider.hpp"

class Acc : public ThreeAxisSensor, public BodyAccProvider
{
public:

	Acc();

	sens_type getSensType();
	void startCalibration();
	void stopCalibration();
	void resetCalibration();
	sen_status getSensorStatus();
	vec_3d<float> getCalibratedData();
	vec_3d<float> getBodyAcceleration();

	virtual void setSettings(setting_type, float) = 0;

protected:

	void setSens(float);
	void setCalibCoeff(float);
	void setgWorkingRange(float);
	virtual vec_3d<int> getRawData() = 0;


private:

	vec_3d<int> raw;
	vec_3d<int> calibration_offset;
	vec_3d<float> calibrated;

	float sens;
	float conv_coef = 1;
	float g_in_working_range = 0;

	bool calibration_flag = false;
	int calibration_counter;
	vec_3d<int> calibration_temp;

	void doCalibrationCycle();
	void updateCalibrationTerms();

};