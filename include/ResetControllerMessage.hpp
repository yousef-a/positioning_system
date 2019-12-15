#pragma once
#include "DataMessage.hpp"

class ResetControllerMessage : public DataMessage{

private:
    msg_type _type;
    int _data;

public:

    msg_type getType();
    const int getSize();
    int getData();
    void setResetControllerMessage(int);

    ResetControllerMessage();
    ~ResetControllerMessage();
};