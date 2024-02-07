#include "main.h"
    Pnumatics::Pnumatics(char adi_port)
    {
        pros::ADIDigitalOut Pnumatic(adi_port);
    }
    Pnumatics::Pnumatics(char adi_port, bool reverse_)
    {
        pros::ADIDigitalOut Pnumatic(adi_port);
        reverse = reverse_;
    }
    void Pnumatics::Out()
    {
        
    }
    void Pnumatics::In()
    {

    }
    void Pnumatics::Control()
    {

    }