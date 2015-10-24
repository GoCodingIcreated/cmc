#include <stdio.h>
#include <stdlib.h>
void normalize_path(char *buf)
{
    int count = 0;
    int real_count = 0;
    int was_slash = 0;
    for ( ; buf[count] != 0; ++count )
    {
        if (buf[count] == '/')
        {
            if (!was_slash)
            {
                buf[real_count] = buf[count];
                real_count++;
            }
            was_slash = 1;
            
        }
        else
        {
            was_slash = 0;
            buf[real_count] = buf[count];
            real_count++;
        }
    }
    buf[real_count] = 0;
}
/*
int main(void)
{
    char str[10000];
    //scanf("%s", str);
    gets(str);
    normalize_path(str);
    printf("%s\n", str);
    return 0;
}
*/
