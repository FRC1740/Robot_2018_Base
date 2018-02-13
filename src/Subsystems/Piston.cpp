#include "Piston.h"

Piston::Piston() : frc::Subsystem("Piston")
{
	s = new DoubleSolenoid(CYLINDER_PORT_GRAB, CYLINDER_PORT_DROP);
	isExtended = false; // Needed for toggle mode
}

void Piston::Extend()
{
	s->Set(DoubleSolenoid::Value::kForward);
	isExtended = true; // Needed for toggle mode
}

void Piston::Retract()
{
	s->Set(DoubleSolenoid::Value::kReverse);
	isExtended = false; // Needed for toggle mode
}

void Piston::Toggle()
{
	if (isExtended)
		Retract();
	else
		Extend();
}
