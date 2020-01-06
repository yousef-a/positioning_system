#include "ROSUnit_dark.hpp"



ROSUnit_dark* ROSUnit_dark::_instance_ptr = NULL;
DarknetMessage ROSUnit_dark::darknet_msg;

ROSUnit_dark::ROSUnit_dark(ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler){
    _sub_darknet = t_main_handler.subscribe("/darknet_ros/bounding_boxes", 10, callbackDarknet);
    _instance_ptr = this;
}


ROSUnit_dark::~ROSUnit_dark() {

}

void ROSUnit_dark::callbackDarknet(const darknet_ros_msgs::BoundingBoxes::ConstPtr& msg){

    for (int i = 0; i < sizeof(msg->bounding_boxes); i++)
    {
        darknet_msg.xmax = msg->bounding_boxes[i].xmax;
        darknet_msg.xmin = msg->bounding_boxes[i].xmin;
        darknet_msg.ymax = msg->bounding_boxes[i].ymax;
        darknet_msg.ymin = msg->bounding_boxes[i].ymin;
        darknet_msg.probability = msg->bounding_boxes[i].probability;
        _instance_ptr->emit_message((DataMessage*) &darknet_msg); 
    }
    
}
void ROSUnit_dark::receive_msg_data(DataMessage* t_msg){

}