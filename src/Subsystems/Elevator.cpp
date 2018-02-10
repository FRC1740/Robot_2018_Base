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
	enc = new Encoder(FORKLIFT_MOTOR_ENCODER_CHANNEL_A, FORKLIFT_MOTOR_ENCODER_CHANNEL_B);
	elevatorMotor = new WPI_TalonSRX(9);
}

double Elevator::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	double current = (double)enc->Get();
	SmartDashboard::PutNumber("Powercube Height", current/TICS_PER_INCH);
	return (double)current;
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
	SetSetpoint(position * TICS_PER_INCH);
	Enable();
}

int Elevator::GetEncoder()
{
	return enc->Get();
}

void Elevator::CancelPID()
{
	Disable();
}

void Elevator::Move(double speed)
{
	Disable();
	elevatorMotor->Set(speed);
}
void Elevator::Stop()
{
	elevatorMotor->StopMotor();
}
void Elevator::GroundFloor()
{
	this->GotoPosition(0.0);
}
