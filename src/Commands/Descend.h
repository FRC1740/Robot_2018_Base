#ifndef Descend_H
#define Descend_H

#include "../CommandBase.h"

class Descend : public CommandBase {
public:
	Descend();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Descend_H
