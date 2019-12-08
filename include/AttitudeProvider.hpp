#pragma once
//#include "Vector3D.hpp"
#include "Provider.hpp"
#include "Quaternion.hpp"
#include "AttitudeMsg.hpp"

class AttitudeProvider : public Provider{

    public:

        virtual AttitudeMsg getAttitude() = 0;
        
        DataMessage* receive_msg_internal(DataMessage*);
        DataMessage* receive_msg_internal();
        
        AttitudeProvider(std::string, block_type);
        ~AttitudeProvider();
    
    private:

        AttitudeMsg m_att_msg;
};