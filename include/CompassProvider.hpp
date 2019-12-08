#pragma once 

#include "vec_3d.hpp"

class CompassProvider
{
public:

	virtual vec_3d<float> GetCompass() = 0;

};