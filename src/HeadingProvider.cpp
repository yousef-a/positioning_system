#include "HeadingProvider.hpp"

HeadingProvider::HeadingProvider(std::string t_name, block_type t_type) : Provider(t_name, t_type) 
{
    
}

HeadingProvider::~HeadingProvider() {

}

DataMessage* HeadingProvider::receive_msg_internal(DataMessage*){
    //TODO
}
DataMessage* HeadingProvider::receive_msg_internal(){
    m_heading_msg = this->getHeading();
    return (DataMessage*) &m_heading_msg;
    //TODO
}
        