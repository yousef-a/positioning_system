#pragma once
#include <stdint.h>
#include "DataMessage.hpp"
#include "common_types.hpp"

class PID_parameters{

public:
	//TODO add a string NAME
	float kp, ki, kd, kdd, anti_windup, dt = -1;
	block_id id;
	uint8_t en_pv_derivation;	   
};


class PID_data {

public:

	float err, pv_first, pv_second;
	   
};