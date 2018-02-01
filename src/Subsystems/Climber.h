#ifndef Climber_H
#define Climber_H

#include "../RobotMap.h"
#include <ctre/Phoenix.h>
#include <Commands/Subsystem.h>
#include <WPILib.h>

class Climber : public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	//WPI_TalonSRX *a; // Climber Motor 1 FIXME two motors
	WPI_TalonSRX *b; // Climber Motor 2

public:
	Climber();
	void InitDefaultCommand();
	void Climb();
	void Descend();
	void Stop();
};

#endif  // Climber_H
