#include "Descend.h"
#include "../RobotMap.h"

Descend::Descend()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(climber);
}

// Called just before this Command runs the first time
void Descend::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Descend::Execute()
{
	climber->Descend();
}

// Make this return true when this Command no longer needs to run execute()
bool Descend::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Descend::End()
{
	climber->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Descend::Interrupted()
{
	climber->Stop();
}
