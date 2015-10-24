#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char ** argv)
{
    srand(time(NULL));
    if ( argc < 2 )
        return 1;
    int fd = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0755);
    if (fd < 0)
    {
        printf("!");
        return 0;
    }
    int temp = -1;
    for (int i = 0; i < 10; ++i)
    {
        unsigned short t = rand() % 10;
        printf("#%d:\n\tsize=%d\n\t", i, t);
        write(fd, &t, sizeof(t));
        for (int j = 0; j < t; ++j)
        {
            char data = rand() % 10 + '0';
            write(fd, &data, sizeof(data));
            printf("%c", data);
        }
        printf("\n");
        long long offset = sizeof(temp);
        if ( i == 9 )
            offset = 0;
        write(fd, &offset, sizeof(offset));
        write(fd, &temp, sizeof(temp));
    }
    close(fd);
    return 0;
}
