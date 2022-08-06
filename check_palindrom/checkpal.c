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
{
    const char *rword = revstring(word);
    int cmp = !strcmp(word, rword);
    return cmp;
}


int main()
{
    //case negative:
    const char *word = "Simulation";
    int p1 = chkpal(word);
    printf("\ncase0 : %d\n", p1);

    //case positive:
    const char *palindrom = "abba";
    int p2 = chkpal(palindrom);
    printf("\ncase1 : %d\n", p2);

    return 0;
}
