#ifndef _SNAKE_H
#define _SNAKE_H

struct body
    {        
        int body_x;
        int body_y;
        body* next;
        body* previous;      
    };
    /*up = 0, down = 1, left = 2, right = 3*/
enum direction
{
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

class snake {
public:
    body* snake_tail;
    body* snake_head;
    direction dir;
    int length;
    
    /*return 1 if snake is dead, 0 otherwise*/
    int snake_dead();      
    
    /*move and make the snake longer*/
    void snake_move(int &eat_flag);

    /*append snake into map*/
    void print_snake(char [30][30]);

    /*initialize the snake with 4 nodes*/
    void snake_init();

    /*change the direction of the snake*/
    void snake_change_dir(direction direct);
};

#endif