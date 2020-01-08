
#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/IntakeSubsystem.h"

class ControlFeederWheels
   : public frc2::CommandHelper<frc2::CommandBase, ControlFeederWheels> {
 public:
  ControlFeederWheels(double speed = 0);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;

 private:
  double inputSpeed;
  bool isDone;
};