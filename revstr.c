#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void revstr(char* str) {
    char tmp;
    size_t s = strlen(str)-1;
    for (int i = 0; i < s / 2; i++) {
        tmp = str[i];
        str[i] = str[s - i];
        str[s - i] = tmp;
    }
}

char* bin(int n) 
{
    size_t slen = 0;

    while (n >> slen > 0) slen++;
    slen = slen;
    printf("slen : %zu\n", slen);

    char* result = (char*)calloc(slen + 1, 1);
    for (size_t i = 0; i < slen; i++) {
        if (result) {
            result[i] = (n % 2) + '0';
            printf("%c : %zi\n", result[i], i);
        }
        n = n / 2;
    }
    return result;
}

// void bin(int n) {
//     if (n <= 1){
//         printf("%d", n);
//     }else{
//         printf("%d", n % 2);
//         bin(n /2 );
//     }
// }

int main()
{
    char *x = bin(1337);
    revstr(x);
    printf("\n%s", x);
    return 0;
}
