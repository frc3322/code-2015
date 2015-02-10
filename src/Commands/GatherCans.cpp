#include "GatherCans.h"
#include "DriveForward.h"
#include "AlignWithStep.h"
#include "RotateWings.h"
#include "BackupToAutonZone.h"

GatherCans::GatherCans() {
	AddSequential(new DriveForward());
	AddSequential(new AlignWithStep());
<<<<<<< HEAD
	AddSequential(new RotateWings());	//TODO: figure out what angle to use
	AddSequential(new BackupToAutonZone());
=======
//	AddSequential(new RotateWings());
//	AddSequential(new BackupToAutonZone());
>>>>>>> origin/master
}
