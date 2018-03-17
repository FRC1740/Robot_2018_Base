#include "DriveTrain.h"

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain")
{
	fl = new WPI_TalonSRX(FRONT_LEFT_MOTOR_ID); // Front Left
	rl = new WPI_TalonSRX(REAR_LEFT_MOTOR_ID); // Rear Left
	fr = new WPI_TalonSRX(FRONT_RIGHT_MOTOR_ID); // Front Right
	rr = new WPI_TalonSRX(REAR_RIGHT_MOTOR_ID); // Rear Right

	m_robotDrive = new MecanumDrive(*fl, *rl, *fr, *rr);

	rlCount = new Counter(REAR_LEFT_MOTOR_ENCODER_CHANNEL_A);

	/* Set every Talon to reset the motor safety timeout. */
	fl->Set(ControlMode::PercentOutput, 0);
	fr->Set(ControlMode::PercentOutput, 0);
	rl->Set(ControlMode::PercentOutput, 0);
	rr->Set(ControlMode::PercentOutput, 0);

	// CRE: 2017-02-17 Initialize the encoder position so we can (hopefully) tell how far we've moved
	rlCount->Reset();
	// fl->SetPosition(0);
	// fr->SetPosition(0);
	// rr->SetPosition(0);

	m_robotDrive->SetExpiration(0.5);
	m_robotDrive->SetSafetyEnabled(false);
}

void DriveTrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// FIXME: The following line throws an "expected type-specifier before 'MecanumSaucerDrive'" error
	// SetDefaultCommand(new MecanumSaucerDrive());
}

void DriveTrain::SaucerDrive(double angle, double magnitude)
{
	rlCount->Reset();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::Go(double x, double y, double twist, double angle)
{
	SmartDashboard::PutNumber("Streering Angle: ", (int)angle%360);
	SmartDashboard::PutNumber("Drive Counter: ", rlCount->Get());

	m_robotDrive->DriveCartesian(Db(x), Db(y), Db(twist), angle);
}

void DriveTrain::Stop()
{
	m_robotDrive->StopMotor();
}

/** @return deadband */
double DriveTrain::Db(double axisVal)
{
	if(axisVal < -DRIVE_DEADBAND)
		return axisVal;
	if(axisVal > +DRIVE_DEADBAND)
		return axisVal;
	return 0;
}

void DriveTrain::Reset()
{
	rlCount->Reset();
}
int DriveTrain::GetCount()
{
	return rlCount->Get();
}
