#include "main.h"
extern Auto_Info Auto_Programs[];
int Color_Num = 1;
int Button_Num = 1;
int Auto_Num = 1;
int Discription_NUM = 1;
int Name_NUM = 1;
int Touch_Checker_NUM = 0;
void Top_Buttons()
{
    //Makes 3 top rectangles that are 50 by 60 pixels
    pros::screen::set_pen(COLOR_GREEN);
    pros::screen::fill_rect(10,10,70,60);
    pros::screen::set_pen(COLOR_BLACK);
    pros::screen::draw_rect(10,10,70,60);
    pros::screen::set_pen(COLOR_RED);
    pros::screen::fill_rect(215,10,275,60);
    pros::screen::set_pen(COLOR_BLACK);
    pros::screen::draw_rect(215,10,275,60);
    pros::screen::set_pen(COLOR_GRAY);
    pros::screen::fill_rect(410,10,470,60);
    pros::screen::set_pen(COLOR_BLACK);
    pros::screen::draw_rect(410,10,470,60);
}
void Draw_Buttons()
{
    Top_Buttons();
    //makes 3 rectangles that are below the top three that are 50 by 100 pixels
    pros::screen::fill_rect(10,110,110,160);
    pros::screen::fill_rect(190,110,290,160);
    pros::screen::fill_rect(370,110,470,160);
    //makes 3 rectangles that are below the middles ones three that are 50 by 100 pixels
    pros::screen::fill_rect(10,180,110,230);
    pros::screen::fill_rect(190,180,290,230);
    pros::screen::fill_rect(370,180,470,230);
    pros::screen::set_pen(COLOR_WHITE);
    pros::screen::draw_rect(10,110,110,160);
    pros::screen::draw_rect(190,110,290,160);
    pros::screen::draw_rect(370,110,470,160);
    pros::screen::draw_rect(10,180,110,230);
    pros::screen::draw_rect(190,180,290,230);
    pros::screen::draw_rect(370,180,470,230);
}
//Return a string from the Auto_Progrmas 'N' or 'n' For name 'D' or 'd' and black for Discription
std::string Call_Text(int num , int size , char type)
{
    num--;
    std::string Curr_String;
    if(type == 'N' || 'n')
    {Curr_String = Auto_Programs[num].Name;}
    if(type == 'D' || 'd')
    {Curr_String = Auto_Programs[num].DisplayName;}   
    Curr_String.std::string::resize(size);
    return Curr_String;
}
std::vector<std::string> Call_Text(int num , int size)
{
    num--;
    std::vector<std::string> Curr_String;
    for (std::string line : Auto_Programs[num].Disciption)
    {
        line.std::string::resize(size);
        Curr_String.emplace_back(line);
    }
    return Curr_String;
}

void Close_Auto_Text()
{

    //Turns the Top Red and put in in auto names
    pros::screen::set_pen(COLOR_GREEN);
    pros::screen::fill_rect(0,0,480,100);
    pros::screen::set_pen(COLOR_GREEN);
    pros::screen::print(pros::E_TEXT_SMALL,12,115,"%S",Call_Text(0,13,'D'));
    pros::screen::print(pros::E_TEXT_SMALL,192,115,"%S",Call_Text(1,13,'D'));
    pros::screen::print(pros::E_TEXT_SMALL,372,115,"%S",Call_Text(2,13,'D'));
    pros::screen::print(pros::E_TEXT_SMALL,12,185,"%S",Call_Text(3,13,'D'));
    pros::screen::print(pros::E_TEXT_SMALL,192,185,"%S",Call_Text(4,13,'D'));
    pros::screen::print(pros::E_TEXT_SMALL,372,185,"%S",Call_Text(5,13,'D'));
    //Redo the top three Rectangles
    Top_Buttons();
    Color_Num = 1;
}
void Far_Auto_Text()
{
     //Turns the Top Blue and put in in auto names
    pros::screen::set_pen(COLOR_RED);
    pros::screen::fill_rect(0,0,480,100);
    pros::screen::set_pen(COLOR_GREEN);
    pros::screen::print(pros::E_TEXT_SMALL,12,115,"%S",Call_Text(6,13,'D'));
    pros::screen::print(pros::E_TEXT_SMALL,192,115,"%S",Call_Text(7,13,'D'));
    pros::screen::print(pros::E_TEXT_SMALL,372,115,"%S",Call_Text(8,13,'D'));
    pros::screen::print(pros::E_TEXT_SMALL,12,185,"%S",Call_Text(9,13,'D'));
    pros::screen::print(pros::E_TEXT_SMALL,192,185,"%S",Call_Text(10,13,'D'));
    pros::screen::print(pros::E_TEXT_SMALL,372,185,"%S",Call_Text(11,13,'D'));
    //Redo the top three Rectangles
    Top_Buttons();
    Color_Num = 2;
}
void Other_Auto_Text()
{
     //Turns the Top Black and put in in auto names
    pros::screen::set_pen(COLOR_BLACK);
    pros::screen::fill_rect(0,0,480,100);
    pros::screen::set_pen(COLOR_GREEN);
    pros::screen::print(pros::E_TEXT_SMALL,12,115,"%S",Call_Text(12,13,'D'));
    pros::screen::print(pros::E_TEXT_SMALL,192,115,"%S",Call_Text(13,13,'D'));
    pros::screen::print(pros::E_TEXT_SMALL,372,115,"%S",Call_Text(14,13,'D'));
    pros::screen::print(pros::E_TEXT_SMALL,12,185,"%S",Call_Text(15,13,'D'));
    pros::screen::print(pros::E_TEXT_SMALL,192,185,"%S",Call_Text(16,13,'D'));
    pros::screen::print(pros::E_TEXT_SMALL,372,185,"%S",Call_Text(17,13,'D'));
    //Redo the top three Rectangles
    Top_Buttons();
    Color_Num = 3;
}
void DIS_Printer(int line,std::vector<std::string> Discription)
{
    int Next_Line = 0;
    for (std::string Text : Discription)
    {
        pros::screen::print(pros::E_TEXT_SMALL,Next_Line + line+3,"%S",Text);
        Next_Line++;
    }
    
}
void NAME_Printer(std::string NAME)
{
    pros::screen::print(pros::E_TEXT_LARGE_CENTER,1,"%S",NAME);
}
void Auton_Checker(int num)
{

    NAME_Printer(Call_Text(num,25,'N'));
    DIS_Printer(0,Call_Text(num,49));
}
void menu()
{
    pros::screen::set_pen(COLOR_LIGHT_GRAY);
    pros::screen::fill_rect(0,0,480,240);
    pros::screen::set_pen(COLOR_RED);
    pros::screen::fill_rect(0,160,240,240);
    pros::screen::set_pen(COLOR_GREEN);
    pros::screen::fill_rect(240,160,480,240);
    pros::screen::set_pen(COLOR_BLACK);
    pros::screen::draw_rect(0,160,240,240);
    pros::screen::draw_rect(240,160,480,240);
    pros::screen::print(pros::E_TEXT_LARGE,80,185,"Back");
    pros::screen::print(pros::E_TEXT_LARGE,320,185,"Ready");
    Auton_Checker(Auto_Num);
    Touch_Checker_NUM = 1;
}
void Print_Auto()
{
    Auto_Num = Button_Num+(6*(Color_Num-1));
    menu();
}
void Touch_Checker(int X, int Y) 
{
if(Touch_Checker_NUM == 0)
{
    if(10<Y & Y<60)
    {
        if (10<X & X<110)
        {
            Close_Auto_Text();
        }
        else if (190<X & X<290)
        {
            Far_Auto_Text();
        }
        else if (370<X & X<470)
        {
            Other_Auto_Text();
        }
    }
    else if(110<Y & Y<160)
    {
        if (10<X & X<110)
        {
            Button_Num = 1;
            Print_Auto();
        }
        else if (190<X & X<290)
        {
            Button_Num = 2;
            Print_Auto();
        }
        else if (370<X & X<470)
        {
            Button_Num = 3;
            Print_Auto();
        }
    }
    else if(180<Y & Y<230)
    {
        if (10<X & X<110)
        {
            Button_Num = 4;
            Print_Auto();
        }
        else if (190<X & X<290)
        {
            Button_Num = 5;
            Print_Auto();
        }
        else if (370<X & X<470)
        {
            Button_Num = 6;
            Print_Auto();
        }
    }
}
        else if(Touch_Checker_NUM ==1)
        {
            if(160<Y & Y<280)
            {
        if (0<X & X<240)
        {
            Touch_Checker_NUM = 0;
            pros::screen::set_pen(COLOR_GRAY );
            pros::screen::fill_rect(0,100,480,240);
            Draw_Buttons();
            switch (Color_Num)
            {
            case 1:
            Close_Auto_Text();
            break;
            case 2:
            Far_Auto_Text();
            break;
            case 3:
            Other_Auto_Text();
            break;
            
            default:
                break;
            }
        }
        else if (240<X & X<480)
        {
            //Start_GUI();
            //Touch_Checker_NUM = 2;
        }
             }
        }
}
void Start_UI()
{
   pros::screen::set_pen(COLOR_GRAY );
   pros::screen::fill_rect(0,100,480,240);
   pros::screen::set_eraser(COLOR_GRAY);
   Draw_Buttons();
   Close_Auto_Text();
}