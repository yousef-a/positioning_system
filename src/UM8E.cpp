#include "UM8E.hpp"

UM8E::UM8E() {

}

UM8E::~UM8E() {

}

Vector3D UM8E::getPosition(){

    std::cout << "Hello, I am UM8E\n";
    Vector3D data;
    data.x = 0;
    data.y = 1;
    data.z = 0;
    
    return data;

}