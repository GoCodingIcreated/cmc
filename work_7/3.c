#include <stdio.h>

int main(void)
{
    long long size = 0;
    char buffer[1024];
    long long size1, size2;
    while (fgets(buffer,sizeof(buffer), stdin) != NULL)
    {
        if (sscanf(buffer, "%llx-%llx", &size1, &size2) != 2)
            break;
        size += size2 - size1;
    }
    printf("%lld\n", size);
    return 0;
}
