#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <memory.h>

void print(char **stringArray, int rows) {
    for (int i = 0; i < rows; i++) {
        printf("[%d] ", i);
        puts(stringArray[i]);       
    }
}

void enter(char **stringArray, int rows) {
    char *buffer = (char*)calloc(sizeof(char), 50);
    for (int i = 0; i < rows; i++) {
        printf("Enter string: ");
        scanf("%s", buffer);
        stringArray[i] = (char*)calloc(sizeof(char), strlen(buffer));
        strcpy(stringArray[i], buffer);
    }
    free(buffer);
}

// return index of min row
int minRow(char **stringArray, int rows) {
    if (rows < 1) return -1;
    int minIndex = 0;
    int minSum = -1;
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (char *p = stringArray[i]; *p; p++) 
            sum += *p;
        if (minSum == -1 || sum < minSum) {
            minSum = sum; 
            minIndex = i;
        }
    }
    return minIndex;
}

int main()
{
    int rows = 4;
    int cols = 6;
    char **stringArray = (char**)calloc(sizeof(char*), rows); 

    enter(stringArray , rows);
    printf("\n");
    print(stringArray , rows);
    printf("First shortest row: %s\n", stringArray[minRow(stringArray, rows)]);

    //deallocating
    for (int i = 0; i<rows; i++) {
        free(stringArray[i]);
    }
    free(stringArray);

    return 0;
}