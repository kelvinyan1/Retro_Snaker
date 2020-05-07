#include <iostream>
#include <conio.h>  //not from standard cpp library
#include <time.h>
#include <windows.h> //only works for windows environment 
#include <beam.h>
#include <snake.h>
#include <map.h>

char map[30][30];

direction direct;
snake snak;
beam be;
void game_execute();