#include "Reference.hpp"

Reference::Reference(string name, block_type type){
    _name = name;
    _type = type;
    
    if(_type == block_type::reference)
        std::cout << "This is a "<< _name <<" block" << std::endl;  
    else
        std::cout << "NOT WHATEVER" << std::endl;

    _status = true;
}

Reference::~Reference() {

}

block_type Reference::getType() {
    return _type;
}

void Reference::switchIn(DataMessage* data){
    _status = true;
}

DataMessage* Reference::switchOut(){
    
    _status = false;
    DataMessage* msg;
    
    return msg;
}    

void Reference::receive_msg_data(DataMessage* t_msg){


}

bool Reference::getStatus(){

    std::cout << "Block Status: " << _status << std::endl;
    return _status;
}

void Reference::setStatus(bool status){

    _status = status;
}

string Reference::getName(){

    std::cout << "Block Type: " << std::endl;
    return _name;
}
