#include "MRFT_ParametersMsg.hpp"

MRFT_ParametersMsg::MRFT_ParametersMsg() {

}

MRFT_ParametersMsg::~MRFT_ParametersMsg() {

}

msg_type MRFT_ParametersMsg::getType(){
    return _type;
}

const int MRFT_ParametersMsg::getSize(){
    return sizeof(this);
}

void MRFT_ParametersMsg::setMRFTParam(MRFT_parameters t_param){

    _type = msg_type::UPDATECONTROLLER;
    _params.beta = t_param.beta;
    _params.relay_amp = t_param.relay_amp;
    _params.bias = t_param.bias;
    _params.id = t_param.id;
    std::cout << "SET MRFT CONTROLLER: " << _params.beta << std::endl;
    
}