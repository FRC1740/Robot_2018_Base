
#include "Extend.h"

Extend::Extend()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(climber);
}

// Called just before this Command runs the first time
void Extend::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Extend::Execute()
{
	climber->Extend();
}

// Make this return true when this Command no longer needs to run execute()
bool Extend::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Extend::End()
{
	climber->StopTelescope();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Extend::Interrupted()
{
	climber->StopTelescope();
}
