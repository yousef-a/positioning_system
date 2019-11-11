#pragma once
#include "Switcher.hpp"
#include "msg_emitter.hpp"
#include "msg_receiver.hpp"

class ControlSystem : public msg_emitter, public msg_receiver{

    private:
        Switcher* controllerSwitcher = new Switcher();
        Switcher* referenceSwitcher = new Switcher();
        Switcher* observerSwitcher = new Switcher();

        std::list<Switcher*> _switchers({controllerSwitcher, referenceSwitcher, observerSwitcher});
        std::list<Switcher*>::iterator _it;
    
    public:
        void receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type);
        void getStatus();

        ControlSystem();
        ~ControlSystem();
};