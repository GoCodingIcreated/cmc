#include <rand.h>


int rand_range(int low, int high)
{
    //srand(time(NULL));
    double r = rand() * 1.0 / (RAND_MAX + 1ll);
    return (int)(r * (high - low)) + low;
}
