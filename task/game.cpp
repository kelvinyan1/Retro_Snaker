#include <game.h>
using namespace std;


/*this is the time delay function, the unit of input should be ms */
void delay(int time)//ms
{
    clock_t init_time=clock();
    while(clock()<(init_time+time))
    {}
      
}

char get_input(){
    char input;
    input = getch();
    return input;
}



void game_execute(){

    char input;

    // initialize map, beam, and snake
    init_map(map);
    int level=1,score=0;
    be.beam_generate();
    snak.snake_init();
    int eat_flag = 0;

    //this is the basic game continue function 
    //to be finished and modified into game theorm
    while(1)
    {
        
        if(snak.snake_dead()==1){
            break;
        } 

        if (_kbhit())
        {
            input = getch();
            if (input == 'w')
                direct = UP;
            else if (input == 's')
                direct = DOWN;
            else if (input == 'a')
                direct = LEFT;
            else if (input == 'd')
                direct = RIGHT;

            else if (input == 0x1B) // if hit "esc", quit game
                break;
            snak.snake_change_dir(direct);
        }

        if(snak.snake_head->body_x == be.x && snak.snake_head->body_y == be.y){
            eat_flag = 1;
            score += 1;
            be.beam_generate();
        }
        snak.snake_move(eat_flag);
        
        init_map(map);
        snak.print_snake(map);
        be.beam_print(map);
        print_map(map);
        
        //delay 500ms
        delay(500);
        
    }

    cout << "your score is "<< score << endl;
}