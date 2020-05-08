#include <mode.h>
#include <game.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void save(snake skobj,beam bobj,int score,int flag)
{
    ofstream fout;
    fout.open("process.txt");
    body *current= skobj.snake_head; 
   while(current != skobj.snake_tail){
        fout << current->body_x << ' ';
        current=current->previous;
    }
    fout<<current->body_x<<' '<<30<<' ';//30 will not appear in map, so it can act as separater
    while(current != skobj.snake_head){
        fout << current->body_y << ' ';
        current=current->next;
    }
    fout<<current->body_y<<' '<<30<< ' ';// the same as above
    fout << bobj.x <<' '<<bobj.y << ' ';
    fout <<score << ' '<< flag <<' ';
    switch (skobj.dir)
    {
    case UP:
        fout << 0;
        break;
    case DOWN:
        fout << 1;
        break;
    case LEFT:
        fout << 2;
        break;
    case RIGHT:
        fout << 3;
        break;
    default:
        break;
    }
    
    fout.close();
}
void load()
{
    ifstream fin;
    fin.open("process.txt");
    int fromfile,count=1;
    fin >> fromfile;
    body *pbody = new body;
    pbody->body_x = fromfile;
    snak.snake_head=pbody;
    fin >> fromfile;
    while (fromfile!=30)
    {
        body *ptr = new body;
        ptr->body_x=fromfile;
        pbody->previous = ptr;
        ptr->next = pbody;
        pbody = ptr;
        count+=1;
        fin >> fromfile;
    }
    snak.snake_tail = pbody;
    fin >> fromfile;
    while(fromfile !=30)
    {
        pbody->body_y = fromfile;
        pbody = pbody->next;
        fin >> fromfile;
    }
    fin >>be.x >> be.y >>score >> eat_flag;
    int dir;
    fin >> dir;
    switch (dir)
    {
    case 0:
        snak.dir = UP;
        break;
    case 1:
        snak.dir = DOWN;
        break;
    case 2:
        snak.dir = LEFT;
        break;
    case 3:
        snak.dir = RIGHT;
        break;
    default:
        break;
    }
    fin.close();
}