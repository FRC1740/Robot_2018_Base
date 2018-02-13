#include "Elevator.h"

#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>

#include "../RobotMap.h"

/*
 * The elevator system is driven by a PG71 Gearmotor http://www.andymark.com/product-p/am-3655.htm
 * The PG71 encoder provides seven ?? pulses per revolution.
 * The output shaft is connected to a driver sprocket with a 2.58 in diameter
 * The distance of one revolution is therfore approximately 8.1 inches.
 */
// Tried .36, 1.44, .0225
// PID Testing: kC = .08 Pc = .5
// kP = .6 * kC
// kI = 2*kP/Pc
// kD = .125 * kP * Pc

Elevator::Elevator() : PIDSubsystem("Elevator", .048, 0.192, 0.006)
{
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	GetPIDController()->SetContinuous(false);
	enc = new Encoder(FORKLIFT_MOTOR_ENCODER_CHANNEL_A, FORKLIFT_MOTOR_ENCODER_CHANNEL_B);
	elevatorMotor = new WPI_TalonSRX(POWERCUBE_LIFTER_MOTOR_ID);
	enc->Reset();
	lastSetPoint = 0.0;
}

double Elevator::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	double current = (double)enc->Get();
	SmartDashboard::PutNumber("Ticks Per Inch: ", TICKS_PER_INCH);
	SmartDashboard::PutNumber("Inches Per Revolution: ", INCHES_PER_REVOLUTION);
	SmartDashboard::PutNumber("Powercube Encoder", current);
	SmartDashboard::PutNumber("Powercube Height", current/TICKS_PER_INCH);
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
	SetSetpoint(position * TICKS_PER_INCH);
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
	elevatorMotor->Set(speed);
	lastSetPoint = (double)enc->Get() * TICKS_PER_INCH;
	SetSetpoint((double)enc->Get());
}
void Elevator::Stop()
{
	elevatorMotor->StopMotor();
}
void Elevator::Hold()
{
	SetSetpoint(lastSetPoint);
	Enable();
}
void Elevator::GroundFloor()
{
	this->GotoPosition(0.0);
	lastSetPoint = 0.0;
}
void Elevator::PIDReset()
{
	Disable();
	enc->Reset();
	lastSetPoint = 0.0;
}
