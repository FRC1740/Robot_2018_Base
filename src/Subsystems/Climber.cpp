#include "Climber.h"

#define CLIMB -1.0
#define DESCEND -CLIMB

// Telescope
#define RETRACT 0.375
#define EXTEND -RETRACT



Climber::Climber() : frc::Subsystem("Climber")
{
	a = new WPI_TalonSRX(CLIMBER_MOTOR_1_ID); // Climber Motor 1
	b = new WPI_TalonSRX(CLIMBER_MOTOR_2_ID); // Climber Motor 2
	//enc = new Encoder(CLIMBER_MOTOR_ENCODER_CHANNEL_A, CLIMBER_MOTOR_ENCODER_CHANNEL_B);

	// a->Set(ControlMode::PercentOutput, 0);
	// b->Set(ControlMode::PercentOutput, 0);
	EncoderValue = 0;
	//enc->Reset();

}

void Climber::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Climber::Climb()
{
	//b->Set(CLIMB);
	a->Set(-CLIMB);
	//EncoderValue = enc->Get();
	//SmartDashboard::PutNumber("Climber Encoder: ", EncoderValue);
}

void Climber::Descend()
{
	//b->Set(DESCEND);
	a->Set(-DESCEND);
	//EncoderValue = enc->Get();
	//SmartDashboard::PutNumber("Climber Encoder: ", EncoderValue);
}

void Climber::StopClimb()
{
	a->Set(0.0);
	//b->Set(0.0);
}
void Climber::Extend()
{
	b->Set(EXTEND);
}
void Climber::Retract()
{
	b->Set(RETRACT);
}
void Climber::StopTelescope()
{
	b->Set(0.0);
}
int Climber::GetPosition()
{
	//return enc->Get();
}
