#include "PistonExtend.h"

PistonExtend::PistonExtend()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(piston);
}

// Called just before this Command runs the first time
void PistonExtend::Initialize()
{
	// This is where we can extend the piston
	piston->Toggle();
}

// Called repeatedly when this Command is scheduled to run
void PistonExtend::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool PistonExtend::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void PistonExtend::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PistonExtend::Interrupted()
{
}
