#pragma once
#include "Switcher.hpp"
#include "msg_emitter.hpp"
#include "msg_receiver.hpp"
#include <vector>
#include "ControlSystemMessage.hpp"
#include "PID_values.hpp"

class ControlSystem : public msg_emitter, public msg_receiver{

    private:
        Switcher* controllerSwitcher = new Switcher("ControlSwitcher", switcher_type::controller);
        Switcher* referenceSwitcher = new Switcher("ReferenceSwitcher", switcher_type::reference);
        Switcher* providerSwitcher = new Switcher("ProviderSwitcher", switcher_type::provider);
        std::vector<Switcher*> _switchers{controllerSwitcher, referenceSwitcher, providerSwitcher};


    public:
        void receive_msg_data(DataMessage* t_msg);
        void getStatus();
        void switchBlock(Block* t_from, Block* t_to);
        void addBlock(Block* t_block);
        void changePIDSettings(PID_parameters* t_pid_para);
                
        Switcher* getControllerSwitcher();
        Switcher* getReferenceSwitcher();
        Switcher* getProviderSwitcher();

        ControlSystem();
        ~ControlSystem();

    
};