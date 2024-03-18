#include "main.h"

class Odometry
{
public:
    struct Point
    {
        double X;
        double Y;
    };
    Point Position = {0,0};

private:
    Drivetrain* Bot;
    double Middle_Wheel;
    double Bot_Width;
public:
    bool Using_Middle_Wheel = false;
    Odometry(Drivetrain* dtrain , double Bot_Width_ , int middle_port);
    void Update();

};





