#pragma once
#include "common_types.hpp"

class ButterFilter_2nd_200Hz {

private:
	float prev_y=0, prev2_y=0, prev_x=0, prev2_x=0;

public:
	float perform(float input);

};
