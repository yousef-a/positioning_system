#pragma once 

#include "ThreeAxisSensor.hpp"
#include "CompassProvider.hpp"

class Mag : public ThreeAxisSensor, public CompassProvider
{
public:

	Mag();

	sens_type getSensType();
	void startCalibration();
	void stopCalibration();
	void resetCalibration();
	sen_status getSensorStatus();
	vec_3d<float> getCalibratedData(); 
	vec_3d<float> GetCompass(); 

	virtual void setSettings(setting_type, float) = 0;

protected:

	void setSens(float);

	virtual vec_3d<int> getRawData() = 0;

private:

	float sens;

	vec_3d<int> raw;
	vec_3d<int> calibration_offset; 
	vec_3d<float> calibration_scale;
	vec_3d<float> calibrated;

	bool calibration_flag = false;
	int calibration_counter;
	vec_3d<int> calibration_temp;

	void doCalibrationCycle();
	void updateCalibrationTerms(); 
	
};