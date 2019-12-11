#include "User.hpp"

User::User() {

}

User::~User() {

}

void User::receive_msg_data(DataMessage* t_msg){

    if(t_msg->getType() == msg_type::FLIGHTSCENARIO){
        
        FlightScenarioMessage* fs_msg = (FlightScenarioMessage*)t_msg;

        if(fs_msg->getType() == msg_type_flight_scenario::user){
            
            _user_msg.setUserMessage(fs_msg->getX(), fs_msg->getY(), fs_msg->getZ(), fs_msg->getYaw());

            this->emit_message((DataMessage*) &_user_msg);
        }
    }
}
