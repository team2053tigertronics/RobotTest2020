#pragma once

#include "frc/XboxController.h"

class OI {
public:
	OI();

private:
	frc::XboxController driverController{0};
	frc::XboxController operatorController{1};
};