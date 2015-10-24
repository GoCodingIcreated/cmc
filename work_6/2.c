#define _XOPEN_SOURCE
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv)
{
    
    FILE *fd = fopen(argv[1], "r");
    char buffer[2000];
    
    time_t temp1, temp2;
    int is_first_time = 1;
    int temp;
    while (fgets(buffer, sizeof(buffer), fd) != NULL)
    {
        if (sscanf(buffer, "%d", &temp) != 1)
            break;
        struct tm Tm ;
        strptime(buffer, "%Y/%m/%d %T", &Tm);
        Tm.tm_isdst = -1;
        temp2 = mktime(&Tm);
        if (is_first_time)
        {
            is_first_time = 0;
            temp1 = temp2;
        }
        else
        {
            printf("%d\n", (int)(temp2 - temp1));
            temp1 = temp2;
        }
    }
    fclose(fd);
    return 0;
}
