#include "main.h"
extern int LeftDTPorts [3];
extern int RightDTPorts [3];
pros::Motor R1Drive(RightDTPorts[0],pros::E_MOTOR_GEARSET_06, false , pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor R2Drive(RightDTPorts[1],pros::E_MOTOR_GEARSET_06, false , pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor R3Drive(RightDTPorts[2],pros::E_MOTOR_GEARSET_06, false , pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor L1Drive(LeftDTPorts[0],pros::E_MOTOR_GEARSET_06, false , pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor L2Drive(LeftDTPorts[1],pros::E_MOTOR_GEARSET_06, false , pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor L3Drive(LeftDTPorts[2],pros::E_MOTOR_GEARSET_06, false , pros::E_MOTOR_ENCODER_DEGREES);