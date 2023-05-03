#include <stdio.h>
#include <string.h>


int main() {
    char str1[] = "streng";
    char str2[] = "string";

    printf("strings difference: %d\n", strcmp(str1, str2));

    return 0;
}