#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(void)
{
    int file = open("binary", O_CREAT | O_TRUNC | O_WRONLY);
    for ( int i = 0; i <= 1000; ++i )
    {
        long long t = (long long)i * 1000;
        write(file, &i, sizeof(i));
        write(file, &t, sizeof(long long));
    }
    return 0;
}
