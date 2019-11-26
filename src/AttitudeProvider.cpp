#include "AttitudeProvider.hpp"

AttitudeProvider::AttitudeProvider(std::string t_name, block_type t_type) : Provider(t_name, t_type) {
    _provider_type = provider_type::attitude;
}

AttitudeProvider::~AttitudeProvider() {

}

DataMessage* AttitudeProvider::receive_msg_internal(DataMessage*){
    std::cout << ".......................Inside ATTITUDE PROVIDER" << std::endl;
    std::cout << "Received request from Switcher."<< std::endl;
    Vector3DMessage* att_msg = new Vector3DMessage(this->getAttitude(), _provider_type);
    std::cout << "Sending it back"<< std::endl;

    return (DataMessage*)att_msg;
}

DataMessage* AttitudeProvider::receive_msg_internal(){

}

provider_type AttitudeProvider::getProviderType(){
    return _provider_type;
}