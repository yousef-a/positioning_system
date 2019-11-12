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

void Switcher::setStatus(Block* b, bool status){

    b->setStatus(status);
}

void Switcher::switchBlock(Block* from, Block* to){
    
    from->switchOut();
    to->switchIn();
}