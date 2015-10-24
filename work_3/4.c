#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

enum 
{
    SIZE_OF_DATA = 12
};

void
my_read(int file, int size, void * buf)
{
    int readed = 0;
    while ((readed += read(file, (char *)buf + readed, size - readed)) != size);
}

void
my_write(int file, void *buf, int size)
{
    int wrote = 0;
    while ((wrote += write(file, (char *)buf + wrote, size - wrote)) != size);
}

void
swap(int file, int i, long long size, int A)
{

    int x1, x2;
    long long y1, y2;
    
    lseek(file, SIZE_OF_DATA * i, SEEK_SET);
    my_read(file, sizeof(x1), &x1);
    my_read(file, sizeof(y1), &y1);
    y1 += (long long) x1 * A;
    
    lseek(file, -SIZE_OF_DATA * (i + 1), SEEK_END);
    my_read(file, sizeof(x2), &x2);
    my_read(file, sizeof(y2), &y2);
    y2 += (long long) x2 * A;
    
    lseek(file, SIZE_OF_DATA * i, SEEK_SET);
    my_write(file, &x2, sizeof(x2));
    my_write(file, &y2, sizeof(y2));
    
    lseek(file, -SIZE_OF_DATA * (i + 1), SEEK_END);
    my_write(file, &x1, sizeof(x1));
    my_write(file, &y1, sizeof(y1));

}

int
main(int argc, char ** argv)
{
    int file = open(argv[1], O_RDWR);
    long long size = lseek(file, 0, SEEK_END);
    
    size /= 12;
    lseek(file, 0, SEEK_SET);
    int A;
    sscanf(argv[2], "%d", &A);
    for ( int i = 0; i <= size - i - 1; ++i ) {
        swap(file, i, size, A);
    }
}
