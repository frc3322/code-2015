#ifndef STEPDETECTORATOR_H
#define STEPDETECTORATOR_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class StepDetectorator: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	BuiltInAccelerometer* accelerometer;
	StepDetectorator();
	void InitDefaultCommand();
	bool IsAtStep();
};

#endif
