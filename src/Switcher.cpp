#include "Switcher.hpp"

Switcher::Switcher(string t_name, switcher_type t_type) {
    _type = t_type;
    _name = t_name;
    _active_block = nullptr;
}

Switcher::~Switcher() {

}

void Switcher::addBlock(Block* b){
    
    _blocks.push_back(b);
}


switcher_type Switcher::getType(){
    return _type;
}

void Switcher::switchBlock(Block* from, Block* to){
    
    DataMessage* msg;    
    from->switchOut();
    to->switchIn(msg);
}

Block* Switcher::getActiveBlock(){
    return _active_block;
}

string Switcher::getName(){
    return _name;
}

void Switcher::receive_msg_data(DataMessage* t_msg){
    
    if(t_msg->getType() == msg_type::control_system){

        ControlSystemMessage* control_system_msg = (ControlSystemMessage*)t_msg;
        Block* block_to_add = control_system_msg->getBlockToAdd();
        
        if(static_cast<int>(this->getType()) == static_cast<int>(block_to_add->getType())){
           
            if(control_system_msg->getControlSystemMsgType() == control_system_msg_type::switch_in_out){

                Block* block_to_remove = control_system_msg->getBlockToRemove();                
               
                //For initial condition setting
                if(block_to_remove == nullptr){
                    _active_block = block_to_add;
                }
                //For block switch in and out
                else if(block_to_remove->getType() == block_to_add->getType()){
                    block_to_add->switchIn(block_to_remove->switchOut());
                    _active_block = block_to_add;          
                }

            } else if (control_system_msg->getControlSystemMsgType() == control_system_msg_type::add_block){
                
                Block* block_to_add = control_system_msg->getBlockToAdd();
                this->addBlock(block_to_add);
                
            }
        }
    }
}