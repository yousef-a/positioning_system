#include "PID_Controller.hpp"

PID_Controller::PID_Controller(string name, block_type type){
    _name = name;
    _type = type;
    
    if(_type == block_type::controller)
        std::cout << "This is a "<< _name <<" block" << std::endl; 
    else
        std::cout << "NOT WHATEVER" << std::endl;
    
    _status = false;
}

PID_Controller::~PID_Controller() {

}

void PID_Controller::receive_msg_data(DataMessage* t_msg){

}

void PID_Controller::switchIn(DataMessage* data){
    _status = true;
}

DataMessage* PID_Controller::switchOut(){
    
    _status = false;
    DataMessage* msg;
    
    return msg;
}   


bool PID_Controller::getStatus(){

    std::cout << "Block Status: " << _status << std::endl;
    return _status;
}

block_type PID_Controller::getType(){

    std::cout << "Block Type: " << std::endl;
    return _type;
}

void PID_Controller::setStatus(bool status){

    _status = status;
}

string PID_Controller::getName(){

    std::cout << "Block Type: " << std::endl;
    return _name;
}