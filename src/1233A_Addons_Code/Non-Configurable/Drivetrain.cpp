#include "main.h"
extern int Wheel_Size;
extern double Striaght_PID [3];
extern double Turn_PID [4];
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
double getAvgDriveSideDeg(char side)
{
  if(side == 'l'){
    return ((L1Drive.get_position() + L2Drive.get_position() + L3Drive.get_position())/3);
  } else{
    return ((R1Drive.get_position() + R2Drive.get_position() + R3Drive.get_position())/3);
  }
  
}
void ResetDrive()
{
  // Stop the motors
  L1Drive.brake();
  L2Drive.brake();
  L3Drive.brake();
  R1Drive.brake();
  R2Drive.brake();
  R3Drive.brake();
  // Reset encoders
  L1Drive.tare_position();
  L2Drive.tare_position();
  L3Drive.tare_position();
  R1Drive.tare_position();
  R2Drive.tare_position();
  R3Drive.tare_position();
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
void Change_DT_Brake(char Brake_Type)
{
  switch (Brake_Type)
  {
   case 'c':
    L1Drive.set_brake_mode(MOTOR_BRAKE_COAST);
    L2Drive.set_brake_mode(MOTOR_BRAKE_COAST);
    L3Drive.set_brake_mode(MOTOR_BRAKE_COAST);
    R1Drive.set_brake_mode(MOTOR_BRAKE_COAST);
    R2Drive.set_brake_mode(MOTOR_BRAKE_COAST);
    R3Drive.set_brake_mode(MOTOR_BRAKE_COAST);
    break;
   case 'b':
    L1Drive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    L2Drive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    L3Drive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    R1Drive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    R2Drive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    R3Drive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    break;
    case 'h':
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
void AutoDrive(double inches, double maxPct) {
  // Reset the drive and make the brake mode "brake"
  int dir = 0;
  Change_DT_Brake('h');
  ResetDrive();
  if(inches<0)
  {
    dir = 1;
  }
  inches = abs(inches);
  // Initialize variables
  const int wheelDiam = Wheel_Size; // Diameter of the robot wheels in inches
  const int target = (inches / (wheelDiam * 3.14)) * 360 * 0.61; // Target distance converted from inches to encoder ticks; double after 360 is a constant tuned for the robot
  int lAvgTicks = 0; // Left average encoder ticks, needed for alignment
  int rAvgTicks = 0; // Right average encoder ticks, needed for alignment
  int avgTicks = 0; // Overall average encoder ticks
  float currentPower = 0; // Current power to be supplied to the motors
  float lPower = 0; // Left power for the left drive side, needed b/c of alignment
  float rPower = 0; // Right power for the rigth drive side, needed b/c of alignment
  float alignErr = 0; // Alignment error calculated to align each side of the robot

  // PID constants
  double kP = Striaght_PID[0]; // Distance from target * kP
  if (inches < 12) kP *= 2; // Increase kP if driving a short distance
  double kI = Striaght_PID[1]; // Not really necessary, but implemented in case its needed // Total accumulative distance from target * kI
  double kD = Striaght_PID[2]; // Difference between current distance from target and previous distance from target * kD
  double kA = Striaght_PID[3]; // Alignment constant
  double error = 0.0; // Distance from target in current iteration
  double prevError = 0.0; // Distance from target from previous iteration
  double accumulativeError = 0.0; // Total of every calculated error combined

  while(avgTicks < target)
  {
    // PID moment
    currentPower = error*kP + accumulativeError*kI + (error-prevError)*kD;

    // Limit the current power to the allowed maximum
    if (currentPower > maxPct) {
      currentPower = maxPct;
    } else if (currentPower < 5) {
      currentPower = 5;
    }

    // Align each drive side
    alignErr = fabs((lAvgTicks - rAvgTicks)) * kA; // Calculate the alignment error between the two sides
    if(lAvgTicks > rAvgTicks) // If left is ahead of right
    {
      lPower = currentPower - alignErr;
      rPower = currentPower;
    }
    else if(rAvgTicks > lAvgTicks) // If right is ahead of left
    {
      rPower = currentPower - alignErr;
      lPower = currentPower;
    }
    else // If neither is ahead
    {
      lPower = currentPower;
      rPower = currentPower;
    }

    // Reverse the speeds if a backwards direction is passed to the function
    if(dir == 1)
    {
      lPower = lPower * -1;
      rPower = rPower * -1;
    }


    // Make the motors move
    SetLeftDTPower(lPower);
    SetRightDTPower(rPower);

    // Update the average ticks for the next iteration
    rAvgTicks = fabs(getAvgDriveSideDeg('r'));
    lAvgTicks = fabs(getAvgDriveSideDeg('l'));
    avgTicks = (rAvgTicks + lAvgTicks)/2;

    // Update the PID variables
    prevError = error; // Set the previous error to the current error before it is updated
    accumulativeError += prevError; // Add the previous error to the accumuilative error; can't add the current error because that is current, not what it has already driven
    error = target - avgTicks; // Update current error
    
    // Wait to save brain resources
    pros::delay(10);
  }
  ResetDrive(); // Reset the drive encoders and stop all of the motors after driving is completed
}
void Auto_Turn(double angle, int maxTurnSp) {
  Change_DT_Brake('h');
  ResetDrive();

  // Determine which way to turn
  double currHeading = Auto_IMU.get_heading(); // Current heading - updated every iteration

  double shortestAngle = fmod((angle-currHeading+540.0), 360.0)-180.0;
  double prevShortestAngle = shortestAngle;
  double totAccumAngle = 0.0;

  // PID Variables
  double kP = Turn_PID[0];

  kP *= 1 + (((180-abs(shortestAngle))/15)*0.22); // 1 + How far we start from the target/15 * .25 to get multiplier to prevent stall

  //if (fabs(shortestAngle)<90) kP *= 1.3;
  //else if (fabs(shortestAngle)<45) kP *= 1.7;

  const double kI = Turn_PID[1];//0.0017;
  const double kD = Turn_PID[2];//4.00;
  
  const double kdecel = Turn_PID[3];
  
  double targetSpeed = 0.0;
  double currentSpeed = 0.0;
  double speed = 0.0;

  uint32_t escapeTime = pros::millis();
  if (fabs(shortestAngle) < 1.0) { // Don't do anything if pretty much already there
    return;
  }

  while (pros::millis() < escapeTime + 60) { // Exit the loop if the angle is within the margin of error and the speed is below 5 (Speed cutoff prevents overshoot)
    targetSpeed = fabs(shortestAngle) * kP + fabs(totAccumAngle) * kI + (fabs(shortestAngle)-fabs(prevShortestAngle)) * kD; // Multiplies the shortest angle by 100 divided by the initial calculated shortest angle so that the drive starts at 100 and will gradually get lower as the target is neared
    
    if (targetSpeed > maxTurnSp)
      targetSpeed = maxTurnSp;

    // End the loop if the angle and speed show that we are basically there so stalls dont happen
    if (fabs(shortestAngle) < 0.80 && targetSpeed < 1.0) {
       ResetDrive();
       return;
    }
    

    if (shortestAngle < 0) { // Negative = counterclockwise (left turn)
      SetLeftDTPower(-targetSpeed);
      SetRightDTPower(targetSpeed);
    } else if (shortestAngle > 0) { // Positive = clockwise (right turn)
      SetLeftDTPower(targetSpeed);
      SetRightDTPower(-targetSpeed);
    } else { // Default to not turn if there is an error

    }

    currHeading = Auto_IMU.get_heading(); // Current heading - updated every iteration

    prevShortestAngle = shortestAngle;
    shortestAngle = fmod((angle-currHeading+540.0), 360.0)-180.0;

    if (fabs(shortestAngle)-fabs(prevShortestAngle) > 15) // make sure that the angle doesnt change by more than 30 each iteration (to prevent accidental turn around)
      shortestAngle = prevShortestAngle;

    totAccumAngle += fabs(prevShortestAngle-shortestAngle);
    
    if (abs(shortestAngle) > 0.65) escapeTime = pros::millis();

    pros::delay(10); // Save resources
  }
  ResetDrive();
  return;

}