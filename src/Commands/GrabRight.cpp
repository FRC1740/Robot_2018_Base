#include "GrabRight.h"

GrabRight::GrabRight()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(grabbarms);
}

// Called just before this Command runs the first time
void GrabRight::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void GrabRight::Execute()
{
	grabbarms->RightIn();
}

// Make this return true when this Command no longer needs to run execute()
bool GrabRight::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void GrabRight::End()
{
	grabbarms->RightStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GrabRight::Interrupted()
{
	grabbarms->RightStop();
}
