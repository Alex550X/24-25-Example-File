#include "main.h"

// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int SWING_SPEED = 90;

///
// Constants
///
void default_constants() {

  chassis.pid_heading_constants_set(7, 0, 45);
  chassis.pid_drive_constants_set(20, 0, 100);
  chassis.pid_turn_constants_set(3, 0.05, 20, 15);
  chassis.pid_swing_constants_set(6, 0, 65);

  chassis.pid_turn_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(80_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  chassis.pid_odom_turn_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 750_ms);
  chassis.pid_odom_drive_exit_condition_set(80_ms, 1_in, 250_ms, 3_in, 500_ms, 750_ms);

  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  chassis.slew_turn_constants_set(3_deg, 70);
  chassis.slew_drive_constants_set(3_in, 70);
  chassis.slew_swing_constants_set(3_in, 80);

}



void Red_Awp() {

  chassis.odom_pose_set({-54, 30, -90});
  chassis.pid_drive_set(-16.8, 65, true);
  chassis.pid_wait();
  chassis.pid_swing_set(RIGHT_SWING, -60.5, 90);
  chassis.pid_wait();
  chassis.pid_drive_set(-12, 40);
  pros::delay(700);
  Clamp.set_value(true); // Goal & Ring 1
  pros::delay(250);
  set_intake(127);
  chassis.pid_wait();

  chassis.pid_turn_set(0, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(18, 70, true); // Ring 2
  chassis.pid_wait();
  pros::delay(1100);
  set_intake(0);

  chassis.pid_odom_set({{{-29, 13}, fwd, 100}, {{-34.3, -14.2}, fwd, 45}}, true);
  Clamp.set_value(false);
  chassis.pid_wait();
  pros::delay(300);
  chassis.pid_turn_set(-60, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-15.5, 40, true); // Goal 2
  pros::delay(1000);
  Clamp.set_value(true);
  chassis.pid_wait();

  chassis.pid_turn_set(-178, TURN_SPEED);
  chassis.pid_wait();
  set_intake(127);
  chassis.pid_drive_set(22, 70, true); // Ring 3
  chassis.pid_wait();

  chassis.pid_odom_set({{{-14, -2}, rev, 70} }, true); // Touch Bar
  chassis.pid_wait();
  set_intake(0);
  Clamp.set_value(false);

}



void Red_Rush() {

  chassis.odom_pose_set({-54, -30.5, 90});
  chassis.pid_swing_set(LEFT_SWING, 104, SWING_SPEED);
  pros::delay(350);
  chassis.pid_drive_set(37, DRIVE_SPEED);
  pros::delay(700);
  Doinker.set_value(true);
  chassis.pid_wait();
  chassis.pid_drive_set(-12, DRIVE_SPEED, true);
  chassis.pid_wait();
  Doinker.set_value(false);
  pros::delay(450);
  chassis.pid_drive_set(-14, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(235, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-19, 30);
  pros::delay(1200);
  Clamp.set_value(true);
  pros::delay(100);
  set_intake(127);
  chassis.pid_wait();
  chassis.pid_turn_set(180, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(20, 70, true);

}



void Red_Safe() {

  chassis.odom_pose_set({-54, 29.5, -90});
  chassis.pid_odom_set({{-33.7, 28.5, -60.5}, rev, 70}, true);
  chassis.pid_wait();
  chassis.pid_turn_set(-60.5, TURN_SPEED);
  pros::delay(10);
  chassis.pid_drive_set(-10, 40);
  pros::delay(400);
  Clamp.set_value(true); // Goal & Preload
  set_intake(127);
  chassis.pid_wait();

  chassis.pid_turn_set(50, TURN_SPEED);
  pros::delay(270);
  chassis.pid_odom_set({{{-9, 34}, fwd, 60}, {{-5.5, 48, 0}, fwd, 45}}, true);
  chassis.pid_wait();

  chassis.pid_odom_set({{{-7, 36}, rev, 50}, {{-23, 31}, rev, 65}}, true);
  chassis.pid_wait();
  chassis.pid_turn_set(0, TURN_SPEED);
  pros::delay(300);
  chassis.pid_drive_set(8, 80);
  pros::delay(400);

  // chassis.pid_odom_set({{-54, 53, -45.5}, fwd, 75});
  // chassis.pid_wait();
  // chassis.pid_turn_set(-45.5, TURN_SPEED); // Ring 5
  // pros::delay(50);
  // chassis.pid_drive_set(11, 90, true);
  // chassis.pid_wait();
  // pros::delay(100);

  // chassis.pid_odom_set({{-6, 0, 0}, rev, 95}); // Touch Bar
  // pros::delay(1000);
  // set_intake(0);
  // Clamp.set_value(false);

}

void Blue_Awp() {
set_intake(127);

}

void Blue_Rush() {
}

void Blue_Safe() {
}

void PogSkills() {
}