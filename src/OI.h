/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#pragma once

#include <WPILIB.h>

class OI {
public:
	OI();
	// Driver - XBoxController
	Joystick *xboxController;

	// Map buttons for turning in gear light
	JoystickButton *gearLightBtn;

	// Pneumatic piston
	JoystickButton *extendBtn;
	JoystickButton *retractBtn;

	// Climb & Descend are Triggers (axes 2 & 3)

	// Forklift Raise & Lower
	JoystickButton *xboxABtn;
	JoystickButton *xboxBBtn;

	// Left & Right Grabber Motors
	JoystickButton *lBumper;
	JoystickButton *rBumper;
	JoystickButton *xboxXBtn;
	JoystickButton *xboxYBtn;
	JoystickButton *xboxBackBtn;

	// Co-Driver - NES Controller
	Joystick *NESController;

	// FIXME: Define the three buttons on the NESController for forklift levels
};
