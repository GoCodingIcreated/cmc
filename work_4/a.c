#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum
{
    MAX_SIZE = 10000,
    MAX_GID = 60,
    USER = 6,
    GROUP = 3,
    NOBODY = 0
};

int
has_permissions(unsigned long command, unsigned long permission, unsigned long status)
{
    command <<= status;
    return (command | permission) == permission;

}

int
is_in_group(unsigned long *gid, int n, unsigned long file_gid)
{
    for (int i = 0; i < n; ++i) {
        if (gid[i] == file_gid) {
            return 1;
        }
    }
    return 0;
}

char*
cat_space(char *s)
{
    while (isspace(*s)) {
        s++;
    }
    int n = strlen(s);
    while (n > 0 && isspace(s[n - 1])) {
        n--;
    }
    s[n] = 0;
    return s;
}


int
main(void)
{
    char buf[MAX_SIZE];
    
    fgets(buf, MAX_SIZE, stdin);
    unsigned long  uid;
    sscanf(buf, "%lu", &uid);
    
    fgets(buf, MAX_SIZE, stdin);
    unsigned long gid[MAX_GID];
    int gid_counter = 0;
    int temp = 0;
    char *p = buf;
    int a = 0;
    printf("%ld\n", uid); 
    while ((a = sscanf(p, "%lu%n", &gid[gid_counter], &temp)) != EOF && a != 0 ) {
        gid_counter++;
        p += temp;
        printf("%ld ", gid[gid_counter - 1]); 
    }
    
    unsigned long operation = 0;
    fgets(buf, MAX_SIZE, stdin);
    sscanf(buf, "%lo", &operation);

    while (fgets(buf, MAX_SIZE, stdin) != NULL) {
        unsigned long file_gid, file_uid;
        unsigned long  permissions;
        p = buf;
        sscanf(p, "%lu%lu%lo%n", &file_uid, &file_gid, &permissions, &temp);
        p += temp;
        p = cat_space(p);
        if (uid == file_uid) {
            if (has_permissions(operation, permissions, USER)) {
                printf("%s\n", p);
            }
        } else {
            if (is_in_group(gid, gid_counter, file_gid)) {
                if (has_permissions(operation, permissions, GROUP)) {
                    printf("%s\n", p);
                }
            } else {
                if (has_permissions(operation, permissions, NOBODY)) {
                    printf("%s\n", p);
                }
            }
        }
    }

    return 0;
}
