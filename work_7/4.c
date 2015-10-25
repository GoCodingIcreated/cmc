#include <stdio.h>

enum
{
    PAGE_SIZE = 1 << 12,
    BUF_SIZE = 1024,
    OFFSET = 22
};

int
main(void)
{
    char buffer[BUF_SIZE];
    unsigned long long size1, size2, size_last = -1;
    long long pages = 1;
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, "%llx-%llx", &size1, &size2) != 2) {
            break;
        }
        size2 >>= OFFSET;
        size1 >>= OFFSET;
        pages += size2 - size1 + 1;
        if (size1 == size_last) {
            --pages;
        }
        size_last = size2;
    }
    printf("%lld\n", pages * PAGE_SIZE);
    return 0;
}
