#pragma once
#include <pthread.h>
#include "timer.hpp"
#include <unistd.h>
const int Loop1KHz_dt = 1000; //in us
const int Loop100Hz_dt = 10000; //in us

class looper {

    public:
        void *Loop1KHz(void *vargp);
        void *Loop100Hz(void *vargp);

};