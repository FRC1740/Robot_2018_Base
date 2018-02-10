/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#pragma once

#include <WPILib.h>

class OI {
public:
	OI();
	// Driver - XBoxController
	Joystick *xboxController;

	// Forklift Raise & Lower
	JoystickButton *xboxABtn; // Button 1
	JoystickButton *xboxBBtn; // Button 2

	// Left & Right Grabber Motors
	JoystickButton *lBumper; // Button 5
	JoystickButton *rBumper; // Button 6

	// Eject PowerCube
	JoystickButton *xboxXBtn; // Button 3

	// Toggle Pneumatic Piston
	JoystickButton *xboxYBtn; // Button 4

	// Linear Actuator
	JoystickButton *xboxBackBtn; // Button 7
	JoystickButton *xboxSetupBtn; // Button 8

	// Co-Driver - NES Controller
	Joystick *NESController;

	// FIXME: Define the three buttons on the NESController for forklift levels
};
