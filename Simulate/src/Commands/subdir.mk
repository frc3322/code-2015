################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/APusH.cpp \
../src/Commands/AlignWithStep.cpp \
../src/Commands/AutonCalibration.cpp \
../src/Commands/AutonJerky.cpp \
../src/Commands/AutonomousCommand.cpp \
../src/Commands/BackupToAutonZone.cpp \
../src/Commands/DriveForward.cpp \
../src/Commands/DriveTeleop.cpp \
../src/Commands/GatherCans.cpp \
../src/Commands/LiftTeleop.cpp \
../src/Commands/LowerOneTote.cpp \
../src/Commands/RaiseOneTote.cpp \
../src/Commands/RaiseWings.cpp \
../src/Commands/ResetLift.cpp \
../src/Commands/RetractWings.cpp \
../src/Commands/RotateWings.cpp \
../src/Commands/RunLift.cpp \
../src/Commands/ShiftToHighGear.cpp \
../src/Commands/ShiftToLowGear.cpp \
../src/Commands/UnAPusH.cpp \
../src/Commands/WingsTeleop.cpp 

OBJS += \
./src/Commands/APusH.o \
./src/Commands/AlignWithStep.o \
./src/Commands/AutonCalibration.o \
./src/Commands/AutonJerky.o \
./src/Commands/AutonomousCommand.o \
./src/Commands/BackupToAutonZone.o \
./src/Commands/DriveForward.o \
./src/Commands/DriveTeleop.o \
./src/Commands/GatherCans.o \
./src/Commands/LiftTeleop.o \
./src/Commands/LowerOneTote.o \
./src/Commands/RaiseOneTote.o \
./src/Commands/RaiseWings.o \
./src/Commands/ResetLift.o \
./src/Commands/RetractWings.o \
./src/Commands/RotateWings.o \
./src/Commands/RunLift.o \
./src/Commands/ShiftToHighGear.o \
./src/Commands/ShiftToLowGear.o \
./src/Commands/UnAPusH.o \
./src/Commands/WingsTeleop.o 

CPP_DEPS += \
./src/Commands/APusH.d \
./src/Commands/AlignWithStep.d \
./src/Commands/AutonCalibration.d \
./src/Commands/AutonJerky.d \
./src/Commands/AutonomousCommand.d \
./src/Commands/BackupToAutonZone.d \
./src/Commands/DriveForward.d \
./src/Commands/DriveTeleop.d \
./src/Commands/GatherCans.d \
./src/Commands/LiftTeleop.d \
./src/Commands/LowerOneTote.d \
./src/Commands/RaiseOneTote.d \
./src/Commands/RaiseWings.d \
./src/Commands/ResetLift.d \
./src/Commands/RetractWings.d \
./src/Commands/RotateWings.d \
./src/Commands/RunLift.d \
./src/Commands/ShiftToHighGear.d \
./src/Commands/ShiftToLowGear.d \
./src/Commands/UnAPusH.d \
./src/Commands/WingsTeleop.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/%.o: ../src/Commands/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"\$\{workspace_loc:/FinalRobot2015}/src" -IC:\Users\Miles/wpilib/cpp/current/sim/include -I/usr/include -I/usr/include/gazebo-3.1 -I/usr/include/sdformat-2.2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


