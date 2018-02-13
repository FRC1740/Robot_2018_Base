#include "autoNearSwitch.h"
#include "ForkMoveToDistance.h"
#include "autoTimedMove.h"
#include "autoTurn.h"

autoNearSwitch::autoNearSwitch(char side) {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	std::string gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	double mobility = SmartDashboard::GetNumber("Mobility", 2.0);

	AddSequential(new autoTimedMove(mobility));
	AddSequential(new autoTurn('L'));
	/*
	if (gameData[0] == side)
	{
		// Do near switch
		AddSequential(new autoTimedMove(mobility)); // FIXME: Change to correct timing
		//AddParallel(new ForkMoveToDistance(SWITCH_HEIGHT));
		AddSequential(new autoTurn('L'));
		// AddSequential(new Eject());
	}
	else if (gameData[1] == side)
	{
		// Do Scale
		AddSequential(new autoTimedMove(mobility * 2)); // FIXME: Change to correct timing
		//AddParallel(new ForkMoveToDistance(SCALE_HEIGHT));
		AddSequential(new autoTurn(side));
		// AddSequential(new Eject());
	}
	else if (gameData[2] == side)
	{
		// Do far switch
		AddSequential(new autoTimedMove(mobility * 3)); // FIXME: Change to correct timing
		//AddParallel(new ForkMoveToDistance(SWITCH_HEIGHT));
		AddSequential(new autoTurn(side));
		// AddSequential(new Eject());
	}
	else
	{
		// Do mobility
		AddSequential(new autoTimedMove(mobility)); // FIXME: Change to correct timing
	}
	*/

}
