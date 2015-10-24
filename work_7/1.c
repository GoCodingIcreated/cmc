#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
    int a;
    int *status = NULL;
    pid_t pid;
    while (scanf("%d", &a) == 1)
    {
        pid = fork();
        if (pid != 0)
        {
            wait(status);
            printf("%d ", a);
            break;
        }
    }
    return 0;
}
