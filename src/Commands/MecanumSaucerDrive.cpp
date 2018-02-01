#include "MecanumSaucerDrive.h"
#include <math.h>

MecanumSaucerDrive::MecanumSaucerDrive(ADIS16448_IMU *imu)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain);
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
	// Get input from OI MOVE - xbox LEFT joystick
	double xOI = this->GetX();
	double yOI = -this->GetY(); // Invert Y axis (stick forward is negative)


	// Convert X/Y inputs to angle/magnitude
	double angle = atan(yOI/xOI);
	double magnitude = sqrt(xOI*xOI + yOI*yOI);


	// Get input from OI TURN joystick
	double twistOI = this->GetTwist(); // Right stick, x axis

	if (oi->xboxBackBtn->Get())
		gyro->Reset();

	gyro_angle = gyro->GetAngleZ();

	// Combine TURN magnitude with MOVE magnitude


	// Engage!!!
	// Fourth argument is Saucer Angle which is the negative of the gyro angle.
	drivetrain->Go(xOI, yOI, twistOI, -gyro_angle);

}

// Make this return true when this Command no longer needs to run execute()
bool MecanumSaucerDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MecanumSaucerDrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MecanumSaucerDrive::Interrupted()
{

}

double MecanumSaucerDrive::GetX()
{
	return oi->xboxController->GetRawAxis(0); // Left stick, X axis
}

double MecanumSaucerDrive::GetY()
{
	return oi->xboxController->GetRawAxis(1); // Left Stick, Y axis
}

double MecanumSaucerDrive::GetTwist()
{
	return oi->xboxController->GetRawAxis(4); // Right stick, X axis
}

