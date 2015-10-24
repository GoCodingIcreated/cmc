#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

void
my_read(int fd, void *buf, size_t size)
{
    int readed = 0;
    while ((readed += read(fd, buf, size - readed)) != size) {
    }
}


int
main(int argc, char **argv)
{
    unsigned short size;
    long long offset;
    sscanf(argv[2], "%lld", &offset);
    int fd = open(argv[1], O_RDONLY);
    size_t size_file = lseek(fd, 0, SEEK_END);
    size_t data_size = 0;
    size_t num_node = 0;
    if (size_file == 0) {
        printf("%u\n%u\n", num_node, data_size);
        return 0;
    }
    lseek(fd, offset, SEEK_SET);
    do {
        my_read(fd, &size, sizeof(size));
        lseek(fd, size, SEEK_CUR);
        my_read(fd, &offset, sizeof(offset));
        ++num_node;
        data_size += size;
        lseek(fd, offset - sizeof(size) - size - sizeof(offset), SEEK_CUR);
    } while (offset != 0);
    printf("%u\n%u\n", num_node, data_size);
    close(fd);
    return 0;
}
