#pragma once
#include "DataMessage.hpp"

class SwitchOutMsg : public DataMessage{

public:

    msg_type getType();
	const int getSize();
    
    SwitchOutMsg();
    ~SwitchOutMsg();
};