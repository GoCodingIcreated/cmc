#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int file = open("binary", O_RDONLY);
    int x;
    long long y;
    while ( read(file, &x, sizeof(x)) > 0 )
    {
        read(file, &y, sizeof(y));
        printf("%d %lld\n", x, y);
    }
    return 0;
}
