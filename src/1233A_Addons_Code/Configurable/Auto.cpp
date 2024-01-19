#include "main.h"
extern Drivetrain drivetrain;
Drivetrain::Straight_PID_Var Alfa_Straight(.3,0,0,.15);
Drivetrain::Turn_PID_Var Alfa_Turn(.6,0,0,true);
Drivetrain::Turn_PID_Var Beta_Turn(1, 0 ,0,true);
extern int Auto_Num;
extern int Change;
extern bool shoot_cata;
extern bool lower_cata;
void Intake_Out()
{
    SetIntake(-127);
    pros::delay(100);
    StopIntake();
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
void Auton_1()
{
    drivetrain.Auto_Turn(48,90, Beta_Turn);
    pros::delay(100);
    lower_cata = true;
    Change = 1800;
    drivetrain.AutoDrive(28,110, Alfa_Straight);
    drivetrain.Auto_Turn(0,70, Alfa_Turn);
    drivetrain.AutoDrive(8,110, Alfa_Straight);
    drivetrain.AutoDrive(-3,110, Alfa_Straight);
    Intake_Out();
    drivetrain.Auto_Turn(270,100, Alfa_Turn);
    drivetrain.AutoDrive(30,110, Alfa_Straight);
    drivetrain.Auto_Turn(0,100, Alfa_Turn);
    SetIntake(127);
    drivetrain.AutoDrive(38,110, Alfa_Straight);
    drivetrain.AutoDrive(-4,110, Alfa_Straight);
    drivetrain.Auto_Turn(90,90, Alfa_Turn);
    SetIntake(-127);
    pros::delay(100);
    drivetrain.AutoDrive(17,110, Alfa_Straight);
    drivetrain.Auto_Turn(225,90, Alfa_Turn);
    StopIntake();
    Wings_Out();
    drivetrain.AutoDrive(42,110, Alfa_Straight);
    drivetrain.Auto_Turn(280,90, Alfa_Turn);
    drivetrain.AutoDrive(6,110, Alfa_Straight);

}
void Auton_2()
{
    Wings_Out();
    drivetrain.AutoDrive(-16,30,Alfa_Straight);
    drivetrain.Auto_Turn(45,70,Alfa_Turn);
    drivetrain.Auto_Turn(0,110,Alfa_Turn);
    Wings_In();
    drivetrain.AutoDrive(20,100,Alfa_Straight);
    drivetrain.Auto_Turn(315,70,Alfa_Turn);
    drivetrain.AutoDrive(40,80,Alfa_Straight);
    Intake_Out();
}
void Auton_3()
{
    Intake_Out();
    Wings_Out();
    AutoDrive(48,110);
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
void Auton_7()
{
    Auton_1();
}
void Auton_8()
{
    Auton_2();
}
void Auton_9()
{
    Auton_3();
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
    Intake_Out();
    MutiShootCata(60, 80);
}
//Backup
void Auton_14()
{
    drivetrain.AutoDrive(-40,90,Alfa_Straight);
    drivetrain.AutoDrive(15,90,Alfa_Straight);
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
    drivetrain.AutoDrive(4,100, Alfa_Straight);
}
void Auton_18()
{

}