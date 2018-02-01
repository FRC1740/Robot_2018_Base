#include "GearLight.h"

GearLight::GearLight(bool direction) {
	// Use Requires() here to declare subsystem dependencies
	Requires(utility);
	retract = direction; // true for retract, false for extend
}

// Called just before this Command runs the first time
void GearLight::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void GearLight::Execute()
{
	// "Gear Light" was for testing purposes. This is simply a relay on the bot.
	// utility->gearLightOn();
	if (retract)
		utility->linearRetract();
	else
		utility->linearExtend();

	SmartDashboard::PutNumber("Linear Actuator Voltage: ", utility->linearGetPosition());
}

// Make this return true when this Command no longer needs to run execute()
bool GearLight::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void GearLight::End()
{
	utility->gearLightOff(); // Turn the relay off (regardless of what's connected)
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GearLight::Interrupted()
{
	utility->gearLightOff(); // Turn the relay off (regardless of what's connected)
}
