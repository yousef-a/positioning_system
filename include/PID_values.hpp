#pragma once
#include <stdint.h>
#include "DataMessage.hpp"
#include "common_types.hpp"

class PID_parameters : public DataMessage{

private:
	msg_type _type;

public:
	//TODO add a string NAME
	float kp, ki, kd, kdd, anti_windup, dt;
	uint8_t en_pv_derivation;

	msg_type getType(){return _type;}
    const int getSize(){return sizeof(this);}
	   
};

class PID_data {

public:

	float err, pv_first, pv_second;
	   
};