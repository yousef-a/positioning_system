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

block_type Controller::getType() {
    return _type;
}

void Controller::switchIn(){


}

void Controller::switchOut(){


}   

void Controller::receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type){


}