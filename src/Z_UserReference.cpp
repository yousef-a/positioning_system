#include "Z_UserReference.hpp"

Z_UserReference::Z_UserReference() {

}

Z_UserReference::~Z_UserReference() {

}

void Z_UserReference::receive_msg_data(DataMessage* t_msg){

    if(t_msg->getType() == msg_type::user){   

        UpdatePoseMessage* user_msg = (UpdatePoseMessage*)t_msg;

        m_output_msg.setControlSystemMessage(control_system::null_type, control_system_msg_type::to_system, user_msg->getZ());
        this->emit_message((DataMessage*) &m_output_msg);
    }
}
