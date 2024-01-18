#include "main.h"
#include <vector>

    //Makes a Drivetrain Class for controll drivetrain functions{All Left Motor Ports | All Right Motor Ports | The width of the drivetrain | The wheel diamter | Driven gear then Powered gear}
    Drivetrain::Drivetrain(const std::vector<int>& leftMotorPorts, const std::vector<int>& rightMotorPorts, const std::vector<int>& IMU_Ports , double WheelDiameter, const std::vector<int> Gears) {
        for (int port : leftMotorPorts) {
            leftMotors.emplace_back(port,pros::E_MOTOR_GEARSET_06 , false , pros::E_MOTOR_ENCODER_DEGREES);
        }
        for (int port : rightMotorPorts) {
            rightMotors.emplace_back(port,pros::E_MOTOR_GEARSET_06 , false , pros::E_MOTOR_ENCODER_DEGREES);
        }
        for (int port : IMU_Ports){
            IMU_List.emplace_back(port);
        }
        Wheel_Diameter = WheelDiameter;
        Gear_Ratio = Gears[0]/Gears[1];
    }
    void Drivetrain::Set_Drive_Motors(std::vector<pros::Motor>& motors, double speed) {
        for (pros::Motor motor : motors) {
            motor.move(speed);
        }
    }
    void Drivetrain::Tank_Control()
    {
        Set_Drivetrain(controller.get_analog(ANALOG_LEFT_Y),controller.get_analog(ANALOG_RIGHT_Y));
    }
    void Drivetrain::Arcade_Control()
    {
        double left = controller.get_analog(ANALOG_LEFT_Y) + controller.get_analog(ANALOG_RIGHT_X);
        double right = controller.get_analog(ANALOG_LEFT_Y) - controller.get_analog(ANALOG_RIGHT_X);
        Set_Drivetrain(left, right);
    }
    void Drivetrain::Driver_Control()
    {
        if(Drivetype == false){Tank_Control();} else{Arcade_Control();}
        if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN))
        {
          if(Drivetype == false) {Drivetype = true;}
          else {Drivetype = false;}
          while((controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN))){
             pros::delay(10);
          } 
        }
    }
    void Drivetrain::Set_Side_Drivetrain(char side , double speed)
    {
        if(side == 'l' ^ 'L')
        {
        Set_Drive_Motors(rightMotors , speed);
        } else if(side == 'r' ^ 'R')
        {
        Set_Drive_Motors(leftMotors , speed); 
        } else
        { return;}
    }
    void Drivetrain::Set_Drivetrain(double Left_Side_Speed, double Right_Side_Speed)
    {
        Set_Drive_Motors(leftMotors , Left_Side_Speed);
        Set_Drive_Motors(rightMotors , Right_Side_Speed);
    }
    double Drivetrain::Degrees_Traveled(char side)
    {
        double Total_Ticks = 0;
        if(side == 'l' ^ 'L')
        {
            for (pros::Motor Motor_Check : leftMotors)
            {
                Total_Ticks = Total_Ticks + Motor_Check.get_position();
                
            }
            return Total_Ticks/leftMotors.size();
        } else if(side == 'r' ^ 'R')
        {
            for (pros::Motor Motor_Check : rightMotors)
            {
                Total_Ticks = Total_Ticks + Motor_Check.get_position();
            }
            return Total_Ticks/rightMotors.size();
        } 
       
        return 0;
    }   
    double Drivetrain::Drive_RPM(char side)
    {
        double Total_RPM;
        if(side == 'l' ^ 'L')
        {
            for (pros::Motor Motor_Check : leftMotors)
            {
                Total_RPM+= Motor_Check.get_actual_velocity();
            }
            return Total_RPM/leftMotors.size();
        } else if(side == 'r' ^ 'R')
        {
            for (pros::Motor Motor_Check : rightMotors)
            {
                Total_RPM+= Motor_Check.get_position();
            }
            return Total_RPM/rightMotors.size();
        } 
        return 0;
    }
    void Drivetrain::Auto_Initialize(){
        for (pros::Imu IMU : IMU_List){
            IMU.reset();
        }
    }
    double Drivetrain::Get_Heading(){
        double total = 0;
        for(pros::Imu IMU : IMU_List){
            total = total + IMU.get_heading();
        }
        return total/IMU_List.size();
    }
    void Drivetrain::Reset_Motor_POS()
    {
        for (pros::Motor Motor : leftMotors)
        {
            Motor.brake();
            Motor.tare_position();
        }
        for (pros::Motor Motor : rightMotors)
        {
            Motor.brake();
            Motor.tare_position();
        }
    }
   //Changes the Brake Type for the drivetrain {B for Brake C for Coast H for Hold}
    void Drivetrain::Change_Brake_Type(char Type)
    {
        switch (Type)
        {
        case 'B':
            for (pros::Motor Motor : leftMotors){
                Motor.set_brake_mode(MOTOR_BRAKE_BRAKE);
            }
            for (pros::Motor Motor : rightMotors){
                Motor.set_brake_mode(MOTOR_BRAKE_BRAKE);
            }
            break;
        case 'C':
            for (pros::Motor Motor : leftMotors){
                Motor.set_brake_mode(MOTOR_BRAKE_COAST);
            }
            for (pros::Motor Motor : rightMotors){
                Motor.set_brake_mode(MOTOR_BRAKE_COAST);
            }
            break;
        case 'H':
            for (pros::Motor Motor : leftMotors){
                Motor.set_brake_mode(MOTOR_BRAKE_HOLD);
            }
            for (pros::Motor Motor : rightMotors){
                Motor.set_brake_mode(MOTOR_BRAKE_HOLD);
            }
            break;
        default:
            break;
        }
    }
    Drivetrain::Straight_PID_Var::Straight_PID_Var() {}
    Drivetrain::Straight_PID_Var::Straight_PID_Var(double kP_, double kI_, double kD_, double kA_)
    {
        kP = kP_;
        kI = kI_;
        kD = kD_;
        kA = kA_;
    };
    Drivetrain::Turn_PID_Var::Turn_PID_Var() {}
    Drivetrain::Turn_PID_Var::Turn_PID_Var(double kP_, double kI_, double kD_, bool Passive_Power_)
    {
        kP = kP_;
        kI = kI_;
        kD = kD_;
        Passive_Power = Passive_Power_;
    };
    void Drivetrain::AutoDrive(double inches, double maxPct, Straight_PID_Var variable) {
        // Reset the drive and make the brake mode "brake"
        int dir = 0;
        Change_Brake_Type('H');
        Reset_Motor_POS();
        if(inches<0)
        {
            dir = 1;
        }
        inches = abs(inches);
        // Initialize variables
        const int target = (inches / (Wheel_Diameter * 3.14)) * 360 * 1.1; // Target distance converted from inches to encoder ticks; double after 360 is a constant tuned for the robot
        int lAvgTicks = 0; // Left average encoder ticks, needed for alignment
        int rAvgTicks = 0; // Right average encoder ticks, needed for alignment
        int avgTicks = 0; // Overall average encoder ticks
        float currentPower = 0; // Current power to be supplied to the motors
        float lPower = 0; // Left power for the left drive side, needed b/c of alignment
        float rPower = 0; // Right power for the rigth drive side, needed b/c of alignment
        float alignErr = 0; // Alignment error calculated to align each side of the robot

        // PID constants
        double kP = variable.kP; // Distance from target * kP
        if (inches < 12) kP *= 2; // Increase kP if driving a short distance
        double kI = variable.kI; // Not really necessary, but implemented in case its needed // Total accumulative distance from target * kI
        double kD = variable.kD; // Difference between current distance from target and previous distance from target * kD
        double kA = variable.kA; // Alignment constant
        double error = 0.0; // Distance from target in current iteration
        double prevError = 0.0; // Distance from target from previous iteration
        double accumulativeError = 0.0; // Total of every calculated error combined

        while(fabs(avgTicks) < fabs(target))
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
            Set_Drivetrain(lPower,rPower);

            // Update the average ticks for the next iteration
            rAvgTicks = fabs(Degrees_Traveled('r'));
            lAvgTicks = fabs(Degrees_Traveled('l'));
            avgTicks = (rAvgTicks + lAvgTicks)/2;

            // Update the PID variables
            prevError = error; // Set the previous error to the current error before it is updated
            accumulativeError += prevError; // Add the previous error to the accumuilative error; can't add the current error because that is current, not what it has already driven
            error = target - avgTicks; // Update current error
            
            // Wait to save brain resources
            pros::delay(10);
        }
        Reset_Motor_POS(); // Reset the drive encoders and stop all of the motors after driving is completed
        }
    void Drivetrain::Auto_Turn(double angle, int maxTurnSp, Turn_PID_Var variable) {
        Reset_Motor_POS();
        Change_Brake_Type('H');
        // Determine which way to turn
        double currHeading = Get_Heading(); // Current heading - updated every iteration
        
        double shortestAngle = fmod((angle-currHeading+540.0), 360.0)-180.0;
        double prevShortestAngle = shortestAngle;
        double totAccumAngle = 0.0;

        // PID Variables
        double kP = variable.kP;

        kP *= 1 + (((180-abs(shortestAngle))/15)*0.22); // 1 + How far we start from the target/15 * .25 to get multiplier to prevent stall

        //if (fabs(shortestAngle)<90) kP *= 1.3;
        //else if (fabs(shortestAngle)<45) kP *= 1.7;

        const double kI = variable.kI;//0.0017;
        const double kD = variable.kD;//4.00;
        
        
        double targetSpeed = 0.0;
        double currentSpeed = 0.0;
        double speed = 0.0;

        uint32_t escapeTime = pros::millis();
        if (fabs(shortestAngle) < 1.0 && targetSpeed < 2.0) { // Don't do anything if pretty much already there
            return;
        }

        while (true) { // Exit the loop if the angle is within the margin of error and the speed is below 5 (Speed cutoff prevents overshoot)
            targetSpeed = fabs(shortestAngle) * kP + fabs(totAccumAngle) * kI + (fabs(shortestAngle)-fabs(prevShortestAngle)) * kD; // Multiplies the shortest angle by 100 divided by the initial calculated shortest angle so that the drive starts at 100 and will gradually get lower as the target is neared
            

            // End the loop if the angle and speed show that we are basically there so stalls dont happen
            if (fabs(shortestAngle) < 0.80 && targetSpeed < 1.0) {
            Reset_Motor_POS();
            return;
            }
            if(variable.Passive_Power == true){
                if(targetSpeed > 0){
                    targetSpeed = fmax(targetSpeed, 25);
                } else{
                    targetSpeed = fmin(targetSpeed, -25);
                }
            }
            if (shortestAngle < 0) { // Negative = counterclockwise (left turn)
            Set_Drivetrain(-targetSpeed,targetSpeed);
            } else if (shortestAngle > 0) { // Positive = clockwise (right turn)
            Set_Drivetrain(targetSpeed,-targetSpeed);
            } else { // Default to not turn if there is an error

            }
            controller.print(1,1,"%d   ",Get_Heading());
            currHeading = Get_Heading(); // Current heading - updated every iteration

            prevShortestAngle = shortestAngle;
            shortestAngle = fmod((angle-currHeading+540.0), 360.0)-180.0;

            if (fabs(shortestAngle)-fabs(prevShortestAngle) > 15) // make sure that the angle doesnt change by more than 30 each iteration (to prevent accidental turn around)
            shortestAngle = prevShortestAngle;

            totAccumAngle += fabs(prevShortestAngle-shortestAngle);
            
            if (abs(shortestAngle) > 0.65) escapeTime = pros::millis();

            pros::delay(10); // Save resources
        }
        Reset_Motor_POS();
        return;

}




