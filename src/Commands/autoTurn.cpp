#include "autoTurn.h"

autoTurn::autoTurn(char side)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(utility);
	Requires(drivetrain);

	if (side == 'L')
		angle = NINETY_DEGREES;
	else if (side == 'R')
		angle = -NINETY_DEGREES;
	else
		angle = 0.0;
}

// Called just before this Command runs the first time
void autoTurn::Initialize()
{
	// Are we turning left or right?
	if (angle < utility->GetAngle())
		m_turn_rate = -TURN_RATE; // Turn Left
	else
		m_turn_rate = TURN_RATE; // Turn Right

}

// Called repeatedly when this Command is scheduled to run
void autoTurn::Execute()
{
	drivetrain->Go(0.0, 0.0, m_turn_rate, 0.0); // TODO: Adding PID control to this would be nice.
	SmartDashboard::PutNumber("Gyro Angle: ", utility->GetAngle());
}

// Make this return true when this Command no longer needs to run execute()
bool autoTurn::IsFinished()
{
	return (abs(angle - utility->GetAngle()) < TURN_DEADBAND);
}

// Called once after isFinished returns true
void autoTurn::End()
{
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoTurn::Interrupted()
{
	drivetrain->Stop();
}
