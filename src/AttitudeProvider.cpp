#include "AttitudeProvider.hpp"

AttitudeProvider::AttitudeProvider(std::string t_name, block_type t_type) : Provider(t_name, t_type) 
{
}

AttitudeProvider::~AttitudeProvider() {

}

DataMessage* AttitudeProvider::receive_msg_internal(DataMessage*){
    
}

DataMessage* AttitudeProvider::receive_msg_internal(){
    m_att_msg = this->getAttitude();
    return (DataMessage*) &m_att_msg;
}