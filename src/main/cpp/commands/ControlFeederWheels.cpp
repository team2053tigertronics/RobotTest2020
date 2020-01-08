/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ControlFeederWheels.h"
#include "Robot.h"

ControlFeederWheels::ControlFeederWheels(double speed){
    HasRequirement(Robot::intakeSubsystem.get());
    isDone = false;
    inputSpeed = speed;
}

void ControlFeederWheels::Initialize(){
    isDone = false;
}

void ControlFeederWheels::Execute() {
	Robot::intakeSubsystem->RunFeederWheel(inputSpeed);
	isDone = true;
}

bool ControlFeederWheels::IsFinished() { 
  return isDone; 
}
