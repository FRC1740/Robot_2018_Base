#include "PistonRetract.h"

PistonRetract::PistonRetract()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(piston);
}

// Called just before this Command runs the first time
void PistonRetract::Initialize()
{
	piston->Retract();
}

// Called repeatedly when this Command is scheduled to run
void PistonRetract::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool PistonRetract::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void PistonRetract::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PistonRetract::Interrupted()
{

}
