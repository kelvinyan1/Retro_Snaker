#include "help.h"
using namespace std;

void help_execute()
{
    while (1)
    {
        system("clear");//clear the screem in linux
        cout<<"-------------Help----------------"<<endl
            <<"W: up       S: down"<<endl
            <<"A: left     D: right"<<endl
            <<"if you eat a beam, then you will"<<endl
            <<"be longer."<<endl
            <<"if your head touch the wall and"<<endl
            <<"your body, then game over."<<endl<<endl
            <<"warning: !! Do not open \"caps lock\" !!"<<endl<<endl
            <<"---------------------------------"<<endl
            <<"Press 'Esc' to exit"<<endl
            <<"---------------------------------"<<endl;

        while (!_kbhit()) // waiting for command
        {

        }

        int bit;
        if (_kbhit())
        {
            bit = _getch();
            if (bit == 27)
                break;
        }
    }
}