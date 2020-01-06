#include "DarknetMessage.hpp"

DarknetMessage::DarknetMessage() {

}

DarknetMessage::~DarknetMessage() {

}


msg_type DarknetMessage::getType()
{
    return msg_type::DARKNET_ROS;
}

const int DarknetMessage::getSize()
{
    return sizeof(DarknetMessage);
}

void DarknetMessage::setDarknetMessage(float t_probability, int t_xmin, int t_xmax, int t_ymin, int t_ymax)
{
    probability = t_probability;
    xmin = t_xmin;
    xmax = t_ymax;
    ymin = t_ymin;
    ymax = t_ymax;
}