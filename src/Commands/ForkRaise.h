#ifndef ForkRaise_H
#define ForkRaise_H

#include "../CommandBase.h"

class ForkRaise : public CommandBase {
private:
	double m_timer;
public:
	ForkRaise(double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ForkRaise_H
