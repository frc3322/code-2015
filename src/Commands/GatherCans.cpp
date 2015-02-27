#include "GatherCans.h"
#include "DriveForward.h"
#include "AlignWithStep.h"
#include "RotateWings.h"
#include "BackupToAutonZone.h"
#include "AutonJerky.h"
#include "timedDrive.h"

GatherCans::GatherCans() {
	int autonNumber = 1;//SmartDashboard::GetNumber("autonNumber");
	switch(autonNumber){
		case 2:
			auton2();
			break;
		case 3:
			auton3();
			break;
		default:
			auton1();
			break;
	}
}

void GatherCans::auton1(){
	Robot::eagleWings->wingRotater->Set(0);
	AddSequential(new DriveForward());
//	AddSequential(new AlignWithStep());
	AddSequential(new RotateWings(0.2,2));
	//AddSequential(new AutonJerky());
	AddSequential(new BackupToAutonZone());
//	AddSequential(new RotateWings(-.2,.4));
}
void GatherCans::auton2(){
	//drive forward
	double duration = 2;
	double speed = .3;
	AddSequential(new timedDrive(duration, speed));
}
void GatherCans::auton3(){
	//do nothing....
}
