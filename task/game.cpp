#include <game.h>
using namespace std;

int map[30][30];


char get_input(){
    char input;
    input = getch();
    return input;
}





int game_execute(){
    time1 = time(NULL);
    time3=time1+10;
    init_map(map);
    int level=1,score=0;

    //this is the basic game continue function 
    //time2 set the current time,time1 is the start time, time3 is the default close time 
    //to be finished and modified into game theorm
    while(1)
    {
        char input;
        time2 = time(NULL);
        if (_kbhit()==1){
            input = get_input();
            cout << input <<endl;
            time1 += 1;
            /*if("吃到果子"){
                eat_flag = 1;(int)
                score += 1;
                beam_destroy();
                beam_generate();
            }
            snack_move(input,,*eat_flag);

            if(snack_dead()==1){
                break;
            } */
        }
        else{
            if (time2==time1+1){
                cout << "1 second pass" <<endl;
                time1 +=1;
            }
        }
        if (time2 == time3){
            break;
        }
    }
    cout << "your score is "<< score << endl;
}