#pragma once
#include "Reference.hpp"

class ProcessVariableReference : public Reference{

private:
    reference_type _reference_type;

public:
    reference_type getReferenceType();
    DataMessage* receive_msg_internal(DataMessage*);
    DataMessage* receive_msg_internal();

    ProcessVariableReference(std::string, block_type);
    ~ProcessVariableReference();
};