#pragma once
#include <list>
#include "common_types.hpp"

class DataMessage {

public:
    
    virtual msg_type getType() = 0;

    DataMessage();
    ~DataMessage();
};