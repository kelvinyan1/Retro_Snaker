#include <iostream>
#include <stdlib.h>
#include <ctime>
/*New Feature, to be tested*/
//enum kind
//{
//    A = 1,
//    B = 2,
//    C = 3,
//}

class beam{
    public:
        int x;
        int y;

        //randomly generate the position of the beam
        int beam_generate();

        //write the beam into the map
        int beam_print(char map[30][30]);
};