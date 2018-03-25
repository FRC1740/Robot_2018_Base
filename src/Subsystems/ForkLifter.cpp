#include "ForkLifter.h"

ForkLifter::ForkLifter() : frc::Subsystem("ForkLifter")
{
	lm = new WPI_TalonSRX(POWERCUBE_LIFTER_MOTOR_ID); // Lifter motor
	enc = new Encoder(FORKLIFT_MOTOR_ENCODER_CHANNEL_A, FORKLIFT_MOTOR_ENCODER_CHANNEL_B);
	//enc->SetMaxPeriod(0.1);
	//enc->SetMinRate(10);
	//enc->SetDistancePerPulse(5);
	//enc->SetReverseDirection(true);
	//enc->SetSamplesToAverage(7);
	EncoderValue = 0;
	enc->Reset();
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
	lm->Set(ApplyDeadband(speed));
	EncoderValue = enc->Get();
	SmartDashboard::PutNumber("ForkLifter Encoder: ", EncoderValue);
}

void ForkLifter::Lower(double speed)
{
	lm->Set(ApplyDeadband(-speed));
	EncoderValue = enc->Get();
	SmartDashboard::PutNumber("ForkLifter Encoder: ", EncoderValue);
}

void ForkLifter::Stop()
{
	lm->Set(0.0);
}
int ForkLifter::ReadEncoder()
{
	return enc->Get();
}

double ForkLifter::ApplyDeadband(double TrgAmnt)
{
	if (TrgAmnt > FORK_DEADBAND)
	{
		return TrgAmnt;
	}
	else if (TrgAmnt < -FORK_DEADBAND)
	{
		return TrgAmnt;
	}
	else
	{
		return 0.0;
	}
}
