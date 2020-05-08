#include "game.h"
#include "mode.h"
using namespace std;


/*this is the time delay function, the unit of input should be ms*/
void delay(int time)//ms
{
    clock_t init_time=clock();
    while(clock()<(init_time+time))
    {}
      
}

//initialize snake and beam
void game_init()
{
    snak.snake_init();
    be.beam_generate();
    score = 0;
    eat_flag = 0;
}

void game_execute(){

    char input;
    
    // initialize map
    char map[30][30];
    init_map(map);
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
            direction direct;
            if (input == 'w')
                direct = UP;
            else if (input == 's')
                direct = DOWN;
            else if (input == 'a')
                direct = LEFT;
            else if (input == 'd')
                direct = RIGHT;

            else if (input == 0x1B){ // if hit "esc", quit game
                cout << "Do you want to save? "<<endl;
                cout << "Note that your history file will be overwrite "<<endl;
                cout << "if so answer yes"<<endl;
                string ans;
                cin >> ans;
                if (ans == "yes"){
                    save(snak,be,score,eat_flag);
                    cout <<"successfully saved"<<endl;
                    delay(500);
                }
                break;
            }
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
        
        system("clear");//clear the screem in linux
        print_map(map);
        
        //delay 500ms
        delay(500);
        
    }
    cout << "your score is "<< score << endl;
}