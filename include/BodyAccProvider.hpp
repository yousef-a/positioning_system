#pragma once 

#include "vec_3d.hpp"

class BodyAccProvider
{
public:

	virtual vec_3d<float> getBodyAcceleration() = 0;

};