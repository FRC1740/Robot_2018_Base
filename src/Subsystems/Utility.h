#ifndef Utility_H
#define Utility_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Utility: public Subsystem
{
public:
	Relay *gearLight;  // light to indicate gear is ready to remove
	AnalogInput *actuator;
	Utility();
	void gearLightOn(); // Turn on the gear Light
	void gearLightOff(); // Turn off the gear Light
	void linearExtend(); // Extend the Linear Actuator
	void linearRetract(); // Extend the Linear Actuator
	double linearGetPosition(); // retrieve position of linear actuator
	void linearGoTo(double); // Extend to a specific distance
};

#endif
