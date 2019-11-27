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
        
        Provider* provider_block = (Provider*)_active_block;
        if(provider_block->getProviderType() == provider_type::position){
            PositioningProvider* pos_provider = (PositioningProvider*)provider_block;

            DataMessage* provider_msg = pos_provider->receive_msg_internal();
            Vector3DMessage* vector3D_msg = (Vector3DMessage*)provider_msg;

            switch (_parent) 
            {
                case control_system::x:
                {
                    Vector3D X_data;
                    X_data.x = vector3D_msg->getData().x;
                    X_data.y = 0.0; //TODO velocity in X
                    X_data.z = 0.0; //TODO acceleration in X

                    SwitcherMessage* switcher_msg = new SwitcherMessage(this->getType(), switcher_type::reference, 
                                                                        internal_switcher_type::position_provider, X_data);
                    this->emit_message((DataMessage*)switcher_msg);
                    break;
                }
                case control_system::y:
                {  
                    Vector3D Y_data;
                    Y_data.x = vector3D_msg->getData().y;
                    Y_data.y = 0.0; //TODO velocity in X
                    Y_data.z = 0.0; //TODO acceleration in X

                    SwitcherMessage* switcher_msg = new SwitcherMessage(this->getType(), switcher_type::reference, 
                                                                        internal_switcher_type::position_provider, Y_data);
                    this->emit_message((DataMessage*)switcher_msg);
                    break;          
                }
                case control_system::z:
                {   /* code */
                    break;           
                }
                default:
                    break;
            } 


        }else if(provider_block->getProviderType() == provider_type::attitude){
            AttitudeProvider* att_provider = (AttitudeProvider*)provider_block;
            DataMessage* provider_msg = att_provider->receive_msg_internal();
            Vector3DMessage* vector3D_msg = (Vector3DMessage*)provider_msg;

            switch (_parent) 
            {
                case control_system::pitch:
                {
                    Vector3D Pitch_data;
                    Pitch_data.x = vector3D_msg->getData().y;
                    Pitch_data.y = 0.0; //TODO pitch_dot
                    Pitch_data.z = 0.0; //TODO pitch_dot_dot

                    SwitcherMessage* switcher_msg = new SwitcherMessage(this->getType(), switcher_type::reference, 
                                                                        internal_switcher_type::attitude_provider, Pitch_data);
                    this->emit_message((DataMessage*)switcher_msg);

                    break;
                }
                case control_system::roll:
                {   
                    Vector3D Roll_data;
                    Roll_data.x = vector3D_msg->getData().x;
                    Roll_data.y = 0.0; //TODO roll_dot
                    Roll_data.z = 0.0; //TODO roll_dot_dot

                    SwitcherMessage* switcher_msg = new SwitcherMessage(this->getType(), switcher_type::reference, 
                                                                        internal_switcher_type::attitude_provider, Roll_data);
                    this->emit_message((DataMessage*)switcher_msg);

                    break;          
                }
                case control_system::yaw:
                {   /* code */
                    break;           
                }
                default:
                    break;
            } 
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
                    && static_cast<int>(this->getType()) == static_cast<int>(block_to_add->getType())){ //TODO Refactor
                
            Block* block_to_add = control_system_msg->getBlockToAdd();
            this->addBlock(block_to_add);
                
        } else if (control_system_msg->getControlSystemMsgType() == control_system_msg_type::change_PID_settings){ //TODO Refactor to change_Controller_sett
            
            if(_active_block->getType() == block_type::controller){
                Controller* controller_block = (Controller*)_active_block; //TODO refactor
                if(controller_block->getControllerType() == controller_type::pid){
                    PIDController* pid_block = (PIDController*)controller_block;
                    pid_block->initialize(control_system_msg->getPIDSettings());
                    std::cout << "Active Block: " << controller_block->getName() << std::endl;
                    std::cout << "CHANGING PID PARAMETERS" << std::endl;
                } //TODO else if MRFT
            } 
        } else if(control_system_msg->getControlSystemMsgType() == control_system_msg_type::provider_data){
            
            Vector3D data_provided = control_system_msg->getV3DData();
            
            if(_active_block->getType() == block_type::reference){
                Reference* reference_block = (Reference*)_active_block;

                if(reference_block->getReferenceType() == reference_type::process_variable_ref){
                    ProcessVariableReference* pv_ref_block = (ProcessVariableReference*)reference_block;

                    Vector3DMessage* process_variable = new Vector3DMessage(data_provided);

                    DataMessage* output_from_reference = pv_ref_block->receive_msg_internal((DataMessage*)process_variable);

                    process_variable = (Vector3DMessage*)output_from_reference;

                    SwitcherMessage* reference_msg = new SwitcherMessage(process_variable->getData());
                    
                    this->emit_message((DataMessage*)reference_msg);

                }//TODO add other references as else if

            }
        }
        
    }else if(t_msg->getType() == msg_type::switcher){

        SwitcherMessage* switcher_msg = (SwitcherMessage*)t_msg;
                      
        DataMessage* output = _active_block->receive_msg_internal((DataMessage*)switcher_msg);

        Vector3DMessage* data = (Vector3DMessage*)output;
        SwitcherMessage* out_switcher_msg = new SwitcherMessage(data->getData());

        this->emit_message((DataMessage*)out_switcher_msg);
        
    }else if(t_msg->getType() == msg_type::vector3D_msg || t_msg->getType() == msg_type::float_msg){ //TODO User message

        float reference = 0.0;

        if(t_msg->getType() == msg_type::vector3D_msg){
            Vector3DMessage* v3d_data = (Vector3DMessage*)t_msg;
            std::cout << " vector3d message received: " << v3d_data->getData().x  << std::endl;
            reference = v3d_data->getData().x;
        }else if(t_msg->getType() == msg_type::float_msg){
            FloatMessage* float_data = (FloatMessage*)t_msg;
            std::cout << " float message received: " << float_data->getData()  << std::endl;
            reference = float_data->getData();
        }
        

        if(_active_block->getType() == block_type::reference){
            Reference* reference_block = (Reference*)_active_block;
            
            if(reference_block->getReferenceType() == reference_type::process_variable_ref){
                ProcessVariableReference* pv_ref_block = (ProcessVariableReference*)reference_block;
                pv_ref_block->setReferenceValue(reference);
                std::cout << "........................Setting Process variable" << std::endl;
            }
           
        }

    }

}