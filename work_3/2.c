#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

enum
{
    SIZE_BUF = 16
};

int
main(void)
{
    
    char buf[SIZE_BUF];
    int pointer = 0;
    long long number = 0;
    long long summ = 0;
    int sign = 1;
    int readed = 0;
    int was_number = 0;
    while ((readed = read(0, buf, SIZE_BUF)) > 0) {
        pointer = 0;
        while (pointer < readed) {
           
            if (buf[pointer] == '-') {
                sign = -1;
                was_number = 0;
            }
            if (buf[pointer] == '+') {
            
            } else if (buf[pointer] >= '0' && buf[pointer] <= '9') {
                number = number * 10 + (buf[pointer] - '0');
                was_number = 1;
            } else { 
                if (was_number) {
                    number *= sign;
                    sign = 1;
                    summ += number;
                    number = 0;
                }
                was_number = 0;
            }
            pointer++;
        }
    }
    number *= sign;
    summ += number;
            
    printf("%lld\n", summ);
    return 0;
}
