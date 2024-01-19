#include "main.h"
#include <vector>
class Drivetrain {
    public:
    struct Straight_PID_Var{
        double kP;
        double kI;
        double kD;
        double kA;
        Straight_PID_Var(double kP_, double kI_, double kD_, double kA_);
        Straight_PID_Var();
    };
    struct Turn_PID_Var{
        double kP;
        double kI;
        double kD;
        bool Passive_Power;
        Turn_PID_Var(double kP_, double kI_, double kD_,  bool Passive_Power_);
        Turn_PID_Var();
    };
    struct RPM_PID_Var{
        double kP;
        double kI;
        double kD;
        double kF;
        RPM_PID_Var(double kP_, double kI_, double kD_,  double kF_);
        RPM_PID_Var();
    };
    public: 
    std::vector<pros::Motor> leftMotors;
    std::vector<pros::Motor> rightMotors;
    std::vector<pros::Imu> IMU_List;
    double current_Max_RPM;
    double Base_Width;
    double Wheel_Diameter;
    double Gear_Ratio;
    bool RPM_PID_State = false;
    bool Drivetype = false;
    void Set_Drive_Motors(std::vector<pros::Motor>& motors, double speed);
    void Tank_Control();
    void Arcade_Control();
    double Get_Position(char side);
    double Get_RPM(char side);
    double Get_Heading();
    void Reset_Motor_Position();
    public:
    Drivetrain(const std::vector<int>& leftMotorPorts, const std::vector<int>& rightMotorPorts, const std::vector<int>& IMU_Ports , double WheelDiameter, const std::vector<int> Gears);
    void Initialize();
    void Driver_Control();
    void Set_Side_Drivetrain(char side , double speed);
    void Set_Drivetrain(double Left_Side_Speed, double Right_Side_Speed);
    void Change_Brake_Type(char Type);
    void RPM_Controller(RPM_PID_Var variable);
    void AutoDrive(double inches, double maxPct, Straight_PID_Var variable);
    void Auto_Turn(double angle, int maxTurnSp, Turn_PID_Var variable);
};



 














