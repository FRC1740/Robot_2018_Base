#include "ForkMoveToDistance.h"

ForkMoveToDistance::ForkMoveToDistance(double dist)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	// Requires(forklifter);
	//int current = forklifter->ReadEncoder();
	Requires(PIDelevator);
	target = dist;

}

// Called just before this Command runs the first time
void ForkMoveToDistance::Initialize()
{
	PIDelevator->GotoPosition(target);
	printf("FormMoveToDistance: %f", target);
}

// Called repeatedly when this Command is scheduled to run
void ForkMoveToDistance::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool ForkMoveToDistance::IsFinished()
{
	return true; // Let PID handle the rest...
}

// Called once after isFinished returns true
void ForkMoveToDistance::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ForkMoveToDistance::Interrupted()
{
}
