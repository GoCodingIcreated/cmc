#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

struct Node
{
    int key;
    int left_idx;
    int right_idx;
};
void
my_read(int file, int *a, size_t size)
{
    char readed = 0;
    while( (readed += read(file, (char*)a + readed, size - readed)) != 4 );
}

typedef struct Node node;
void
print_tree(int file, int index)
{
    node n; 
    lseek(file, index * sizeof(n), SEEK_SET);
    my_read(file, &n.key, sizeof(n.key));
    my_read(file, &n.left_idx, sizeof(n.left_idx));
    my_read(file, &n.right_idx, sizeof(n.right_idx));
    if (n.right_idx) {
        print_tree(file, n.right_idx);
        lseek(file, index * sizeof(n), SEEK_SET);
    }
    printf("%d ", n.key);
    if (n.left_idx) {
        print_tree(file, n.left_idx);
    }
}

int
main(int argc, char ** argv)
{
    int file = open(argv[1], O_RDONLY);
    print_tree(file, 0);
    printf("\n");
    close(file);
    return 0;
}
