#pragma once

#include "DataMessage.hpp"
#include "msg_emitter.hpp"
#include "msg_receiver.hpp"
#include "ControlSystemMessage.hpp"


class  Actuator {
    public:
        virtual bool initialize() = 0;
        virtual bool applyCommand(int command) = 0;
};
