/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Buttons/JoystickButton.h>
#include <Joystick.h>
#include <OI.h>
#include <Commands/Eject.h>
#include <Commands/GearLight.h>
#include <Commands/GrabLeft.h>
#include <Commands/GrabRight.h>
#include <Commands/PistonExtend.h>
#include <Commands/PistonRetract.h>
#include <Commands/Climb.h>
#include <Commands/Descend.h>

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
	// gearLightBtn = new JoystickButton(xboxController, 9); // Left Stick
	// gearLightBtn->WhileHeld(new GearLight);

	// xBox Button Mapping
	xboxBBtn = new JoystickButton(xboxController, 1);
	xboxABtn = new JoystickButton(xboxController, 2);
	JoystickButton *climbBtn = xboxABtn;
	JoystickButton *descendBtn = xboxBBtn;

	xboxXBtn = new JoystickButton(xboxController, 3);
	JoystickButton *eject = xboxXBtn;

	xboxYBtn = new JoystickButton(xboxController, 4);
	JoystickButton *pistonBtn = xboxYBtn;

	lBumper = new JoystickButton(xboxController, 5);
<<<<<<< HEAD
	JoystickButton *grabLBtn = lBumper;
	rBumper = new JoystickButton(xboxController, 6);
	JoystickButton *grabRBtn = rBumper;

	xboxBackBtn = new JoystickButton(xboxController, 7);
	JoystickButton *linearExtendBtn = xboxBackBtn;

	xboxSetupBtn = new JoystickButton(xboxController, 8);
	JoystickButton *linearRetractBtn = xboxSetupBtn;

=======
	//lBumper->WhileHeld(new GrabLeft); // FIXME: replace WhileHeld(new GrabLeft) command
	rBumper = new JoystickButton(xboxController, 6);
	//rBumper->WhileHeld(new GrabRight); // FIXME: replace with WhenHeld(new GrabRight) command

	// PowerCube Eject
	xboxXBtn = new JoystickButton(xboxController, 3);
	//xboxXBtn->WhileHeld(new Eject); // FIXME: Replace with WhileHeld(new Eject) command
>>>>>>> 1b5c6ee682d43a7b976bd49d7dd07efb073d4ad0

	// Climb & Descend
	descendBtn->WhileHeld(new Descend);
	climbBtn->WhileHeld(new Climb);

	// PowerCube Eject
	eject->WhileHeld(new Eject);

	// Piston Extend & Retract is a "Y-Toggle"
	pistonBtn->WhenPressed(new PistonExtend); // FIXME: Rename class? actually toggles extend/retract

	// PowerCube Grab
	grabLBtn->WhileHeld(new GrabLeft);
	grabRBtn->WhileHeld(new GrabRight);

	// Linear Actuator Extend & Retract (Manual) Back/Setup buttons
	linearExtendBtn->WhileHeld(new GearLight(false));
	linearRetractBtn->WhileHeld(new GearLight(true));

	// ForkLift Raise & Lower utilize AXES 2 & 3 (Left & Right Triggers)

	// Initialize the Co-Driver's controller in USB slot 5
	// NESController = new Joystick(5); // FIXME: Add NES Controller inputs & commands

}
