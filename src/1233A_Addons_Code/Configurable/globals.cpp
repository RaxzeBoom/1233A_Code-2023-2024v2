#include "main.h"
//Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);
//Drive Motor Configation
pros::Motor Intake(intake_port,pros::E_MOTOR_GEARSET_06, false , pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Catapult(Catapult_Port,pros::E_MOTOR_GEARSET_36, false , pros::E_MOTOR_ENCODER_DEGREES);
pros::Rotation rotation_sensor(Cata_Senser_Port);

Drivetrain drivetrain({-10,-9,-8} , {6,15,2} , {18} , 2.75, {48,36});
Pnumatics wings({'H'},pros::E_CONTROLLER_DIGITAL_B,false);
Pnumatics hang({'G'},pros::E_CONTROLLER_DIGITAL_X ,false);