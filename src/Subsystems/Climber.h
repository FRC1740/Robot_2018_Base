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
	WPI_TalonSRX *a; // Climber Motor 1
	WPI_TalonSRX *b; // Climber Motor 2
	Encoder *enc;
	int EncoderValue;

public:
	Climber();
	void InitDefaultCommand();
	void Climb();
	void Descend();
	void Stop();
	int GetPosition();
};

#endif  // Climber_H
