#ifndef TANKDRIVE_H
#define TANKDRIVE_H

#include "../CommandBase.h"
#include "OI.h"

class TankDrive : public CommandBase
{
public:
	TankDrive();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
	double GetLeftStickY(bool);
	double GetRightStickY(bool);
};
#endif
