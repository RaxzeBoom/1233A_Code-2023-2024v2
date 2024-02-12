#include "main.h"
/*extern Drivetrain::Straight_PID_Var Alfa_Straight(.35,0.08,0,.15);
extern Drivetrain::Straight_PID_Var Beta_Straight(1,0.05,0.1,.15);
extern Drivetrain::Straight_PID_Var Charlie_Straight(.3,0.05,0.1,.6);
extern Drivetrain::Turn_PID_Var Alfa_Turn(1.00,0.09,0.0,false);
extern Drivetrain::Turn_PID_Var Beta_Turn(1,0,0,true);
extern Drivetrain::Turn_PID_Var Charlie_Turn(1.2,0.1,0,true);*/

struct Auto_Info
{
    std::string Name; //Limit X
    std::string DisplayName; //Limit 13
    std::vector<std::string> Disciption; //Limit 49 per line
    void* Current_Auto;
};  

extern Auto_Info Auto_Programs[];

void Run_Auto();
void Auton_1();
void Auton_2();
void Auton_3();
void Auton_4();
void Auton_5();
void Auton_6();
void Auton_7();
void Auton_8();
void Auton_9();
void Auton_10();
void Auton_11();
void Auton_12();
void Auton_13();
void Auton_14();
void Auton_15();
void Auton_16();
void Auton_17();
void Auton_18();
void Marco_Skills();