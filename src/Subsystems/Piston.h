#ifndef PISTON_H
#define PISTON_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Solenoid.h"
#include "../RobotMap.h"

class Piston: public Subsystem
{
private:
	DoubleSolenoid *s;
public:
	Piston();
	void Extend();
	void Retract();
	void Toggle();
	bool isExtended;
};

#endif
