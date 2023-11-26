#include "main.h"
int Color_Num = 1;
int Button_Num = 1;
int Auto_Num = 1;
int Discription_NUM = 1;
int Name_NUM = 1;
int Touch_Checker_NUM = 0;
void Draw_Buttons()
{
    pros::screen::set_pen(COLOR_RED);
    //Makes 3 top rectangles that are 50 by 60 pixels
    pros::screen::fill_rect(10,10,70,60);
    pros::screen::set_pen(COLOR_BLACK);
    pros::screen::draw_rect(10,10,70,60);
    pros::screen::set_pen(COLOR_BLUE);
    pros::screen::fill_rect(215,10,275,60);
    pros::screen::set_pen(COLOR_BLACK);
    pros::screen::draw_rect(215,10,275,60);
    pros::screen::set_pen(COLOR_GRAY);
    pros::screen::fill_rect(410,10,470,60);
    pros::screen::set_pen(COLOR_BLACK);
    pros::screen::draw_rect(410,10,470,60);
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
void Red_Auto_Text()
{
    //Turns the Top Red and put in in auto names
    pros::screen::set_pen(COLOR_RED);
    pros::screen::fill_rect(0,0,480,100);
    pros::screen::set_pen(COLOR_GREEN);
    pros::screen::print(pros::E_TEXT_SMALL,12,115,"Far Side   ");
    pros::screen::print(pros::E_TEXT_SMALL,192,115,"Close Side ");
    pros::screen::print(pros::E_TEXT_SMALL,372,115,"Distruption");
    pros::screen::print(pros::E_TEXT_SMALL,12,185,"Auto 4 ");
    pros::screen::print(pros::E_TEXT_SMALL,192,185,"Auto 5 ");
    pros::screen::print(pros::E_TEXT_SMALL,372,185,"Auto 6 ");
    //Redo the top three Rectangles
    pros::screen::set_pen(COLOR_RED);
    pros::screen::fill_rect(10,10,70,60);
    pros::screen::set_pen(COLOR_BLUE);
    pros::screen::fill_rect(215,10,275,60);
    pros::screen::set_pen(COLOR_GRAY);
    pros::screen::fill_rect(410,10,470,60);
    pros::screen::set_pen(COLOR_BLACK);
    pros::screen::draw_rect(10,10,70,60);
    pros::screen::draw_rect(215,10,275,60);
    pros::screen::draw_rect(410,10,470,60);
    Color_Num = 1;
}
void Blue_Auto_Text()
{
     //Turns the Top Blue and put in in auto names
    pros::screen::set_pen(COLOR_BLUE);
    pros::screen::fill_rect(0,0,480,100);
    pros::screen::set_pen(COLOR_GREEN);
    pros::screen::print(pros::E_TEXT_SMALL,12,115,"Far Side    ");
    pros::screen::print(pros::E_TEXT_SMALL,192,115,"Close Side  ");
    pros::screen::print(pros::E_TEXT_SMALL,372,115,"Distruption ");
    pros::screen::print(pros::E_TEXT_SMALL,12,185,"Auto 10");
    pros::screen::print(pros::E_TEXT_SMALL,192,185,"Auto 11");
    pros::screen::print(pros::E_TEXT_SMALL,372,185,"Auto 12");
    //Redo the top three Rectangles
    pros::screen::set_pen(COLOR_RED);
    pros::screen::fill_rect(10,10,70,60);
    pros::screen::set_pen(COLOR_BLUE);
    pros::screen::fill_rect(215,10,275,60);
    pros::screen::set_pen(COLOR_GRAY);
    pros::screen::fill_rect(410,10,470,60);
    pros::screen::set_pen(COLOR_BLACK);
    pros::screen::draw_rect(10,10,70,60);
    pros::screen::draw_rect(215,10,275,60);
    pros::screen::draw_rect(410,10,470,60);
    Color_Num = 2;
}
void Other_Auto_Text()
{
     //Turns the Top Black and put in in auto names
    pros::screen::set_pen(COLOR_BLACK);
    pros::screen::fill_rect(0,0,480,100);
    pros::screen::set_pen(COLOR_GREEN);
    pros::screen::print(pros::E_TEXT_SMALL,12,115,"Skills      ");
    pros::screen::print(pros::E_TEXT_SMALL,192,115,"Back-Up     ");
    pros::screen::print(pros::E_TEXT_SMALL,372,115,"Auto 15");
    pros::screen::print(pros::E_TEXT_SMALL,12,185,"Auto 16");
    pros::screen::print(pros::E_TEXT_SMALL,192,185,"Auto 17");
    pros::screen::print(pros::E_TEXT_SMALL,372,185,"Nothing    " );
    //Redo the top three Rectangles
    pros::screen::set_pen(COLOR_RED);
    pros::screen::fill_rect(10,10,70,60);
    pros::screen::set_pen(COLOR_BLUE);
    pros::screen::fill_rect(215,10,275,60);
    pros::screen::set_pen(COLOR_GRAY);
    pros::screen::fill_rect(410,10,470,60);
    pros::screen::set_pen(COLOR_BLACK);
    pros::screen::draw_rect(10,10,70,60);
    pros::screen::draw_rect(215,10,275,60);
    pros::screen::draw_rect(410,10,470,60);
    Color_Num = 3;
}
void DIS_Printer(int line,std::string Discription)
{
    pros::screen::print(pros::E_TEXT_SMALL,line+3,"%S",Discription);
}
void NAME_Printer(std::string NAME)
{
    pros::screen::print(pros::E_TEXT_LARGE_CENTER,1,"%S",NAME);
}
void Auton_Checker(int num)
{
    switch (Auto_Num)
    {
    case 1:
        NAME_Printer("Far Side Red Auto");
        DIS_Printer(0,"Pushes in red ball, then moves and score ball");
        DIS_Printer(1,"by goal and then touches bar.");
        break;
    case 2:
        NAME_Printer("Close Side Red Auto");
        DIS_Printer(0,"Back up and moves the inside ball from the match");
        DIS_Printer(1,"loading zone then moves forward and touches bar");
        break;
    case 3:
        NAME_Printer("Close Side Red Distruption");
        DIS_Printer(0,"Wings Out Moves torwards middle and stops");
        break;
    case 4:
        NAME_Printer("DEFULT 4");
        DIS_Printer(0,"DEFULT");
        break;
    case 5:
        NAME_Printer("DEFULT 5");
        DIS_Printer(0,"DEFULT");
        break;
    case 6:
        NAME_Printer("DEFULT 6");
        DIS_Printer(0,"DEFULT");
        break;
    //BLUE AUTOS
    case 7:
        NAME_Printer("Far Side Blue Auto");
        DIS_Printer(0,"Pushes in Blue ball, then moves and score ball");
        DIS_Printer(1,"by goal and then touches bar.");
        break;
    case 8:
        NAME_Printer("Close Side Blue Auto");
        DIS_Printer(0,"Back up and moves the inside ball from the match");
        DIS_Printer(1,"loading zone then moves forward and touches bar");
        break;
    case 9:
        NAME_Printer("Close Side Blue Distruption");
        DIS_Printer(0,"Wings Out Moves torwards middle and stops");
        break;
    case 10:
        NAME_Printer("DEFULT 10");
        DIS_Printer(0,"DEFULT");
        break;
    case 11:
        NAME_Printer("DEFULT 11");
        DIS_Printer(0,"DEFULT");
        break;
    case 12:
        NAME_Printer("DEFULT 12");
        DIS_Printer(0,"DEFULT");
        break;
    //OTHER AUTOS
    case 13:
        NAME_Printer("Skills Auto");
        DIS_Printer(0,"Shoots 46 times then goes to other side to score");
        DIS_Printer(1,"triball");
        break;
    case 14:
        NAME_Printer("Backup");
        DIS_Printer(0,"Backs up and them moves forwards");
        break;
    case 15:
        NAME_Printer("DEFULT 15");
        DIS_Printer(0,"DEFULT");
        break;
    case 16:
        NAME_Printer("DEFULT 16");
        DIS_Printer(0,"DEFULT");
        break;
    case 17:
        NAME_Printer("DEFULT 17");
        DIS_Printer(0,"DEFULT");
        break;
    case 18:
        NAME_Printer("Nothing");
        DIS_Printer(0,"Does Nothing");
        break;
    default:
        break;
    }
}
void menu()
{
    pros::screen::set_pen(COLOR_GRAY);
    pros::screen::fill_rect(0,0,480,240);
    pros::screen::set_pen(COLOR_RED);
    pros::screen::fill_rect(0,160,240,240);
    pros::screen::set_pen(COLOR_GREEN);
    pros::screen::fill_rect(240,160,480,240);
    pros::screen::set_pen(COLOR_BLACK);
    pros::screen::draw_rect(0,160,240,240);
    pros::screen::draw_rect(240,160,480,240);
    pros::screen::set_pen(COLOR_WHITE);
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
            Red_Auto_Text();
        }
        else if (190<X & X<290)
        {
            Blue_Auto_Text();
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
            Red_Auto_Text();
            break;
            case 2:
            Blue_Auto_Text();
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
   Draw_Buttons();
   Red_Auto_Text();
}