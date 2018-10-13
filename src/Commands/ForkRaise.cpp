#include "ForkRaise.h"

ForkRaise::ForkRaise(double s)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	// Requires(grabbarms);
	Requires(forklifter);
	m_timer = s;
}

// Called just before this Command runs the first time
void ForkRaise::Initialize()
{
	SetTimeout(m_timer);
}

// Called repeatedly when this Command is scheduled to run
void ForkRaise::Execute()
{
	forklifter->Raise(1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool ForkRaise::IsFinished()
{
	return (IsTimedOut());
}

// Called once after isFinished returns true
void ForkRaise::End()
{
	forklifter->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ForkRaise::Interrupted()
{
	forklifter->Stop();
}
