#include "PositioningProvider.hpp"

PositioningProvider::PositioningProvider(std::string t_name, block_type t_type) : Provider(t_name, t_type){

}

PositioningProvider::~PositioningProvider(){
    
}

void PositioningProvider::setHomePosition(Vector3D data){


}

Vector3D PositioningProvider::getRelativePosition(){
    return _homePos;
}
