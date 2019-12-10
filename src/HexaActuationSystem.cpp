#include "HexaActuationSystem.hpp"


HexaActuationSystem::HexaActuationSystem(std::vector<Actuator*> t_actuators) : ActuationSystem(t_actuators){
    _actuators = t_actuators;
}

HexaActuationSystem::~HexaActuationSystem() {

}


void HexaActuationSystem::command(){

    for(int i = 0; i < 6; i++){
        _commands[i] = 0;
    }
    
    //Update pulse values
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 4; j++){
            _commands[i] += _geometry[i][j] * _movements[j];
        }
    }

    //_movements (PID outputs) should be between 0 and 1. Thus, we have to adjust for the range 1000 to 2000 on _commands.
    //Normalize
    for(int i = 0; i < 6; i++){
        _commands[i] = (_commands[i] * 1000) + 1000;
        //std::cout << "Motor " << i+1 << " value: " << _commands[i] << std::endl;
    }
    

    std::cout << "M1:" << constrain(_commands[0], _escMin, _escMax)
            << " M2:" << constrain(_commands[1], _escMin, _escMax)
            << " M3:" << constrain(_commands[2], _escMin, _escMax)
            << " M4:" << constrain(_commands[3], _escMin, _escMax)
            << " M5:" << constrain(_commands[4], _escMin, _escMax)
            << " M6:" << constrain(_commands[5], _escMin, _escMax) << "\r";

    //Actuate with constrains
    for(int i = 0; i < 6; i++){
        _actuators[i]->applyCommand(this->constrain(_commands[i], _escMin, _escMax));
    }

}

int HexaActuationSystem::constrain(float value, int min_value, int max_value) {
    if (value > max_value) {
        value = max_value;
    } else if (value < min_value) {
        value = min_value;
    }
    return int(value);
}

void HexaActuationSystem::receive_msg_data(DataMessage* t_msg){

    if(t_msg->getType() == msg_type::control_system){
        ControlSystemMessage* control_system_msg = (ControlSystemMessage*)t_msg;
        if(control_system_msg->getControlSystemMsgType() == control_system_msg_type::to_system){
            
            switch (control_system_msg->getSource())
            {
            case control_system::pitch:
            {
                _movements[0] = control_system_msg->getV3DData().x;
                //_movements[0] = 0;
                // std::cout << "ACTUATION SYSTEM RECEIVED THE MESSAGE FROM PITCH: " << control_system_msg->getV3DData().x << std::endl; 
                break;
            }
            case control_system::roll:
            {
                _movements[1] = control_system_msg->getV3DData().x;
                //_movements[1] = 0;
                // std::cout << "ACTUATION SYSTEM RECEIVED THE MESSAGE FROM ROLL: " << control_system_msg->getV3DData().x << std::endl;  
                break;
            }
            case control_system::yaw:
            {
                _movements[2] = control_system_msg->getV3DData().x;
                //_movements[2] = 0;
                // std::cout << "ACTUATION SYSTEM RECEIVED THE MESSAGE FROM YAW: " << control_system_msg->getV3DData().x << std::endl;  
                break;
            }
            case control_system::z:
            {
                _movements[3] = control_system_msg->getV3DData().x;
                //_movements[3] = 0;
                // std::cout << "ACTUATION SYSTEM RECEIVED THE MESSAGE FROM Z: " << control_system_msg->getV3DData().x << std::endl; 
                break;
            }
            default:
                break;
            }

            this->command();
            
        }
          
    }
}