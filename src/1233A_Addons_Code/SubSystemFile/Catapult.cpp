#include "main.h"
extern int Driver_Catapult_Speed;
extern int Catapult_Down_Pos;
extern int Catapult_Auto_Speed;
extern int Catapult_Wait_Time;
extern int CataPort_PID[3];
bool shoot_cata = false;
void Setcataport(int power)
{
    Catapult = power;
}
void stopCatapult()
{
    Catapult = 0;
}
int Catapultpower = 0;
int CataStop = 0;
void setCatapultMotors()
{

    // One trigger to shoot cata in case of a malfuntion
    if ((controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)))
    {
        Catapultpower = Driver_Catapult_Speed;
        CataStop = 1;
        Setcataport(Catapultpower);
    }
    else
    {
        if (CataStop == 1)
        {
            Catapultpower = 0;
            CataStop = 0;
            Setcataport(Catapultpower);
        }
    }
}
void AutoCatapult()
{
    
    Setcataport(Catapult_Auto_Speed);
    pros::delay(Catapult_Wait_Time);
    stopCatapult();
    double prevError = rotation_sensor.get_position() - Catapult_Down_Pos;
    while(!(rotation_sensor.get_angle() > 4400 && rotation_sensor.get_angle() < 5000 ))
    {
        double Error = rotation_sensor.get_position() - Catapult_Down_Pos;
        double accumError = accumError + Error;
        double Power = Error*CataPort_PID[1] + accumError*CataPort_PID[2] + (Error-prevError)*CataPort_PID[3];
        prevError = Error;
        Setcataport(Power);
        pros::delay(20);
    }
    stopCatapult();
}
void Driver_AutoCatapult()
{
    if ((controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) || (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) || shoot_cata == true)
    {
        AutoCatapult();
    }
}