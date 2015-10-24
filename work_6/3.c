#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int num[200];
    int p[200];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &num[i], &p[i]);
    }
    int m, seed;
    scanf("%d%d", &m, &seed);
    srand(seed);
    for ( int i = 0; i < m; ++i )
    {
        int R = (int)(rand() * 1.0 / (RAND_MAX + 1ll) * 100);
        //printf("%d\n", R);
        int temp = 0;
        for (int j = 0; j < n; ++j)
        {
            if (temp <= R && R < temp + p[j])
            {
                printf("%d\n", num[j]);
                break;
            }
            temp += p[j];
        }

    }
    return 0;
}
