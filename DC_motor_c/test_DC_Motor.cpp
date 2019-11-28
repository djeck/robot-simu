#include <iostream>
#include "Moteur_DC.h"

int main(int argc, char** argv)
{
	Moteur_DC motor;

	double time = 0;
	double cmd = 0;
	double load = 0;
	std::cout<<"Time,Position,Speed,Torque,Load,Command,"<<std::endl;
	motor.process(0.1); time += 0.1;
	std::cout<<time<<","<<motor.getPosition()<<","<<motor.getSpeed()<<","<<motor.getCouple()<<","<<load<<","<<cmd<<","<<std::endl;
	motor.process(0.1); time += 0.1;
	std::cout<<time<<","<<motor.getPosition()<<","<<motor.getSpeed()<<","<<motor.getCouple()<<","<<load<<","<<cmd<<","<<std::endl;
	motor.process(0.1); time += 0.1;
	std::cout<<time<<","<<motor.getPosition()<<","<<motor.getSpeed()<<","<<motor.getCouple()<<","<<load<<","<<cmd<<","<<std::endl;

	return 0;
}
