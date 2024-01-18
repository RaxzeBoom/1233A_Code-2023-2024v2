#include "main.h"
extern int Driver_Catapult_Speed;
extern int Catapult_Down_Pos;
extern int Catapult_Auto_Speed;
extern int Change;
extern int Catapilt_Middle_Pos;
extern double CataPort_PID[3];
bool shoot_cata = false;
bool lower_cata = false;
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
    while(!(rotation_sensor.get_position() < Catapult_Down_Pos - 500))
    {
        pros::delay(20);
    }
    stopCatapult();
    double prevError = Catapult_Down_Pos-(Change) - rotation_sensor.get_position();
    while(!((controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) & (rotation_sensor.get_position() > Catapult_Down_Pos - (700 + Change)))) & !(controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)))
    {
        if ((controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT))) {Change = Catapilt_Middle_Pos;}
        double Error = Catapult_Down_Pos-(Change) - rotation_sensor.get_position();
        double accumError = accumError + Error;
        double Power = Error*CataPort_PID[0] + accumError*CataPort_PID[1] + (Error-prevError)*CataPort_PID[2];
        prevError = Error;
        Setcataport(Power);
        pros::delay(6);
    }
    stopCatapult();
}
void Driver_AutoCatapult()
{
    if ((controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) || (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) || shoot_cata == true)
    {
        Change = 0;
        AutoCatapult();
    }
    if ((controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) || lower_cata == true)
    {
        Change = Catapilt_Middle_Pos;
        AutoCatapult();
    }
}
void MutiShootCata(int Number , double speed)
{
    int Cata_Counter = 0;
    bool Cata_Switch = false;
    while(Cata_Counter <= Number ^ (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)))
    {
        Setcataport(speed);
        if(rotation_sensor.get_angle() > 3000 & rotation_sensor.get_angle() < 4000 & Cata_Switch == false)
        {
            Cata_Counter++;
            Cata_Switch = true;
        }
        if(rotation_sensor.get_angle() > 2000 & rotation_sensor.get_angle() < 3000)
        {
            Cata_Switch = false;
        }
        pros::delay(20);
    }
    stopCatapult();
}