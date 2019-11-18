#pragma once
#include <list>
#include "common_types.hpp"

class DataMessage {

public:
    std::list<uint8_t> data;
    switcher_msg_type msg_type;

    DataMessage();
    ~DataMessage();
};