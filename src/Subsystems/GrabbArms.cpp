#include "../RobotMap.h"
#include "GrabbArms.h"
#define OUT 1.0 //FIXME direction of motors
#define IN -1.0

GrabbArms::GrabbArms() : frc::Subsystem("GrabbArms")
{
	larm = new WPI_TalonSRX(LEFT_GRAB_MOTOR_ID); // left arm
	//rarm = new WPI_TalonSRX(RIGHT_GRAB_MOTOR_ID); // right arm
	//rarm->SetInverted(true);
}

void GrabbArms::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void GrabbArms::RightIn()
{
	//rarm->Set(IN);

}

void GrabbArms::RightStop()
{
	//rarm->Set(0.0);

}

void GrabbArms::LeftIn()
{
	larm->Set(IN);

}

void GrabbArms::LeftStop()
{
	larm->Set(0.0);

}

void GrabbArms::Eject()
{
	larm->Set(OUT);
	//rarm->Set(OUT);

}

void GrabbArms::AllStop()
{
	larm->Set(0.0);
	//rarm->Set(0.0);
}

