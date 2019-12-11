#include "PositioningProvider.hpp"

PositioningProvider::PositioningProvider(std::string t_name, block_type t_type) : Provider(t_name, t_type){

}

PositioningProvider::~PositioningProvider(){
    
}

void PositioningProvider::setHomePosition(Vector3D data){


}

Vector3D PositioningProvider::getRelativePosition(){
    return _homePos;
}

//TODO remove the need of argument
DataMessage* PositioningProvider::receive_msg_internal(DataMessage* t_msg){
    
}

DataMessage* PositioningProvider::receive_msg_internal(){
    m_pos_msg = this->getPosition();
    return (DataMessage*) &m_pos_msg;
}