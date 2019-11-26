#include "PositioningProvider.hpp"

PositioningProvider::PositioningProvider(std::string t_name, block_type t_type) : Provider(t_name, t_type){
    _provider_type = provider_type::position;
    Vector3D _homePos;

}

PositioningProvider::~PositioningProvider(){
    
}

void PositioningProvider::setHomePosition(Vector3D data){


}

provider_type PositioningProvider::getProviderType(){
    return _provider_type;
}
Vector3D PositioningProvider::getRelativePosition(){
    return _homePos;
}

//TODO remove the need of argument
DataMessage* PositioningProvider::receive_msg_internal(DataMessage* t_msg){
    
}

DataMessage* PositioningProvider::receive_msg_internal(){
    std::cout << "POSITIONING PROVIDER BLOCK" << std::endl;
    std::cout << "Received request from Switcher."<< std::endl;
    Vector3DMessage* pos_msg = new Vector3DMessage(this->getPosition(), _provider_type);
    std::cout << "Sending it back"<< std::endl;

    return (DataMessage*)pos_msg;
}