#include "PID_ParametersMsg.hpp"

PID_ParametersMsg::PID_ParametersMsg() {

}

PID_ParametersMsg::~PID_ParametersMsg() {

}

msg_type PID_ParametersMsg::getType(){
    return _type;
}

const int PID_ParametersMsg::getSize(){
    return sizeof(this);
}

void PID_ParametersMsg::setPIDParam(PID_parameters t_param){

    _type = msg_type::UPDATECONTROLLER;
    _params.kp = t_param.kp;
    _params.ki = t_param.ki;
    _params.kd = t_param.kd;
    _params.kdd = t_param.kdd;
    _params.anti_windup = t_param.anti_windup;
    _params.en_pv_derivation = t_param.en_pv_derivation;
    _params.id = t_param.id;
    
}

void PID_ParametersMsg::set_dt(float t_dt){

    _type = msg_type::UPDATECONTROLLER;
    _params.dt = t_dt;
    
}