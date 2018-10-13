
#include "Retract.h"

Retract::Retract()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(climber);
}

// Called just before this Command runs the first time
void Retract::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Retract::Execute()
{
	climber->Retract();
}

// Make this return true when this Command no longer needs to run execute()
bool Retract::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Retract::End()
{
	climber->StopTelescope();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Retract::Interrupted()
{
	climber->StopTelescope();
}
