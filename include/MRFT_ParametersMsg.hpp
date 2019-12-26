#pragma once
#include "MRFT_values.hpp"
#include "DataMessage.hpp"

class MRFT_ParametersMsg : public DataMessage{

private:
    msg_type _type;
    MRFT_parameters _params;

public:

    msg_type getType();
    const int getSize();
	void setMRFTParam(MRFT_parameters);
    MRFT_parameters getMRFTParam(){return _params;}

    MRFT_ParametersMsg();
    ~MRFT_ParametersMsg();
};

