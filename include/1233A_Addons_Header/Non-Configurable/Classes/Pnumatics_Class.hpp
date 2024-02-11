#include "main.h"
class Pnumatics {
    private:
    std::vector<pros::ADIDigitalOut> Pnumatic_List;
    pros::controller_digital_e_t Button;
    bool reverse;
    bool state;
    bool Driver_Used;
    public:
    Pnumatics(std::vector<char> adi_port);
    Pnumatics(std::vector<char> adi_port,bool reverse_);
    Pnumatics(std::vector<char> adi_port, pros::controller_digital_e_t Button_);
    Pnumatics(std::vector<char> adi_port, pros::controller_digital_e_t Button_,bool reverse_);
    
    void Out();
    void In();
    void Toggle();
    void Control();
};