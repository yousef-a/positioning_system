#include "ROSUnit_FlightScenario.hpp"

//TODO rename the topics and class
ROSUnit_FlightScenario* ROSUnit_FlightScenario::_instance_ptr = NULL;
FlightScenarioMessage ROSUnit_FlightScenario::user_msg;

ROSUnit_FlightScenario::ROSUnit_FlightScenario(ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    //_sub_attitude = t_main_handler.subscribe("/flightscenario/setpoint_position", 10, callbackOptitrack);
    _instance_ptr = this;
}   

ROSUnit_FlightScenario::~ROSUnit_FlightScenario() {

}

void ROSUnit_FlightScenario::receive_msg_data(DataMessage* t_msg){


}