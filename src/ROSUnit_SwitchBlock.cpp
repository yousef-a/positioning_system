#include "ROSUnit_SwitchBlock.hpp"
ROSUnit_SwitchBlock* ROSUnit_SwitchBlock::_instance_ptr = NULL;
SwitchBlockMsg ROSUnit_SwitchBlock::_switch_msg;

ROSUnit_SwitchBlock::ROSUnit_SwitchBlock(ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    _srv_switch = t_main_handler.advertiseService("switch_block", callbackSwitchBlocks);
    _instance_ptr = this;
}   

ROSUnit_SwitchBlock::~ROSUnit_SwitchBlock() {

}

void ROSUnit_SwitchBlock::receive_msg_data(DataMessage* t_msg){


}

bool ROSUnit_SwitchBlock::callbackSwitchBlocks(positioning_system::SwitchBlock::Request &req, 
                                               positioning_system::SwitchBlock::Response &res){

    int block_in, block_out;
    block_in = req.block_in;
    block_out = req.block_out;

    _switch_msg.setSwitchBlockMsg(block_in, block_out);
    _instance_ptr->emit_message((DataMessage*) &_switch_msg);
    
    return true;
}