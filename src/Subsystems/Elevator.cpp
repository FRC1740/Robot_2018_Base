#include "Elevator.h"

#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>

#include "../RobotMap.h"

Elevator::Elevator() : PIDSubsystem("Elevator", 1.0, 0.0, 0.0)
{
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	GetPIDController()->SetContinuous(false);
	enc = new Encoder(0,1);
	elevatorMotor = new WPI_TalonSRX(9);
}

double Elevator::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	return (double)enc->Get();
}

void Elevator::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	elevatorMotor->PIDWrite(output);
}

void Elevator::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Elevator::GotoPosition(double position)
{
	SetSetpoint(position);
	Enable();
}
