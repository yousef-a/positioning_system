#include "ROSUnit.hpp"

ROSUnit::ROSUnit() {

}

ROSUnit::ROSUnit(ros::NodeHandle& main_handler){

    _main_handler = main_handler;
}

ROSUnit::~ROSUnit() {

}

ros::NodeHandle ROSUnit::getNodeHandle(){

    return _main_handler;
}