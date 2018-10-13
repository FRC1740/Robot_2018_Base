#include "ForkLower.h"

ForkLower::ForkLower(double s)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	// Requires(grabbarms);
	Requires(forklifter);
	m_timer = s;
}

// Called just before this Command runs the first time
void ForkLower::Initialize()
{
	SetTimeout(m_timer);
}

// Called repeatedly when this Command is scheduled to run
void ForkLower::Execute()
{
	forklifter->Lower(1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool ForkLower::IsFinished()
{
	return (IsTimedOut());
}

// Called once after isFinished returns true
void ForkLower::End()
{
	forklifter->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ForkLower::Interrupted()
{
	forklifter->Stop();
}
