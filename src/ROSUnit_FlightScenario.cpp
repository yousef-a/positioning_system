#include "ROSUnit_FlightScenario.hpp"

ROSUnit_FlightScenario* ROSUnit_FlightScenario::_instance_ptr = NULL;
FlightScenarioMessage FlightScenarioMessage::flight_scenario_msg;

ROSUnit_FlightScenario::ROSUnit_FlightScenario(ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    _instance_ptr = this;
}   

ROSUnit_FlightScenario::~ROSUnit_FlightScenario() {

}

void ROSUnit_FlightScenario::receive_msg_data(DataMessage* t_msg){


}