#ifndef autoTurn_H
#define autoTurn_H

#include "../CommandBase.h"

#define TURN_RATE .3 // FIXME: Based on limited testing
#define TURN_DEADBAND 2.0 // degrees: close enough?
#define NINETY_DEGREES 88.0 // Prevent overshooting

class autoTurn : public CommandBase
{
private:
	double angle;
	double turn_rate;
public:
	autoTurn(char);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // autoTurn_H
