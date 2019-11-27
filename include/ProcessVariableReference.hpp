#pragma once
#include "Reference.hpp"
#include "FloatMessage.hpp"
#include "Vector3D.hpp"
#include "Vector3DMessage.hpp"

class ProcessVariableReference : public Reference{

private:
    reference_type _reference_type;
    float _reference_value;

public:
    reference_type getReferenceType();
    DataMessage* receive_msg_internal(DataMessage*);
    DataMessage* receive_msg_internal();
    void setReferenceValue(float);

    ProcessVariableReference(std::string, block_type);
    ~ProcessVariableReference();
};