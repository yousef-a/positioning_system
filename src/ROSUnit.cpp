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

//template<typename T>
void ROSUnit::serializeData(double data[], int numVariables, uint8_t serializedData[]){

    //std::cout << sizeof(data) << std::endl;
    uint8_t* data_ptr=(uint8_t*)&data[0];
    
    for(int i = 0; i < numVariables * sizeof(double); i++){
        serializedData[i]=*((uint8_t*)data_ptr++);
    }
}