#pragma once
#include "GPS.hpp"
#include <iostream>

class UM8E : public GPS {

    public:
        Vector3D getPosition();
        UM8E();
        ~UM8E();
};