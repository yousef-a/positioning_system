#pragma once
#include <math.h>
#include "ControllerMessage.hpp"
#include "FloatMessage.hpp"
#include "MRFT_values.hpp"
#include "Controller.hpp"

struct mrft_bag{
        float amplitude;
        uint32_t duration;
    };

class MRFTController : public Controller{

private:
    controller_type _controller_type;
    //Chehadeh's code
	const uint8_t iterations_lock_count = 5;
	bool prev_res, first_run = true;
	float prev_err = 0;
	/*
	last_switch: to detect the previous switch state; 
	period_switch: detect two switchings, i.e. one period
	*/
	uint32_t last_peak_micros;
	bool mem1=false,mem2 = 0;
	uint8_t iteration_number;
	float realy_output;
	float minpeak_out = 0;
	float maxpeak_out = 0;
	float maxpeak(bool, float);
	float minpeak(bool, float);
	bool algorithm(float, bool&, mrft_bag&);
    //---------------
public:
    //Chehadeh's code
    MRFT_para parameters;
	void initialize(MRFT_para*);
	float mrft_with_antilock(float,bool&, mrft_bag&);
    //---------------

	DataMessage* receive_msg_internal(DataMessage*);
    controller_type getControllerType();

    MRFTController(block_id name, block_type type);
    ~MRFTController();
};
