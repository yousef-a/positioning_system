#include "looper.hpp"
    
void *Loop1KHz(void *vargp) 
{ 
    Timer* _loop_timer = new Timer();
    
    while(1){
        _loop_timer->tick();
        //CS.loop_internal()
        int consumed_time =_loop_timer->tockMicroSeconds();
        if (consumed_time>Loop1KHz_dt){
            Logger.getMainLogger()->log("exceeded loop time",Logger::Warning);
        }
        else{
            usleep(Loop1KHz_dt-consumed_time);
        }
    }
} 

void *Loop100Hz(void *vargp) 
{ 
    Timer _loop_timer = new Timer();
    while(1){
        _loop_timer.tick();
        //CS.loop_internal()
        int consumed_time =_loop_timer->tockMicroSeconds();
        if (consumed_time>Loop100Hz_dt){
            Logger.getMainLogger()->log("exceeded loop time",Logger::Warning);
        }
        else{
            usleep(Loop100Hz_dt-consumed_time);
        }
    }
} 
