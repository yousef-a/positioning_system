#pragma once
#include "ActuationSystem.hpp"
#include "ControlSystemMessage.hpp"

class HexaActuationSystem : public ActuationSystem {

public:

    void receive_msg_data(DataMessage* t_msg);

    HexaActuationSystem();
    ~HexaActuationSystem();
};