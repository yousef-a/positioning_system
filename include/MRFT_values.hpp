#pragma once
#include <stdint.h>
#include "common_types.hpp"


class MRFT_bag {

public:

	float amplitude;
    uint32_t duration;
	   
};

class MRFT_parameters {

public:

	float beta;
	float relay_amp;
	float bias;
	float dt = -1;
	block_id id;
	   
};

class MRFT_data {
	
public:
	float err;
	bool mrft_bag_ready_para;
	MRFT_bag mrft_period;
};
