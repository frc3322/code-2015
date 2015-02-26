#include "GatherCans.h"
#include "DriveForward.h"
#include "AlignWithStep.h"
#include "RotateWings.h"
#include "BackupToAutonZone.h"
#include "AutonJerky.h"
#include "timedDrive.h"

GatherCans::GatherCans() {
	int autonNumber = SmartDashboard::GetNumber("autonNumber");
	auton1();
//	switch(autonNumber){
//	case 1:{
//		auton1();
//	}
//	case 2:{
//		auton2();
//	}
//	case 3:{
//		auton3();
//	}
//	}
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
