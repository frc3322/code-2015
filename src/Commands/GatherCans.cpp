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
	case 1:
		auton1();
		break;
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
			auton0();
			break;
	}
}
void GatherCans::auton0(){
	Robot::eagleWings->wingRotater->Set(0);
	AddParallel(new ResetLift());
	AddSequential(new DriveForward(6,0.25));

	AddParallel(new DriveForward(2,.3)); //keep "aligned" with the step while grabbing the cans.  Cancelled when AutonJerky is run
	AddSequential(new RotateWings(0.25,2));

	//	AddSequential(new AutonJerky());
//	AddParallel(new RotateWings(0.4,6));
	AddSequential(new BackupToAutonZone());
//	AddSequential(new RotateWings(-.2,.4));
}

void GatherCans::auton1(){
	Robot::eagleWings->wingRotater->Set(0);
	AddParallel(new ResetLift());
//	AddSequential(new DriveForward(.2,1));
	AddParallel(new RotateWings(-0.5,1));
	AddSequential(new DriveForward(autonTimeout,autonForwardSpeed));

	AddParallel(new DriveForward(autonRotateTime,.3)); //keep "aligned" with the step while grabbing the cans.  Cancelled when AutonJerky is run
	AddSequential(new RotateWings(autonRotateSpeed,autonRotateTime));

//	AddParallel(new RotateWings(.3,4));
//	AddSequential(new AutonJerky());

	AddSequential(new BackupToAutonZone());
}
void GatherCans::auton2(){
	//super secret auton
	Robot::eagleWings->wingRotater->Set(0);
	AddParallel(new ResetLift());
	AddSequential(new DriveForward(0.4,1));
	AddParallel(new RotateWings(-.6,.15)); //clap on top of cans to thwart burglars...
	AddSequential(new DriveForward(.5,0.25));
	AddSequential(new AutonJerky()); //being used for waiting at the step.  Waits for 4.5 seconds, needs to be random 4 to 7 eventually.
	AddSequential(new RotateWings(0.25,2));
	AddSequential(new BackupToAutonZone());
}
void GatherCans::auton3(){
	AddParallel(new ResetLift());
	//reset lift...
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
