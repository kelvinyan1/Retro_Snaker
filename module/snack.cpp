#include <snack.h>
void snack::snack_init(){
    
}
void snack::snack_move(char input,int * flag_ptr)
{
    /*to be finished*/
}

void snack::print_snack(int map[30][30])
   {
       body* current=snack_head;
    while(current !=snack_tail)
    {
            map[current->body_x][current->body_y]='&';
        current = current->next;
    }
    map[current->body_x][current->body_y]='&';
}

int snack::snack_dead()       //return 1 if snack is dead, 0 otherwise
{   
    body* current = snack_head;
    while(current != snack_tail)
    {
        if ((current->body_x==snack_head->body_x) &&(current->body_y==snack_head->body_y))
        {
           return 1;
        }
        current = current->next;
    }
    if ((current->body_x==snack_head->body_x) &&(current->body_y==snack_head->body_y))
    {
         return 1;
    }
    else{
         return 0;
    }
}