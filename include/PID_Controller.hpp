#pragma once
#include "Controller.hpp"

class PID_Controller : public Controller{

    private:
        string _name;
        
    public:
        PID_Controller();
        ~PID_Controller();
};