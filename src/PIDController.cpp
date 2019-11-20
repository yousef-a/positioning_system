#include "PIDController.hpp"

PIDController::PIDController(string name, block_type type){
    _name = name;
    _type = type;
    
    if(_type == block_type::controller)
        std::cout << "This is a "<< _name <<" block" << std::endl; 
    else
        std::cout << "NOT WHATEVER" << std::endl;
}

PIDController::~PIDController() {

}

void PIDController::receive_msg_data(DataMessage* t_msg){

}

void PIDController::switchIn(DataMessage* data){
    this->emit_message(data);
}


DataMessage* PIDController::switchOut(){
    
    DataMessage* msg;
    return msg;
}   

block_type PIDController::getType(){
    return _type;
}

string PIDController::getName(){

    std::cout << "Block Name: " << std::endl;
    return _name;
}