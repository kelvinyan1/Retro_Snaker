#include <beam.h>
using namespace std;

int beam::beam_generate()
{
    srand(time(NULL)); // randomly generate the position of the beam
    x = rand() % 28 +1;
    y = rand() % 28 +1;
}

int beam::beam_print(char map[30][30])
{
    map[x][y] = '*';
}