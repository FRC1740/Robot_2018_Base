#ifndef _Retract_H
#define _Retract_H

#include "../CommandBase.h"

class Retract : public CommandBase {
public:
	Retract();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif
