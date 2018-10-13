#ifndef _Extend_H
#define _Extend_H

#include "../CommandBase.h"

class Extend : public CommandBase {
public:
	Extend();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif
