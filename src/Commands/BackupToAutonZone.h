#ifndef BACKUPTOAUTONZONE_H
#define BACKUPTOAUTONZONE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class BackupToAutonZone: public Command {
	double startTime;
	double duration;
public:
	BackupToAutonZone();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

};

#endif
