#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


const char *revstring(const char *string)
{   
    size_t wlen = strlen(string);

    char *revstr = (char*)calloc(
            sizeof(char) * wlen + 1,
            sizeof(char));

    for (size_t i = 0; i < wlen; i++){
        revstr[i] = string[wlen - i - 1];
    }
    //safety check:
    if (revstr[wlen] != '\0') strcat(revstr, "\0");
    return (const char*) revstr;
}


int chkpal(const char *word)
{   //simple but doing lots of garbage:
    const char *rword = revstring(word);
    int cmp = !strcmp(word, rword);
    return cmp;
}


int chkpal2(const char *word)
{   //optimized:
    size_t wlen = strlen(word);
    for (size_t i = 0; i < wlen; i++){
        if (word[i] != word[wlen - i - 1]) return 0;
    }
    return 1;
}




int main()
{
    //case negative:
    const char *word = "Simulation";
    int p1 = chkpal(word);
    printf("\ncase0 : %d\n", p1);

    //case positive:
    const char *palindrome = "abba";
    int p2 = chkpal(palindrome);
    printf("\ncase1 : %d\n", p2);

    //case negative:
    int p3 = chkpal2(word);
    printf("\ncase0 : %d\n", p3);

    //case positive:
    int p4 = chkpal2(palindrome);
    printf("\ncase1 : %d\n", p4);


    return 0;
}
