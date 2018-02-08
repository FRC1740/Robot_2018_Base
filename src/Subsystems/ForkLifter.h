#ifndef ForkLifter_H
#define ForkLifter_H
#define FORK_DEADBAND 0.2
#define LIFTER_RATIO 1.0
#define FORK_SPEED 1.0
#include "../RobotMap.h"
#include <ctre/Phoenix.h>
#include <Commands/Subsystem.h>
#include <WPILib.h>

class ForkLifter : public Subsystem
{
private:

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_TalonSRX *lm;
	int EncoderValue;
	Encoder *enc;

public:
	ForkLifter();
	void InitDefaultCommand();
	void Raise(double);
	void Lower(double);
	void Stop();
	int ReadEncoder();
	double ApplyDeadband(double);




};

#endif  // ForkLifter_H
