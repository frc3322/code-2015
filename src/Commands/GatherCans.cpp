#include "GatherCans.h"
#include "DriveForward.h"
#include "AlignWithStep.h"
#include "RotateWings.h"
#include "BackupToAutonZone.h"

GatherCans::GatherCans() {
	AddSequential(new DriveForward());
	AddSequential(new AlignWithStep());
	AddSequential(new RotateWings(RotateWings::FORWARD));
	AddSequential(new BackupToAutonZone());
//	AddSequential(new RotateWings());
}
