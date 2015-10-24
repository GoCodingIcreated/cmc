#include <stdio.h>

struct A
{
    enum B { ASD = 1, QWE, ZXC} b;
    int data;
};

enum F { ASD = 3};

struct C
{
    enum D { ASD = 2 } d;
    int data;
};


int main(void)
{
    struct A a;
    struct C c;
    a.data = ASD;
    c.data = ASD;
    printf("%d %d\n", a.data, c.data);
    return 0;
}
