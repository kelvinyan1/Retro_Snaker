#ifndef _SNACK_H
#define _SNACK_H

class snack {
public:
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
    
    body* snack_tail;
    body* snack_head;
    
    /*return 1 if snack is dead, 0 otherwise*/
    int snack_dead();      
    
    /*move and make the snack longer*/
    void snack_move(char ,int *);

    /*append snack into map*/
    void print_snack(int [30][30]);

    void snack_init();
};

#endif