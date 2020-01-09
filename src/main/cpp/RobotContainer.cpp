/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "frc2/command/button/JoystickButton.h"
#include "frc/Joystick.h"
#include "commands/ControlFeederWheels.h"
#include "commands/ControlIntakeWheels.h"
#include <frc/XboxController.h>

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings(){
  frc2::JoystickButton intakeButton(&operatorController, (int) frc::XboxController::Button::kA);
  intakeButton.WhileHeld(ControlIntakeWheels(30));

  frc2::JoystickButton feederButton(&operatorController, (int) frc::XboxController::Button::kB);
  feederButton.WhileHeld(ControlFeederWheels(30));
}


