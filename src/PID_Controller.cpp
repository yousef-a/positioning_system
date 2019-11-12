#include "PID_Controller.hpp"

PID_Controller::PID_Controller(string name, block_type type) {
    if(_type == block_type::controller)
        std::cout << "This is a Controller block" << std::endl; 
    else
        std::cout << "NOT WHATEVER" << std::endl;
   
    _status = false;
}

PID_Controller::~PID_Controller() {

}

void PID_Controller::receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type){

}

void PID_Controller::switchIn(){
    _status = true;
}

void PID_Controller::switchOut(){
    _status = false;
}   
