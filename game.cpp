#include <iostream>
#include <time.h>
#include <snack.h>
#include <snack.cpp>
#include <map.cpp>
using namespace std;

int map[30][30];

time_t time1,time2,time3;

int main(){
    time1 = time(NULL);
    time3=time1+10;
    init_map(map);
    int level=1,score=0;

    //this is the basic game continue function 
    //time2 set the current time,time1 is the start time, time3 is the default close time 
    //to be finished and modified into game theorm
    while(1)
    {
        time2 = time(NULL);
        if (time2 == time1+1){
            cout <<"1 second passes"<<endl;
            time1 +=1;
            //print_map();
            //get_input();
            //snack_go();
            //if(snack_dead()==1){
                //cout <<"game over!"<<endl;
            //} 
        }
        if (time2 == time3){
            break;
        }
    }
    cout << "your score is "<< score << endl;
}