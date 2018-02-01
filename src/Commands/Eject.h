#ifndef Eject_H
#define Eject_H

#include "../CommandBase.h"

class Eject : public CommandBase {
public:
	Eject();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Eject_H
