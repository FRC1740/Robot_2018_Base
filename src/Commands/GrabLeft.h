#ifndef GrabLeft_H
#define GrabLeft_H

#include "../CommandBase.h"

class GrabLeft : public CommandBase {
public:
	GrabLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GrabLeft_H
