#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc < 3)
        return 1;
    long long offset;
    long long last_pos;
    sscanf(argv[2], "%lld", &offset);
    int fd = open(argv[1], O_RDONLY);
    lseek(fd, offset, SEEK_SET);
    offset = 0;
    unsigned short size = 0;
    char data[100];
    do
    {
        read(fd, &size, sizeof(size));
        read(fd, data, size);
        read(fd, &offset, sizeof(offset));
        printf("size = %d\n", size);
        data[size] = 0;
        printf("data = %s\n", data);
        printf("offset = %lld\n\n", offset);
        lseek(fd, offset - size - sizeof(size) - sizeof(offset), SEEK_CUR);
    } while (offset != 0);
    close(fd);
    return 0;
}
