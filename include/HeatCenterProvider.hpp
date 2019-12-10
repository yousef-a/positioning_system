#pragma once

#include "math.h"
#include "Provider.hpp"
#include "ImageConverter.hpp"
#include "ThermalImageMsg.hpp"
#include "NozzleOrientationMsg.hpp"
#include <iostream>

class  HeatCenterProvider : public Provider
{
public:
	float getThermalCutoff(void);
	void setDynThermalCutoff(float);
	NozzleOrientationMsg getHeatCenter(ThermalImageMsg*);

	DataMessage* receive_msg_internal(DataMessage*);
    DataMessage* receive_msg_internal();
    void receive_msg_data(DataMessage* t_msg);


private:

	NozzleOrientationMsg orientation;
	ThermalImageMsg* m_thermal_image;
	int _t_threshold;
	float _t_cutoff;
	void calcFireCenter(cv::Mat, CamSpecs cam);
	void calcFireAngles(int x,int y, CamSpecs cam);
	int getThreshold(float, float);
};
