#pragma once
#include "DataMessage.hpp"
#include <vector>
#include "PID_parameters.hpp"

class ControllerMessage : public DataMessage{

private:
    std::vector<double> _data;
    msg_type _type;
    PID_parameters* _pid_para;
    controller_msg_type _controller_msg_type;

public:
    std::vector<double> getData();
    PID_parameters* getSettings();
    msg_type getType();
    controller_msg_type getControllerMsgType();

    ControllerMessage(controller_msg_type, std::vector<double>);
    ControllerMessage(controller_msg_type, PID_parameters*);
    ~ControllerMessage();
};