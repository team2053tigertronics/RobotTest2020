/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ControlIntakeWheels.h"
#include "Robot.h"

ControlIntakeWheels::ControlIntakeWheels(double speed){
    HasRequirement(Robot::intakeSubsystem.get());
    isDone = false;
    inputSpeed = speed;
}

void ControlIntakeWheels::Initialize(){
    isDone = false;
}

void ControlIntakeWheels::Execute() {
	Robot::intakeSubsystem->SetIntakeWheelSpeed(inputSpeed);
	isDone = true;
}

bool ControlIntakeWheels::IsFinished() { 
  return isDone; 
}


