#include "Climb.h"
#include "../RobotMap.h"

Climb::Climb()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(climber);
}

// Called just before this Command runs the first time
void Climb::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Climb::Execute()
{
	climber->Climb();
}

// Make this return true when this Command no longer needs to run execute()
bool Climb::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Climb::End()
{
	climber->StopClimb();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Climb::Interrupted()
{
	climber->StopClimb();
}
