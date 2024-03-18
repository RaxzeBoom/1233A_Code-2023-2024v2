#include "main.h"
    Odometry::Odometry(Drivetrain* dtrain , double Middle_Dist , int middle_port){
        Bot = dtrain;
    }
    void Odometry::Update()
    {   
        // Defining variables
        double prev_right, prev_left, prev_middle, prev_heading;
        double total_right, total_left, total_middle, total,heading;
        double delta_right, delta_left, delta_middle, delta_heading;
        while (true)
        {
            
            double local_x;
            double local_y;
            
            if (delta_heading) {
                double i = sin(delta_heading / 2.0) * 2.0;
                //local_x = (delta_right / delta_heading - left_right_distance) * i;
                //local_y = (delta_middle / delta_heading + middle_distance) * i;
            } else {
                local_x = delta_right;
                local_y = delta_middle;
            }
        }
    }






