#ifndef COMMANDBASE_H
#define COMMANDBASE_H

#include <string>
#include <Commands/Command.h>
#include "OI.h"
#include <WPILib.h>
#include "Subsystems/ForkLifter.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/Utility.h"
#include "Subsystems/Piston.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/DriveTrainFriction.h"
#include "Subsystems/Climber.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static Climber *climber;
	static OI *oi;
	static Elevator *PIDelevator;
	static ForkLifter *forklifter;
	static Piston *piston;
	static DriveTrain *drivetrain;
	static DriveTrainFriction *drivetrainf;
	static Utility *utility;
	//	static DataLogger *datalogger;
	//	static Camera *camera;
};
#endif
