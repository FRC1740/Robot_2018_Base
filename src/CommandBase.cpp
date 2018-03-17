#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static pointer/instance of all of your subsystems to NULL
Climber* CommandBase::climber;
OI* CommandBase::oi = NULL;
DriveTrain* CommandBase::drivetrain = NULL;
Piston*	CommandBase::piston = NULL;
Utility* CommandBase::utility = NULL;
GrabbArms* CommandBase::grabbarms = NULL;
//Camera* CommandBase::camera = NULL;
ForkLifter* CommandBase::forklifter = NULL;
Elevator* CommandBase::PIDelevator = NULL;

CommandBase::CommandBase(char const *name): Command(name) {}

CommandBase::CommandBase(): Command() {}

void CommandBase::init()
{
	drivetrain = new DriveTrain();
	climber = new Climber();
	oi = new OI();
//	datalogger = new DataLogger();
	piston = new Piston();
//	camera = new Camera();
	utility = new Utility();
	forklifter = new ForkLifter();
	PIDelevator = new Elevator();
	grabbarms = new GrabbArms();
}
