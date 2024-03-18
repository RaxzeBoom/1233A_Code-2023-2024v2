#include "main.h"
extern Pnumatics wings;
extern Pnumatics hang;
Drivetrain::Straight_PID_Var Alfa_Straight(.6,0,0.8,0.8);
Drivetrain::Straight_PID_Var Beta_Straight(1,0.05,0.1,.15);
Drivetrain::Straight_PID_Var Charlie_Straight(.3,0.05,0.1,.6);
Drivetrain::Turn_PID_Var Alfa_Turn(.60,0.001,0,false);
Drivetrain::Turn_PID_Var Beta_Turn(1,0,0,true);
Drivetrain::Turn_PID_Var Charlie_Turn(1.2,0.1,0,true);
Drivetrain::Swing_PID_Var Alfa_Swing(1.5,0.0009,0);
extern int Auto_Num;
extern int Change;
extern bool shoot_cata;
extern bool lower_cata;

Auto_Info Auto_Programs[] = {
    //  Name  ,   Display Name  ,  Disciption  ,  Auto that should be ran
    {"Close Side Winpoint","CS_Win_Point",
    {"Back up and moves the inside ball from the match",
     "loading zone then moves forward and touches bar",
     "pushes the middle triball past line score{4}"},
    (void*) Auton_1},
    //-------------------------------------------------
    {"Close Side Distruption","Disruption",
    {"Wings Out Moves torwards middle and stops"},
    (void*) Auton_2},
    //-------------------------------------------------
    {"DEFULT 3","Auto 3",
    {"DEFULT"},
    (void*) Auton_3},
    //-------------------------------------------------
    {"DEFULT 4","Auto 4",
    {"DEFULT"},
    (void*) Auton_4},
    //-------------------------------------------------
    {"DEFULT 5","Auto 5",
    {"DEFULT"},
    (void*) Auton_5},
    //-------------------------------------------------
    {"DEFULT 6","Auto 6",
    {"DEFULT"},
    (void*) Auton_6},
    //-------------------------------------------------
    {"Far Side Winpoint","FS_Win_Point",
    {"Pushes in red ball, then moves and score ball",
     "by goal and then touches bar."},
    (void*) Auton_7},
    //-------------------------------------------------
    {"DEFULT 8","Auto 8",
    {"DEFULT"},
    (void*) Auton_8},
    //-------------------------------------------------
    {"DEFULT 9","Auto 9",
    {"DEFULT"},
    (void*) Auton_9},
    //-------------------------------------------------
    {"DEFULT 10","Auto 10",
    {"DEFULT"},
    (void*) Auton_10},
    //-------------------------------------------------
    {"DEFULT 11","Auto 11",
    {"DEFULT"},
    (void*) Auton_11},
    //-------------------------------------------------
    {"DEFULT 12","Auto 12",
    {"DEFULT"},
    (void*) Auton_12},
    //-------------------------------------------------
    {"Skills Auto","Skills",
    {"Shoots 46 times then goes to other side to score",
     "triball"},
    (void*) Auton_13},
    //-------------------------------------------------
    {"Backup","Back-Up",
    {"Backs up and them moves forwards"},
    (void*) Auton_14},
    //-------------------------------------------------
    {"DEFULT 15","Auto 15",
    {"DEFULT"},
    (void*) Auton_15},
    //-------------------------------------------------
    {"DEFULT 16","Auto 16",
    {"DEFULT"},
    (void*) Auton_16},
    //-------------------------------------------------
    {"Simple Score","Simple Score",
    {"Moves forward to prevent triball form touching  ",
     "bot"},
    (void*) Auton_17},
    //-------------------------------------------------
    {"Nothing","Nothing",
    {"Does Nothing"},
    (void*) Auton_18}
};

void Intake_Out()
{
    lower_cata = true;
}

void Run_Auto()
{
    //Auto_Programs[Auto_Num].Current_Auto;
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

void Marco_Skills()
{
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A))
    {
    drivetrain.Set_Heading(45);
    drivetrain.Turn(0,100,Alfa_Turn);
    drivetrain.driveDistance(-18,90,Alfa_Straight);
    drivetrain.Turn(110,100,Alfa_Turn);
    MutiShootCata(47, 126);
    }
}
//Start of close side autos
void Auton_1()
{
    drivetrain.driveDistance(-12,100,Alfa_Straight);
    drivetrain.Turn(-65,100,Alfa_Turn);
    drivetrain.driveDistance(-12,100,Alfa_Straight);
    drivetrain.Turn(-45,100,Alfa_Turn);
    back_right_wing.Out();
    drivetrain.driveDistance(12,100,Alfa_Straight);
    drivetrain.Turn(-105,100,Alfa_Turn);
    drivetrain.Turn(-45,100,Alfa_Turn);
    drivetrain.driveDistance(12,100,Alfa_Straight);
    back_right_wing.In();
    SetIntake(-127);
    drivetrain.Turn(-75,100,Alfa_Turn);
    drivetrain.driveDistance(12,100,Alfa_Straight);
    drivetrain.Turn(-90,100,Alfa_Turn);
    drivetrain.driveDistance(20,100,Alfa_Straight);
}
void Auton_2()
{
    Intake_Out();
    wings.Out();
    drivetrain.driveDistance(48,110,Alfa_Straight);
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
    back_right_wing.Out();
    SetIntake(127);
    pros::delay(400);
    drivetrain.driveDistance(3,100, Alfa_Straight);
    back_right_wing.In();
    drivetrain.driveDistance(-33,60, Alfa_Straight);
    drivetrain.Turn(-25,100,Alfa_Turn, 4 , 9);
    back_left_wing.Out();
    drivetrain.driveDistance(-23,100, Alfa_Straight);
    drivetrain.Turn(-120,100,Alfa_Turn, 12 , 20);
    back_left_wing.In();
    drivetrain.Turn(135,100,Alfa_Turn, 4 , 9);
    drivetrain.driveDistance(8,100, Alfa_Straight);
    drivetrain.driveDistance({0,100}, 350);
    SetIntake(-127);
    drivetrain.driveDistance(127, 450);
    drivetrain.driveDistance(-6,100, Alfa_Straight);
    drivetrain.Turn(22,100,Alfa_Turn, 6 , 5);
    SetIntake(127);
    drivetrain.driveDistance(53,100, Alfa_Straight);
    drivetrain.Turn(170,100,Alfa_Turn, 7 , 6);
    SetIntake(-60);
    pros::delay(300);
    drivetrain.Turn(60,100,Alfa_Turn, 6 , 15);
    SetIntake(127);
    drivetrain.driveDistance(26,100, Alfa_Straight);
    drivetrain.Turn(180,100,Alfa_Turn, 5 , 11);
    SetIntake(-127);
    wings.Out();
    drivetrain.driveDistance(127,1000);
    wings.In();
    drivetrain.driveDistance(-4,100, Alfa_Straight);
}
void Auton_8()
{
    drivetrain.Turn(48,90, Beta_Turn);
    pros::delay(100);
    lower_cata = true;
    Change = 1500;
    drivetrain.driveDistance(28,110, Alfa_Straight);
    drivetrain.Turn(0,70, Alfa_Turn);
    drivetrain.driveDistance(17,110, Alfa_Straight);
    drivetrain.driveDistance(-2,110, Alfa_Straight);
    drivetrain.Turn(280,100, Alfa_Turn);
    drivetrain.driveDistance(32,110, Alfa_Straight);
    drivetrain.Turn(0,100, Alfa_Turn);
    SetIntake(127);
    drivetrain.driveDistance(40,110, Alfa_Straight);
    drivetrain.driveDistance(-4,110, Alfa_Straight);
    drivetrain.Turn(90,90, Alfa_Turn);
    SetIntake(-127);
    pros::delay(100);
    drivetrain.driveDistance(17,110, Alfa_Straight);
    drivetrain.Turn(225,90, Alfa_Turn);
    StopIntake();
    wings.Out();
    drivetrain.driveDistance(42,110, Alfa_Straight);
    drivetrain.Turn(265,90, Alfa_Turn);
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
    drivetrain.Turn(30,100,Alfa_Turn);
    drivetrain.driveDistance(-18,100,Alfa_Straight);
    drivetrain.Turn(-25,100,Alfa_Turn);
    drivetrain.driveDistance(-2,100,Alfa_Straight);
    back_right_wing.Out();
    //MutiShootCata(48,150);
    drivetrain.Set_Heading(335);
    SetIntake(-127);
    drivetrain.driveDistance(6,100,Alfa_Straight);
    back_right_wing.In();
    drivetrain.Turn(30,100,Alfa_Turn);
    drivetrain.driveDistance(28,100,Alfa_Straight);
    drivetrain.Turn(0,100,Alfa_Turn);
    drivetrain.driveDistance(96,100,Alfa_Straight);
    drivetrain.Turn(120,100,Alfa_Turn);
    drivetrain.driveDistance(-127,1500);
    drivetrain.driveDistance(4,100,Alfa_Straight);
    drivetrain.Turn(10,100,Alfa_Turn);
    drivetrain.driveDistance(-36,100,Alfa_Straight);
    back_right_wing.Out();
    back_left_wing.Out();
    drivetrain.Swing(175,100,'r',Alfa_Swing);
    drivetrain.driveDistance(-127,1000);
    drivetrain.driveDistance(4,100,Alfa_Straight);
    back_right_wing.In();
    back_left_wing.In();
    drivetrain.Turn(200,100,Alfa_Turn);
    drivetrain.driveDistance(20,100,Alfa_Straight);
    back_left_wing.Out();
    drivetrain.Swing(165,100,'r',Alfa_Swing);
    back_right_wing.Out();
    drivetrain.driveDistance(-127,1000);
    drivetrain.Turn(210,100,Alfa_Turn);
    drivetrain.driveDistance(32,100,Alfa_Straight);
    back_left_wing.In();
    back_right_wing.In();
    drivetrain.Turn(-50,100,Alfa_Turn);
    drivetrain.driveDistance(36,100,Alfa_Straight);
    back_left_wing.Out();
    drivetrain.Swing(-135,100,'r',Alfa_Swing);
    drivetrain.driveDistance(-20,100,Alfa_Straight);
    drivetrain.driveDistance(-127,800);
    drivetrain.driveDistance(6,100,Alfa_Straight);
    drivetrain.driveDistance(-127,500);
    drivetrain.driveDistance(6,100,Alfa_Straight);
    drivetrain.Turn(-135,100,Alfa_Turn);
    back_left_wing.In();
    drivetrain.driveDistance(30,100,Alfa_Straight);
    drivetrain.Turn(180,100,Alfa_Turn);
    hang.Out();
    drivetrain.driveDistance(127,800);
    hang.In();
}
//Backup
void Auton_14()
{
    drivetrain.driveDistance(-40,90,Alfa_Straight);
    drivetrain.driveDistance(15,90,Alfa_Straight);
    
}
void Auton_15()
{

}
void Auton_16()
{
    
}
void Auton_17()
{
    drivetrain.driveDistance(4,100, Alfa_Straight);
}
void Auton_18()
{
    //Do nothing
}
