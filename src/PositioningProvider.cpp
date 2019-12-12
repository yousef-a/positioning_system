#include "PositioningProvider.hpp"

PositioningProvider::PositioningProvider(){

}

PositioningProvider::~PositioningProvider(){
    
}

void PositioningProvider::setHomePosition(Vector3D data){


}

Vector3D PositioningProvider::getRelativePosition(){
    return _homePos;
}
