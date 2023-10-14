#include "main.h"
//Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);
//Drive Motor Configation
pros::Motor Intake(intake_port,pros::E_MOTOR_GEARSET_06, false , pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Catapult(Catapult_Port,pros::E_MOTOR_GEARSET_36, false , pros::E_MOTOR_ENCODER_DEGREES);
pros::Rotation rotation_sensor(Cata_Senser_Port);
//More motor Configation here

//More senser Configation here
pros::Imu Auto_IMU(IMU_Port);
//More pnumatics Configation here
pros::ADIDigitalOut Wing (Wings_Port);
pros::ADIDigitalOut Intake_Lift (Intake_Lift_Port);
pros::ADIDigitalOut Hang (Hang_Port);