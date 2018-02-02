#include "autoNothing.h"

autoNothing::autoNothing(double input)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	timer = input;
}

// Called just before this Command runs the first time
void autoNothing::Initialize()
{
	SetTimeout(timer);
}

// Called repeatedly when this Command is scheduled to run
void autoNothing::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool autoNothing::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void autoNothing::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoNothing::Interrupted()
{

}
