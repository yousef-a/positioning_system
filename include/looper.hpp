#pragma once
#include <pthread.h>
#include "timer.hpp"
#include <unistd.h>
const int Loop1KHz_dt = 1000; //in us
const int Loop100Hz_dt = 10000; //in us
#include "logger.hpp"
#include "TimedBlock.hpp"
#include <list>
#include <iostream>
//TODO: pass _dt to reflect looping rate!!!
class Looper {
    //TODO convert to singleton
    //TODO create Timed Block as parent of ControlSystem

    private:
        std::list<TimedBlock*> _timed_blocks;
        std::list<TimedBlock*>::iterator _it;
        static Looper* _instance_ptr;

    public:
        static void* Loop1KHz(void *vargp);
        static void* Loop100Hz(void *vargp);
        void addTimedBlock(TimedBlock*);

        Looper();
};