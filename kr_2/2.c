#include <stdio.h>
#include <time.h>

enum
{
    FIRST_YEAR = 1900,
    DAY_IN_WEEK = 7,
    MONTH_IN_YEAR = 12
};

int main(int argc, char **argv)
{
    int year, m_day, w_day;
    sscanf(argv[1], "%d", &year);
    sscanf(argv[2], "%d", &m_day);
    sscanf(argv[3], "%d", &w_day);
    int cnt = 0;
    w_day %= DAY_IN_WEEK;
    year -= FIRST_YEAR;
    for (int i = 0; i < MONTH_IN_YEAR; ++i)
    {
        time_t t = time(NULL);
        struct tm my_time;;
        my_time.tm_sec = my_time.tm_min = my_time.tm_hour = 0;
        my_time.tm_year = year;
        my_time.tm_mon = i;
        my_time.tm_mday = m_day;
        t = mktime(&my_time);
        struct tm *new_time = localtime(&t);
        if (new_time->tm_wday == w_day)
            cnt++;
    }
    printf("%d\n", cnt);
}
