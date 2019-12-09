#pragma once

#include <cstdint>
#include "DataMessage.hpp"

class TestMsg : public DataMessage
{

public:

    msg_type getType();
    const int getSize();

    int data;
};