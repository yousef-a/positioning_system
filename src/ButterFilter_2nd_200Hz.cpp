#include "ButterFilter_2nd_200Hz.hpp"

float ButterFilter_2nd_200Hz::perform(float x) {
	float y = -coeff_200Hz_2nd_butter[0] * prev_y - coeff_200Hz_2nd_butter[1] * prev2_y + coeff_200Hz_2nd_butter[2] * x + coeff_200Hz_2nd_butter[3] * prev_x + coeff_200Hz_2nd_butter[4] * prev2_x;
	prev2_y = prev_y;
	prev_y = y;
	prev2_x = prev_x;
	prev_x = x;
	return y;
}