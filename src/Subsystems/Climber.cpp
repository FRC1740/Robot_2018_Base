#include "Climber.h"
#include "../RobotMap.h"

#define FWD 1.0
#define REV -1.0

Climber::Climber() : Subsystem("Climber")
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
	//a->Set(FWD); FIXME two motors
	b->Set(FWD);
}

void Climber::Descend()
{
	//a->Set(REV); FIXME two motors
	b->Set(REV);
}

void Climber::Stop()
{
	//a->Set(0.0); FIXME two motors
	b->Set(0.0);
}
