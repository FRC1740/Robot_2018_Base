#ifndef DriveTrain_H
#define DriveTrain_H

#include <ctre/Phoenix.h>
#include <WPILib.h>
#include <Commands/Subsystem.h>
#include <OI.h>
#include "../RobotMap.h"

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

class DriveTrain : public frc::Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	WPI_TalonSRX *fl; // Front Left motor
	WPI_TalonSRX *fr; // Front Right motor
	WPI_TalonSRX *rl; // Rear left motor
	WPI_TalonSRX *rr; // Rear Right motor
	char gyroString[128];
	MecanumDrive *m_robotDrive;

public:
	DriveTrain();
	void InitDefaultCommand();
	void SaucerDrive(double, double);
	void Go(double, double, double, double); // Left X, Left Y, Twist, Angle
	void Stop(); // All Stop
	double Db(double); // Deadband
};

#endif  // DriveTrain_H
