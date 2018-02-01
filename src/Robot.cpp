/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commandbase.h"
#include <WPILib.h>
#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <TimedRobot.h>

#include "Commands/MecanumSaucerDrive.h"
//#include "Commands/ExampleCommand.h"
#include "Commands/MyAutoCommand.h"
#include "Subsystems/ForkLifter.h"
#include <Commands/ForkMove.h>
#include "Commands/GrabLeft.h"//FIXME remove after test
#include <ctre/Phoenix.h>
#include <ADIS16448_IMU.h>

#include "OI.h"

class Robot : public frc::TimedRobot {
private:
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.
	// The following are based on the WPILib example
	frc::Command* m_autonomousCommand = nullptr;
	frc::Command* m_teleopCommand = nullptr;

	// The following were copied from 2017 code base
	SendableChooser<Command*> *drivemodechooser;
	SendableChooser<Command*> *autonomouschooser;
	Command *autonomousCommand = nullptr;
	Command *teleopCommand = nullptr;
	Command *fork = nullptr;
	ADIS16448_IMU *imu; // Inertial Management Unit

	//ExampleCommand m_defaultAuto;
	MyAutoCommand m_myAuto;
	frc::SendableChooser<frc::Command*> m_chooser;
	Compressor *compressor;
	bool compressorEnabled, compressorPressureSwitch;
	double compressorCurrent;

public:

	double gyroAngle;

	void RobotInit() override
	{
		CommandBase::init(); // Borrowed from 2017 code base

		//m_chooser.AddDefault("Default Auto", &m_defaultAuto);
		m_chooser.AddObject("My Auto", &m_myAuto);
		//frc::SmartDashboard::init();
		frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
		SmartDashboard::PutData("Grab Left Command", new GrabLeft()); //can run command on SmartDashboard

		printf("Instantiating compressor object...\n");
		compressor = new Compressor();
		compressor->SetClosedLoopControl(true);
		compressorEnabled = compressor->Enabled();
		compressorPressureSwitch = compressor->GetPressureSwitchValue();
		compressorCurrent = compressor->GetCompressorCurrent();
		cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture();
		camera.SetResolution(640, 480);
		imu = new ADIS16448_IMU();
		// drivemodechooser = new SendableChooser<Command*>;
//		drivemodechooser->AddObject("Standard Tank Drive", new StandardTankDrive());
//		drivemodechooser->AddObject("2 Joystick Mecanum", new MecanumTankDrive());
		// drivemodechooser->AddDefault("Xbox Standard", new MecanumSaucerDrive());

	}

	/**
	 * This function is called once each time the robot enters Disabled mode.
	 * You can use it to reset any subsystem information you want to clear
	 * when the robot is disabled.
	 */
	void DisabledInit() override
	{
		imu->Reset();
		gyroAngle = 0.0;
	}

	void DisabledPeriodic() override
	{
		frc::Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString code to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional commands to the chooser
	 * code above (like the commented example) or additional
	 * comparisons to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() override
	{
		std::string autoSelected = frc::SmartDashboard::GetString(
				"Auto Selector", "Default");
		if (autoSelected == "My Auto") {
			m_autonomousCommand = &m_myAuto;
		} else {
			//m_autonomousCommand = &m_defaultAuto;
		}

		m_autonomousCommand = m_chooser.GetSelected();

		if (m_autonomousCommand != nullptr) {
			m_autonomousCommand->Start();
		}
		imu->Reset();
		gyroAngle = 0.0;

	}

	void AutonomousPeriodic() override
	{
		frc::Scheduler::GetInstance()->Run();
		gyroAngle = imu->GetAngleZ();
	}

	void TeleopInit() override {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (m_autonomousCommand != nullptr) {
			m_autonomousCommand->Cancel();
			m_autonomousCommand = nullptr;
		}
		// If we're offering multiple drive/controller options through sendable chooser:
		// teleopCommand = (Command *) drivemodechooser->GetSelected();

		teleopCommand = new MecanumSaucerDrive(imu);
		if (teleopCommand != nullptr)
			teleopCommand->Start();
		/*
		 * FIXME Can we run a second command concurrently for forklift?

		climber = new Climb();
		if (climber != nullptr)
			climber->Start();
		 */
		fork = new ForkMove();
		if (fork != nullptr)
			fork->Start();

		imu->Reset();
		gyroAngle = 0.0;
	}

	void TeleopPeriodic() override
	{
		gyroAngle = imu->GetAngleZ();
		frc::Scheduler::GetInstance()->Run();
		// -------------> Not working ---->SmartDashboard::PutNumber("Joystick X value", oi->extendBtn->Get());
		//sd->PutNumber("Joystick X value", oi->extendBtn->Get());
		SmartDashboard::PutBoolean("Compressor: ",compressor->Enabled());
		SmartDashboard::PutBoolean("Pressure Switch: ", compressor->GetPressureSwitchValue());
		SmartDashboard::PutNumber("Compressor Current: ", compressorCurrent = compressor->GetCompressorCurrent());

	}

	void TestPeriodic() override
	{
		// How do we access the OI object from here? xboxController not recognized
		// SmartDashboard::PutNumber("Left Stick X: ", oi->xboxController->GetX());
		// SmartDashboard::PutNumber("Left Stick Y: ", oi->xboxController->GetY());
	}

};

START_ROBOT_CLASS(Robot)
