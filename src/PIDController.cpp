#include "PIDController.hpp"

PIDController::PIDController(string name, block_type type){
    _name = name;
    _type = type;
    
    if(_type == block_type::controller)
        std::cout << "This is a "<< _name <<" block" << std::endl; 
    else
        std::cout << "NOT WHATEVER" << std::endl;
    
    _status = false;
}

PIDController::~PIDController() {

}

void PIDController::receive_msg_data(DataMessage* t_msg){

}

void PIDController::switchIn(DataMessage* data){
    _status = true;
    this->emit_message(data);
}

void PIDController::switchIn(){
    _status = true;
}

DataMessage* PIDController::switchOut(){
    
    _status = false;
    DataMessage* msg;
    return msg;
}   


bool PIDController::getStatus(){

    std::cout << "Block " << _name << " Status: " << _status << std::endl;
    return _status;
}

block_type PIDController::getType(){
    return _type;
}

void PIDController::setStatus(bool status){

    _status = status;
}

string PIDController::getName(){

    std::cout << "Block Name: " << std::endl;
    return _name;
}