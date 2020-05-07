#include <iostream>
#include <game.h>
#include <mode.h>
#include <help.h>
#include <conio.h>
using namespace std;

int main()
{
    while (1)
    {
        system("cls");
        cout<<"-------------------------------"<<endl
            <<"/---Welcome to Eating Snake---/"<<endl
            <<"-------------------------------"<<endl<<endl
            <<"1  start game"<<endl
            <<"2  mode"<<endl
            <<"3  help"<<endl
            <<"4  exit"<<endl;

        while (!_kbhit()) // if hitting detected, then execute following
        {

        }
        if (_kbhit())
        {
            int bit;
            bit = _getch();
            if (bit == 49){ // if press "1", start game
                game_execute();
            }
            else if (bit == 50) // if press "2", change mode
                mode_change_execute();
            else if (bit == 51) // if press "3", open help
                help_execute();
            else if (bit == 52) // exit game
                break;
        }
    }

    cout<<"successfully quit!"<<endl;
    system("pause");
}
