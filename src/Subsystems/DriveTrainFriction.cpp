/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "DriveTrainFriction.h"
#include "../RobotMap.h"

DriveTrainFriction::DriveTrainFriction() : frc::Subsystem("DriveTrainFriction")
{
#if 0
	fl = new WPI_TalonSRX(FRONT_LEFT_MOTOR_ID); // Front Left
	rl = new WPI_TalonSRX(REAR_LEFT_MOTOR_ID); // Rear Left
	fr = new WPI_TalonSRX(FRONT_RIGHT_MOTOR_ID); // Front Right
	rr = new WPI_TalonSRX(REAR_RIGHT_MOTOR_ID); // Rear Right
	/*
	 *
	 *   frc::Spark m_frontLeft{1};
	 *   frc::Spark m_rearLeft{2};
	 *   frc::SpeedControllerGroup m_left{m_frontLeft, m_rearLeft};
	 *
	 *   frc::Spark m_frontRight{3};
	 *   frc::Spark m_rearRight{4};
	 *   frc::SpeedControllerGroup m_right{m_frontRight, m_rearRight};
	 *
	 *   frc::DifferentialDrive m_drive{m_left, m_right};
	 *
	 *
	 */
	// FIXME: Need to group left & right wheels so they run in sync
	// m_left = new SpeedControllerGroup(fl, rl);
	// m_right = new SpeedControllerGroup(fr, rr);
	// m_left(fl, rl);
	/// m_right(fr, rr);
	//m_robotDrive = new DifferentialDrive(*fl, *fr);
	//m_robotDrive = new DifferentialDrive(*m_left, *m_right);

	// rlCount = new Counter(REAR_LEFT_MOTOR_ENCODER_CHANNEL_A);

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
#endif
}

void DriveTrainFriction::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void DriveTrainFriction::Go(double left, double right, bool square_inputs)
{
#if 0
	double lspeed, rspeed;
	// m_robotDrive->TankDrive(left, right, square_inputs);
	if (square_inputs) {
		lspeed = left * left;
		rspeed = right * right;
	} else {
		lspeed = left;
		rspeed = right;
	}
	fl->Set(lspeed); // Left Wheels CW (positive) forward
	rl->Set(lspeed); // Left Wheels CW (positive) forward
	fr->Set(-rspeed); // Right Wheels CCW (negative) forward
	rr->Set(-rspeed); // Right Wheels CCW (negative) forward
#endif
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveTrainFriction::Stop()
{
#if 0
	// m_robotDrive->StopMotor();
	fl->Set(0.0);
	rl->Set(0.0);
	fr->Set(0.0);
	rr->Set(0.0);
#endif
}
