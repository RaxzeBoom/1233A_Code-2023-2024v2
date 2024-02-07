#include "main.h"
class Pnumatics {
    private:
    pros::ADIDigitalOut Pnumatic();
    bool reverse;
    public:
    Pnumatics(char adi_port);
    Pnumatics(char adi_port, bool reverse_);
    void Out();
    void In();
    void Control();
};