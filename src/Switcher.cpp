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

    DataMessage* msg;
    b->switchIn(msg);
}

void Switcher::switchBlock(Block* from, Block* to){
    
    DataMessage* msg;    
    from->switchOut();
    to->switchIn(msg);
}

void Switcher::receive_msg_data(DataMessage* t_msg){
    if(t_msg->getType() == msg_type::switcher){
        SwitchMessage* switch_msg = (SwitchMessage*)t_msg;
        Block* switch_from_block = switch_msg->getFromBlock();
        Block* switch_to_block = switch_msg->getToBlock();

        if(switch_from_block == nullptr){
            switch_to_block->switchIn();
        }
        else if(switch_from_block->getType() == switch_to_block->getType()){
            switch_to_block->switchIn(switch_from_block->switchOut());
        }
    }
}