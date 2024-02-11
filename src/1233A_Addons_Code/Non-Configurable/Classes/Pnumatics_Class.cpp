#include "main.h"
    Pnumatics::Pnumatics(std::vector<char> adi_port)
    {
        for (char port : adi_port)
        {
            Pnumatic_List.emplace_back(port);
        }
    }
    Pnumatics::Pnumatics(std::vector<char> adi_port, bool reverse_)
    {
        for (char port : adi_port)
        {
            Pnumatic_List.emplace_back(port);
        }
        reverse = reverse_;
    }
    Pnumatics::Pnumatics(std::vector<char> adi_port, pros::controller_digital_e_t Button_)
    {
        for (char port : adi_port)
        {
            Pnumatic_List.emplace_back(port);
        }
        Button = Button_;
        Driver_Used = true;
    }
    Pnumatics::Pnumatics(std::vector<char> adi_port, pros::controller_digital_e_t Button_,bool reverse_)
    {
        for (char port : adi_port)
        {
            Pnumatic_List.emplace_back(port);
        }
        Button = Button_;
        reverse = reverse_;
        Driver_Used = true;
    }
    void Pnumatics::Out()
    {
        for (pros::ADIDigitalOut Pnumatic : Pnumatic_List)
        {
            if (reverse == false){
                Pnumatic.set_value(true);
            } else{
                Pnumatic.set_value(false);
            }
        }
        state = true;
    }
    void Pnumatics::In()
    {
        for (pros::ADIDigitalOut Pnumatic : Pnumatic_List)
        {
            if (reverse == false){
                Pnumatic.set_value(false);
            } else{
                Pnumatic.set_value(true);  
            }
        }
        state = false;
    }
    void Pnumatics::Toggle()
    {
        for (pros::ADIDigitalOut Pnumatic : Pnumatic_List)
        {
            if(state){
                In();
            }else{
                Out();
            }
        }
    }
    void Pnumatics::Control()
    {
        if(Driver_Used == true)
        {
            if(controller.get_digital(Button)){
                Toggle();
            }
            while(controller.get_digital(Button)){
                pros::delay(10);
            }
        }
    }