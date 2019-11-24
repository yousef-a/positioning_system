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

void Switcher::loopInternal(){
    std::cout << "2" << std::endl;
    if(this->getType() == switcher_type::provider){
        std::cout << "3" << std::endl;
        FloatMessage* a = new FloatMessage(3.0);
        DataMessage* provider_msg = _active_block->receive_msg_internal((DataMessage*)a);
        std::cout << "3.5" << std::endl;
        if(provider_msg->getType() == msg_type::vector3D_msg){
            std::cout << "4" << std::endl;
            Vector3DMessage* vector3D_msg = (Vector3DMessage*)provider_msg;
            SwitcherMessage* switcher_msg = new SwitcherMessage(internal_switcher_type::position_provider, vector3D_msg->getData());
            std::cout << "5" << std::endl;
            this->emit_message((DataMessage*)switcher_msg);
            std::cout << "6" << std::endl;
        }
         
    }

}
//TODO add reference block so the error can be calculated
void Switcher::receive_msg_data(DataMessage* t_msg){
    
    if(t_msg->getType() == msg_type::control_system){

        ControlSystemMessage* control_system_msg = (ControlSystemMessage*)t_msg;
        Block* block_to_add = control_system_msg->getBlockToAdd();
        
        //Considering the message is sent to all the Switchers, this checks if the block being altered belongs to that switcher
        
        if(control_system_msg->getControlSystemMsgType() == control_system_msg_type::switch_in_out
            && std::find(_blocks.begin(), _blocks.end(), block_to_add) != _blocks.end()){

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

        } else if (control_system_msg->getControlSystemMsgType() == control_system_msg_type::add_block
                    && static_cast<int>(this->getType()) == static_cast<int>(block_to_add->getType())){
                
            Block* block_to_add = control_system_msg->getBlockToAdd();
            this->addBlock(block_to_add);
                
        } else if (control_system_msg->getControlSystemMsgType() == control_system_msg_type::change_PID_settings
                     && this->getType() == switcher_type::controller){
            
            PIDController* pid_block = (PIDController*)_active_block;
            if(pid_block->getControllerType() == controller_type::pid){
                pid_block->initialize(control_system_msg->getPIDSettings());
                std::cout << "Active Block: " << pid_block->getName() << std::endl;
                std::cout << "CHANGING PID PARAMETERS" << std::endl;
            }
              
        }
        
    }else if(t_msg->getType() == msg_type::switcher){
        std::cout << "5.1" << std::endl;
        SwitcherMessage* switcher_msg = (SwitcherMessage*)t_msg;
        std::cout << "5.2" << std::endl;
        if(switcher_msg->getInternalType() == internal_switcher_type::position_provider){
            std::cout << "5.3" << std::endl;
            PID_data* pid_data = new PID_data;
            pid_data->err = 0.0; //TODO calculate the error
            pid_data->pv_first = 0.0;
            pid_data->pv_second = 0.0;
            std::cout << "5.4" << std::endl;
            std::cout << "INSIDE SWITCHER MSG RECEIVE" << std::endl;
            ControllerMessage* pos_control_msg = new ControllerMessage(controller_msg_type::data, pid_data);
            DataMessage* output = _active_block->receive_msg_internal((DataMessage*)pos_control_msg);
            std::cout << "output of switcher controller" << std::endl;
            //TODO emit the output from PID to someplace.
        }
    }

}