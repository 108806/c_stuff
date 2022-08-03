#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int counter[10] = {0};
    
    char *line = (char*)malloc(sizeof(char)*1024);
    scanf("%[^\n]", line);
    line = realloc(line, strlen(line)+1);
    
    for (int i = 0; i < strlen(line); i++){
        if (line[i] < 65 && line[i] > 47){
            int idx = line[i] - '0';
            counter[idx]++;
        }
    }
    
    for (int i = 0; i < 10 ; i++) printf("%i ", counter[i]);
    
    return 0;
}
