#pragma once 

#include "vec_3d.hpp"

class BodyRateProvider
{
public:
	virtual vec_3d<float> getBodyRate() = 0;
};