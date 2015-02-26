################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Subsystems/Drivetrain.cpp \
../src/Subsystems/EagleWings.cpp \
../src/Subsystems/Lift.cpp \
../src/Subsystems/StepDetectorator.cpp \
../src/Subsystems/compresoratoror.cpp 

OBJS += \
./src/Subsystems/Drivetrain.o \
./src/Subsystems/EagleWings.o \
./src/Subsystems/Lift.o \
./src/Subsystems/StepDetectorator.o \
./src/Subsystems/compresoratoror.o 

CPP_DEPS += \
./src/Subsystems/Drivetrain.d \
./src/Subsystems/EagleWings.d \
./src/Subsystems/Lift.d \
./src/Subsystems/StepDetectorator.d \
./src/Subsystems/compresoratoror.d 


# Each subdirectory must supply rules for building sources it contributes
src/Subsystems/%.o: ../src/Subsystems/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"\$\{workspace_loc:/FinalRobot2015}/src" -IC:\Users\Miles/wpilib/cpp/current/sim/include -I/usr/include -I/usr/include/gazebo-3.1 -I/usr/include/sdformat-2.2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


