// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AlignWithStep.h"
#include "Commands/BackupToAutonZone.h"
#include "Commands/DriveForward.h"
#include "Commands/DriveTeleop.h"
#include "Commands/GatherCans.h"
#include "Commands/LiftTeleop.h"
#include "Commands/RetractWings.h"
#include "Commands/RotateWings.h"
#include "Commands/RunLift.h"
#include "Commands/ShiftToHighGear.h"
#include "Commands/ShiftToLowGear.h"
#include "Commands/WingsTeleop.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	joystick1 = new Joystick(0);
	
     

        // SmartDashboard Buttons

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	p =  SmartDashboard::GetNumber("P",1);
	i = SmartDashboard::GetNumber("I",0);
	d = SmartDashboard::GetNumber("D",0);
	SmartDashboard::PutNumber("indexToteDistance",450);
	SmartDashboard::PutNumber("autonNumber", 1);
	SmartDashboard::PutNumber("backupTime", 3);

}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

Joystick* OI::getJoystick1() {
	return joystick1;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

