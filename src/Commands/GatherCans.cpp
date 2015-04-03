#include "GatherCans.h"
#include "DriveForward.h"
#include "AlignWithStep.h"
#include "RotateWings.h"
#include "BackupToAutonZone.h"
#include "AutonJerky.h"
#include "timedDrive.h"
#include "ResetLift.h"

GatherCans::GatherCans(int autonNumber, double autonForwardSpeed, double autonJerkSpeed, double autonTimeout, double autonDriveBackSpeed, double autonRotateTime, double autonRotateSpeed, double autonDriveBackTime) {
//	autonNumber = 1;
	this->autonForwardSpeed = autonForwardSpeed;
	this->autonJerkSpeed = autonJerkSpeed;
	this->autonTimeout = autonTimeout;
	this->autonDriveBackSpeed = autonDriveBackSpeed;
	this->autonRotateTime = autonRotateTime;
	this->autonRotateSpeed = autonRotateSpeed;
	this->autonDriveBackTime = autonDriveBackTime;

	switch(autonNumber){
		case 2:
			auton2();
			break;
		case 3:
			auton3();
			break;
		case 4:
			auton4();
			break;
		case 5:
			auton5();
			break;
		default:
			auton1();
			break;
	}
}

//void GatherCans::auton1(){
//	Robot::eagleWings->wingRotater->Set(0);
//	AddParallel(new ResetLift());
//	AddSequential(new DriveForward(6,0.25));
////	AddSequential(new AlignWithStep());
//	AddSequential(new RotateWings(0.2,2));
//	AddSequential(new AutonJerky());
//	AddSequential(new BackupToAutonZone());
////	AddSequential(new RotateWings(-.2,.4));
//}
//commented out to test auton.
void GatherCans::auton1(){
	Robot::eagleWings->wingRotater->Set(0);
	AddParallel(new ResetLift());
	AddSequential(new DriveForward(autonTimeout,autonForwardSpeed));
	AddSequential(new RotateWings(autonRotateSpeed,autonRotateTime));
	AddParallel(new RotateWings(.3,4));
	AddSequential(new AutonJerky());
	AddSequential(new BackupToAutonZone());


}
void GatherCans::auton2(){
	//drive forward
	double duration = 2;
	double speed = .3;
	AddParallel(new ResetLift());
	AddSequential(new timedDrive(duration, speed));
}
void GatherCans::auton3(){
	AddParallel(new ResetLift());
	//do nothing....
}
void GatherCans::auton4(){
	Robot::eagleWings->wingRotater->Set(0);
	AddParallel(new ResetLift());
	AddSequential(new DriveForward(4.5,0.30));
//	AddSequential(new AlignWithStep());
	AddSequential(new RotateWings(0.2,2));
	AddSequential(new AutonJerky());
	AddSequential(new BackupToAutonZone());
}
void GatherCans::auton5(){
	Robot::eagleWings->wingRotater->Set(0);
	AddParallel(new ResetLift());
	AddSequential(new DriveForward(4,0.35));
//	AddSequential(new AlignWithStep());
	AddSequential(new RotateWings(0.2,2));
	AddSequential(new AutonJerky());
	AddSequential(new BackupToAutonZone());
}
