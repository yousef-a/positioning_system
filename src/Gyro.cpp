#include "Gyro.hpp"
#include <iostream>
//TODO remove
Gyro::Gyro()
{
	calibration_offset = 0;
}

sens_type Gyro::getSensType(void)
{
	return GYROSCOPE;
}

void Gyro::resetCalibration(void)
{
	calibration_offset = 0;
	calibration_counter = 0;
}

void Gyro::startCalibration(void)
{
	resetCalibration();
	calibration_flag = true;
}

void Gyro::stopCalibration(void)
{
	calibration_flag = false;
	updateCalibrationTerms();
}

void Gyro::updateCalibrationTerms(void)
{
	calibration_offset = calibration_temp;
}

sen_status Gyro::getSensorStatus(void)
{
	if(calibration_flag)
	{
		return CALIBRATING;
	}
	else
	{
		return CALIBRATED;
	}
}

void Gyro::setSens(float tmp)
{
	sens = tmp;
}

void Gyro::doCalibrationCycle(void)
{
	float avg_factor = 0;

	if((calibration_counter + 1) > 0)
	{
		avg_factor = (float) (calibration_counter - 1);
		avg_factor = (float) avg_factor/calibration_counter;

		calibration_temp = vec_3d<int>(vec_3d<float>(calibration_temp) * avg_factor + vec_3d<float>(raw) / (float)calibration_counter);
	}
}

vec_3d<float> Gyro::getCalibratedData(void)
{
	raw = getRawData();
	if(calibration_flag) //TODO: raw is int, but the func returns float
	{
		doCalibrationCycle();
		return raw;
	}
	calibrated = vec_3d<float>((raw - calibration_offset)) / sens;

	// std::cout << "Calibrated_X " <<  calibrated.x << std::endl;
	// std::cout << "Calibrated_Y " <<  calibrated.y << std::endl;
	// std::cout << "Calibrated_Z " <<  calibrated.z << std::endl;


	return calibrated;
}

vec_3d<float> Gyro::getBodyRate(void)
{	
	return getCalibratedData();
}