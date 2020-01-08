#include "OI.h"
#include "Robot.h"
#include "frc2/command/button/JoystickButton.h"
#include "frc/Joystick.h"
#include "commands/ControlIntakeWheels.h"
#include "commands/ControlFeederWheels.h"

#include <frc/smartdashboard/SmartDashboard.h>

OI::OI() {
    frc2::JoystickButton intakeButton(&driverController, (int) frc::XboxController::Button::kA);
    intakeButton.WhileHeld(ControlIntakeWheels(30));

    frc2::JoystickButton feederButton(&driverController, (int) frc::XboxController::Button::kB);
    feederButton.WhileHeld(ControlFeederWheels(30));
}
