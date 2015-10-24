#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int count, low, high, seed;
    if (argc < 5)
    {
        return 1;
    }
    sscanf(argv[1], "%d", &count);
    sscanf(argv[2], "%d", &low);
    sscanf(argv[3], "%d", &high);
    sscanf(argv[4], "%d", &seed);
    
    srand(seed);
    for (int i = 0; i < count; ++i)
    {
        double r = rand() * 1.0 / (RAND_MAX + 1ll);
        int R = (int)(r * (high - low)) + low;
        printf("%d\n", R);
    }
    return 0;
}
