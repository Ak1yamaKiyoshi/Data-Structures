#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


int main() {

    int *table = (int*)calloc(sizeof(int), 25);  // (a 97, z 122)
    char *line = (char*)calloc(sizeof(char), 200);
    int lineLenght = 200;
    int tableLen = 25;

    printf("Enter line:");
    getline(&line, &lineLenght, stdin);

    // increment array indexes that represent letters (char-97)
    for (int i = 0; i < lineLenght; i++) 
        if (line[i] >= 'a' && line[i] <= 'z') 
            table[(int)line[i]-97]++;

    for (int i = 0; i < tableLen; i++) 
        if (table[i] > 0) 
            printf("char: %c, amount: %d\n", i+97, table[i]);

    free(table);
    free(line);

    return 0;
}