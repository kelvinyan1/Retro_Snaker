#include <iostream>
#include "mode.h"

void mode()
{
    game();
    if (game_f == 1)
    {
        mode_f = 1;
        std::cout<<"mode ok"<<std::endl;
    }
    
}