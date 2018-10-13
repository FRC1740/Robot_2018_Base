#ifndef ForkMoveToDistance_H
#define ForkMoveToDistance_H
#include "../CommandBase.h"

class ForkMoveToDistance : public CommandBase {
private:
	double target;

public:
	ForkMoveToDistance(double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ForkMoveToDistance_H
