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

    float error = 0.0;

    if(t_msg->getType() == msg_type::float_msg){
        FloatMessage* pos_msg = (FloatMessage*)t_msg;
        std::cout << "Data received: " << pos_msg->getData() << std::endl;

        error = pos_msg->getData() - _process_variable;

    }

    FloatMessage* error_msg = new FloatMessage(error);

    return (DataMessage*)error_msg;
}

DataMessage* ProcessVariableReference::receive_msg_internal(){
    
}

void ProcessVariableReference::setProcessVariable(float t_process_variable){
    _process_variable = t_process_variable;
}