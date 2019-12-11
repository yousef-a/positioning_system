#include "FlightScenarioMessage.hpp"

FlightScenarioMessage::FlightScenarioMessage(float t_x, float t_y, float t_z, float t_yaw) {
    _type = msg_type::FLIGHTSCENARIO;
    _fs_msg_type = msg_type_flight_scenario::USER;
    _x = t_x;
    _y = t_y;
    _z = t_z;
    _yaw = t_yaw;
}
//TODO add constructor for SET PID

FlightScenarioMessage::FlightScenarioMessage() {

}

FlightScenarioMessage::~FlightScenarioMessage() {

}

float FlightScenarioMessage::getX(){
    return _x;
}
float FlightScenarioMessage::getY(){
    return _y;
}
float FlightScenarioMessage::getZ(){
    return _z;
}
float FlightScenarioMessage::getYaw(){
    return _yaw;
}
msg_type FlightScenarioMessage::getType(){
    return _type;
}
void FlightScenarioMessage::setFSUserMessage(float t_x, float t_y, float t_z, float t_yaw){
    _x = t_x;
    _y = t_y;
    _z = t_z;
    _yaw = t_yaw;
}
const int FlightScenarioMessage::getSize()
{
    return sizeof(this);
}

msg_type_flight_scenario FlightScenarioMessage::getFlightScenarioMsgType(){
    return _fs_msg_type;
}