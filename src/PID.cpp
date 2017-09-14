#include "PID.h"
#include <iostream>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID(): is_initialized(false) {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd)
{
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;

	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;

	prev_cte = 0.0;
	sum_cte = 0.0;

	is_initialized = true;

}

bool PID::isInitialized()
{
	return is_initialized;
}

void PID::UpdateError(double cte)
{
	p_error = cte;
	d_error = cte - prev_cte;
	prev_cte = cte;
	i_error += cte;

	//std::cout << ((Kp * p_error)) << "," <<  Kd * d_error << "," << -1 * (Kp * p_error) - Kd * d_error - Ki * i_error << std::endl;
}

double PID::TotalError()
{

	return -1 * (Kp * p_error) - Kd * d_error - Ki * i_error;

}

