#include "X_UserReference.hpp"

X_UserReference::X_UserReference() {

}

X_UserReference::~X_UserReference() {

}

void X_UserReference::receive_msg_data(DataMessage* t_msg){
//TODO remove checks for msg_type_reference because they are connected directly
    if(t_msg->getType() == msg_type::USERREFERENCE){   
        UpdatePoseMessage* user_msg = (UpdatePoseMessage*)t_msg;
        if(user_msg->getRefType() == msg_type_reference::X){
            m_output_msg.setControlSystemMessage(control_system::null_type, control_system_msg_type::to_system, user_msg->getX());
            //TODO make a logger
            std::cout << "Setting X Reference: " << user_msg->getX() << std::endl;
            this->emit_message((DataMessage*) &m_output_msg);
        }    
    }
}
