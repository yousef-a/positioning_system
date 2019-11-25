#pragma once
#include "Reference.hpp"
#include "Vector3DMessage.hpp"

class ProcessVariableReference : public Reference{

private:
    reference_type _reference_type;
    float _process_variable;

public:
    reference_type getReferenceType();
    DataMessage* receive_msg_internal(DataMessage*);
    DataMessage* receive_msg_internal();
    void setProcessVariable(float);

    ProcessVariableReference(std::string, block_type);
    ~ProcessVariableReference();
};