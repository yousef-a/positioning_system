#include "PositioningSystem.hpp"

PositioningSystem::PositioningSystem(){

    Vector3D _homePos;
}

void PositioningSystem::setHomePosition(Vector3D data){


}

Vector3D PositioningSystem::getRelativePosition(){

    return _homePos;
}