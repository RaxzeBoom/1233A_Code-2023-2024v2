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
        Button_List.emplace_back(Button_);
        Driver_Used = true;
    }
    Pnumatics::Pnumatics(std::vector<char> adi_port, pros::controller_digital_e_t Button_,bool reverse_)
    {
        for (char port : adi_port)
        {
            Pnumatic_List.emplace_back(port);
        }
        Button_List.emplace_back(Button_);
        reverse = reverse_;
        Driver_Used = true;
    }
    Pnumatics::Pnumatics(std::vector<char> adi_port, std::vector<Button_Com> Button_Combo,bool reverse_)
    {
        for (char port : adi_port)
        {
            Pnumatic_List.emplace_back(port);
        }
        Combos = Button_Combo;
        reverse = reverse_;
        for (size_t i = 0; i < Combos.size(); i++)
        {
            Combos[i].state = i;
        }
        Driver_Vector_Used = true;
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
    void Pnumatics::Out(std::vector<int> Pistons)
    {
        for(int num : Pistons)
        {
            num--;
            if(num < 0 || num > Pnumatic_List.size()) continue;
            if (reverse == false){
                Pnumatic_List[num].set_value(true);
            } else{
                Pnumatic_List[num].set_value(false);
            }
        }
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
    void Pnumatics::In(std::vector<int> Pistons)
    {
        for(int num : Pistons)
        {
            num--;
            if(num < 0 || num > Pnumatic_List.size()) continue;
            if (reverse == false){
                Pnumatic_List[num].set_value(false);
            } else{
                Pnumatic_List[num].set_value(true);
            }
        }
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
    void Pnumatics::Toggle(Button_Com Pnumatics)
    {
        if(Pnumatics.state){
            In(Pnumatics.Num);
            Combos[Pnumatics.order].state = false;
        }else{
            Out(Pnumatics.Num);
            Combos[Pnumatics.order].state = true;
        }
    }
    void Pnumatics::Control()
    {
        if(Driver_Used == true)
        {
            if(controller.get_digital(Button_List[0]) & Button_State == false){
                Toggle();
                Button_State = true;
            }
            if(!controller.get_digital(Button_List[0]))
            {
                Button_State = false;
            }
        } else if(Driver_Vector_Used == true)
        {
            for(Button_Com Pistons : Combos)
            {
                if(controller.get_digital(Pistons.But) & Combos[Pistons.order].but_state == false){
                Toggle(Pistons);
                Combos[Pistons.order].but_state = true;
                }
                if(!controller.get_digital(Pistons.But))
                {
                    Combos[Pistons.order].but_state = false;
                }
            }
        }
    }