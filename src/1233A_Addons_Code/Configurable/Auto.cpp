#include "main.h"
extern int Auto_Num;
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
    default:
        break;
    }
}
void Auton_1()
{
  SetIntake(127);
  Auto_Turn(35,90);
  SetIntake(-127);
  pros::delay(100);
  AutoDrive(28,110);
  Auto_Turn(0,70);
  AutoDrive(8,110);
  AutoDrive(-4,110);
  Auto_Turn(270,100);
  AutoDrive(30,110);
  Auto_Turn(0,100);
  SetIntake(127);
  Intake_In();
  AutoDrive(29.5,110);
  AutoDrive(-2,110);
  Auto_Turn(90,90);
  Intake_Out();
  SetIntake(-127);
  pros::delay(100);
  AutoDrive(15,110);
  Auto_Turn(225,90);
  StopIntake();
  Intake_In();
  AutoDrive(48,110);

}
void Auton_2()
{
    Intake_In();
    Wings_Out();
    AutoDrive(-14,30);
    Auto_Turn(315,60);
    Wings_In();
    SetIntake(127);
    Auto_Turn(0,60);
    AutoDrive(15 ,60);
    Auto_Turn(300,110);
    AutoDrive(-40,100);
    Auto_Turn(225,100);
    Intake_Out();
    SetIntake(-127);
    pros::delay(200);
    AutoDrive(10,60);
    AutoDrive(-6,100);
    Auto_Turn(0,100);
    Intake_In();
    StopIntake();
    AutoDrive(35,100);
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
//Start of blue team autos
//Blue side half win point, ball out of corner + touching bar
void Auton_7()
{
    Intake_In();
    Wings_Out();
    AutoDrive(-14,30);
    Auto_Turn(45,60);
    Wings_In();
    SetIntake(127);
    Auto_Turn(0,60);
    AutoDrive(15 ,60);
    Auto_Turn(60,110);
    AutoDrive(-40,100);
    Auto_Turn(135,100);
    Intake_Out();
    SetIntake(-127);
    pros::delay(200);
    AutoDrive(10,60);
    AutoDrive(-6,100);
    Auto_Turn(0,100);
    Intake_In();
    StopIntake();
    AutoDrive(35,100);
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
}
void Auton_14()
{

}
void Auton_15()
{

}
void Auton_16()
{

}