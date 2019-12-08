#pragma once 

#include "data_message.hpp"
#include "common_types.hpp"

class HeadingMsg : public DataMessage
{
public:

	msg_type getType();
	const int getSize();

	float yaw;	 
};