/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>

class IntakeSubsystem : public frc2::SubsystemBase {
 public:
    IntakeSubsystem();
    void Periodic() override;
    void SetIntakeWheelSpeed(double speed);
    void RunFeederWheel(double speed);

 private:
    std::unique_ptr<ctre::phoenix::motorcontrol::can::TalonSRX> intakeWheelsTalonLeader;
    std::unique_ptr<ctre::phoenix::motorcontrol::can::TalonSRX> intakeWheelsTalonFollower;
    std::unique_ptr<ctre::phoenix::motorcontrol::can::TalonSRX> feederWheelTalon;
};
