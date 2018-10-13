#ifndef ForkRaise_H
#define ForkRaise_H
#define TRIGGER_DEADBAND 0.2
#include "../CommandBase.h"

class ForkMove : public CommandBase
{
public:
	ForkMove();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double GetRightTrig();
	double GetLeftTrig();
	void GoToGround();
	};

#endif  // ForkRaise_H
