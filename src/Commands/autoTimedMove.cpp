#include "autoTimedMove.h"

autoTimedMove::autoTimedMove(double seconds)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain);
	timer = seconds;
}

// Called just before this Command runs the first time
void autoTimedMove::Initialize()
{
	SetTimeout(timer);
}

// Called repeatedly when this Command is scheduled to run
void autoTimedMove::Execute()
{
	drivetrain->Go(0.0, 0.5, 0.0, 0.0);
}

// Make this return true when this Command no longer needs to run execute()
bool autoTimedMove::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void autoTimedMove::End()
{
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoTimedMove::Interrupted()
{
	drivetrain->Stop();
}
