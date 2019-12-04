#include "looper.hpp"

Looper* Looper::_instance_ptr = NULL;

Looper::Looper(){
    _instance_ptr = this;
}

void* Looper::Loop1KHz(void *vargp) 
{ 
    Timer* _loop_timer = new Timer();
    
    while(1){
        _loop_timer->tick();

        for (ControlSystem* const& i : _instance_ptr->_control_systems_1khz){
            i->loopInternal();
        }
        
        int consumed_time =_loop_timer->tockMicroSeconds();
        if (consumed_time>Loop1KHz_dt){
            Logger::getAssignedLogger()->log("exceeded loop time",LoggerLevel::Warning);
            std::cout << "exceeded loop time" << std::endl;
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

        for (ControlSystem* const& j : _instance_ptr->_control_systems_100hz){
            j->loopInternal();
        }
        
        int consumed_time =_loop_timer->tockMicroSeconds();
        if (consumed_time>Loop100Hz_dt){
            Logger::getAssignedLogger()->log("exceeded loop time",LoggerLevel::Warning);
            std::cout << "exceeded loop time" << std::endl;
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
