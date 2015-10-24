#include <stdio.h>

int main(int argc, char ** argv)
{
    double count, credit_rate, deposit_rate;
    sscanf(argv[1], "%lf", &count);//from_string_to_double(argv[1]);
    sscanf(argv[3], "%lf", &credit_rate);//from_string_to_double(argv[3]);
    sscanf(argv[2], "%lf", &deposit_rate);//from_string_to_double(argv[2]);
    double tmp;
    for ( int i = 4; i < argc; ++i )
    {
        sscanf(argv[i], "%lf", &tmp);
        count += tmp;
        if ( count > 0 )
            count = count * deposit_rate / 100 + count;
        else
        if ( count < 0 )
            count = count * credit_rate / 100 + count;
    }
    printf("%.10g\n", count);
    return 0;
    
}
