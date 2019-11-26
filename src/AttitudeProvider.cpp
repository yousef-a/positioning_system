#include "AttitudeProvider.hpp"

AttitudeProvider::AttitudeProvider(std::string t_name, block_type t_type) : Provider(t_name, t_type) {
    _provider_type = provider_type::position;
}

AttitudeProvider::~AttitudeProvider() {

}

DataMessage* AttitudeProvider::receive_msg_internal(DataMessage*){

}

DataMessage* AttitudeProvider::receive_msg_internal(){

}

provider_type AttitudeProvider::getProviderType(){
    return _provider_type;
}