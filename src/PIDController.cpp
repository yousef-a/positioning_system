#include "PIDController.hpp"

PIDController::PIDController(std::string name, block_type type){
    _name = name;
    _type = type;
    _controller_type = controller_type::pid;
    if(_type == block_type::controller)
        std::cout << "This is a "<< _name <<" block" << std::endl; 
    else
        std::cout << "NOT WHATEVER" << std::endl;
}

PIDController::~PIDController() {

}

DataMessage* PIDController::receive_msg_internal(DataMessage* t_msg){
        
	ControllerMessage* controller_msg = (ControllerMessage*)t_msg;

    PID_data* data = controller_msg->getData();
    std::cout << "pid block receives msg: " << std::endl;
	std::cout << "error: " << data->err << std::endl;
	std::cout << "pv_first: " << data->pv_first << std::endl;
	std::cout << "pv_second: " << data->pv_second << std::endl;
    float command = pid_direct(data->err, data->pv_first, data->pv_second);
    FloatMessage* output_msg = new FloatMessage(command);

    std::cout << "SENDING COMMAND" << std::endl;
	return (DataMessage*)output_msg;
}

controller_type PIDController::getControllerType(){
	return _controller_type;
}

void PIDController::switchIn(DataMessage* data){
    //this->emit_message(data);
}


DataMessage* PIDController::switchOut(){
    
    DataMessage* msg;
    return msg;
}   

block_type PIDController::getType(){
    return _type;
}

std::string PIDController::getName(){
    return _name;
}


void PIDController::set_internal_sw(PID_parameters pid_para_x){ //This checks input parameters. If Kd or Ki<0 it means we do not use them
		i_term = !(pid_para_x.ki <= 0);
		d_term = !(pid_para_x.kd <= 0);
		dd_term= !(pid_para_x.kdd <= 0);
		en_anti_windup = !(pid_para_x.anti_windup <= 0); //Same check for Anti-Windup
		en_pv_derivation = pid_para_x.en_pv_derivation;
	}
    
void PIDController::initialize(void* para){ //Refer to example 1 on how to initialize
		parameters = *((PID_parameters*)para); //TODO: Revise parameters scope
		set_internal_sw(parameters);
		accum_u = 0; //This is important as it resets NaN condition
		accum_I = 0;
		prev_err = 0;
		prev2_err = 0;
		prev_pv_rate = 0;

		std::cout << "PID SETTINGS: " << std::endl;
		std::cout << "Kp Term: " << parameters.kp << std::endl;
		std::cout << "Ki Term: " << parameters.ki << std::endl;
		std::cout << "Kd Term: " << parameters.kd << std::endl;
		std::cout << "Kdd Term: " << parameters.kdd << std::endl;
		std::cout << "Anti Windup Term: " << parameters.anti_windup << std::endl;
		std::cout << "en_pv_derivation Term: " << static_cast<int>(parameters.en_pv_derivation) << std::endl;

	}

float PIDController::pid_direct(float err, float pv_first, float pv_second) { //Arbitrary large default value for pv_rate
	float u = 0;
	// ************************** P-term ***************************
	u = err *parameters.kp;
	// ************************** I-term ***************************
	if (i_term)//&& os::is_flying) 
	{
		if (en_anti_windup) { //$$$$$$$$$$$$$$$$$$$$ TODO: Optimize! $$$$$$$$$$$$$$$$$$$$$
			if (fabs(accum_I) < parameters.anti_windup) {
				accum_I += parameters.ki*err*dt_manual;
			}
			else {
				//float buff_I = accum_I + parameters.ki*err*dt_manual;
				//if (abs(buff_I) < parameters.anti_windup) {
				//	accum_I = buff_I;
				//}
				if (((accum_I > 0) && (err < 0))||((accum_I < 0) && (err > 0))) {
					accum_I += parameters.ki*err*dt_manual;
				}
			}
		}
		else {
			accum_I += parameters.ki*err*dt_manual;
		}
	}
	u += accum_I;
	// ************************** D-term ***************************
	if (d_term) {
		if (en_pv_derivation) {
			u += parameters.kd*(-pv_first);
		}
		else {
			u += parameters.kd*(err - prev_err) / dt_manual;
		}
	}
	// ************************* DD-term ***************************
	if (dd_term) {
		u+= parameters.kdd*(-pv_second);
	}
	prev_err = err;
	return u;
}

float PIDController::pid_inc(float err, float pv_first,float pv_second) { //Arbitrary large default value for pv_rate
	static int ctr = 0;
	ctr++;
	// ************************** P-term ***************************
	accum_u += (err - prev_err)*parameters.kp;
	// ************************** I-term ***************************
	if (i_term)//&& os::is_flying) 
	{
		if (en_anti_windup) { //$$$$$$$$$$$$$$$$$$$$ TODO: Optimize! $$$$$$$$$$$$$$$$$$$$$
			if (fabs(accum_u)<parameters.anti_windup)
				accum_u += parameters.ki*err*dt_manual;//os::get_dt()
		}
		else {
			accum_u += parameters.ki*err*dt_manual;
		}
	}
	// ************************** D-term ***************************
	if (d_term) {
		if (en_pv_derivation) {
			accum_u += parameters.kd*(-pv_first + prev_pv_rate);
		}
		else {
			accum_u += parameters.kd*(-err + 2 * prev_err - prev2_err) / dt_manual;
		}
	}
	prev_pv_rate = pv_first;
	prev2_err = prev_err;
	prev_err = err;
	return accum_u;
	}

void PIDController::set_I_term(float forced_I) {
// #ifdef PID_INC
// 	accum_u = forced_I;
// #else
	accum_I = forced_I;
// #endif // PID_INC

}