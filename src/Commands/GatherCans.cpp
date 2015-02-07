#include "GatherCans.h"
#include "DriveForward.h"
#include "AlignWithStep.h"
#include "RotateWings.h"
#include "BackupToAutonZone.h"

GatherCans::GatherCans() {
	AddSequential(new DriveForward());
	AddSequential(new AlignWithStep());
	AddSequential(new RotateWings(90.0));	//TODO: figure out what angle to use
	AddSequential(new BackupToAutonZone());
}
