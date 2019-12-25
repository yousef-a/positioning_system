#pragma once
#include "DataMessage.hpp"
#include "common_types.hpp"
#include "PID_values.hpp"

class PID_ParametersMsg : public DataMessage{

private:
	msg_type _type;
    PID_parameters _params;
    
public:

	msg_type getType();
    const int getSize();
	void setPIDParam(PID_parameters);
    PID_parameters getPIDParam(){return _params;}

    PID_ParametersMsg();
    ~PID_ParametersMsg();
};