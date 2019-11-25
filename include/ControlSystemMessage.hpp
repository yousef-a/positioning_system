#pragma once
#include "DataMessage.hpp"
#include "Block.hpp"
#include "PID_values.hpp"

class ControlSystemMessage : public DataMessage{

private:
    Block* _to_remove;
    Block* _to_add;
    msg_type _type;
    control_system_msg_type _control_system_msg_type;
    PID_parameters* _pid_para;
    control_system _source;
    control_system _destination;
    float _data;

public:
    msg_type getType();
    Block* getBlockToRemove();
    Block* getBlockToAdd();
    control_system_msg_type getControlSystemMsgType();
    PID_parameters* getPIDSettings();
    control_system getSource();
    control_system getDestination();
    float getData();

    ControlSystemMessage(control_system_msg_type, Block*, Block*);
    ControlSystemMessage(control_system_msg_type, Block*);
    ControlSystemMessage(control_system_msg_type, PID_parameters*);
    ControlSystemMessage(control_system, control_system, control_system_msg_type, float);
    
    ~ControlSystemMessage();
};