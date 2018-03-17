/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "autoDriveDistance.h"

autoDriveDistance::autoDriveDistance(double distance)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain);
	Requires(utility);
	m_target_count = (long)(distance * M_1_PI);
	m_steering_angle = 0.0;
}

// Called just before this Command runs the first time
void autoDriveDistance::Initialize()
{
	drivetrain->Reset(); // Reset counter
}

// Called repeatedly when this Command is scheduled to run
void autoDriveDistance::Execute()
{
	m_steering_angle = -utility->GetAngle();
	// FIXME: drifting right... Include a multiplier? or add a twist component?
	// FIXME: eg., gyro_angle *= 1.1;
	// FIXME: or... drivetrain->Go(0.0, 0.5, COMPENSATE_FOR_RIGHT_DRIFT, -gyro_angle);
	drivetrain->Go(0.0, 0.5, 0.0, m_steering_angle);
}

// Make this return true when this Command no longer needs to run execute()
bool autoDriveDistance::IsFinished()
{
	 if (drivetrain->GetCount() > m_target_count)
	 {
	 	 return true;
	 }
	 else
	 {
	 	 return false;
	 }
}

// Called once after isFinished returns true
void autoDriveDistance::End()
{
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoDriveDistance::Interrupted()
{
	drivetrain->Stop();
}
