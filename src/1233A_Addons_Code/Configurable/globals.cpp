#include "main.h"
//Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);
//Drive Motor Configation
pros::Motor Intake(intake_port,pros::E_MOTOR_GEARSET_06, true , pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Catapult_1(13,pros::E_MOTOR_GEARSET_18, false , pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Catapult_2(19,pros::E_MOTOR_GEARSET_18, true , pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor_Group Catapult({Catapult_1,Catapult_2});
pros::Rotation rotation_sensor(Cata_Senser_Port);

Drivetrain drivetrain({-10,-9,-8} , {6,15,2} , {18} , 2.75, {48,36});
Pnumatics wings({'F'},pros::E_CONTROLLER_DIGITAL_Y,false);
Pnumatics Back_Right_wing({'H'},pros::E_CONTROLLER_DIGITAL_B,false);
Pnumatics Back_Left_wing({'G'},pros::E_CONTROLLER_DIGITAL_DOWN,false);
Pnumatics hang({'E'},pros::E_CONTROLLER_DIGITAL_X ,false);  
Pnumatics::Button_Com Test = {pros::E_CONTROLLER_DIGITAL_X,{1,2}};
Pnumatics back_wings({'H','G'},{Test},false);