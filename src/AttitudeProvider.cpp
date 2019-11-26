#include "AttitudeProvider.hpp"

AttitudeProvider::AttitudeProvider(std::string t_name, block_type t_type) : Provider(t_name, t_type) {
    _provider_type = provider_type::attitude;
}

AttitudeProvider::~AttitudeProvider() {

}

DataMessage* AttitudeProvider::receive_msg_internal(DataMessage*){
    
}

DataMessage* AttitudeProvider::receive_msg_internal(){
    std::cout << ".......................Inside ATTITUDE PROVIDER BLOCK" << std::endl;
    std::cout << "Received request from Switcher."<< std::endl;
    Vector3DMessage* att_msg = new Vector3DMessage(this->getAttitude(), _provider_type);
    std::cout << "Sending it back"<< std::endl;

    return (DataMessage*)att_msg;
}

provider_type AttitudeProvider::getProviderType(){
    return _provider_type;
}