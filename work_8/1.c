#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
    printf("1");
    /* PLACE1 */
    fflush(stdout);
    if (!fork()) {
        printf("2");
    }
    int status;
    wait(&status);
    /* PLACE2 */
    printf("3");
    return 0;
}
