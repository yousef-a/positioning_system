#pragma once

#include "CamSpecs.hpp"
#include "ThermalImageMsg.hpp"
#include "positioning_system/temp_range.h"


enum camera_name {
	LEPTON3_5 // 0
};

enum scaling_method {
	FIXED_SCALING, // 0
	AUTO_SCALING  // 1
};
	

class ThermalCam
{

public:
	virtual bool getImage(ThermalImageMsg&) = 0;
	virtual CamSpecs getSpecs() = 0;
	virtual void receive_msg_data(DataMessage* t_msg) = 0;	
};