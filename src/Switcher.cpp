#include "Switcher.hpp"

Switcher::Switcher(switcher_type t_type) {
    _type = t_type;
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

switcher_type Switcher::getType(){
    return _type;
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
    if(t_msg->getType() == msg_type::control_system){
        
        SwitchMessage* switch_msg = (SwitchMessage*)t_msg;
        
        if(switch_msg->getControlSystemMsgType() == control_system_msg_type::switch_in_out){
            Block* switch_from_block = switch_msg->getFromBlock();
            Block* switch_to_block = switch_msg->getToBlock();

            if(switch_from_block == nullptr){
                switch_to_block->switchIn();
            }
            else if(switch_from_block->getType() == switch_to_block->getType()){
                switch_to_block->switchIn(switch_from_block->switchOut());
            }
            
        } else if (switch_msg->getControlSystemMsgType() == control_system_msg_type::add_block){
            Block* block_to_add = switch_msg->getBlockToAdd();

            if(this->getType() == switcher_type::controller && block_to_add->getType() == block_type::controller){
                this->addBlock(block_to_add);
            }else if(this->getType() == switcher_type::reference && block_to_add->getType() == block_type::reference){
                this->addBlock(block_to_add);
            }else if(this->getType() == switcher_type::provider && block_to_add->getType() == block_type::provider){
                this->addBlock(block_to_add);
            }
        }
        
    }
}