#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

enum
{
    MAX_SIZE = 10000,
    MAX_GID = 60,
    USER = 6,
    GROUP = 3,
    NOBODY = 0,
    BASE10 = 10,
    BASE8 = 8
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
    
    char *ebuff1, *ebuff2;
    ebuff1 = buf;
    ebuff2 = buf;
    while ((gid[gid_counter] = strtol(ebuff1, &ebuff1, 10)) != 0  || ebuff1 != ebuff2 ) {
        gid_counter++;
        ebuff2 = ebuff1;
    }
    
    unsigned long operation = 0;
    fgets(buf, MAX_SIZE, stdin);
    sscanf(buf, "%lo", &operation);

    while (fgets(buf, MAX_SIZE, stdin) != NULL) {
        unsigned long file_gid, file_uid;
        unsigned long  permissions;
        ebuff1 = buf;
        file_uid = strtol(ebuff1, &ebuff1, BASE10);
        file_gid = strtol(ebuff1, &ebuff1, BASE10);
        permissions = strtol(ebuff1, &ebuff1, BASE8);
        ebuff1 = cat_space(ebuff1);
        if (uid == file_uid) {
            if (has_permissions(operation, permissions, USER)) {
                printf("%s\n", ebuff1);
            }
        } else {
            if (is_in_group(gid, gid_counter, file_gid)) {
                if (has_permissions(operation, permissions, GROUP)) {
                    printf("%s\n", ebuff1);
                }
            } else {
                if (has_permissions(operation, permissions, NOBODY)) {
                    printf("%s\n", ebuff1);
                }
            }
        }
    }
    return 0;
}
