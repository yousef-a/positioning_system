#pragma once
#include "DataMessage.hpp"
#include <vector>

class ControllerMessage : public DataMessage{

private:
    std::vector<double> _data;
    
    struct pid_para{
		float kp, ki, kd, kdd, anti_windup;
		uint8_t en_pv_derivation;
	}parameters;

public:
    std::vector<double> getData();
    pid_para getSettings();
    
    ControllerMessage();
    ~ControllerMessage();
};