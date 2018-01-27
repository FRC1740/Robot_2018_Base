#ifndef ForkLifter_H
#define ForkLifter_H

#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include "WPILib.h"

class ForkLifter : public Subsystem
{
private:

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_TalonSRX *lm;
	Encoder *enc;

public:
	ForkLifter();
	void InitDefaultCommand();
	void Raise(double);
	void Lower(double);
	void Stop();
	int ReadEncoder();

};

#endif  // ForkLifter_H
