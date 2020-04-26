#ifndef _SNACK_H
#define _SNACK_H

struct node{
    int body_x;
    int body_y;
    node* next;    
};


struct snake_head{
    int length;
    int head_x,head_y;
    int direction;//0 for up, 1 for down, 2 for left, 3 for right
    node* next;
};


#endif