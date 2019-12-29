#include "Y_UserReference.hpp"

Y_UserReference::Y_UserReference() {

}

Y_UserReference::~Y_UserReference() {

}

void Y_UserReference::receive_msg_data(DataMessage* t_msg){

    if(t_msg->getType() == msg_type::USERREFERENCE){   
        UpdatePoseMessage* user_msg = (UpdatePoseMessage*)t_msg;
        if(user_msg->getRefType() == msg_type_reference::Y){
            m_output_msg.setControlSystemMessage(control_system::null_type, control_system_msg_type::to_system, user_msg->getY());
            //TODO make a logger
            std::cout << "Setting Y Reference: " << user_msg->getY() << std::endl;
            this->emit_message((DataMessage*) &m_output_msg);
        }    
    }
}
