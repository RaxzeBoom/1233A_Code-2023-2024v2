#include "main.h"
class Pnumatics {
    public:
    struct Button_Com{
        pros::controller_digital_e_t But;
        std::vector<int> Num;
        bool state;
        bool but_state;
        int order = 0;
    };
    private:
    std::vector<pros::ADIDigitalOut> Pnumatic_List;
    std::vector<pros::controller_digital_e_t> Button_List;
    std::vector<Button_Com> Combos;
    bool reverse;
    bool state;
    bool Driver_Used;
    bool Driver_Vector_Used;
    bool Button_State;
    public:
    Pnumatics(std::vector<char> adi_port);
    Pnumatics(std::vector<char> adi_port,bool reverse_);
    Pnumatics(std::vector<char> adi_port, pros::controller_digital_e_t Button_);
    Pnumatics(std::vector<char> adi_port, pros::controller_digital_e_t Button_,bool reverse_);
    Pnumatics(std::vector<char> adi_port, std::vector<Button_Com> Button_Combo,bool reverse_);
    
    void Out();
    void Out(std::vector<int> Pistons);
    void In();
    void In(std::vector<int> Pistons);
    void Toggle();
    void Toggle(Button_Com Pnumatics);
    void Control();
};