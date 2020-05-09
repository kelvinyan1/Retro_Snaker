#include "snake.h"
void snake::snake_init()
{
    // initialize the first body's infomation
    body* pbody = new body();
    pbody->body_x = 10;
    pbody->body_y = 13;
    pbody->next = pbody;
    pbody->previous = pbody;

    // set the first body as the snake head
    snake_head = pbody;
    snake_tail = pbody;

    // append 3 bodies
    for (int i = 1; i < 4; i++)
    {
        body* ptr = new body();
        ptr->body_y = 13 - i;
        ptr->body_x = 10;
        ptr->next = pbody;
        pbody->previous = ptr;
        pbody = ptr;
    }

    snake_tail = pbody; // set snake tail

    length = 4; // set initial length of snake
    dir = DOWN; // set initial direction
}

void snake::snake_move(int &flag_ptr)
{
    body* ptr = new body(); // create a new body

    // new body's coodinate is determined by previous head position and moving direction
    switch (dir)
    {
    case UP:
    {
        ptr->body_y = snake_head->body_y;
        ptr->body_x = snake_head->body_x - 1;
        break;
    }
    case DOWN:
    {
        ptr->body_y = snake_head->body_y;
        ptr->body_x = snake_head->body_x + 1;
        break;
    }
    case RIGHT:
    {
        ptr->body_x = snake_head->body_x;
        ptr->body_y = snake_head->body_y + 1;
        break;
    }
    case LEFT:
    {
        ptr->body_x = snake_head->body_x;
        ptr->body_y = snake_head->body_y - 1;
        break;
    }
    default:
        break;
    }
    
    ptr->previous = snake_head; // link new body to the whole snake
    snake_head->next = ptr;
    ptr->next = ptr;
    
    snake_head = ptr; // set new body as snake head

    if (flag_ptr == 0) {// snake head doesn't touch the beam, delete the tail to move forward
        snake_tail = snake_tail->next;
        snake_tail->previous = snake_tail;
    }
    else if (flag_ptr == 1) //  snake head touches the beam, length plus 1
    {
        flag_ptr = 0;
        length += 1;
    }
}

void snake::print_snake(char map[30][30])
{
    body* current = snake_head;
    
    map[current->body_x][current->body_y] = '*'; // set head as "*"
    current = current->previous;

    // set remain bodies as "&"
    while(current != snake_tail)
    {
        map[current->body_x][current->body_y]='&';
        current = current->previous;
    }
    map[current->body_x][current->body_y]='&';
}

int snake::snake_dead()       //return 1 if snake is dead, 0 otherwise
{   
    body* current = snake_head->previous;
    while(current != snake_tail)
    {
        if ((current->body_x==snake_head->body_x) &&(current->body_y==snake_head->body_y))
        {
           return 1;
        }
        current = current->previous;
    }
    if ((current->body_x==snake_head->body_x) &&(current->body_y==snake_head->body_y))
    {
        return 1;
    }
    if (snake_head->body_x == 29 || snake_head->body_x == 0 || snake_head->body_y == 0 || snake_head->body_y == 29)
        return 1;
    return 0;
}

void snake::snake_change_dir(direction ipdir)
{
    // snake can just turn their head 90 degrees
    if ((dir==UP&&ipdir==DOWN) || (dir==DOWN&&ipdir==UP) || (dir==LEFT&&ipdir==RIGHT) || (dir==RIGHT&&ipdir==LEFT))
    {}
    else
    {
        dir = ipdir;
    }
    
}
