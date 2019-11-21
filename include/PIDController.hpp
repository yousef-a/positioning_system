#pragma once
#include "Block.hpp"
#include <math.h>
#define dt_manual 0.01f

class PIDController : public Block{

    private:
        string _name; 
        block_type _type;
        //Chehadeh's code
        bool i_term, d_term, dd_term; //Comparing against booleans is faster
	    bool en_pv_derivation = true, en_anti_windup = false;
        struct pid_para{
            float kp, ki, kd,kdd, anti_windup;
            uint8_t en_pv_derivation;
        }parameters;
        void set_internal_sw(pid_para pid_para_x);
        //---------------
        
    public:
        //Chehadeh's code
        float prev_err = 0, prev2_err = 0, prev_pv_rate = 0, accum_u = 0, accum_I = 0;
        void initialize(void*);
        float pid_inc(float err, float pv_first,float pv_second=-1);
        float pid_direct(float err, float pv_first,float pv_second=-1);
        void set_I_term(float);
        //---------------
        void receive_msg_data(DataMessage* t_msg);
        void switchIn(DataMessage*);
        DataMessage* switchOut();
        string getName();
        block_type getType();

        PIDController(string name, block_type type);
        ~PIDController();
};
