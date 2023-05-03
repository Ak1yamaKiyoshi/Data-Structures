#include <stdio.h>
#include <string.h>


int main() {
    char str1[] = "string1";
    char str2[20];
    int str1len = 8;
    int str2len = 20;

    if (str1len < str2len) {
        strcpy(str2, str1);
        puts(str2);
    }

    return 0;
}