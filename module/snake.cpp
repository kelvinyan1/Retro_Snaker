#include <snake.h>
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
    for (int i = 0; i < 3; i++)
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
    body* ptr = new body(); // create new a body

    // new body's coodinate is determined by previous head position and moving direction
    switch (dir)
    {
    case UP:
    {
        ptr->body_y = snake_head->body_y - 1;
        ptr->body_x = snake_head->body_x;
    }
    case DOWN:
    {
        ptr->body_y = snake_head->body_y + 1;
        ptr->body_x = snake_head->body_x;
    }
    case RIGHT:
    {
        ptr->body_x = snake_head->body_x + 1;
        ptr->body_y = snake_head->body_y;
    }
    case LEFT:
    {
        ptr->body_x = snake_head->body_x - 1;
        ptr->body_y = snake_head->body_y;
    }
        break;
    default:
        break;
    }
    
    ptr->previous = snake_head; // link new body to the whole snake
    snake_head = ptr; // set new body as snake head

    if (flag_ptr == 0) // snake head doesn't touch the beam, delete the tail to move forward
        snake_tail = snake_tail->next;
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
    current = current->next;

    // set remain bodies as "&"
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

void snake::snake_change_dir(direction direct)
{
    // snake can just turn their head 90 degrees
    if (direct == UP || direct == DOWN)
        if (dir == RIGHT || dir == LEFT)
            dir = direct;
    
    else
        if(dir == UP || dir == DOWN)
            dir = direct;
    
}