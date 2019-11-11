#include "Block.hpp"

Block::Block(block_type tmp) {
    _type = tmp;
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
