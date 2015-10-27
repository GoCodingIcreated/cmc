#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    if (!fork())
    {
        execlp(argv[1], argv[1], NULL);
        return 1;
    }
    int status;
    wait(&status);
    if (WIFEXITED(status) == 0 || WEXITSTATUS(status) != 0)
    {
        if (!fork())
        {
            execlp(argv[2], argv[2], NULL);
            return 1;
        }
        wait(&status);
        if (WIFEXITED(status) == 0 || WEXITSTATUS(status) != 0)
            return 1;
    }
    if (!fork())
    {
        execlp(argv[3], argv[3], NULL);
        return 1;
    }
    wait(&status);
    return WIFEXITED(status) == 0 || WEXITSTATUS(status) != 0 ? 1 : 0;
}
