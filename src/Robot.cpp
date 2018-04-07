/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "CommandBase.h"
#include <string.h>
#include <WPILib.h>
#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <TimedRobot.h>

#include "Commands/MecanumSaucerDrive.h"
//#include "Commands/TankDrive.h"
#include "Commands/autoNothing.h"
#include "Commands/autoDelivery.h"
#include "Commands/autoDriveDistance.h"
#include "Commands/autoTimedMove.h"
#include "Commands/autoTurn.h"
#include "Commands/autoGroupTest.h"
#include "Commands/ForkMoveToDistance.h"
#include "Commands/ForkRaise.h"
#include "Commands/ForkLower.h"
#include "FieldMap.h"

// #include "Subsystems/ForkLifter.h"
//#include "Commands/ForkMove.h"
#include <ctre/Phoenix.h>

//On error, create env.h from env-default.h and modify ROBOT_VERSION_STRING
#include "env.h"

class Robot : public frc::TimedRobot {
private:
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.
	// The following are based on the WPILib example

	Command *autonomousCommand = nullptr;
	Command *teleopCommand = nullptr;
	Command *elevator = nullptr;

	SendableChooser<Command*> *autochooser;
	SendableChooser<Command*> *teleopchooser;

	Preferences *m_prefs;
	std::string m_gameData;

public:

	void RobotInit() override
	{
		CommandBase::init(); // Borrowed from 2017 code base
		autochooser = new SendableChooser<Command*>;
		teleopchooser = new SendableChooser<Command*>;
		m_prefs = Preferences::GetInstance();

		// double rotation = m_prefs->GetDouble("Rotation", 90.0); // changed to #define
		//foo = SmartDashboard::GetNumber("Mobility", 2.5);

		/*
		 * Autonomous Sendable chooser modes
		*/

		autochooser->AddDefault("Do Nothing", new autoNothing(15));
		// autochooser->AddObject("Lifter Test", new ForkMoveToDistance(SWITCH_HEIGHT));
		// Retrieve basic/timed mobility duration from SmartDashboard prefs
		autochooser->AddObject("Timed Mobility", new autoTimedMove(m_prefs->GetDouble("Mobility", 2.0))); // 42 in/sec? - auto line 75 in
		autochooser->AddObject("Basic Mobility", new autoDriveDistance(AUTO_LINE_DISTANCE));
		autochooser->AddObject("Auto Turn Test", new autoTurn('L'));
		autochooser->AddObject("Left Field Plates", new autoGroupTest);

		//autochooser->AddObject("Left Field Plates", new autoDelivery);
		//autochooser->AddObject("Right Field Plates", new autoDelivery('R'));

		// FIXME: Use True/False to indicate drive with or without gyro/saucer mode?
		teleopchooser->AddDefault("Xbox Standard", new MecanumSaucerDrive(nullptr));
		teleopchooser->AddObject("Xbox Saucer", new MecanumSaucerDrive(CommandBase::utility->imu));
//		teleopchooser->AddObject("Xbox Tank Drive", new TankDrive());

		//SmartDashboard::init();
		SmartDashboard::PutData("Auto Modes", autochooser);
		SmartDashboard::PutData("Teleop Modes", teleopchooser);
		// SmartDashboard::PutData("Grab Left Command", new GrabLeft()); //can run command on SmartDashboard

		SmartDashboard::PutString("Build Version: ", ROBOT_VERSION_STRING);

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
		if (autonomousCommand != nullptr)
		{
			autonomousCommand->Cancel();
			autonomousCommand = nullptr;
		}
		if (teleopCommand != nullptr)
		{
			teleopCommand->Cancel();
			teleopCommand = nullptr;
		}

		// Referesh the preferences
		double mobility = m_prefs->GetDouble("Mobility", 2.5);
		double rotation = m_prefs->GetDouble("Rotation", 90.0);
		CommandBase::PIDelevator->PIDReset();
		//double kP = m_prefs->GetDouble("PID p constant", 1.0);
		//double kI = m_prefs->GetDouble("PID i constant", 0.0);
		//double kD = m_prefs->GetDouble("PID d constant", 0.0);

	}

	void DisabledPeriodic() override
	{
		frc::Scheduler::GetInstance()->Run();
		// ScreenstepsLive suggests checking the gameData string here so we have it BEFORE auto begins
		m_gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
		SmartDashboard::PutString("Plate Configuration: ", m_gameData);
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
		CommandBase::PIDelevator->PIDReset();

		// Engage!!
		autonomousCommand = (Command *) autochooser->GetSelected();
		if (autonomousCommand != nullptr)
		{
			autonomousCommand->Start();
		}
	}

	void AutonomousPeriodic() override
	{
		frc::Scheduler::GetInstance()->Run();
		SmartDashboard::UpdateValues();
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
		teleopCommand = (Command *) teleopchooser->GetSelected();

		if (teleopCommand != nullptr)
		{
			teleopCommand->Start();
		}
	}

	void TeleopPeriodic() override
	{
		frc::Scheduler::GetInstance()->Run();
		SmartDashboard::UpdateValues();
	}

	void TestPeriodic() override
	{
		SmartDashboard::UpdateValues();
	}

};

START_ROBOT_CLASS(Robot)
