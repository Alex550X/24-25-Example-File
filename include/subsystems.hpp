#pragma once

#include "api.h"

inline pros::Motor intakeHook(7);  // Initializes the motor port for the Hook stage or the second stage of the intake.
inline pros::Motor intakeFlex(-10);  // Initializes the motor port for the Flex Wheel stage or first stage of the intake.
inline pros::MotorGroup Intake({7,-10});
inline const std::vector<pros::Motor> intake_motors = {intakeHook, intakeFlex};
void set_intake(int input);
void intake_opcontrol();

inline pros::adi::DigitalOut Doinker('F'); //Initializes the piston for the Rushing Arm.
inline pros::adi::DigitalOut Clamp('E'); //Initializes the pistons for the Clamp mechanism.

inline bool RUN_JAM = true;

