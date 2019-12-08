#include "HeadingProvider.hpp"

HeadingProvider::HeadingProvider(std::string t_name, block_type t_type) : Provider(t_name, t_type) {
    _provider_type = provider_type::heading;
}

HeadingProvider::~HeadingProvider() {

}

DataMessage* HeadingProvider::receive_msg_internal(DataMessage*){
    //TODO
}
DataMessage* HeadingProvider::receive_msg_internal(){
    //TODO
}