#pragma once
#include "Switcher.hpp"
#include "msg_emitter.hpp"
#include "msg_receiver.hpp"
#include <vector>
#include "ControlSystemMessage.hpp"

class ControlSystem : public msg_emitter, public msg_receiver{

    private:
        Switcher* controllerSwitcher = new Switcher(switcher_type::controller);
        Switcher* referenceSwitcher = new Switcher(switcher_type::reference);
        Switcher* providerSwitcher = new Switcher(switcher_type::provider);
        std::vector<Switcher*> _switchers{controllerSwitcher, referenceSwitcher, providerSwitcher};


    public:
        void receive_msg_data(DataMessage* t_msg);
        void getStatus();
        void switchBlock(Block* t_from, Block* t_to);
        void addBlock(Block* t_block);

        Switcher* getControllerSwitcher();
        Switcher* getReferenceSwitcher();
        Switcher* getProviderSwitcher();

        ControlSystem();
        ~ControlSystem();

    
};