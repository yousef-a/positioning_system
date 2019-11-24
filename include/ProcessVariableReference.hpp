#pragma once
#include "Reference.hpp"

class ProcessVariableReference : public Reference{

private:
    reference_type _reference_type;

public:
    reference_type getReferenceType();

    ProcessVariableReference(std::string, block_type);
    ~ProcessVariableReference();
};