#include <malloc.h>
#include <stdio.h> 
#include <strings.h>


int main() {

    char *str = (char*)calloc(sizeof(char), 100);
    printf(" enter string: ");
    scanf("%s", str);

    puts(str);

    return 0;
}