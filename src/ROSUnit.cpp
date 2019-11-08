#include "ROSUnit.hpp"

ROSUnit::ROSUnit() {

}

ROSUnit::ROSUnit(ros::NodeHandle& _main_handler){

    main_handler = _main_handler;
}

ROSUnit::~ROSUnit() {

}

ros::NodeHandle ROSUnit::getNodeHandle(){

    return main_handler;
}