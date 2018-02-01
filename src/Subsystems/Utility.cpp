#include "Utility.h"
#include "../RobotMap.h"

Utility::Utility(): Subsystem("Utility")
{
	// utility_motor = new TalonSRX(UTILITY_MOTOR_PORT);
	gearLight = new frc::Relay(GEAR_LIGHT_RELAY_PORT);
	actuator = new AnalogInput(0);
}

void Utility::gearLightOn()
{
	gearLight->Set(frc::Relay::kForward);
}

void Utility::gearLightOff()
{
	gearLight->Set(frc::Relay::kOff);
}
void Utility::linearExtend()
{
	gearLight->Set(frc::Relay::kForward);

}
void Utility::linearRetract()
{
	gearLight->Set(frc::Relay::kReverse);

}
double Utility::linearGetPosition()
{
	return actuator->GetAverageVoltage();
}
void Utility::linearGoTo(double distance)
{
	// FIXME: Need feedback from Analog Input to control linear actuator
}
/* */
