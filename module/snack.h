#ifndef _SNACK_H
#define _SNACK_H

struct body{
    int body_x;
    int body_y;
    body* next;
    body* previous;      
};

enum direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct snake{
    int length;
    direction dir;//0 for up, 1 for down, 2 for left, 3 for right
    body* head;
};


#endif