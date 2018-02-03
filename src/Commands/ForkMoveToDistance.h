#ifndef ForkMoveToDistance_H
#define ForkMoveToDistance_H
#define FORK_DISTANCE_DEADBAND 0.5
#define TICS_PER_INCH 33
#define FORK_LEVEL_1 0
#define FORK_LEVEL_2 200
#define FORK_LEVEL_3 400
#define FORK_LEVEL_4 600
#include "../CommandBase.h"

class ForkMoveToDistance : public CommandBase {
private:
	int Target;

public:
	ForkMoveToDistance(int);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ForkMoveToDistance_H
