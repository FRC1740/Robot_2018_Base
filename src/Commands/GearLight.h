#ifndef GearLight_H
#define GearLight_H

#include "../CommandBase.h"
#include <WPILib.h>

class GearLight : public CommandBase {
public:
	GearLight(bool);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	bool retract;
};

#endif  // GearLight_H
