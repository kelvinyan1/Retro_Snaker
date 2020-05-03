#include <game.h>
using namespace std;


char get_input(){
    char input;
    input = getch();
    return input;
}



int game_execute(){
//    time1 = time(NULL);
//    time3=time1+10;

    char input;

    // initialize map, beam, and snake
    init_map(map);
    int level=1,score=0;
    be.beam_generate();
    snak.snake_init();
    int eat_flag = 0;

    //this is the basic game continue function 
    //time2 set the current time,time1 is the start time, time3 is the default close time 
    //to be finished and modified into game theorm
    while(1)
    {
        
        if(snak.snake_dead()==1){
            break;
        } 
//        time2 = time(NULL);
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
//            else if (input == 12) // pause function
//                while ()
            else if (input == 0x1B) // if hit "esc", quit game
                break;
            snak.snake_change_dir(direct);
        }
//        cout << input <<endl;
//        time1 += 1;
        if(snak.snake_head->body_x == be.x && snak.snake_head->body_y == be.y){
            eat_flag = 1;
            score += 1;
            be.beam_generate();
        }
        snak.snake_move(eat_flag);

        snak.print_snake(map);
        be.beam_print(map);
        print_map(map);

        
    }
//        else{
//            if (time2==time1+1){
//                cout << "1 second pass" <<endl;
//                time1 +=1;
//           }
//        }
//        if (time2 == time3){
//            break;
//        }
    cout << "your score is "<< score << endl;
}