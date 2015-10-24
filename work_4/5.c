#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <linux/limits.h>
#include <string.h>
#include <stdlib.h>

enum
{
    START_DIRS_NUMBER = 5
};


int
cmp(const void *s1, const void *s2)
{
    char *a = (char*)s1;
    char *b = (char*)s2;
    return strcasecmp(a, b);
}


void
go_dir(char *path)
{
    // need to check can we read the dir
    // need to check if file which we are looking at is dir
    // need to do in alphabet with checking by strcasecmp
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return;
    }
    struct dirent *p;
    struct stat st;
    int current_dir = 1;
    int max_dir = START_DIRS_NUMBER;
    char (*dirs_list)[PATH_MAX];
    dirs_list = calloc(max_dir, sizeof(*dirs_list));
    while ((p = readdir(dir)) != NULL) {
        if (strcmp(p->d_name, ".") == 0 || 
            strcmp(p->d_name, "..") == 0 ) {
            continue;
        }
        snprintf(dirs_list[0], PATH_MAX, "%s/%s", path, p->d_name);
        int temp = lstat(dirs_list[0], &st);
        if (temp == 0 && S_ISDIR(st.st_mode)) {
            if (current_dir >= max_dir) {
                max_dir = max_dir * 3 / 2;
                dirs_list = realloc(dirs_list, sizeof(*dirs_list) * max_dir);
            }
            snprintf(dirs_list[current_dir], PATH_MAX, "%s", p->d_name);
            current_dir++;    
        }
    }
    closedir(dir);
    qsort(dirs_list + 1, current_dir - 1, sizeof(dirs_list[0]), cmp);
    for (int i = 1; i < current_dir; ++i) { 
        snprintf(dirs_list[0], PATH_MAX, "%s/%s", path, dirs_list[i]);
        DIR *d = opendir(dirs_list[0]);
        if (d == NULL) {
            continue;
        }
        closedir(d);
        printf("cd %s\n", dirs_list[i]);
        go_dir(dirs_list[0]);
        printf("cd ..\n");
    }
    free(dirs_list);
}



int
main(int argc, char ** argv)
{
    go_dir(argv[1]);
    return 0;
}
