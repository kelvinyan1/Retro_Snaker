#include <game.h>
#include <mode.h>
using namespace std;


/*this is the time delay function, the unit of input should be ms*/
void delay(int time)//ms
{
    clock_t init_time=clock();
    while(clock()<(init_time+time))
    {}
      
}


void game_execute(){

    char input;
    
    // initialize map, beam, and snake
    char map[30][30];
    init_map(map);
    int score=0;
    be.beam_generate();
    snak.snake_init();
    int eat_flag = 0;
    be.beam_print(map);
    snak.print_snake(map);

    print_map(map);
    delay(500);

    //this is the basic game continue function 
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
                cout << "Do you want to save? if so answer yes"<<endl;
                string ans;
                cin >> ans;
                if (ans == "yes"){
                    save(snak,be,score);
                }
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
        
        //need to clear the scream by printf("\033[2J");
        //need to hide the cursor by printf("\033[?251")
        print_map(map);
        
        //delay 500ms
        delay(500);
        
    }
    //need to show the cursor by printf("\033[?25h")
    cout << "your score is "<< score << endl;
}