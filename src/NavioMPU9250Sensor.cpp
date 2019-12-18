#include "NavioMPU9250Sensor.hpp"
#include <iostream>
//TODO remove

NAVIOMPU9250_sensor::NAVIOMPU9250_sensor() //TODO: we need to add a logger for imu fail!!!
{
	
	if(_imu.probe())
	{
		_imu.initialize();
		_imu.update();
		//_timer.tick();
		std::cout << "init imu" << std::endl;
	}
	else
	{
		while(1)
		{
			std::cout << "FAILED TO START IMU" << std::endl;
		}
	}
}

Acc* NAVIOMPU9250_sensor::getAcc()
{
	return (Acc*) _acc;
}

Gyro* NAVIOMPU9250_sensor::getGyro()
{
	return (Gyro*) _gyro;
}

Mag* NAVIOMPU9250_sensor::getMag()
{
	return (Mag*) _mag;
}

void NAVIOMPU9250_sensor::updateReadings()
{
	if(_timer.tockMicroSeconds() > _dt)
	{
		_imu.update();
		_timer.tick();
		_imu.read_raw_accelerometer(&(m_acc.x), &(m_acc.y), &(m_acc.z));
		_imu.read_raw_gyroscope(&(m_gyro.x), &(m_gyro.y), &(m_gyro.z));
		_imu.read_raw_magnetometer(&(m_mag.x), &(m_mag.y), &(m_mag.z));
	}
}

void NAVIOMPU9250_sensor::getAccelReadings(Vector3D<int> &tmp)
{
	tmp = m_acc;
}

void NAVIOMPU9250_sensor::getGyroReadings(Vector3D<int> &tmp)
{
	tmp = m_gyro;
}

void NAVIOMPU9250_sensor::getMagReadings(Vector3D<int> &tmp)
{
	tmp = m_mag;
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
			_gyro->setSettings(SENS, 16.f);
		}
		else if(sensor_name == MAGNETOMETER)
		{
			//TODO: add a warning here, since it is fixed for this type of sensors
		}
	}
	else if(setting_name == SAMPLERATE)
	{
		//m_samplerate = val;
		int _dt = (int) 1000000.f/((float)val);
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