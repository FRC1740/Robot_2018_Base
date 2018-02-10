#include "ForkMove.h"

ForkMove::ForkMove()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	// Requires(forklifter);
	Requires(PIDelevator);
}

// Called just before this Command runs the first time
void ForkMove::Initialize()
{
	PIDelevator->CancelPID();
}

// Called repeatedly when this Command is scheduled to run
void ForkMove::Execute()
{
	double ForkMove;

	if((ForkMove = GetRightTrig()) > TRIGGER_DEADBAND)
	{
		// forklifter->Raise(ForkMove);
		PIDelevator->Move(1.0);
	}
	else if((ForkMove = GetLeftTrig()) > TRIGGER_DEADBAND)
	{
		// forklifter->Lower(ForkMove);
		PIDelevator->Move(-1.0);
	}
	else
	{
		// forklifter->Stop();
		PIDelevator->Stop();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ForkMove::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ForkMove::End()
{
	// forklifter->Stop();
	PIDelevator->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ForkMove::Interrupted()
{
	// forklifter->Stop();
	PIDelevator->Stop();
}

double ForkMove::GetLeftTrig()
{
	return oi->xboxController->GetRawAxis(2); //Left trigger
}

double ForkMove::GetRightTrig()
{
	return oi->xboxController->GetRawAxis(3); //Right trigger
}

