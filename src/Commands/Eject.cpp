#include "Eject.h"

Eject::Eject()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(grabbarms);
}

// Called just before this Command runs the first time
void Eject::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Eject::Execute()
{
	grabbarms->Eject();
}

// Make this return true when this Command no longer needs to run execute()
bool Eject::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Eject::End()
{
	grabbarms->AllStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Eject::Interrupted()
{
	grabbarms->AllStop();
}
