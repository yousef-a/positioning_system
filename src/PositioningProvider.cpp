#include "PositioningProvider.hpp"

PositioningProvider::PositioningProvider(std::string t_name, block_type t_type){
    _name = t_name;
    _type = t_type;
    Vector3D _homePos;
    std::cout << "Position constructor" << std::endl;
}

void PositioningProvider::setHomePosition(Vector3D data){


}

Vector3D PositioningProvider::getRelativePosition(){

    return _homePos;
}

std::string PositioningProvider::getName(){
    return _name;
}
block_type PositioningProvider::getType(){
    return _type;
}
void PositioningProvider::switchIn(DataMessage* t_pos_msg){
    Vector3DMessage* pos_msg = (Vector3DMessage*)t_pos_msg;
    
    std::cout << "Switch In with Message: \n";
    std::cout << "X: " << pos_msg->getData().x << std::endl;
    std::cout << "Y: " << pos_msg->getData().y << std::endl;
    std::cout << "Z: " << pos_msg->getData().z << std::endl;

}
DataMessage* PositioningProvider::switchOut(){
    Vector3DMessage* pos_msg = new Vector3DMessage(this->getPosition());

    return (DataMessage*)pos_msg;
}

DataMessage* PositioningProvider::receive_msg_internal(){
    std::cout << "Received request from Switcher."<< std::endl;
    Vector3DMessage* pos_msg = new Vector3DMessage(this->getPosition());
    std::cout << "Sending it back"<< std::endl;

    return (DataMessage*)pos_msg;
}
