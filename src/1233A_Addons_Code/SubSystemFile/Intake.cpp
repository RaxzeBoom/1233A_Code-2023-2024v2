#include "main.h"
extern int Driver_Intake_Speed;
void SetIntake(int power)
{
    Intake = power;
}
void StopIntake()
{
    Intake = 0;
}
void Driver_Intake() {
    int Intakepower = 0;
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        Intakepower =Driver_Intake_Speed;
    }
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        Intakepower =Driver_Intake_Speed*-1;
    }
    SetIntake(Intakepower);
}