#ifndef autoNothing_H
#define autoNothing_H

#include "../CommandBase.h"

class autoNothing : public CommandBase {
private:
	double timer;
public:
	autoNothing(double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // autoNothing_H
