#ifndef Elevator_H
#define Elevator_H

#include <WPILib.h>
#include <Commands/PIDSubsystem.h>
#include <ctre/Phoenix.h>

#define TICS_PER_INCH 33

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
	void CancelPID();
	void Move(double);
	void Stop();
	void GroundFloor();
};

#endif  // Elevator_H
