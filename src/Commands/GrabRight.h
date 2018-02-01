#ifndef GrabRight_H
#define GrabRight_H

#include "../CommandBase.h"

class GrabRight : public CommandBase {
public:
	GrabRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GrabRight_H
