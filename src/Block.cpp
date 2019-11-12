#include "Block.hpp"

Block::Block() {

}

Block::Block(string name, block_type type) {
    _type = type;
    _name = name;
}

Block::~Block() {

}

bool Block::getStatus(){

    std::cout << "Block Status: " << _status << std::endl;
    return _status;
}

block_type Block::getType(){

    std::cout << "Block Type: " << std::endl;
    return _type;
}

void Block::setStatus(bool status){

    _status = status;
}

string Block::getName(){

    std::cout << "Block Type: " << std::endl;
    return _name;
}

void Block::receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type){

}