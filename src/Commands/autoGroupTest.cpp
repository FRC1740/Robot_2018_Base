/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "autoGroupTest.h"
#include "autoNothing.h"
#include "autoTimedMove.h"
#include "ForkMoveToDistance.h"
#include "autoTurn.h"
#include "autoNothing.h"
#include "autoDriveDistance.h"
#include "Eject.h"
#include "ForkRaise.h"
#include "ForkLower.h"
#include <string>
#include <FieldMap.h>

autoGroupTest::autoGroupTest()
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
	std::string gameData;
	double mobility = SmartDashboard::GetNumber("Mobility", 1.0);

	// printf("Game Data: %c", gameData[0]);
	// printf("Game Data: %c", gameData[1]);
	//printf("Game Data: %c", gameData[2]);
	AddSequential(new autoNothing(.5));
	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	SmartDashboard::PutString("Game Data: ", gameData);
	if (gameData.length() > 0) // We received the plate configuration...
	{
		// Do near switch
		// AddParallel(new ForkMoveToDistance(SWITCH_HEIGHT));
		AddParallel (new ForkRaise(2.0)); // Was .25
		AddSequential(new autoDriveDistance(AUTO_LINE_DISTANCE));
		if (gameData[0] == side) // Is the near switch on our side?
		{
			AddSequential(new autoTurn(side));
			AddSequential(new autoDriveDistance(20.0)); // Guessing at 20 inches
			// AddSequential (new ForkLower(.25));
			// AddSequential (new autoNothing(2.0));
			// May need another AddSequential() to move forward to switch plate?
			AddSequential(new Eject());

		}
#if 0
		else if (gameData[1] == side) // Is the scale on our side?
		{
			// Do Scale
			AddParallel(new ForkMoveToDistance(SCALE_HEIGHT));
			// AddSequential(new autoTimedMove(mobility * 2));
			AddSequential(new autoDriveDistance(SCALE_DISTANCE));
			AddSequential(new autoTurn(side));
			// May need another AddSequential() to move forward to switch plate?
			AddSequential(new Eject());

		}
		else if (gameData[2] == side)
		{
			// Do far switch
			AddParallel(new ForkMoveToDistance(SWITCH_HEIGHT));
			//AddSequential(new autoTimedMove(mobility * 3));
			AddSequential(new autoDriveDistance(FAR_SWITCH_DISTANCE));
			AddSequential(new autoTurn(side));
			// May need another AddSequential() to move forward to switch plate?
			AddSequential(new Eject());
		}
		else // No plates on our side.
		{
			// Do mobility
			AddSequential(new autoTimedMove(AUTO_LINE_DISTANCE));
		}
#endif
	}
	else // No plate configuration received
	{
		// Do mobility
		AddSequential(new autoDriveDistance(AUTO_LINE_DISTANCE));
	}
	/* */
}

