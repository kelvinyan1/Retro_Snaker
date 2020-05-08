#include <iostream>
#include <conio.h>  //not from standard cpp library
#include <time.h>
#include <beam.h>
#include <snake.h>
#include <map.h>

char map[30][30];

snake snak;
beam be;
int score;
int eat_flag;
void game_execute();
void game_init();