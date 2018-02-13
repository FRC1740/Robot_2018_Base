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
#include "Commands/autoNothing.h"
#include "Commands/autoNearSwitch.h"
#include "Commands/autoTimedMove.h"
#include "Commands/autoTurn.h"
#include "Commands/ForkMoveToDistance.h"

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
#ifdef USE_COMPRESSOR
	Compressor *compressor;
	bool compressorEnabled, compressorPressureSwitch;
	double compressorCurrent;
#endif

public:

	void RobotInit() override
	{
		CommandBase::init(); // Borrowed from 2017 code base
		autochooser = new SendableChooser<Command*>;
		teleopchooser = new SendableChooser<Command*>;

		SmartDashboard::PutString("Build Version: ", ROBOT_VERSION_STRING);

#ifdef USE_COMPRESSOR
		printf("Instantiating compressor object...\n");
		compressor = new Compressor();
		compressor->SetClosedLoopControl(true);
		compressorEnabled = compressor->Enabled();
		compressorPressureSwitch = compressor->GetPressureSwitchValue();
		compressorCurrent = compressor->GetCompressorCurrent();
#endif
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
		Preferences *prefs;

		prefs = Preferences::GetInstance();
		double mobility = prefs->GetDouble("Mobility", 2.5);
		double rotation = prefs->GetDouble("Rotation", 90.0);
		CommandBase::PIDelevator->PIDReset();
		//double kP = prefs->GetDouble("PID p constant", 1.0);
		//double kI = prefs->GetDouble("PID i constant", 0.0);
		//double kD = prefs->GetDouble("PID d constant", 0.0);

		//foo = SmartDashboard::GetNumber("Mobility", 2.5);
		// Autonomous Modes
		autochooser->AddDefault("Do Nothing", new autoNothing(15)); // rotation is from SmartDashboard
		autochooser->AddObject("Lifter Test", new ForkMoveToDistance(SWITCH_HEIGHT));
		autochooser->AddObject("Basic Mobility", new autoTimedMove(mobility)); // mobility is from SmartDashboard
		autochooser->AddObject("AutoTurn Test", new autoTurn('L'));
		// autochooser->AddObject("Left Field Plates", new autoNearSwitch('L'));
		// autochooser->AddObject("Right Field Plates", new autoNearSwitch('R'));

		// FIXME: Use True/False to indicate drive with or without gyro/saucer mode?
		teleopchooser->AddDefault("Xbox Saucer", new MecanumSaucerDrive(CommandBase::utility->imu));
		teleopchooser->AddObject("Xbox Standard", new MecanumSaucerDrive(nullptr));

		//SmartDashboard::init();
		SmartDashboard::PutData("Auto Modes", autochooser);
		SmartDashboard::PutData("Teleop Modes", teleopchooser);
		// SmartDashboard::PutData("Grab Left Command", new GrabLeft()); //can run command on SmartDashboard

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
		std::string gameData;

		CommandBase::PIDelevator->PIDReset();

		gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
		SmartDashboard::PutString("Plate Configuration: ", gameData);
		autonomousCommand = (Command *) autochooser->GetSelected();
		if (autonomousCommand != nullptr)
		{
			autonomousCommand->Start();
		}

	}

	void AutonomousPeriodic() override
	{
		frc::Scheduler::GetInstance()->Run();
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

#ifdef USE_COMPRESSOR
		// -------------> Not working ---->SmartDashboard::PutNumber("Joystick X value", oi->extendBtn->Get());
		//sd->PutNumber("Joystick X value", oi->extendBtn->Get());
		SmartDashboard::PutBoolean("Compressor: ",compressor->Enabled());
		SmartDashboard::PutBoolean("Pressure Switch: ", compressor->GetPressureSwitchValue());
		SmartDashboard::PutNumber("Compressor Current: ", compressorCurrent = compressor->GetCompressorCurrent());
#endif
		// If we're offering multiple drive/controller options through sendable chooser:
		teleopCommand = (Command *) teleopchooser->GetSelected();
		// teleopCommand = new MecanumSaucerDrive(imu);

		if (teleopCommand != nullptr)
			teleopCommand->Start();

	}

	void TeleopPeriodic() override
	{
		frc::Scheduler::GetInstance()->Run();

		if (CommandBase::oi->xboxYBtn->Get())
		{
			CommandBase::PIDelevator->GotoPosition(SCALE_HEIGHT);
		}
		else if (CommandBase::oi->xboxXBtn->Get())
		{
			CommandBase::PIDelevator->GotoPosition(SWITCH_HEIGHT);
		}
		else if (CommandBase::oi->xboxController->GetRawAxis(2) > .15) // Left trigger
		{
			CommandBase::PIDelevator->Move(1.0); // FIXME: Define a macro for "
		}
		// Right trigger
		else if (CommandBase::oi->xboxController->GetRawAxis(3) > .15)
		{
			CommandBase::PIDelevator->Move(-1.0);
		}
		else
		{
			CommandBase::PIDelevator->Enable();
		}
	}

	void TestPeriodic() override
	{
	}

};

START_ROBOT_CLASS(Robot)
