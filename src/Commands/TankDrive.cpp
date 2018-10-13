/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "TankDrive.h"

TankDrive::TankDrive()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrainf);
	Requires(forklifter);
}

// Called just before this Command runs the first time
void TankDrive::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute()
{
	if (CommandBase::oi->xboxController->GetRawAxis(2) > .15) // Left Trigger -> Dn
	{
		forklifter->Lower(1.0);
	}
	else if (CommandBase::oi->xboxController->GetRawAxis(3) > .15) // Right Trigger -> Up
	{
		forklifter->Raise(1.0);
	}
	drivetrainf->Go(this->GetLeftStickY(true), this->GetRightStickY(true), true);

}

// Make this return true when this Command no longer needs to run execute()
bool TankDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void TankDrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDrive::Interrupted()
{

}

double TankDrive::GetLeftStickY(bool inverted)
{
	if (inverted)
		return -oi->xboxController->GetRawAxis(1); // Left stick, Y axis INVERTED
	else
		return oi->xboxController->GetRawAxis(1); // Left stick, Y axis
}

double TankDrive::GetRightStickY(bool inverted)
{
	if (inverted)
		return -oi->xboxController->GetRawAxis(3); // Right Stick, Y axis INVERTED
	else
		return oi->xboxController->GetRawAxis(3); // Right Stick, Y axis
}

