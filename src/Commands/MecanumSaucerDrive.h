#ifndef MecanumSaucerDrive_H
#define MecanumSaucerDrive_H

#include <ADIS16448_IMU.h>
#include "../CommandBase.h"
#include "OI.h"

#define SCALE_TWIST 1.0 // Adjust these to suit drivers' preference
#define SCALE_YAXIS 1.0
#define SCALE_XAXIS 1.0
#define DEADBAND_XAXIS .1 // Adjust these to prevent unwanted movement when input at rest
#define DEADBAND_YAXIS .1
#define DEADBAND_TWIST .3

class MecanumSaucerDrive : public CommandBase {
private:
	ADIS16448_IMU *gyro;
	double gyro_angle;
public:
	MecanumSaucerDrive(ADIS16448_IMU *);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double GetX();
	double GetY();
	double GetInvertedY(); // Negative of GetY()
	double GetTwist();
};

#endif  // MecanumSaucerDrive_H
