/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commandbase.h"
#include <string.h>
#include <WPILib.h>
#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <TimedRobot.h>

#include "Commands/autoNothing.h"
#include "Commands/autoTimedMove.h"
#include "Commands/GrabLeft.h"
//#include "Commands/GrabRight.h"

// #include "Subsystems/ForkLifter.h"
#include "Commands/ForkMove.h"
#include <ctre/Phoenix.h>
#include "ADIS16448_IMU.h"

#include "OI.h"

#ifndef ROBOT_VERSION_STRING
#define ROBOT_VERSION_STRING "Undefined Version"
#endif

class Robot : public frc::TimedRobot {
private:
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.
	// The following are based on the WPILib example

	Command *autonomousCommand = nullptr;
	Command *teleopCommand = nullptr;
	Command *fork = nullptr;

	SendableChooser<Command*> *autochooser;
	SendableChooser<Command*> *teleopchooser;
	Compressor *compressor;
	bool compressorEnabled, compressorPressureSwitch;
	double compressorCurrent;
	ADIS16448_IMU *imu; // Inertial Management Unit

public:

	double gyroAngle;

	void RobotInit() override
	{

		CommandBase::init(); // Borrowed from 2017 code base

		autochooser = new SendableChooser<Command*>;
		teleopchooser = new SendableChooser<Command*>;
		imu = new ADIS16448_IMU(); // Instantiate before Sendable Chooser

		// Autonomous Modes
		autochooser->AddDefault("Do Nothing", new autoNothing(15));
		autochooser->AddObject("Basic Mobility", new autoTimedMove(5));
		autochooser->AddObject("Left Field Plates", new autoNothing(15));
		autochooser->AddObject("Right Field Plates", new autoNothing(15));

		teleopchooser->AddDefault("Xbox Saucer", new MecanumSaucerDrive(imu));
		teleopchooser->AddObject("Xbox Standard", new MecanumSaucerDrive(nullptr));

		//SmartDashboard::init();
		SmartDashboard::PutData("Auto Modes", autochooser);
		SmartDashboard::PutData("Teleop Modes", teleopchooser);
		// SmartDashboard::PutData("Grab Left Command", new GrabLeft()); //can run command on SmartDashboard
		SmartDashboard::PutString("Build Version: ", ROBOT_VERSION_STRING);

		printf("Instantiating compressor object...\n");
		compressor = new Compressor();
		compressor->SetClosedLoopControl(true);
		compressorEnabled = compressor->Enabled();
		compressorPressureSwitch = compressor->GetPressureSwitchValue();
		compressorCurrent = compressor->GetCompressorCurrent();
		cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture();
		camera.SetResolution(640, 480);

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
		imu->Reset();
		gyroAngle = 0.0;

		autonomousCommand = (Command *) autochooser->GetSelected();
		if (autonomousCommand != nullptr)
		{
			autonomousCommand->Start();
		}

	}

	void AutonomousPeriodic() override
	{
		std::string gameData;
		gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
		SmartDashboard::PutString("Plate Configuration: ", gameData);

		frc::Scheduler::GetInstance()->Run();
		gyroAngle = imu->GetAngleZ();
	}

	void TeleopInit() override {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != nullptr)
		{
			autonomousCommand->Cancel();
			autonomousCommand = nullptr;
		}
		// If we're offering multiple drive/controller options through sendable chooser:
		// teleopCommand = (Command *) drivemodechooser->GetSelected();

		teleopCommand = (Command *) teleopchooser->GetSelected();
		// teleopCommand = new MecanumSaucerDrive(imu);
		if (teleopCommand != nullptr)
			teleopCommand->Start();

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
