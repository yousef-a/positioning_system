#include "DataMessage.hpp"

DataMessage::DataMessage() {
    data = {};
    msg_type = switcher_msg_type::controller;
}

DataMessage::~DataMessage() {

}