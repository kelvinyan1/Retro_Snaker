#include <snake.h>
void snake::snake_init()
{

    
}
void snake::snake_move(char input,int * flag_ptr)
{
    /*to be finished*/
}

void snake::print_snake(int map[30][30])
   {
    body* current=snake_head;
    
    while(current != snake_tail)
    {
        map[current->body_x][current->body_y]='&';
        current = current->next;
    }
    map[current->body_x][current->body_y]='&';
}

int snake::snake_dead()       //return 1 if snake is dead, 0 otherwise
{   
    body* current = snake_head;
    while(current != snake_tail)
    {
        if ((current->body_x==snake_head->body_x) &&(current->body_y==snake_head->body_y))
        {
           return 1;
        }
        current = current->next;
    }
    if ((current->body_x==snake_head->body_x) &&(current->body_y==snake_head->body_y))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}