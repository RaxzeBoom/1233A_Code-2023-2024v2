#include "main.h"
extern Drivetrain drivetrain;
Drivetrain::Straight_PID_Var Alfa_Straight(.35,0.08,0,.15);
Drivetrain::Straight_PID_Var Beta_Straight(1,0.05,0.1,.15);
Drivetrain::Straight_PID_Var Charlie_Straight(.3,0.05,0.1,.6);
Drivetrain::Turn_PID_Var Alfa_Turn(1.00,0.09,0.0,false);
Drivetrain::Turn_PID_Var Beta_Turn(1,0,0,true);
Drivetrain::Turn_PID_Var Charlie_Turn(1.2,0.08,0,true);
void RPM_Control(){
    drivetrain.RPM_Var.kP = .05;
    drivetrain.RPM_Var.kI = 0;
    drivetrain.RPM_Var.kD = 0;
    drivetrain.RPM_Var.kF = 1;
    drivetrain.RPM_Controller(drivetrain.RPM_Var);
}
extern int Auto_Num;
extern int Change;
extern bool shoot_cata;
extern bool lower_cata;

void Intake_Out()
{
    lower_cata = true;
}
void Run_Auto()
{
    switch (Auto_Num)
    {
    case 1:
        Auton_1();
        break;
    case 2:
        Auton_2();
        break;
    case 3:
        Auton_3();
        break;
    case 4:
        Auton_4();
        break;
    case 5:
        Auton_5();
        break;
    case 6:
        Auton_6();
        break;
    case 7:
        Auton_7();
        break;
    case 8:
        Auton_8();
        break;
    case 9:
        Auton_9();
        break;
    case 10:
        Auton_10();
        break;
    case 11:
        Auton_11();
        break;
    case 12:
        Auton_12();
        break;
    case 13:
        Auton_13();
        break;
    case 14:
        Auton_14();
        break;
    case 15:
        Auton_15();
        break;
    case 16:
        Auton_16();
        break;
    case 17:
        Auton_17();
        break;
    case 18:
        Auton_18();
        break;
    default:
        break;
    }
}
void Macro_Skill()
{
  if((controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)))
  {
    drivetrain.Straight(-18,90,Alfa_Straight);
    drivetrain.Turn(105,100,Alfa_Turn);
    drivetrain.Straight(3,90,Alfa_Straight);
    Wings_Out();
    //Intake_Out();
    MutiShootCata(50, 126);
  }
}
//Start of close side autos
void Auton_1()
{
    Wings_Out();
    drivetrain.Straight(-16,30,Alfa_Straight);
    drivetrain.Turn(45,70,Alfa_Turn);
    drivetrain.Turn(0,110,Alfa_Turn);
    Wings_In();
    drivetrain.Straight(20,100,Alfa_Straight);
    drivetrain.Turn(315,70,Alfa_Turn);
    drivetrain.Straight(40,80,Alfa_Straight);
}
void Auton_2()
{
    Intake_Out();
    Wings_Out();
    AutoDrive(48,110);
}
void Auton_3()
{

}
void Auton_4()
{
   
}
void Auton_5()
{

}
void Auton_6()
{

}
//Start of far side autos
void Auton_7()
{
    drivetrain.Turn(48,90, Beta_Turn);
    pros::delay(100);
    lower_cata = true;
    Change = 1800;
    drivetrain.Straight(28,110, Alfa_Straight);
    drivetrain.Turn(0,70, Alfa_Turn);
    drivetrain.Straight(17,110, Alfa_Straight);
    drivetrain.Straight(-2,110, Alfa_Straight);
    drivetrain.Turn(280,100, Alfa_Turn);
    drivetrain.Straight(32,110, Alfa_Straight);
    drivetrain.Turn(0,100, Alfa_Turn);
    SetIntake(127);
    drivetrain.Straight(40,110, Alfa_Straight);
    drivetrain.Straight(-4,110, Alfa_Straight);
    drivetrain.Turn(90,90, Alfa_Turn);
    SetIntake(-127);
    pros::delay(100);
    drivetrain.Straight(17,110, Alfa_Straight);
    drivetrain.Turn(225,90, Alfa_Turn);
    StopIntake();
    Wings_Out();
    drivetrain.Straight(42,110, Alfa_Straight);
    drivetrain.Turn(265,90, Alfa_Turn);
}
void Auton_8()
{

}
void Auton_9()
{

}
void Auton_10()
{

}
void Auton_11()
{

}
void Auton_12()
{

}
//Start of Other programs
void Auton_13()
{
    drivetrain.Straight(-18,90,Alfa_Straight);
    drivetrain.Turn(105,100,Alfa_Turn);
    drivetrain.Straight(3,90,Alfa_Straight);
    Wings_Out();
    //Intake_Out();
    MutiShootCata(50, 126);
    Wings_In();
    drivetrain.Turn(0,100,Alfa_Turn);
    drivetrain.Straight(28,90,Alfa_Straight);
    drivetrain.Turn(135,80,Alfa_Turn);
    //drivetrain.Set_Heading(0);
    lower_cata = true;
    Change = 1800;
    drivetrain.Straight(-85,80,Charlie_Straight);
    drivetrain.Turn(90,125,Alfa_Turn);
    drivetrain.Straight(-40,100,Beta_Straight);
    drivetrain.Straight(8,100,Alfa_Straight);
    drivetrain.Turn(135,100,Alfa_Turn);
    drivetrain.Straight(40,100,Alfa_Straight);
    drivetrain.Turn(225,100,Alfa_Turn);
    drivetrain.Straight(35,100,Alfa_Straight);
    drivetrain.Turn(315,100,Alfa_Turn);
    Wings_Out();
    for (size_t i = 0; i < 3; i++)
    {
        drivetrain.Straight(40,100,Alfa_Straight);
        drivetrain.Straight(-39.5,100,Alfa_Straight);
        drivetrain.Turn(315,100,Alfa_Turn);
    }
    Wings_In();
    drivetrain.Turn(260,100,Alfa_Turn);
    drivetrain.Straight(68,100,Alfa_Straight);
    Wings_Out();
    drivetrain.Turn(135,100,Alfa_Turn);
    drivetrain.Straight(-35,100,Beta_Straight);
    drivetrain.Straight(20,100,Beta_Straight);
}
//Backup
void Auton_14()
{
    drivetrain.Straight(-40,90,Alfa_Straight);
    drivetrain.Straight(15,90,Alfa_Straight);
}
void Auton_15()
{

}
void Auton_16()
{
    /*
 AutoDrive(1,110);
    Auto_Turn(35,110);
    SetIntake(-127);
    pros::delay(100);
    AutoDrive(28,110);
    Auto_Turn(0,70);
    AutoDrive(7,125);
    AutoDrive(-4,110);
    Auto_Turn(45,127);
    AutoDrive(-12,110);
    StopIntake();
    Auto_Turn(110,70);
    Intake_In();
    AutoDrive(5,110);
    AutoDrive(-8,110);
    pros::delay(2000);
    MutiShootCata(6);
    AutoDrive(-4,110);
    Auto_Turn(35,100);
    AutoDrive(-12,110);
    Auto_Turn(90,60);
    pros::delay(100);
    AutoDrive(-39,90);
    Auto_Turn(90,20);
    AutoDrive(-30,90);
    Auto_Turn(145,100);
    AutoDrive(-28,110);
    AutoDrive(2,110);
    Auto_Turn(90,50);
    pros::delay(100);
    AutoDrive(45,110);
    Auto_Turn(0,100);
    AutoDrive(45,110);
    Auto_Turn(270,100);
    Wings_Out();
    AutoDrive(35,110);
    AutoDrive(-10,110);
    Auto_Turn(300,100);
    AutoDrive(20,110);
    AutoDrive(-5,110);
    Auto_Turn(270,100);
    AutoDrive(-15,110);
    AutoDrive(20,110);
    */
}
void Auton_17()
{
    drivetrain.Straight(4,100, Alfa_Straight);
}
void Auton_18()
{

}