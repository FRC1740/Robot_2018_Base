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
#include <Commands/PistonExtend.h>
#include <Commands/PistonRetract.h>
#include <Commands/ForkMoveToDistance.h>
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

	// Climb & Descend
	descendBtn->WhileHeld(new Descend);
	climbBtn->WhileHeld(new Climb);

	// Fork/Elevator Auto Move to Level
	xboxXBtn = new JoystickButton(xboxController, 3);
	xboxYBtn = new JoystickButton(xboxController, 4);

	//xboxXBtn->WhenPressed(new ForkMoveToDistance(SWITCH_HEIGHT));
	//xboxYBtn->WhenPressed(new ForkMoveToDistance(SCALE_HEIGHT));

	// PowerCube Grab & Release (pneumatic piston)
	lBumper = new JoystickButton(xboxController, 5);
	JoystickButton *PowercubeGrabBtn = lBumper;
	rBumper = new JoystickButton(xboxController, 6);
	JoystickButton *PowercubeReleaseBtn = rBumper;

	PowercubeGrabBtn->WhenPressed(new PistonExtend); // FIXME: May need to swap L/R buttons
	PowercubeReleaseBtn->WhenPressed(new PistonRetract); // FIXME: May need to swap L/R buttons

	// The Back Button is used to reset the gyro
	xboxBackBtn = new JoystickButton(xboxController, 7);
	xboxSetupBtn = new JoystickButton(xboxController, 8);
	JoystickButton *testLightBtn = xboxSetupBtn;

	// Green light from SteamWorks "Gear Ready"
	testLightBtn->WhileHeld(new GearLight(false)); // FIXME: boolean argument left over from linear actuator testing

	// ForkLift Raise & Lower utilize AXES 2 & 3 (Left & Right Triggers)

	// Initialize the Co-Driver's controller in USB slot 5
	//NESController = new Joystick(5); // FIXME: Add NES Controller inputs & commands

}
