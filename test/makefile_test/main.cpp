#include <iostream>
#include "game.h"
#include "mode.h"
#include "help.h"

int main()
{
    game();
    mode();
    help();
    if (game_f == 1 && mode_f == 1 && help_f == 1)
        std::cout<<"main ok"<<std::endl<<"successful!"<<std::endl;
}