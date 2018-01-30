#include "GrabLeft.h"

GrabLeft::GrabLeft()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(grabbarms);
}

// Called just before this Command runs the first time
void GrabLeft::Initialize()
{
	SmartDashboard::PutBoolean("Grab Left", true);
}

// Called repeatedly when this Command is scheduled to run
void GrabLeft::Execute()
{
	grabbarms->LeftIn();
}

// Make this return true when this Command no longer needs to run execute()
bool GrabLeft::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void GrabLeft::End()
{
	grabbarms->LeftStop();
	SmartDashboard::PutBoolean("Grab Left", false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GrabLeft::Interrupted()
{
	grabbarms->LeftStop();
	SmartDashboard::PutBoolean("Grab Left", false);
}
