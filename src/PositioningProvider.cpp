#include "PositioningProvider.hpp"

PositioningProvider::PositioningProvider(){

    Vector3D _homePos;
}

void PositioningProvider::setHomePosition(Vector3D data){


}

Vector3D PositioningProvider::getRelativePosition(){

    return _homePos;
}