/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Buttons/JoystickButton.h>
#include <Joystick.h>
#include <OI.h>
// #include <Commands/Eject.h> // FIXME: No longer using grab motors
#include <Commands/GearLight.h>
// #include <Commands/GrabLeft.h> // FIXME: No longer using grab motors
// #include <Commands/GrabRight.h> // FIXME: No longer using grab motors
#include <Commands/PistonExtend.h> // FIXME: PistonExtend is actually a toggle
#include <Commands/ForkMoveToDistance.h>
#include <Commands/PistonExtend.h> // FIXME: PistonExtend is actually a toggle
#include <Commands/Climb.h>
#include <Commands/Descend.h>

/* ****
 *
 * 	xBox Controller button mapping:
 * 	Button 1 - A - Descend
 * 	Button 2 - B - Climb
 * 	Button 3 - X - unused
 * 	Button 4 - Y - Pneumatic toggle
 * 	Button 5 - Left Bumper - unused
 * 	Button 6 - Right Bumper - unused
 * 	Button 7 - Back - Reset Gyro
 * 	Button 8 - Start - Test Light
 * 	Button 9 - Left Stick - unused
 * 	Button 10 - Right Stick - unused
 */
OI::OI() {
	// Process operator interface input here.

	// Driver Station USB slot 4: Xbox controller
	xboxController = new Joystick(4);

	// xBox Button Mapping
	xboxABtn = new JoystickButton(xboxController, 1);
	xboxBBtn = new JoystickButton(xboxController, 2);
	JoystickButton *climbBtn = xboxBBtn;
	JoystickButton *descendBtn = xboxABtn;

	xboxXBtn = new JoystickButton(xboxController, 3);
	//JoystickButton *eject = xboxXBtn;

	xboxYBtn = new JoystickButton(xboxController, 4);
	JoystickButton *pistonBtn = xboxYBtn;

	lBumper = new JoystickButton(xboxController, 5);
	// JoystickButton *grabLBtn = lBumper;
	rBumper = new JoystickButton(xboxController, 6);
	//JoystickButton *grabRBtn = rBumper;

	lBumper->WhenPressed(new ForkMoveToDistance(6.0));
	rBumper->WhenPressed(new ForkMoveToDistance(100.0));

	// The Back Button is used to reset the gyro
	xboxBackBtn = new JoystickButton(xboxController, 7);
	xboxSetupBtn = new JoystickButton(xboxController, 8);
	JoystickButton *testLightBtn = xboxSetupBtn;

	// Climb & Descend
	descendBtn->WhileHeld(new Descend);
	climbBtn->WhileHeld(new Climb);

	// PowerCube Eject FIXME: No more grab/eject motors
	// eject->WhileHeld(new Eject); // FIXME: No more grab/eject motors

	// Piston Extend & Retract is a "Y-Toggle"
	pistonBtn->WhenPressed(new PistonExtend); // FIXME: Rename class? actually toggles extend/retract

	// Green light from SteamWorks "Gear Ready"
	testLightBtn->WhileHeld(new GearLight(false)); // FIXME: boolean argument left over from linear actuator testing

	// PowerCube Grab FIXME: No more grab/eject motors
	// grabLBtn->WhileHeld(new GrabLeft); FIXME: No more grab/eject motors
	// grabRBtn->WhileHeld(new GrabRight); FIXME: No more grab/eject motors

	// Linear Actuator Extend & Retract (Manual) Back/Setup buttons
	//linearExtendBtn->WhileHeld(new GearLight(false));
	//linearRetractBtn->WhileHeld(new GearLight(true));

	// ForkLift Raise & Lower utilize AXES 2 & 3 (Left & Right Triggers)

	// Initialize the Co-Driver's controller in USB slot 5
	NESController = new Joystick(5); // FIXME: Add NES Controller inputs & commands

}
