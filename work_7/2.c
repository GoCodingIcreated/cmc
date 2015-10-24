#include <stdio.h>

int main(int argc, char **argv)
{
    int r_time, w_time, wr_time;
    sscanf(argv[1], "%d", &r_time);
    sscanf(argv[2], "%d", &w_time);
    sscanf(argv[3], "%d", &wr_time);
    char buffer[1024];
    char op, last_op = '!';
    int adr, last_adr = 0;
    int size, last_size = 0;
    char *p;
    long long all_time = 0;
    while (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        p = buffer;
        op = buffer[0];
        p += 2;
        sscanf(p, "%x %d", &adr, &size);
        if (op == 'R')
        {
            all_time += r_time;
            if (last_op == 'W' && last_adr == adr && last_size == size)
            {
                all_time += wr_time - r_time - w_time;
            }
        }
        if (op == 'W')
            all_time += w_time;
        last_op = op;
        last_adr = adr;
        last_size = size;
    }
    printf("%lld\n", all_time);
    return 0;
}
