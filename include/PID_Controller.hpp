#pragma once
#include "Controller.hpp"

class PID_Controller : public Controller{

    private:
        string _name; //TODO remove _name from here and add type
        
    public:
        PID_Controller();
        ~PID_Controller();
};