#include "ProcessVariableReference.hpp"

ProcessVariableReference::ProcessVariableReference(std::string t_name, block_type t_type) : Reference(t_name, t_type) {
    
    _reference_type = reference_type::process_variable_ref;
    _process_variable = 0.0;
}

ProcessVariableReference::~ProcessVariableReference() {

}

reference_type ProcessVariableReference::getReferenceType(){
    return _reference_type;
}

DataMessage* ProcessVariableReference::receive_msg_internal(DataMessage* t_msg){
    std::cout << " My current Process Variable Value: " << _process_variable << std::endl;
    //TODO Calculate the error HERE

    Vector3DMessage* pos_msg = (Vector3DMessage*)t_msg;
    std::cout << "Data received: " << pos_msg->getData().x << std::endl;
    Vector3D error;

    error.x = _process_variable - pos_msg->getData().x;
    error.y = 0.0 - pos_msg->getData().y ;
    error.z = 0.0 - pos_msg->getData().z;

    Vector3DMessage* error_msg = new Vector3DMessage(error);

    return (DataMessage*)error_msg;
}

DataMessage* ProcessVariableReference::receive_msg_internal(){
    
}

void ProcessVariableReference::setProcessVariable(float t_process_variable){
    _process_variable = t_process_variable;
}