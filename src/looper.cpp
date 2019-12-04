#include "looper.hpp"
    
Looper::Looper(){

}

void* Looper::Loop1KHz(void *vargp) 
{ 
    Timer* _loop_timer = new Timer();
    
    while(1){
        _loop_timer->tick();
        //t_CS->loopInternal();
        int consumed_time =_loop_timer->tockMicroSeconds();
        if (consumed_time>Loop1KHz_dt){
            Logger::getAssignedLogger()->log("exceeded loop time",LoggerLevel::Warning);
        }
        else{
            usleep(Loop1KHz_dt-consumed_time);
        }
    }
} 

void* Looper::Loop100Hz(void *vargp) 
{ 
    Timer* _loop_timer = new Timer();
    while(1){
        _loop_timer->tick();
        //CS.loop_internal()
        int consumed_time =_loop_timer->tockMicroSeconds();
        if (consumed_time>Loop100Hz_dt){
            Logger::getAssignedLogger()->log("exceeded loop time",LoggerLevel::Warning);
        }
        else{
            usleep(Loop100Hz_dt-consumed_time);
        }
    }
} 

void Looper::addTimedBlock100Hz(ControlSystem* t_cs){
    _control_systems_100hz.push_back(t_cs);
}

void Looper::addTimedBlock1KHz(ControlSystem* t_cs){
    _control_systems_1khz.push_back(t_cs);
}
