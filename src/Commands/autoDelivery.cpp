/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "autoDelivery.h"
#include "autoNothing.h"
#include "autoTimedMove.h"
#include "autoTurn.h"
#include "ForkMoveToDistance.h"

autoDelivery::autoDelivery()
{
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
	AddSequential(new autoTimedMove(2.0));
	// AddParallel(new ForkMoveToDistance(100));
	AddSequential(new autoTurn('L'));
	AddSequential(new autoTimedMove(1.0));
}
#if 0
#include "autoDelivery.h"
/* */
#include "ForkMoveToDistance.h"
#include "autoTimedMove.h"
#include "autoTurn.h"
#include "autoNothing.h"
#include "Eject.h"
#include <string>
/* */
autoDelivery::autoDelivery()
{
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
	char side = 'L';
	std::string gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	double mobility = SmartDashboard::GetNumber("Mobility", 1.0);

	printf("Game Data: %c", gameData[0]);
	printf("Game Data: %c", gameData[1]);
	printf("Game Data: %c", gameData[2]);

	if (gameData.length() > 0) // We received the plate configuration...
	{

		if (gameData[0] == side) // Is the near switch on our side?
		{
			// Do near switch
			AddParallel(new ForkMoveToDistance(SWITCH_HEIGHT));
			AddSequential(new autoTimedMove(mobility));
			AddSequential(new autoTurn(side));
			// May need another AddSequential() to move forward to swtich plate?
			AddSequential(new Eject());
		}
		else if (gameData[1] == side) // Is the scale on our side?
		{
			// Do Scale
			AddParallel(new ForkMoveToDistance(SCALE_HEIGHT));
			AddSequential(new autoTimedMove(mobility * 2));
			AddSequential(new autoTurn(side));
			// May need another AddSequential() to move forward to swtich plate?
			AddSequential(new Eject());
		}
		else if (gameData[0] == side)
		{
			// Do far switch
			AddParallel(new ForkMoveToDistance(SWITCH_HEIGHT));
			AddSequential(new autoTimedMove(mobility * 3));
			AddSequential(new autoTurn(side));
			// May need another AddSequential() to move forward to swtich plate?
			AddSequential(new Eject());
		}
		else // No plates on our side.
		{
			// Do mobility
			AddSequential(new autoTimedMove(mobility));
		}
	}
	else // No plate configuration received
	{
		// Do mobility
		AddSequential(new autoTimedMove(mobility));
	}
	/* */
}
#endif
