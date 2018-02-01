#include "Climber.h"

#define CLIMB 1.0
#define DESCEND -1.0

Climber::Climber() : frc::Subsystem("Climber")
{
	//a = new WPI_TalonSRX(CLIMBER_MOTOR_1_ID); // Climber Motor a FIXME restore when have two motors
	b = new WPI_TalonSRX(CLIMBER_MOTOR_2_ID); // Climber Motor 2
	b->SetInverted(true);

	//a->Set(ControlMode::PercentOutput, 0); FIXME rtwo motors
	b->Set(ControlMode::PercentOutput, 0);
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
	//a->Set(CLIMB); FIXME two motors
	b->Set(CLIMB);
}

void Climber::Descend()
{
	//a->Set(DESCEND); FIXME two motors
	b->Set(DESCEND);
}

void Climber::Stop()
{
	//a->Set(0.0); FIXME two motors
	b->Set(0.0);
}
