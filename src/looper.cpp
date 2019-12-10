#include "looper.hpp"

Looper* Looper::_instance_ptr = NULL;

Looper::Looper(){
    _instance_ptr = this;
}

void* Looper::Loop1KHz(void *vargp) 
{ 
    Timer* _loop_timer = new Timer();
    
    int j = 0;
    int p = 0;

    while(1){
        _loop_timer->tick();

        for (TimedBlock* const& i : _instance_ptr->_timed_blocks){
            if(i->getLoopTime() == block_frequency::hz1000){
                i->loopInternal();
            }
        }
        
        int consumed_time =_loop_timer->tockMicroSeconds();
        if (consumed_time>Loop1KHz_dt){
            //Logger::getAssignedLogger()->log("exceeded loop time 1khz ",LoggerLevel::Warning);
            std::cout << "Consumed Time 1kHz" << consumed_time << std::endl;
            //std::cout << "Exceeded: " << j++ << std::endl;

        }
        else{
            //std::cout << "Sleep Time" << Loop1KHz_dt-consumed_time << std::endl;
            usleep(Loop1KHz_dt-consumed_time);
            std::cout << "Fine: " << p++ << std::endl;
        }
    }
} 

void* Looper::Loop100Hz(void *vargp) 
{ 
    Timer* _loop_timer = new Timer();
    while(1){
        _loop_timer->tick();

        for (TimedBlock* const& j : _instance_ptr->_timed_blocks){
            if(j->getLoopTime() == block_frequency::hz100){
                j->loopInternal();
            }
        }
        
        int consumed_time =_loop_timer->tockMicroSeconds();
        if (consumed_time>Loop100Hz_dt){
            Logger::getAssignedLogger()->log("exceeded loop time 100hz",LoggerLevel::Warning);
            // std::cout << "exceeded loop time" << std::endl;
        }
        else{
            usleep(Loop100Hz_dt-consumed_time);
        }
    }
} 

void Looper::addTimedBlock(TimedBlock* t_cs){
    _timed_blocks.push_back(t_cs);
}