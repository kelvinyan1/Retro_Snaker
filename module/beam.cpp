#include <beam.h>
using namespace std;

int beam::beam_generate(snake snak)
{
    srand(time(NULL)); // randomly generate the position of the beam
    x = rand() % 30;
    y = rand() % 30;
}

int beam::beam_print(int map[30][30])
{
    map[x][y] = '*';
}