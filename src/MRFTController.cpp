#include "MRFTController.hpp"

MRFTController::MRFTController(block_id t_id, block_type t_type) : Controller(t_id, t_type) {  
    _controller_type = controller_type::mrft;
}

MRFTController::~MRFTController() {

}

DataMessage* MRFTController::receive_msg_internal(DataMessage* t_msg){
        
	// ControllerMessage* controller_msg = (ControllerMessage*)t_msg;

    // PID_data* data = controller_msg->getData();
    // // std::cout << "pid block receives msg: " << std::endl;
	// // std::cout << "error: " << data->err << std::endl;
	// // std::cout << "pv_first: " << data->pv_first << std::endl;
	// // std::cout << "pv_second: " << data->pv_second << std::endl;
    // float command = pid_direct(data->err, data->pv_first, data->pv_second);
    // FloatMessage* output_msg = new FloatMessage(command);

    // // std::cout << "SENDING COMMAND" << std::endl;
	// return (DataMessage*)output_msg;
}

controller_type MRFTController::getControllerType(){
	return _controller_type;
}

// Start of Chehadeh's Code
float MRFTController::maxpeak(bool cntrl, float in){
	if (cntrl == 1){
		if (in>0)
		{
			maxpeak_out = in;
		}
		else
		{
			maxpeak_out = 0;
		}
	}
	else
	{
		if (in>maxpeak_out){
			maxpeak_out = in;
		}
	}
	return maxpeak_out;

}

float MRFTController::minpeak(bool cntrl, float in){
	if (cntrl == 1){
		if (in <= 0)
		{
			minpeak_out = in;
		}
		else
		{
			minpeak_out = 0;
		}
	}
	else
	{
		if (in<minpeak_out){
			minpeak_out = in;
		}
	}
	return minpeak_out;
}

bool MRFTController::algorithm(float err, bool& mrft_bag_ready_para, mrft_bag& mrft_period){
	float buff1, outmin, outmax, outswitch;
	bool op1, op2;
	// if (mrft_bag_ready_para){
	// 	mrft_bag_ready_para = false;
	// }
	// buff1 = ((-err) - (prev_err)) / _dt;//TODO: use Gyro
	// prev_err = -err;
	// if (buff1 >= 0)
	// {
	// 	op1 = true;
	// }
	// else
	// {
	// 	op1 = false;
	// }
	// op2 = ((!op1) && (mem1 ^ op1));
	// outmax = maxpeak(op2, err);
	// op2 = ((op1) && (mem1 ^ op1));
	// outmin = minpeak(op2, err);
	// if (op1 == true){
	// 	outswitch = outmax;
	// }
	// else{
	// 	outswitch = outmin;
	// }
	// buff1 = outswitch*parameters.beta + err;
	// if (buff1 >= 0){
	// 	op2 = true;
	// }
	// else{
	// 	op2 = false;
	// }
	// if (mem2 != op2){
	// 	if (op2)
	// 	{
	// 		mrft_period.amplitude = mrft_period.amplitude - outmin;
	// 		mrft_period.duration = micros() - last_peak_micros;
	// 		mrft_bag_ready_para = true;
	// 		last_peak_micros = micros();
	// 	}
	// 	else
	// 	{
	// 		mrft_period.amplitude = outmax;
	// 	}
	// }
	// mem1 = op1;
	// mem2 = op2;
	return op2;
}

void MRFTController::initialize(MRFT_para* para){
	parameters.beta = para->beta;
	parameters.relay_amp = para->relay_amp;
	parameters.bias = para->bias;
	//1;//Roll mrft, beta: {parameters.beta}, amp: {parameters.relay_amp}, bias: {parameters.bias}
}

float MRFTController::mrft_with_antilock(float err, bool& mrft_bag_ready_para, mrft_bag& mrft_period){
	bool mrft_res;
	mrft_res = algorithm(err, mrft_bag_ready_para, mrft_period);
	if (first_run){
		if (mrft_res)
		{ 
			realy_output = parameters.relay_amp; 
		}
		else
		{ 
			realy_output = -parameters.relay_amp; 
		}
		iteration_number = iterations_lock_count;
		prev_res = mrft_res;
		first_run = false;
		return (realy_output);
	}
	if (mrft_res){
		if ((prev_res == !mrft_res) && (iteration_number == 0)) {
			prev_res = mrft_res;
			realy_output = parameters.relay_amp;
			iteration_number = iterations_lock_count;
		}
		/*if (angle_pitch>max_angle_pitch[cycle]){
		max_angle_pitch[cycle] = angle_pitch;
		}*/

	}
	else
	{
		if ((prev_res == !mrft_res) && (iteration_number == 0)){
			prev_res = mrft_res;
			realy_output = -parameters.relay_amp;
			iteration_number = iterations_lock_count;
		}
		/*if (angle_pitch<min_angle_pitch[cycle]){
		min_angle_pitch[cycle] = angle_pitch;
		}*/
	}
	if (iteration_number > 0){ 
		iteration_number--; 
	}
	return (realy_output+parameters.bias);
}