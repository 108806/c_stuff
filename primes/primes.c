#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    
    int _MAX_ = 128;

    int p, i, primes[_MAX_/2], primeIndex = 2;
    bool isPrime;

    primes[0] = 2;
    primes[1] = 3;

    for (p = 5; p <= _MAX_; p = p+2)
    {
        isPrime = true;
        printf("Now looking at %i\n", p);
        //Divide the current prime candidate with previous primes
        for (i = 1; isPrime && p / primes[i] >= primes[i]; ++i)
        {   
            printf("Testing %i against %i\n", p, primes[i]);
            if (primes[i] == primes[primeIndex]) break;
            if (p % primes[i] == 0) isPrime = false;
            
            if (isPrime == true)
            {
                primes[primeIndex] = p;
                ++primeIndex; 
            }
        }
    }

for (i = 0; i < primeIndex; i++)
    {
        printf("#%i : %i\n", i+1, primes[i]);       
    }
return 0;
}
