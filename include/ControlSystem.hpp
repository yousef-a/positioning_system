#pragma once
#include "Switcher.hpp"
#include "msg_emitter.hpp"
#include "msg_receiver.hpp"
#include <vector>

class ControlSystem : public msg_emitter, public msg_receiver{

    private:
        Switcher* controllerSwitcher = new Switcher();
        Switcher* referenceSwitcher = new Switcher();
        Switcher* observerSwitcher = new Switcher();
        std::vector<Switcher*> _switchers{controllerSwitcher, referenceSwitcher, observerSwitcher};

    public:
        void receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type);
        void getStatus();
        Switcher* getControllerSwitcher();
        Switcher* getReferenceSwitcher();
        Switcher* getObserverSwitcher();

        ControlSystem();
        ~ControlSystem();

    
};