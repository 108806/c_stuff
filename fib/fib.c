#include <stdio.h>

int main(void)
{
    int fib[32]; int i;

    //Vals only for initiation
    fib[0] = 0; fib[1] = 1;

    for (i = 2; i <= 32; ++i)
    {
            fib[i] = fib[i-1] + fib[i-2];
            //Printing from 3 upwards
            printf("%i ", fib[i]);
    }

    return 0;
}
