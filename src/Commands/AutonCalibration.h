// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef AUTONCALIBRATION_H
#define AUTONCALIBRATION_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
#include <stdio.h>
#define NUM_SAMPLES 20
class AutonCalibration: public Command {
public:
	AutonCalibration();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	float leftSum;
	float rightSum;
	unsigned int currentSample;
};

#endif
