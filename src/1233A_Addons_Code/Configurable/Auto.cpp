#include "main.h"
extern int Auto_Num;
extern int Change;
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
    SetIntake(127);
    Auto_Turn(35,90);
    SetIntake(-127);
    pros::delay(100);
    AutoDrive(28,110);
    Auto_Turn(0,70);
    AutoDrive(7,110);
    AutoDrive(-3.5,110);
    Auto_Turn(270,100);
    AutoDrive(30,110);
    Auto_Turn(0,100);
    SetIntake(127);
    Intake_In();
    AutoDrive(29.5,110);
    AutoDrive(-2,110);
    Auto_Turn(90,90);
    Intake_Out();
    Change = 1800;
    AutoCatapult();
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
    Wings_Out();
    AutoDrive(-14,30);
    Auto_Turn(45,70);
    Auto_Turn(0,70);
    AutoDrive(12,60);
    Wings_In();
    Auto_Turn(315,70);
    AutoDrive(40,80);
}
void Auton_3()
{
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
//Blue side half win point, ball out of corner + touching bar
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
   AutoDrive(7,110);
   Intake_In();
   Auto_Turn(340,110);
   AutoDrive(-3,110);
   pros::delay(500);
   MutiShootCata(47);
   Auto_Turn(20,110);
   AutoDrive(-8,110);
   Auto_Turn(355,60);
   pros::delay(100);
   AutoDrive(-70,50);
   Intake_Out();
   Auto_Turn(310,60);
   AutoDrive(-35,70);
   Auto_Turn(5,80);
   AutoDrive(30,70);
   Auto_Turn(90,80);
   AutoDrive(30,70);
   Auto_Turn(180,80);
   Wings_Out();
    AutoDrive(16,70);
    AutoDrive(-16,70);
   for (size_t i = 0; i < 3; i++)
   {
       AutoDrive(17,70);
       AutoDrive(-16,70);
   }

}
//Backup
void Auton_14()
{
    AutoDrive(-40,90);
    AutoDrive(15,90);
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

}
void Auton_18()
{

}