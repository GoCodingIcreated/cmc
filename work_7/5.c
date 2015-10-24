#include <stdio.h>
#include <stdlib.h>

enum
{
    BUF_SIZE = 1024
};

int
main(int argc, char **argv)
{
    unsigned memory_size, cache_size, block_size;
    sscanf(argv[1], "%u", &memory_size);
    sscanf(argv[2], "%u", &cache_size);
    sscanf(argv[3], "%u", &block_size);
    char buffer[BUF_SIZE];
    char *p;
    long long all_miss = 0;
    int cache_num = cache_size / block_size;
    int *cache = calloc(cache_num, sizeof(*cache));
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        p = buffer + 2;
        unsigned adr, size;
        if (sscanf(p, "%x %d", &adr, &size) != 2)
            break;
        unsigned memory_num = adr / block_size + 1;

        int c_b_n = memory_num % cache_num;
        if (cache[c_b_n] != memory_num) {
            if (cache[c_b_n] != 0) {
                all_miss++;
            }
        }
        int memory_num2 = (adr + size - 1) / block_size + 1;
        if (memory_num2 % cache_num != memory_num % cache_num) {
            if (cache[memory_num2 % cache_num] != memory_num2) {
                if (cache[memory_num2 % cache_num] != 0) {
                    all_miss++;
                }
            }
            cache[memory_num2 % cache_num] = memory_num2;
        }
        cache[c_b_n] = memory_num;
    }
    printf("%lld\n", all_miss);
    return 0;
}
