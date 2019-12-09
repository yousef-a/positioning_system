#include "NavioMPU9250Sensor.hpp"

NAVIOMPU9250_sensor::NAVIOMPU9250_sensor() //TODO: we need to add a logger for imu fail!!!
{
	if(_imu.probe())
	{
		_imu.initialize();
	}
	else
	{
		//add warning here
	}
}

ThreeAxisSensor* NAVIOMPU9250_sensor::getAcc()
{
	return _acc;
}

ThreeAxisSensor* NAVIOMPU9250_sensor::getGyro()
{
	return _gyro;
}

ThreeAxisSensor* NAVIOMPU9250_sensor::getMag()
{
	return _mag;
}

void NAVIOMPU9250_sensor::setSettings(sens_type sensor_name, setting_type setting_name, int val)
{
	if(setting_name == LPF) //TODO: add a warning here that it effects all sensors
	{
		//TODO: not implemented, navio library doesnt have this feature
		//TODO: should be added?
	}
	else if(setting_name == FSR)
	{
		if(sensor_name == ACCELEROMETER)
		{
			//TODO: the set_scale for navio library is private
			// should be made public?
			//_imu.set_acc_scale(val);

			//TODO: navio library has no getsens function
			// should be added? 
			_acc->setSettings(SENS, 2048);
		}
		else if(sensor_name == GYROSCOPE)
		{
			//TODO: see acc notes
			_gyro->setSettings(SENS, 16.4f);
		}
		else if(sensor_name == MAGNETOMETER)
		{
			//TODO: add a warning here, since it is fixed for this type of sensors
		}
	}
	else if(setting_name == SAMPLERATE)
	{
		if(sensor_name == ACCELEROMETER || sensor_name == GYROSCOPE) //TODO: add a warning here that they are coupled
		{
			//TODO: navio library has no set sample rate setting_name
			// add?
		}
		else if(sensor_name == MAGNETOMETER)
		{
			//TODO: see above comment
		}
	}
}