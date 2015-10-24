#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char **argv)
{
    if (argc < 2)
        return 1;
    int fd = open(argv[1], O_RDONLY);
    char buf;
    while (read(fd, &buf, sizeof(buf)) > 0)
    {
        printf("%d", buf);
    }
    printf("\n");
    close(fd);
    return 0;
}
