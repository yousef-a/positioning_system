#include "Reference.hpp"

Reference::Reference(string name, block_type type){
    _name = name;
    _type = type;
    
    if(_type == block_type::reference)
        std::cout << "This is a "<< _name <<" block" << std::endl;  
    else
        std::cout << "NOT WHATEVER" << std::endl;
}

Reference::~Reference() {

}

block_type Reference::getType() {
    return _type;
}

void Reference::switchIn(DataMessage* data){
    this->emit_message(data);
}


DataMessage* Reference::switchOut(){
    
    DataMessage* msg;
    
    return msg;
}    

void Reference::receive_msg_data(DataMessage* t_msg){


}

string Reference::getName(){
    return _name;
}
