#include "ForkLifter.h"
#include "../RobotMap.h"



ForkLifter::ForkLifter() : frc::Subsystem("ForkLifter")
{
	lm = new WPI_TalonSRX(POWERCUBE_LIFTER_ID); // Lifter motor
	enc = new Encoder(0, 1, false, Encoder::EncodingType::k4X);
	enc->SetMaxPeriod(0.1);
	enc->SetMinRate(10);
	enc->SetDistancePerPulse(5);
	enc->SetReverseDirection(true);
	enc->SetSamplesToAverage(7);
}

void ForkLifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void ForkLifter::Raise(double speed)
{
	lm->Set(speed);


}

void ForkLifter::Lower(double speed)
{

	lm->Set(-speed);
}

void ForkLifter::Stop()
{

	lm->Set(0.0);
}
int ForkLifter::ReadEncoder()
{
	enc->Get();
}
