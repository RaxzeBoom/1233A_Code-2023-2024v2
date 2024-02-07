#include "main.h"
//Intake Config
int Driver_Intake_Speed = 127;
//Catapult Config
int Driver_Catapult_Speed = 127;
int Catapult_Down_Pos = 6550;
int Catapilt_Middle_Pos = 1500;
int Catapult_Auto_Speed = 127;
int Change = 0;
double CataPort_PID [3] = {.19,0,0.2};