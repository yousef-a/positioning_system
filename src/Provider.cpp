#include "Provider.hpp"

Provider::Provider(std::string t_name, block_type t_type) {
    _name = t_name;
    _type = t_type;
}

Provider::~Provider() {

}

std::string Provider::getName(){
    return _name;
}
block_type Provider::getType(){
    return _type;
}
void Provider::switchIn(DataMessage* data){
    // Vector3DMessage* pos_msg = (Vector3DMessage*)t_pos_msg;
    
    // std::cout << "Switch In with Message: \n";
    // std::cout << "X: " << pos_msg->getData().x << std::endl;
    // std::cout << "Y: " << pos_msg->getData().y << std::endl;
    // std::cout << "Z: " << pos_msg->getData().z << std::endl;
}
DataMessage* Provider::switchOut(){
    //TODO implement
    // Vector3DMessage* pos_msg = new Vector3DMessage(this->getPosition());

    // return (DataMessage*)pos_msg;
    DataMessage* msg;
    return msg;
}