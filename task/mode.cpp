#include <mode.h>
#include <game.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void save(snake skobj,beam bobj,int score,int flag)
{
    string num;
    cout << "number your game, please check documentary \"process\" to find a number doesn't appear"<<endl;
    cin >> num;
    ofstream fout;
    fout.open("process"+num+".txt");
    body *current= skobj.snake_head; 
    while(current != skobj.snake_tail){
        fout << current->body_x << ' ';
    }
    fout <<endl;
    while(current != skobj.snake_tail){
        fout << current->body_y << ' ';
    }
    fout <<endl;
    fout << bobj.x <<' '<<bobj.y;
    fout <<endl;
    fout <<score;
    fout.close();
}
void load()
{
    string num;
    cout <<"Which number of process do you want to load?"<<endl;
    cin >> num;
    ifstream fin;
}