#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char buf[] = "asdqwerjlkcvxn;mn[q";
    qsort(buf, sizeof(buf), sizeof(*buf), strcasecmp);
    printf("%s\n", buf);
    return 0;
}
