#pragma once
#include "Vector3D.hpp"

class PositioningSystem {

    private:
        Vector3D _homePos;
    public:
        virtual Vector3D getPosition() = 0;
        void setHomePosition(Vector3D);
        Vector3D getRelativePosition();
        
        PositioningSystem();
};