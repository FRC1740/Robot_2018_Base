#ifndef autoTimedMove_H
#define autoTimedMove_H

#include "../CommandBase.h"

class autoTimedMove : public CommandBase {
private:
	double timer;
public:
	autoTimedMove(double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // autoTimedMove_H
