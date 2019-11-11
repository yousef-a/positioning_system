#include "Controller.hpp"

Controller::Controller() {
    _type = block_type::controller;
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