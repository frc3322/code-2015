/*
 * RunLift.h
 *
 *  Created on: Feb 15, 2015
 *      Author: Miles
 */
#ifndef RUNLIFT_H
#define RUNLIFT_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class RunLift: public Command {
public:
	RunLift(float direction);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	float direction;
};

#endif
