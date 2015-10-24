#include <stdio.h>

int main(int argc, char ** argv)
{
    int x;
    char templ[] = "rwxrwxrwx";
    for ( int i = 1; i < argc; ++i )
    {
        char str[]= "---------";
        sscanf(argv[i], "%o", &x);
        for ( int j = 0; j < 9; ++j )
        {
            if ( x & (1 << (9 - j - 1) ) )
                str[j] = templ[j];
        }
        printf("%s\n", str);
    }
    return 0;
}
