#include "main.h"
    //Makes a Drivetrain Class for controlling drivetrain functions{All Left Motor Ports | All Right Motor Ports | All IMUs | The wheel diamter | Driven gear then Powered gear}
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
    //Sets a list of Motors to a set speed up to 127
    void Drivetrain::Set_Drive_Motors(std::vector<pros::Motor>& motors, double speed) {
        for (pros::Motor motor : motors) {
            motor.move(speed);
        }
    }
    //Give basic tank drive in driver control
    void Drivetrain::Tank_Control()
    {
        Set_Drivetrain(controller.get_analog(ANALOG_LEFT_Y),controller.get_analog(ANALOG_RIGHT_Y));
    }
    //Give basic split arcade in driver control
    void Drivetrain::Arcade_Control()
    {
        double left = controller.get_analog(ANALOG_LEFT_Y) + controller.get_analog(ANALOG_RIGHT_X);
        double right = controller.get_analog(ANALOG_LEFT_Y) - controller.get_analog(ANALOG_RIGHT_X);
        Set_Drivetrain(left, right);
    }
    //Lets the driver switct bewteen Tank & arcade using down arrow.
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
    //More user friendly way to set a side of the drivetrian 'L' or'l' for left & 'R' or 'r' for right
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
    //Sets each side of the drivetrain going from left to right
    void Drivetrain::Set_Drivetrain(double Left_Side_Speed, double Right_Side_Speed)
    {
        Set_Drive_Motors(leftMotors , Left_Side_Speed);
        Set_Drive_Motors(rightMotors , Right_Side_Speed);
    }
    //Runs basic commands for drivetrain
    void Drivetrain::Initialize(){
        for (pros::Imu IMU : IMU_List){
            IMU.reset();
        }
    }
    //Resets the Motor positions while stoping them
    void Drivetrain::Reset_Motor_Position()
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
    //Get the average positions of one side of the drivetrain 'L' or'l' for left & 'R' or 'r' for right
    double Drivetrain::Get_Position(char side)
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
    //Get the average RPM of one side of the drivetrain 'L' or'l' for left & 'R' or 'r' for right
    double Drivetrain::Get_RPM(char side)
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
                Total_RPM+= Motor_Check.get_actual_velocity();
            }
            return Total_RPM/rightMotors.size();
        } 
        return 0;
    }
    //Get the average heading from the IMU
    double Drivetrain::Get_Heading(){
        double total = 0;
        for(pros::Imu IMU : IMU_List){
            total = total + IMU.get_heading();
        }
        return total/IMU_List.size();
    }
    //Sets the heading on all IMU
    void Drivetrain::Set_Heading(double heading_){
        for(pros::Imu IMU : IMU_List){
            IMU.set_heading(heading_);
        }
    }
   //Changes the Brake Type for the drivetrain {B for Brake C for Coast H for Hold}
    void Drivetrain::Change_Brake_Type(Brake_Type Type)
    {
        pros::motor_brake_mode_e_t prosBrakeType;
        switch (Type)
        {
        case BRAKE:
            prosBrakeType = pros::E_MOTOR_BRAKE_BRAKE;
            break;
        case COAST:
            prosBrakeType = pros::E_MOTOR_BRAKE_COAST;
            break;
        case HOLD:
            prosBrakeType = pros::E_MOTOR_BRAKE_HOLD;
            break;
        default:
            prosBrakeType = pros::E_MOTOR_BRAKE_COAST;
            break;
        }
        for (pros::Motor Motor : leftMotors){
            Motor.set_brake_mode(prosBrakeType);
        }
        for (pros::Motor Motor : rightMotors){
            Motor.set_brake_mode(prosBrakeType);
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
    void Drivetrain::driveDistance(double speed, double time){
        Set_Drivetrain(speed,speed);
        pros::delay(time);
        Set_Drivetrain(0,0);
    }
    void Drivetrain::driveDistance(std::vector<double> speed, double time){
        Set_Drivetrain(speed.at(0),speed.at(1));
        pros::delay(time);
        Set_Drivetrain(0,0);
    }
    void Drivetrain::driveDistance(double inches, double maxSpeed, Straight_PID_Var variable) {
    Change_Brake_Type(BRAKE);
    Reset_Motor_Position();

    // Constants and initial calculations
    const double target = (inches / (Wheel_Diameter * M_PI)) * 360 * 1.1 ;
    const double Max = 127; //Max speed for motors

    // PID constants, adjust or utilize as passed from the structure
    double kP = variable.kP * (inches < 12 ? 2 : 1);
    double kI = variable.kI, kD = variable.kD;

    // P constants for heading correction
    double kP_heading = variable.kA;

    // Initialize encoder readings and PID variables
    double lAvgTicks = 0, rAvgTicks = 0, avgTicks = 0;
    double error = 0, prevError = 0, accumulativeError = 0;
    double headingError = 0;
    while (fabs(avgTicks) < fabs(target)) {
        // Calculate PID output
        double currentPower = error * kP + accumulativeError * kI + (error - prevError) * kD;
        currentPower = std::clamp(currentPower,-maxSpeed,maxSpeed);// Constrain power within max
        
        // Calculate heading error and correction
        headingError = fmod((Target_Heading-Get_Heading()+540.0), 360.0)-180.0;

        // Simple proportional correction for heading
        double headingCorrection = headingError * kP_heading;

        // Apply heading correction to motor powers
        double lPower = currentPower + headingCorrection;
        double rPower = currentPower - headingCorrection;

        // Constrain Power to highest and lowest power of motors
        lPower = std::clamp(lPower,-Max,Max);
        rPower = std::clamp(rPower,-Max,Max);

        // Apply direction and set motor powers
        Set_Drivetrain(lPower, rPower);

        // Update encoders and error for next iteration
        lAvgTicks = Get_Position('l');
        rAvgTicks = Get_Position('r');
        avgTicks = (lAvgTicks + rAvgTicks) / 2;
        prevError = error;
        error = target - avgTicks; // Adjust for direction

        // Reset accumulative error under specific conditions
        if(fabs(error) < 0.5 || fabs(error) > 150) accumulativeError = 0;
        else accumulativeError += error;

        pros::delay(10); // Delay to save resources
    }

    Reset_Motor_Position(); // Reset motors encoders at the end
    }
    void Drivetrain::Turn(double angle, double maxTurnSp, Turn_PID_Var variable) {
        Reset_Motor_Position();
        Change_Brake_Type(BRAKE);
        Target_Heading = angle;
        // Determine which way to turn
        double shortestAngle = fmod((angle-Get_Heading()+540.0), 360.0)-180.0;
        double prevShortestAngle = shortestAngle;
        double totAccumAngle = 0.0;
        // PID Variables
        const double kP = variable.kP;
        const double kI = variable.kI;
        const double kD = variable.kD;
        int Counter = 0;
        double targetSpeed = 0.0;
        double currentSpeed = 0.0;
        double speed = 0.0;
        while (true) { // Exit the loop if the angle is within the margin of error and the speed is below 5 (Speed cutoff prevents overshoot)
            targetSpeed = fabs(shortestAngle) * kP + fabs(totAccumAngle) * kI + (fabs(shortestAngle)-fabs(prevShortestAngle)) * kD; // Multiplies the shortest angle by 100 divided by the initial calculated shortest angle so that the drive starts at 100 and will gradually get lower as the target is neared
            currentSpeed = (Get_RPM('l') + Get_RPM('r'))/2;

            // End the loop if the angle and speed show that we are basically there so stalls dont happen
            if (fabs(shortestAngle) < 0.80 && currentSpeed < .8) {
            Counter++;
            Reset_Motor_Position();
            return;
            }
            if(variable.Passive_Power == true){
                if(targetSpeed > 0){
                    targetSpeed = fmax(targetSpeed, 17);
                } else{
                    targetSpeed = fmin(targetSpeed, -17);
                }
            }
            if (shortestAngle < 0) { // Negative = counterclockwise (left turn)
            Set_Drivetrain(-targetSpeed,targetSpeed);
            } else if (shortestAngle > 0) { // Positive = clockwise (right turn)
            Set_Drivetrain(targetSpeed,-targetSpeed);
            } else { // Default to not turn if there is an error

            }
            controller.print(1,1,"%f \n", Get_Heading());
            Get_Heading(); // Current heading - updated every iteration

            prevShortestAngle = shortestAngle;
            shortestAngle = fmod((angle-Get_Heading()+540.0), 360.0)-180.0;

            if (fabs(shortestAngle)-fabs(prevShortestAngle) > 15) // make sure that the angle doesnt change by more than 30 each iteration (to prevent accidental turn around)
            shortestAngle = prevShortestAngle;

            totAccumAngle += fabs(shortestAngle);
            if(fabs(shortestAngle) < .5)
            {
                totAccumAngle = 0;
            }
            if(fabs(shortestAngle) > 15)
            {
                totAccumAngle = 0;
            }
            pros::delay(10); // Save resources
        }
        Reset_Motor_Position();
        //return;

}
