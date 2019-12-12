#include "User.hpp"

User::User() {

}

User::~User() {

}

void User::receive_msg_data(DataMessage* t_msg){

    //if(t_msg->getType() == msg_type::FLIGHTSCENARIO){
    if(t_msg->getType() == msg_type::user){   
        //FlightScenarioMessage* fs_msg = (FlightScenarioMessage*)t_msg;
        UserMessage* user_msg = (UserMessage*)t_msg;
        //if(fs_msg->getFlightScenarioMsgType() == msg_type_flight_scenario::USER){
        _user_msg.setUserMessage(user_msg->getX(), user_msg->getY(), user_msg->getZ(), user_msg->getYaw());
        this->emit_message((DataMessage*) &_user_msg);
    }
}
