#ifndef ForkMoveToDistance_H
#define ForkMoveToDistance_H
#define FORK_DISTANCE_DEADBAND 0.5
#define TICS_PER_INCH 33.0 //Number of encoder tics for one inch of travel
#define FORK_LEVEL_1 0
#define FORK_LEVEL_2 200
#define FORK_LEVEL_3 400
#define FORK_LEVEL_4 600
#include "../CommandBase.h"

class ForkMoveToDistance : public CommandBase {
private:
	int target;

public:
	ForkMoveToDistance(double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ForkMoveToDistance_H
