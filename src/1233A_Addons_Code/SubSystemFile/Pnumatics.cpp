#include "main.h"
bool Intake_Toggle = false;
bool Wings_Toggle = false;
bool Hang_Toggle = false;
/*
void Intake_Out() {
    Intake_Lift.set_value(true);
}
void Intake_In()
{
    Intake_Lift.set_value(false);
}*/
void Wings_Out()
{
    Wing.set_value(true);
}
void Wings_In()
{
    Wing.set_value(false);
}
void Hang_Out()
{
    Hang.set_value(true);
}
void Hang_In()
{
    Hang.set_value(false);
}
//Driver Controller Functions
void Wings_Driver_Control()
{
    if((controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)))
    {
    if(Wings_Toggle == false)
        {
          Wings_Out();
          Wings_Toggle = true;
        }
         else
        {
          Wings_In();
          Wings_Toggle = false;
        }
    }
    while((controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)))
    {
        pros::delay(10);
    }
}
void Hang_Driver_Control(){
    if((controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)))
    {
    if(Hang_Toggle == false)
        {
          Hang_Out();
          Hang_Toggle = true;
        }
         else
        {
          Hang_In();
          Hang_Toggle = false;
        }
    }
    while((controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)))
    {
        pros::delay(10);
    }
}