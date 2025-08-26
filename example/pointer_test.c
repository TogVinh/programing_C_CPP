#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5;
    int *p = NULL;
    int **p2 = NULL;

    *p = a;
    p2 = &p;

    system("clear");

    // a = *p = **p
    // &a = p = *p
    // &p = p2d

    printf("a   =  |%d| \n", a);\
    printf("&a   = |%p| \n", &a);
    printf("*p   = |%d| \n", *p);
    printf("p    = |%p| \n", p);
    printf("&p   = |%p| \n", &p);
    printf("**p2 = |%d| \n", **p2);
    printf("*p2  = |%p| \n", *p2);
    printf("p2   = |%p| \n", p2);
    printf("&p2  = |%p| \n", &p2);


    return 0;
}