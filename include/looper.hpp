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
    public:
        static void* Loop1KHz(void *vargp);
        static void* Loop100Hz(void *vargp);
        
};