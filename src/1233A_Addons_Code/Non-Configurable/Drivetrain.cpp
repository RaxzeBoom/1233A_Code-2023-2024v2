#include "main.h"
void SetLeftDTPower (int power)
{
    L1Drive = power;
    L2Drive = power;
    L3Drive = power;
}
void SetRightDTPower (int power)
{
    R1Drive = power;
    R2Drive = power;
    R3Drive = power;
}
void TDrive()
{
  SetRightDTPower(controller.get_analog(ANALOG_RIGHT_Y));
  SetLeftDTPower(controller.get_analog(ANALOG_LEFT_Y));
}
void ADrive()
{
    int turn = controller.get_analog(ANALOG_RIGHT_X);
    int power = controller.get_analog(ANALOG_LEFT_Y);
    int left = power + turn;
    int right = power - turn;
    SetRightDTPower(right);
    SetLeftDTPower(left);
}
//1 is Coast 2 is Brake 3 is Hold   
void Change_DT_Brake(int Brake_Type)
{
  switch (Brake_Type)
  {
  case 1:
    L1Drive.set_brake_mode(MOTOR_BRAKE_COAST);
    L2Drive.set_brake_mode(MOTOR_BRAKE_COAST);
    L3Drive.set_brake_mode(MOTOR_BRAKE_COAST);
    R1Drive.set_brake_mode(MOTOR_BRAKE_COAST);
    R2Drive.set_brake_mode(MOTOR_BRAKE_COAST);
    R3Drive.set_brake_mode(MOTOR_BRAKE_COAST);
    break;
   case 2:
    L1Drive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    L2Drive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    L3Drive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    R1Drive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    R2Drive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    R3Drive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    break;
    case 3:
    L1Drive.set_brake_mode(MOTOR_BRAKE_HOLD);
    L2Drive.set_brake_mode(MOTOR_BRAKE_HOLD);
    L3Drive.set_brake_mode(MOTOR_BRAKE_HOLD);
    R1Drive.set_brake_mode(MOTOR_BRAKE_HOLD);
    R2Drive.set_brake_mode(MOTOR_BRAKE_HOLD);
    R3Drive.set_brake_mode(MOTOR_BRAKE_HOLD);
    break;
  default:
    break;
  }
}
bool drive_type = false;
void Basic_Control()
{
  if(drive_type == false)
   {
    TDrive();
   }
   else{
    ADrive();
   }
   if((controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)))
    {
      if( drive_type == false){
         drive_type = true;
      }
      else 
      {
         drive_type = false;
      }
      while((controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)))
      {
        pros::delay(10);
      }

    }
}