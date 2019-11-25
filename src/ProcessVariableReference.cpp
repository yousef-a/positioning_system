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
    std::cout << " I AM HEREEEEEEE RECEIVE MSG FROM REFERENCE" << std::endl;
    std::cout << " My current Process Variable Value: " << _process_variable << std::endl;
    if(t_msg->getType() == msg_type::vector3D_msg){
        Vector3DMessage* pos_msg = (Vector3DMessage*)t_msg;
        
    }
}

DataMessage* ProcessVariableReference::receive_msg_internal(){
    
}

void ProcessVariableReference::setProcessVariable(float t_process_variable){
    _process_variable = t_process_variable;
}