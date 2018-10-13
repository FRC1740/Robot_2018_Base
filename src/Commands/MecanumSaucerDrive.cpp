#include "MecanumSaucerDrive.h"
#include <math.h>

MecanumSaucerDrive::MecanumSaucerDrive(ADIS16448_IMU *imu)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain);
	Requires(forklifter);
	gyro = imu;
	gyro_angle = 0.0;
}

// Called just before this Command runs the first time
void MecanumSaucerDrive::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void MecanumSaucerDrive::Execute()
{
	// Check Operator Input for manual gyro reset
	if (gyro != nullptr)
	{
		if (oi->xboxBackBtn->Get())
			gyro->Reset();
		else
			gyro_angle = gyro->GetAngleZ();
	}

	// Check Operator input for Lifter commands
	/*
	if (CommandBase::oi->xboxYBtn->Get())
	{
		CommandBase::PIDelevator->GotoPosition(SCALE_HEIGHT);
	}
	else if (CommandBase::oi->xboxXBtn->Get())
	{
		CommandBase::PIDelevator->GotoPosition(SWITCH_HEIGHT);
	}
	else if (CommandBase::oi->xboxController->GetRawAxis(2) > .15) // Left trigger
	{
		CommandBase::PIDelevator->Move(1.0); // FIXME: Define a macro for "
	}
	// Right trigger
	else if (CommandBase::oi->xboxController->GetRawAxis(3) > .15)
	{
		CommandBase::PIDelevator->Move(-1.0);
	}
	else
	{
		CommandBase::PIDelevator->Enable();
	}
	*/
	if (CommandBase::oi->xboxController->GetRawAxis(2) > .15) // Left Trigger -> Dn
	{
		forklifter->Lower(1.0);
	}
	else if (CommandBase::oi->xboxController->GetRawAxis(3) > .15) // Right Trigger -> Up
	{
		forklifter->Raise(1.0);
	}
	else
	{
		forklifter->Stop();
	}

	// Engage!!!
	// Fourth argument is Saucer Angle which is the negative of the gyro angle.
	// If we're not using the imu (null pointer), gyro_angle remains 0.0
	// drivetrain->Go(this->GetX(), this->GetInvertedY(), this->GetTwist(), -gyro_angle);
	// Disable skating
	drivetrain->Go(0.0, this->GetInvertedY(), this->GetTwist(), -gyro_angle);
}

// Make this return true when this Command no longer needs to run execute()
bool MecanumSaucerDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MecanumSaucerDrive::End()
{
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MecanumSaucerDrive::Interrupted()
{
	drivetrain->Stop();
}

double MecanumSaucerDrive::GetX()
{
	return oi->xboxController->GetRawAxis(0); // Left stick, X axis
}

double MecanumSaucerDrive::GetY()
{
	return oi->xboxController->GetRawAxis(1); // Left Stick, Y axis
}

double MecanumSaucerDrive::GetInvertedY()
{
	return -oi->xboxController->GetRawAxis(1); // Left Stick, Y axis, Inverted
}

double MecanumSaucerDrive::GetTwist()
{
	return oi->xboxController->GetRawAxis(4); // Right stick, X axis
}

