#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    DIR * dir = opendir(argv[1]);
    struct dirent *p;
    struct stat st;
    long long size = 0;
    char str[1000];
    getcwd(str, 1000);
    chdir(argv[1]);
    while ((p = readdir(dir)) != NULL)
    {
        int temp = lstat(p->d_name, &st);
        if (temp == 0 && S_ISREG(st.st_mode))
        {
            size += st.st_size;
        }
    }
    closedir(dir);
    printf("%lld\n", size);
    return 0;
}
