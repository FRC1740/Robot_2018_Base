/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef autoDriveDistance_H
#define autoDriveDistance_H

#include "../CommandBase.h"

class autoDriveDistance : public CommandBase
{
public:
	autoDriveDistance(double); // target distance in inches
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
	long m_target_count;
	double m_steering_angle;
};

#endif
