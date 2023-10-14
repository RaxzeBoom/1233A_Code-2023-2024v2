#include "main.h"
int Color_Num = 1;
int Button_Num = 1;
int Auto_Num = 1;
void Draw_Buttons()
{
    pros::screen::set_pen(COLOR_RED);
    //Makes 3 top rectangles that are 50 by 60 pixels
    pros::screen::fill_rect(10,10,70,60);
    pros::screen::set_pen(COLOR_BLUE);
    pros::screen::fill_rect(215,10,275,60);
    pros::screen::set_pen(COLOR_GRAY);
    pros::screen::fill_rect(410,10,470,60);
    //makes 3 rectangles that are below the top three that are 50 by 100 pixels
    pros::screen::set_pen(COLOR_BLACK);
    pros::screen::fill_rect(10,110,110,160);
    pros::screen::fill_rect(190,110,290,160);
    pros::screen::fill_rect(370,110,470,160);
    //makes 3 rectangles that are below the middles ones three that are 50 by 100 pixels
    pros::screen::fill_rect(10,180,110,230);
    pros::screen::fill_rect(190,180,290,230);
    pros::screen::fill_rect(370,180,470,230);
}
void Red_Auto_Text()
{
    //Turns the Top Red and put in in auto names
    pros::screen::set_pen(COLOR_RED);
    pros::screen::fill_rect(0,0,480,100);
    pros::screen::set_pen(COLOR_GREEN);
    pros::screen::print(pros::E_TEXT_SMALL,12,110,"Auto 1 ");
    pros::screen::print(pros::E_TEXT_SMALL,192,110,"Auto 2 ");
    pros::screen::print(pros::E_TEXT_SMALL,372,110,"Auto 3 ");
    pros::screen::print(pros::E_TEXT_SMALL,12,180,"Auto 4 ");
    pros::screen::print(pros::E_TEXT_SMALL,192,180,"Auto 5 ");
    pros::screen::print(pros::E_TEXT_SMALL,372,180,"Auto 6 ");
    //Redo the top three Rectangles
    pros::screen::set_pen(COLOR_RED);
    pros::screen::fill_rect(10,10,70,60);
    pros::screen::set_pen(COLOR_BLUE);
    pros::screen::fill_rect(215,10,275,60);
    pros::screen::set_pen(COLOR_GRAY);
    pros::screen::fill_rect(410,10,470,60);
    Color_Num = 1;
}
void Blue_Auto_Text()
{
     //Turns the Top Blue and put in in auto names
    pros::screen::set_pen(COLOR_BLUE);
    pros::screen::fill_rect(0,0,480,100);
    pros::screen::set_pen(COLOR_GREEN);
    pros::screen::print(pros::E_TEXT_SMALL,12,110,"Auto 7 ");
    pros::screen::print(pros::E_TEXT_SMALL,192,110,"Auto 8 ");
    pros::screen::print(pros::E_TEXT_SMALL,372,110,"Auto 9 ");
    pros::screen::print(pros::E_TEXT_SMALL,12,180,"Auto 10");
    pros::screen::print(pros::E_TEXT_SMALL,192,180,"Auto 11");
    pros::screen::print(pros::E_TEXT_SMALL,372,180,"Auto 12");
    //Redo the top three Rectangles
    pros::screen::set_pen(COLOR_RED);
    pros::screen::fill_rect(10,10,70,60);
    pros::screen::set_pen(COLOR_BLUE);
    pros::screen::fill_rect(215,10,275,60);
    pros::screen::set_pen(COLOR_GRAY);
    pros::screen::fill_rect(410,10,470,60);
    Color_Num = 2;
}
void Other_Auto_Text()
{
     //Turns the Top Black and put in in auto names
    pros::screen::set_pen(COLOR_BLACK);
    pros::screen::fill_rect(0,0,480,100);
    pros::screen::set_pen(COLOR_GREEN);
    pros::screen::print(pros::E_TEXT_SMALL,12,110,"Auto 13");
    pros::screen::print(pros::E_TEXT_SMALL,192,110,"Auto 14");
    pros::screen::print(pros::E_TEXT_SMALL,372,110,"Auto 15");
    pros::screen::print(pros::E_TEXT_SMALL,12,180,"Auto 16");
    pros::screen::print(pros::E_TEXT_SMALL,192,180,"Auto 17");
    pros::screen::print(pros::E_TEXT_SMALL,372,180,"Auto 18");
    //Redo the top three Rectangles
    pros::screen::set_pen(COLOR_RED);
    pros::screen::fill_rect(10,10,70,60);
    pros::screen::set_pen(COLOR_BLUE);
    pros::screen::fill_rect(215,10,275,60);
    pros::screen::set_pen(COLOR_GRAY);
    pros::screen::fill_rect(410,10,470,60);
    Color_Num = 3;
}
void Print_Auto()
{
    Auto_Num = Button_Num+(6*(Color_Num-1));
    pros::screen::set_pen(COLOR_GREEN);
    pros::screen::print(pros::E_TEXT_SMALL,170,80,"Seleted Auto %i  ",Auto_Num);
}
void Touch_Checker(int X, int Y)
{
    if(10<Y & Y<60)
    {
        if (10<X & X<110)
        {
            Red_Auto_Text();
            Print_Auto();
        }
        else if (190<X & X<290)
        {
            Blue_Auto_Text();
            Print_Auto();
        }
        else if (370<X & X<470)
        {
            Other_Auto_Text();
            Print_Auto();
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
void Start_UI()
{
   pros::screen::set_pen(COLOR_GRAY );
   pros::screen::fill_rect(0,100,480,240);
   
   Draw_Buttons();
   Red_Auto_Text();
}