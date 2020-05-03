#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <beam.h>
#include <snake.h>
#include <map.h>

time_t time1,time2,time3;

char map[30][30];
beam be;
snake snak;
direction direct;

int game_execute();