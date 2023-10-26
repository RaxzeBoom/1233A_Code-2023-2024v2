#include "main.h"
extern int Driver_Catapult_Speed;
extern int Catapult_Down_Pos;
extern int Catapult_Auto_Speed;
extern double CataPort_PID[3];
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
void AutoCatapult(int Change)
{
    
    Setcataport(Catapult_Auto_Speed);
    while(!(rotation_sensor.get_angle() > 0 & rotation_sensor.get_angle() < Catapult_Down_Pos-(200+Change+1000)))
    {
        pros::delay(20);
    }
    stopCatapult();
    double prevError = rotation_sensor.get_position() - Catapult_Down_Pos;
    while(!(rotation_sensor.get_angle() > Catapult_Down_Pos-(200+Change) && rotation_sensor.get_angle() < Catapult_Down_Pos+3000 ))
    {
        double Error = rotation_sensor.get_position() - Catapult_Down_Pos;
        double accumError = accumError + Error;
        double Power = Error*CataPort_PID[0] + accumError*CataPort_PID[1] + (Error-prevError)*CataPort_PID[2];
        prevError = Error;
        Setcataport(fabs(Power));
        pros::delay(6);
    }
    stopCatapult();
}
void Driver_AutoCatapult()
{
    if ((controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) || (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) || shoot_cata == true)
    {
        AutoCatapult(0);
    }
    if ((controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)))
    {
        AutoCatapult(2000);
    }
}
void MutiShootCata(int Number)
{
    int Cata_Counter = 0;
    int Cata_Switch = 1;
    while(Cata_Counter <= Number)
    {
        Setcataport(127);
        if(rotation_sensor.get_angle() > 3000 & rotation_sensor.get_angle() < 4000 & Cata_Switch == 1)
        {
            Cata_Counter++;
            Cata_Switch = 0;
        }
        if(rotation_sensor.get_angle() > 2000 & rotation_sensor.get_angle() < 3000)
        {
            Cata_Switch = 1;
        }
        pros::delay(20);
    }
    stopCatapult();
}