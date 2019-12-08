#pragma once
#include "Switcher.hpp"
#include "MsgEmitter.hpp"
#include "MsgReceiver.hpp"
#include <vector>
#include "ControlSystemMessage.hpp"
#include "PID_values.hpp"
#include "UserMessage.hpp"
#include "GeneralStateProvider.hpp"
#include "ReferenceMessage.hpp"
#include "TimedBlock.hpp"
#include "../include/Switcher.hpp"

class ControlSystem : public TimedBlock, public msg_emitter, public msg_receiver{

    private:
        control_system _control_system;
        Switcher* controllerSwitcher;
        Switcher* referenceSwitcher;
        GeneralStateProvider* _providerProcessVariable;
        std::vector<Switcher*> _switchers;
        // ControlSystem();

    public:
        void receive_msg_data(DataMessage* t_msg);
        void getStatus();
        void switchBlock(Block* t_from, Block* t_to);
        void addBlock(Block* t_block);
        void changePIDSettings(PID_parameters* t_pid_para);
        control_system getControlSystemType();
        void loopInternal();
                
        Switcher* getControllerSwitcher();
        Switcher* getReferenceSwitcher();
        // Switcher* getProviderSwitcher();

        ControlSystem(control_system, GeneralStateProvider*, block_frequency);
        ~ControlSystem(); //TODO prevent automatic storage

    
};