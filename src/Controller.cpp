#include "Controller.hpp"

Controller::Controller() {
    _type = block_type::controller;
}

Controller::~Controller() {

}

block_type Controller::getType(){
    return _type;
}
