#pragma once
#include "Switcher.hpp"
#include "msg_emitter.hpp"
#include "msg_receiver.hpp"
#include <vector>
#include "ControlSystemMessage.hpp"
#include "PID_values.hpp"
#include "UserMessage.hpp"
#include "GeneralStateProvider.hpp"

class ControlSystem : public msg_emitter, public msg_receiver{

    private:
        control_system _control_system;
        Switcher* controllerSwitcher;
        Switcher* referenceSwitcher;
        GeneralStateProvider* _providerProcessVariable;
        std::vector<Switcher*> _switchers;
        ControlSystem();

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

        ControlSystem(control_system, GeneralStateProvider*);
        ~ControlSystem(); //TODO prevent automatic storage

    
};