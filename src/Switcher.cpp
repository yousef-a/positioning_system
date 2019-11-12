#include "Switcher.hpp"

Switcher::Switcher() {

}

Switcher::~Switcher() {

}

void Switcher::addBlock(Block* b){
    
    _blocks.push_back(b);
}

void Switcher::getStatus(){

    for(_it=_blocks.begin(); _it!=_blocks.end(); ++_it){
        (*_it)->getStatus();
    }
}

void Switcher::setInitialCondition(Block* b, bool status){

    b->switchIn();
}

void Switcher::switchBlock(Block* from, Block* to){
    
    from->switchOut();
    to->switchIn();
}

void Switcher::receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type){
    
}