#include "Reference.hpp"

Reference::Reference(block_id t_id, block_type t_type){
    _id = t_id;
    _type = t_type;
    
}

Reference::~Reference() {

}

block_type Reference::getType() {
    return _type;
}

void Reference::switchIn(DataMessage* data){
    //this->emit_message(data);
}


DataMessage* Reference::switchOut(){
    
    DataMessage* msg;
    
    return msg;
}    

void Reference::receive_msg_data(DataMessage* t_msg){


}

block_id Reference::getID(){
    return _id;
}

