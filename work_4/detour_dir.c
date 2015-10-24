#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <limits.h>

int main(int argc, char ** argv)
{
    DIR *dir = opendir(argv[1]);
    struct dirent * d; 
    struct stat st;
    long long size = 0;
    char str[PATH_MAX];
    while ( (p = readdir(dir)) != NULL )
    {
        int temp = lstat(p->d_name, &st);
        snprintf(str, MAX_PATH, "%s/%s", argv[1], p->d_name);
        if ( temp == 0 && S_ISREG(st.st_mode))
        {
            size += st.st_size;
        }

    }


    closedir(dir);
    printf("%lld\n", size);
    return 0;
}
