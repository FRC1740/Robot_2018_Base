#ifndef Elevator_H
#define Elevator_H

#include <WPILib.h>
#include <Commands/PIDSubsystem.h>
#include <ctre/Phoenix.h>
#define SPROCKET_DIAMETER 2.58
#define INCHES_PER_REVOLUTION (M_PI * SPROCKET_DIAMETER) // About 8
#define TICKS_PER_REVOLUTION 525  // Should be 7 ticks per rev * 75:1 = 525
//#define TICKS_PER_INCH TICKS_PER_REVOLUTION * M_1_PI * (1/SPROCKET_DIAMETER) // BLYME!!!

#define TICKS_PER_INCH 21.875

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
	void Hold();
	void GroundFloor();
	void PIDReset();
	double lastSetPoint;
};

#endif  // Elevator_H
