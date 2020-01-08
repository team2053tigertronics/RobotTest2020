/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/IntakeSubsystem.h"
#include "Robot.h"

IntakeSubsystem::IntakeSubsystem() {
  intakeWheelsTalonLeader = std::make_unique<ctre::phoenix::motorcontrol::can::TalonSRX>(0);
  intakeWheelsTalonFollower = std::make_unique<ctre::phoenix::motorcontrol::can::TalonSRX>(1);
  feederWheelTalon = std::make_unique<ctre::phoenix::motorcontrol::can::TalonSRX>(2);

  intakeWheelsTalonLeader->ConfigFactoryDefault();
  intakeWheelsTalonFollower->ConfigFactoryDefault();
  feederWheelTalon->ConfigFactoryDefault();

  intakeWheelsTalonLeader->ConfigNominalOutputForward(0,30);
  intakeWheelsTalonFollower->ConfigNominalOutputForward(0,30);
  feederWheelTalon->ConfigNominalOutputForward(0,10);

  intakeWheelsTalonFollower->Follow(*intakeWheelsTalonLeader.get());
}

void IntakeSubsystem::Periodic() {
}

void IntakeSubsystem::SetIntakeWheelSpeed(double speed) {
  intakeWheelsTalonLeader->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, speed);
}

void IntakeSubsystem::RunFeederWheel(double speed) {
  feederWheelTalon->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, speed);
}
