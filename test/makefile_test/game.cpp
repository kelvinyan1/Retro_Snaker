#include "game.h"
void game()
{
    snake();
    beam();
    map();
    if (snake_f == 1 && beam_f == 1 && map_f == 1)
    {
        game_f = 1;
        std::cout<<"game ok"<<std::endl;
    }
    
}