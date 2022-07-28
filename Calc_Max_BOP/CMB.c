#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"


int OPa(int a, int b) { return a & b; } 
int OPb(int a, int b) { return a | b; } 
int OPx(int a, int b) { return a ^ b; } 

void cmo(int n, int k, const char c)
{
    int max = 0, tmp = 0, (*OP)(int,int);

    switch (c)
    {
        case '&':
            OP = OPa;break;
        case '|': 
            OP = OPb;break;
        case '^':
            OP = OPx;break;
    }

    printf("%p %p %p %p\n", &OPx, &OPb, &OPa, &*OP);

    for (int i = 1; i <= n ; i++){
        for (int j = 1; j <= n ; j++)
            if (j!=i){
                {
                    tmp = OP(i,j);
                    //printf("%i-OP-%i=%i ", i,j,tmp);
                    if (tmp > max && tmp < k) max = tmp;
                }
            }
    }
    printf("\nMAX : %i\n", max);
}

void calculate_the_maximum(int n, int k) {
  cmo(n, k, '&');
  cmo(n, k, '|');
  cmo(n, k, '^');
}

int main() {
    int n, k;
  
    calculate_the_maximum(39, 32);
 
    return 0;
}
