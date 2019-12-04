#pragma once
#include <pthread.h>
#include "timer.hpp"
#include <unistd.h>
const int Loop1KHz_dt = 1000; //in us
const int Loop100Hz_dt = 10000; //in us
#include "logger.hpp"
#include "ControlSystem.hpp"

class Looper {
    //TODO convert to singleton
    //TODO create Timed Block as parent of ControlSystem

    private:
        std::list<ControlSystem*> _control_systems_100hz;
        std::list<ControlSystem*> _control_systems_1khz;
        std::list<ControlSystem*>::iterator _it;

    public:
        static void* Loop1KHz(void *vargp);
        static void* Loop100Hz(void *vargp);
        void addTimedBlock100Hz(ControlSystem*);
        void addTimedBlock1KHz(ControlSystem*);

        Looper();
};