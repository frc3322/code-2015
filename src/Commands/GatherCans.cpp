#include "GatherCans.h"
#include "DriveForward.h"
#include "AlignWithStep.h"
#include "RotateWings.h"
#include "BackupToAutonZone.h"
#include "AutonJerky.h"

GatherCans::GatherCans() {
	Robot::eagleWings->wingRotater->Set(0);
	AddSequential(new DriveForward());
//	AddSequential(new AlignWithStep());
	AddSequential(new RotateWings(SmartDashboard::GetNumber("gatherCansRotateSpeed"),SmartDashboard::GetNumber("gatherCanseRotateDuration")));
	//AddSequential(new AutonJerky());
	AddSequential(new BackupToAutonZone());
//	AddSequential(new RotateWings(-.2,.4));
}
