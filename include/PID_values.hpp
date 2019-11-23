#pragma once
#include <stdint.h>

class PID_parameters {

public:

	float kp, ki, kd, kdd, anti_windup;
	uint8_t en_pv_derivation;
	   
};

class PID_data {

public:

	float err, pv_first, pv_second;
	   
};