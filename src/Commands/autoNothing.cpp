#include "autoNothing.h"

autoNothing::autoNothing(double seconds)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(PIDelevator);
	timer = seconds;
}

// Called just before this Command runs the first time
void autoNothing::Initialize()
{
	SetTimeout(timer);
	PIDelevator->GotoPosition(timer);
}

// Called repeatedly when this Command is scheduled to run
void autoNothing::Execute()
{
	frc::SmartDashboard::PutNumber("PID Elevator distance to target: ", PIDelevator->GetPosition());
}

// Make this return true when this Command no longer needs to run execute()
bool autoNothing::IsFinished()
{
	return PIDelevator->OnTarget();
	// return IsTimedOut();
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
