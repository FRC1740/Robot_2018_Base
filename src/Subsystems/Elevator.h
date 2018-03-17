#ifndef Elevator_H
#define Elevator_H

#include <WPILib.h>
#include <Commands/PIDSubsystem.h>
#include <ctre/Phoenix.h>

class Elevator : public PIDSubsystem {
private:
	WPI_TalonSRX *elevatorMotor;
	Encoder *enc;

public:
	Elevator();
	double ReturnPIDInput();
	void UsePIDOutput(double);
	void InitDefaultCommand();
	void GotoPosition(double);
	int GetEncoder();
};

#endif  // Elevator_H
