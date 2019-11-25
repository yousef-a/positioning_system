#include "Switcher.hpp"

Switcher::Switcher(string t_name, switcher_type t_type, control_system t_parent) {
    _type = t_type;
    _name = t_name;
    _parent = t_parent;
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

    if(this->getType() == switcher_type::provider){
        std::cout << "PROVIDER SWITCHER" << std::endl;
        std::cout << "Request for active block data" << std::endl;
        DataMessage* provider_msg = _active_block->receive_msg_internal(); 
        
        if(provider_msg->getType() == msg_type::vector3D_msg){

            std::cout << "Message of type vector3D received" << std::endl;
            Vector3DMessage* vector3D_msg = (Vector3DMessage*)provider_msg;
            SwitcherMessage* switcher_msg = new SwitcherMessage(this->getType(), switcher_type::reference, internal_switcher_type::position_provider, vector3D_msg->getData());
            std::cout << "SENDING MESSAGE TO REFERENCE SWITCHER" << std::endl;
            this->emit_message((DataMessage*)switcher_msg);

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
            
            Controller* controller_block = (Controller*)_active_block; //TODO refactor
            if(controller_block->getControllerType() == controller_type::pid){
                PIDController* pid_block = (PIDController*)controller_block;
                pid_block->initialize(control_system_msg->getPIDSettings());
                std::cout << "Active Block: " << controller_block->getName() << std::endl;
                std::cout << "CHANGING PID PARAMETERS" << std::endl;
            }
              
        }
        
    }else if(t_msg->getType() == msg_type::switcher){

        SwitcherMessage* switcher_msg = (SwitcherMessage*)t_msg;

        if(switcher_msg->getInternalType() == internal_switcher_type::position_provider
            && switcher_msg->getSource() == switcher_type::provider
            && switcher_msg->getDestination() == this->getType()){
        
                Vector3DMessage* pos_provided = new Vector3DMessage(switcher_msg->getVector3DData());
                DataMessage* output_from_receiver = _active_block->receive_msg_internal((DataMessage*)pos_provided);

                FloatMessage* error = (FloatMessage*)output_from_receiver;

                SwitcherMessage* reference_msg = new SwitcherMessage(this->getType(), switcher_type::controller, internal_switcher_type::reference, error->getData());
                
                std::cout << "REFERENCE SWITCHER" << std::endl;
                std::cout << "Sending to Controller Switcher" << std::endl;
                this->emit_message((DataMessage*)reference_msg);
                
        }else if(switcher_msg->getInternalType() == internal_switcher_type::reference
            && switcher_msg->getSource() == switcher_type::reference
            && switcher_msg->getDestination() == this->getType()){
            
            Controller* controller_block = (Controller*)_active_block;

            if(controller_block->getControllerType() == controller_type::pid){
                std::cout << "CONTROLLER SWITCHER" << std::endl;
                std::cout << "Calculating PID input data" << std::endl;
                PID_data* pid_data = new PID_data;
                pid_data->err = 0.0; //TODO calculate the error
                pid_data->pv_first = 0.0;
                pid_data->pv_second = 0.0;
            
                std::cout << "Sending calculated data to active block" << std::endl;
                ControllerMessage* pos_control_msg = new ControllerMessage(controller_msg_type::data, pid_data);
                DataMessage* output = _active_block->receive_msg_internal((DataMessage*)pos_control_msg);
                FloatMessage* float_command = (FloatMessage*)output;
       
                std::cout << "Output of switcher controller" << std::endl;       
            }
        }
    }else if(t_msg->getType() == msg_type::float_msg){

        FloatMessage* user_data = (FloatMessage*)t_msg;

        if(this->getType() == switcher_type::reference){
            Reference* reference_block = (Reference*)_active_block;
            if(reference_block->getReferenceType() == reference_type::process_variable_ref){
                ProcessVariableReference* pv_ref_block = (ProcessVariableReference*)reference_block;
                pv_ref_block->setProcessVariable(user_data->getData());

                //HERE
            }
           
        }

    }

}