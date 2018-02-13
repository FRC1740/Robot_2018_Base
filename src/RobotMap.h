/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// Pneumatic port configuration
#define CYLINDER_PORT_GRAB 0 // Grab/Release solenoid wired to port 0 on PCM
#define CYLINDER_PORT_DROP 1 // Grab/Release solenoid wired to port 1 on PCM

// Relays
#define GEAR_LIGHT_RELAY_PORT 0 // Testbed functionality check

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// Talon SRX CAN ID's
#define FRONT_LEFT_MOTOR_ID 3
#define FRONT_RIGHT_MOTOR_ID 4
#define REAR_LEFT_MOTOR_ID 1
#define REAR_RIGHT_MOTOR_ID 2

//#define LEFT_GRAB_MOTOR_ID 5
// #define RIGHT_GRAB_MOTOR_ID 6
#define CLIMBER_MOTOR_1_ID 5
#define CLIMBER_MOTOR_2_ID 6
#define POWERCUBE_LIFTER_MOTOR_ID 7

// Field Elements for PowerCube Lift
#define SWITCH_HEIGHT 18.75 // inches
#define SCALE_HEIGHT 84.0

// Encoder DIO Ports
#define FORKLIFT_MOTOR_ENCODER_CHANNEL_A 0
#define FORKLIFT_MOTOR_ENCODER_CHANNEL_B 1
#define CLIMBER_MOTOR_ENCODER_CHANNEL_A 2
#define CLIMBER_MOTOR_ENCODER_CHANNEL_B 3

// Ideally we have motor encoders on ALL drive wheels
// Wired directly to TALONS, not through RoboRio,
// since there are only 9 DIO ports on the Rio
#define REAR_LEFT_MOTOR_ENCODER_CHANNEL_A 4
#define REAR_LEFT_MOTOR_ENCODER_CHANNEL_B 5

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;
