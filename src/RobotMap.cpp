// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
SpeedController* RobotMap::eagleWingsRightWinch = NULL;
SpeedController* RobotMap::eagleWingsLeftWinch = NULL;
SpeedController* RobotMap::drivetrainrearRight = NULL;
SpeedController* RobotMap::drivetrainfrontLeft = NULL;
SpeedController* RobotMap::drivetrainrearLeft = NULL;
SpeedController* RobotMap::drivetrainfrontRight = NULL;
RobotDrive* RobotMap::drivetrainrobotDrive = NULL;
Gyro* RobotMap::drivetraindriveGyro = NULL;
SpeedController* RobotMap::liftSpeedController1 = NULL;
Encoder* RobotMap::liftencoder = NULL;
DigitalInput* RobotMap::liftlimitSwitch = NULL;
DoubleSolenoid* RobotMap::liftgearboxShifter = NULL;
AnalogInput* RobotMap::stepDetectoratorsonar = NULL;
Compressor* RobotMap::compresoratororcompressor = NULL;
SpeedController* RobotMap::canStashinatorconveyor = NULL;
DoubleSolenoid* RobotMap::canStashinatorlifter = NULL;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
SpeedController* RobotMap::alignerSpinner = NULL;
SpeedController* RobotMap::wingRotater = NULL;
AnalogInput* RobotMap::drivetrainleftSonar = NULL;
AnalogInput* RobotMap::drivetrainrightSonar = NULL;
DigitalInput* RobotMap::liftlimitswitchhigh = NULL;
DoubleSolenoid* RobotMap::alignerDeploy = NULL;
PIDController* RobotMap::liftPidController = NULL;

void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();

	eagleWingsRightWinch = new Talon(6);
	lw->AddActuator("EagleWings", "RightWinch", (Talon*) eagleWingsRightWinch);
	
	eagleWingsLeftWinch = new Talon(7);
	lw->AddActuator("EagleWings", "LeftWinch", (Talon*) eagleWingsLeftWinch);
	
	drivetrainrearRight = new Talon(2);
	lw->AddActuator("Drivetrain", "rearRight", (Talon*) drivetrainrearRight);
	
	drivetrainfrontLeft = new Talon(1);
	lw->AddActuator("Drivetrain", "frontLeft", (Talon*) drivetrainfrontLeft);
	
	drivetrainrearLeft = new Talon(3);
	lw->AddActuator("Drivetrain", "rearLeft", (Talon*) drivetrainrearLeft);
	
	drivetrainfrontRight = new Talon(0);
	lw->AddActuator("Drivetrain", "frontRight", (Talon*) drivetrainfrontRight);
	
	drivetrainrobotDrive = new RobotDrive(drivetrainfrontLeft, drivetrainrearLeft,
              drivetrainfrontRight, drivetrainrearRight);
	
	drivetrainrobotDrive->SetSafetyEnabled(true);
        drivetrainrobotDrive->SetExpiration(0.1);
        drivetrainrobotDrive->SetSensitivity(0.5);
        drivetrainrobotDrive->SetMaxOutput(1.0);
        drivetrainrobotDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
        drivetrainrobotDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	drivetraindriveGyro = new Gyro(1);
	lw->AddSensor("Drivetrain", "driveGyro", drivetraindriveGyro);
	drivetraindriveGyro->SetSensitivity(0.007);
	liftSpeedController1 = new Talon(4);
	lw->AddActuator("Lift", "Speed Controller 1", (Talon*) liftSpeedController1);
	
	liftencoder = new Encoder(2, 3, false, Encoder::k4X);
		liftencoder->SetSamplesToAverage(1);
	lw->AddSensor("Lift", "encoder", liftencoder);
	liftencoder->SetDistancePerPulse(1.0);
        liftencoder->SetPIDSourceParameter(Encoder::kRate);
	liftlimitSwitch = new DigitalInput(4);
	lw->AddSensor("Lift", "limitSwitch", liftlimitSwitch);
	
	liftgearboxShifter = new DoubleSolenoid(0, 2, 3);      
	lw->AddActuator("Lift", "gearboxShifter", liftgearboxShifter);
	
	stepDetectoratorsonar = new AnalogInput(2);
	lw->AddSensor("StepDetectorator", "sonar", stepDetectoratorsonar);
	
	compresoratororcompressor = new Compressor(0);
	
	
	canStashinatorconveyor = new Talon(5);
	lw->AddActuator("CanStashinator", "conveyor", (Talon*) canStashinatorconveyor);
	
	canStashinatorlifter = new DoubleSolenoid(0, 4, 5);      
	lw->AddActuator("CanStashinator", "lifter", canStashinatorlifter);
	


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	wingRotater = new Talon(8);
	lw->AddActuator("EagleWings","wingRotater",(Talon*)wingRotater);
	liftlimitswitchhigh = new DigitalInput(5);
	lw->AddActuator("Lift","highLiftSwitch", liftlimitswitchhigh);
	alignerDeploy = new DoubleSolenoid(0,0,1);
	lw->AddActuator("Aligner", "Deploy", alignerDeploy);

	alignerSpinner = new Talon(9);
	lw->AddActuator("Aligner", "Spinner", (Talon*) alignerSpinner);

	liftencoder->SetPIDSourceParameter(Encoder::PIDSourceParameter::kDistance);
	liftPidController = new PIDController(0.01, 0.00005, 0.0001, liftencoder, liftSpeedController1);
	lw->AddActuator("Lift", "pidController", liftPidController);


}
