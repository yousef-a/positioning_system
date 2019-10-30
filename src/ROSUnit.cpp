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
void ROSUnit::serializeData(double data[], int numVariables, uint8_t wtv[]){

    uint8_t* data_ptr=(uint8_t*)&data[0];
    //uint8_t serializedData[sizeof(data)];
    
    for(int i = 0; i < numVariables * sizeof(double); i++){
        wtv[i]=*((uint8_t*)data_ptr++);
    }
    //std::cout << sizeof(data) << std::endl;
    //wtv = serializedData;
}