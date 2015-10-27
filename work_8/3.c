#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>

int main(void)
{
    int pipefd[2];
    pipe(pipefd);
    time_t temp;
    if (!fork())
    {
        //son
        close(pipefd[1]);
        if (!fork())
        {
            //son
            if (!fork())
            {
                //son
                read(pipefd[0], &temp, sizeof(temp));
                struct tm *t = gmtime(&temp);
                printf("S:%d\n", t->tm_sec);
                return 0;
            }
            read(pipefd[0], &temp, sizeof(temp));
            wait(NULL);
            struct tm *t = gmtime(&temp);
            printf("M:%02d\n", t->tm_min);
            return 0;
        }
        read(pipefd[0], &temp, sizeof(temp));
        wait(NULL);
        struct tm *t = localtime(&temp);
        printf("H:%02d\n", t->tm_hour);
        return 0;
    }
    close(pipefd[0]);
    temp = time(NULL);
    for (int i = 0; i < 3; ++i )
        write(pipefd[1], &temp, sizeof(temp));
    fsync(pipefd[1]);
    wait(NULL);
    return 0;
}
