#pragma once 

#include "vec_3d.hpp"
#include "DataMessage.hpp"
#include "common_types.hpp"

class ThreeAxisSensorMsg : public DataMessage
{
public:

	msg_type getType();
	const int getSize();

	vec_3d<float> data; 
};