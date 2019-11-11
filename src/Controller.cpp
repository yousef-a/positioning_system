#include "Controller.hpp"

Controller::Controller() : Block(block_type::controller){
    if(_type == block_type::controller)
        std::cout << "This is a Controller block" << std::endl; 
    else
        std::cout << "NOT WHATEVER" << std::endl;
    //while(1);        
}

Controller::~Controller() {

}

void Controller::switchIn(){
    _status = true;
}

void Controller::switchOut(){
    _status = false;
}   

void Controller::receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type){


}