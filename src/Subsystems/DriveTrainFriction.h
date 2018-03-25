#ifndef TankDrive_H
#define TankDrive_H
/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <ctre/Phoenix.h>
#include <WPILib.h>
#include <Commands/Subsystem.h>
#include <OI.h>
#include <RobotMap.h>

/*
 *  xbox controller axes
 *  0 - Left stick X axis
 *  1 - Left stick Y axis
 *  2 - Right stick X axis
 */
#define DRIVE_X_AXIS 0
#define DRIVE_Y_AXIS 1
#define TURN_AXIS 2

#define DRIVE_DEADBAND .2 // Axis deadband

class DriveTrainFriction : public frc::Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_TalonSRX *fl; // Front Left motor
	WPI_TalonSRX *fr; // Front Right motor
	WPI_TalonSRX *rl; // Rear left motor
	WPI_TalonSRX *rr; // Rear Right motor
	char gyroString[128];
	DifferentialDrive *m_robotDrive;
	Counter *rlCount; // Rear Left Wheel counter (not an encoder)
	// Group left & right motors so they run in sync
	SpeedControllerGroup *m_left;
	SpeedControllerGroup *m_right;

public:
	DriveTrainFriction();
	void InitDefaultCommand() override;
	void Go(double, double, bool);
	void Stop();
};

#endif
