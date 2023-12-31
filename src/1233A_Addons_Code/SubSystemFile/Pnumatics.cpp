#include "main.h"
bool Intake_Toggle = false;
bool Wings_Toggle = false;
void Intake_Out() {
    Intake_Lift.set_value(true);
}
void Intake_In()
{
    Intake_Lift.set_value(false);
}
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
//Driver Controller Functions
void Intake_Lift_Driver_Control()
{
    if((controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)))
    {
    if(Intake_Toggle == false)
        {
         Intake_Out();
          Intake_Toggle = true;
        }
         else
        {
          Intake_In();
          Intake_Toggle = false;
        }
    }
    while((controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)))
    {
        pros::delay(10);
    }
}
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
    if((controller.get_digital(pros::E_CONTROLLER_DIGITAL_X))){
        Hang_Out();
    }
}