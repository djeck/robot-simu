#ifndef SIMULATEUR_H
#define SIMULATEUR_H

#include "Robot.h"

class Simulateur
{
public:
	Simulateur(robot_data* data);
	~Simulateur();
private:
	robot_data* data;
};

#endif // SIMULATEUR_H
