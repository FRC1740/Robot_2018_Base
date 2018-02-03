#include "ForkMoveToDistance.h"

ForkMoveToDistance::ForkMoveToDistance(int lvl)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(forklifter);
	int Current = forklifter->ReadEncoder();

		if(lvl == 1)
		{
			Target = FORK_LEVEL_1 - Current;
			//if target is negative go down, otherwise go up
		}
		else if (lvl == 2)
		{
			Target = FORK_LEVEL_2 - Current;

		}
		else if (lvl == 3)
		{
			Target = FORK_LEVEL_3 - Current;

		}
		else if (lvl == 4)
		{
			Target = FORK_LEVEL_4 - Current;

		}
}

// Called just before this Command runs the first time
void ForkMoveToDistance::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ForkMoveToDistance::Execute()
{
	if (Target > forklifter->ReadEncoder()){
		forklifter->Raise(FORK_SPEED);
	}
	else if (Target < -FORK_DISTANCE_DEADBAND)
	{
		forklifter->Lower(FORK_SPEED);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ForkMoveToDistance::IsFinished()
{
	return ((abs(Target - forklifter->ReadEncoder())) < FORK_DISTANCE_DEADBAND);
}

// Called once after isFinished returns true
void ForkMoveToDistance::End()
{
	forklifter->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ForkMoveToDistance::Interrupted()
{
	forklifter->Stop();
}
