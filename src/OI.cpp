/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <Commands/GearLight.h>
#include <Commands/PistonExtend.h>
#include <Commands/PistonRetract.h>
#include <Commands/Climb.h>
#include <Commands/Descend.h>
#include <Commands/GrabLeft.h>
#include <Commands/GrabRight.h>
#include <Commands/Eject.h>

/* ****
 *
 * 	xBox Controller button mapping:
 * 	Button 1 - A - Descend
 * 	Button 2 - B - Climb
 * 	Button 3 - X - Eject
 * 	Button 4 - Y - Gyro Reset
 * 	Button 5 - Left Bumper - Grab Left
 * 	Button 6 - Right Bumper - Grab Right
 * 	Button 7 - Back - Piston
 * 	Button 8 - Start - Piston
 * 	Button 9 - Left Stick
 * 	Button 10 - Right Stick
 */
OI::OI() {
	// Process operator interface input here.

	// Driver Station USB slot 4: Xbox controller
	xboxController = new Joystick(4);
	// Green light from SteamWorks "Gear Ready"
	gearLightBtn = new JoystickButton(xboxController, 9); // Left Stick
	gearLightBtn->WhileHeld(new GearLight);

	// Piston Extend & Retract buttons
	extendBtn = new JoystickButton(xboxController, 7);
	extendBtn->WhenPressed(new PistonExtend);
	retractBtn = new JoystickButton(xboxController, 8);
	retractBtn->WhenPressed(new PistonRetract);

	// PowerCube Grab
	lBumper = new JoystickButton(xboxController, 5);
	lBumper->WhileHeld(new GrabLeft); // FIXME: replace WhileHeld(new GrabLeft) command
	rBumper = new JoystickButton(xboxController, 6);
	rBumper->WhileHeld(new GrabRight); // FIXME: replace with WhenHeld(new GrabRight) command

	// PowerCube Eject
	xboxXBtn = new JoystickButton(xboxController, 3);
	xboxXBtn->WhileHeld(new Eject); // FIXME: Replace with WhileHeld(new Eject) command

	// Climb & Descend
	xboxABtn = new JoystickButton(xboxController, 2);
	xboxABtn->WhileHeld(new Climb); // FIXME: replace with WhileHeld(new Climb) command
	xboxBBtn = new JoystickButton(xboxController, 1);
	xboxBBtn->WhileHeld(new Descend); // FIXME: replace with WhileHeld(new Descend) command

	xboxYBtn = new JoystickButton(xboxController, 4);

	// ForkLift Raise & Lower utilize AXES 2 & 3 (Left & Right Triggers)

	// Initialize the Co-Driver's controller in USB slot 5
	NESController = new Joystick(5);

}
