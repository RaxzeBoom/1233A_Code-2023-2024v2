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
    Catapult.move_velocity(power);
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
    if ((controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)))
    {
        Catapultpower = Driver_Catapult_Speed;
        CataStop = 1;
        Catapult.move_velocity(130);
    }
    else
    {
        if (CataStop == 1)
        {
            Catapultpower = 0;
            CataStop = 0;
            Catapult.move_velocity(0);
        }
    }
}
void MutiShootCataControl(int Number , double speed ,pros::controller_digital_e_t Button){
    if(controller.get_digital(Button)){
        MutiShootCata(Number , speed);
    }
}
void MutiShootCata(int Number , double speed)
{
    double time = ((Number/speed)*60)+.5;
    int counter = 0;
    while(!(counter >= time*10))
    {
        Setcataport(speed);
        if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {break;}
        pros::delay(100);
        counter++;
    }
    stopCatapult();
}