#include "main.h"
bool Toggle_GUI = true;
void Drive_Train_Heat_Drawer(int Drive_Train_Heat)
{
    if(Drive_Train_Heat < 25)
    {
        pros::screen::set_pen(COLOR_GREEN);
    } else if(Drive_Train_Heat <50)
    {
        pros::screen::set_pen(COLOR_YELLOW);
    } else if (Drive_Train_Heat < 70)
    {
        pros::screen::set_pen(COLOR_ORANGE_RED);
    } else
    {
        pros::screen::set_pen(COLOR_RED);
    }
        pros::screen::fill_rect(40,20,140,200);
        pros::screen::set_pen(COLOR_BLACK);
        pros::screen::draw_rect(40,20,140,200);
        pros::screen::set_pen(COLOR_GREEN);
        pros::screen::print(pros::E_TEXT_SMALL,40,150,"Drive Train %3d", Drive_Train_Heat);
}
void Catapult_Heat_Drawer(int Catapult_Heat)
{
    if(Catapult_Heat < 25)
    {
        pros::screen::set_pen(COLOR_GREEN);
    } else if(Catapult_Heat <50)
    {
        pros::screen::set_pen(COLOR_YELLOW);
    } else if (Catapult_Heat < 70)
    {
        pros::screen::set_pen(COLOR_ORANGE_RED);
    } else
    {
        pros::screen::set_pen(COLOR_RED);
    }
        pros::screen::fill_rect(180,20,280,200);
        pros::screen::set_pen(COLOR_BLACK);
        pros::screen::draw_rect(180,20,280,200);
        pros::screen::print(pros::E_TEXT_SMALL,180,150,"Catapult %3d", Catapult_Heat);
}
void Intake_Heat_Drawer(int Intake_Heat)
{
    if(Intake_Heat < 25)
    {
        pros::screen::set_pen(COLOR_GREEN);
    } else if(Intake_Heat <50)
    {
        pros::screen::set_pen(COLOR_YELLOW);
    } else if (Intake_Heat < 70)
    {
        pros::screen::set_pen(COLOR_ORANGE_RED);
    } else
    {
        pros::screen::set_pen(COLOR_RED);
    }
        pros::screen::fill_rect(340,20,440,200);
        pros::screen::set_pen(COLOR_BLACK);
        pros::screen::draw_rect(340,20,440,200);
        pros::screen::print(pros::E_TEXT_SMALL,340,150,"Intake %3d", Intake_Heat);
}
void Start_GUI()
{
    pros::screen::set_pen(COLOR_GRAY );
    pros::screen::fill_rect(0,0,480,240);
    while(Toggle_GUI)
    {
        int Drive_Train_Heat = (R1Drive.get_temperature() + R2Drive.get_temperature() + R3Drive.get_temperature() + L1Drive.get_temperature() + L2Drive.get_temperature() + L3Drive.get_temperature())/6;
        int Catapult_Heat = Catapult.get_temperature();
        int Intake_Heat = Intake.get_temperature();
        Drive_Train_Heat_Drawer(Drive_Train_Heat);
        Catapult_Heat_Drawer(Catapult_Heat);
        Intake_Heat_Drawer(Intake_Heat);
        pros::delay(1000);
    }
}