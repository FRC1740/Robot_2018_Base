#include "Piston.h"

Piston::Piston() : frc::Subsystem("Piston")
{
	s = new DoubleSolenoid(CYLINDER_PORT0, CYLINDER_PORT1);
	isExtended = false;
}

void Piston::Extend()
{
	s->Set(DoubleSolenoid::Value::kForward);
	isExtended = true;
}

void Piston::Retract()
{
	s->Set(DoubleSolenoid::Value::kReverse);
	isExtended = false;
}

void Piston::Toggle()
{
	if (isExtended)
		Retract();
	else
		Extend();
}
