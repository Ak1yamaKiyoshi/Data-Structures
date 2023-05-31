#include <stdio.h>
#include <string.h>

int main()
{
    
    char *str1 = "cc";
    char *str2 = "occooooddddddddd";

    printf("1 string: %s\n", str1);
    printf("2 string: %s\n", str2);
    
    printf("first entry str1 in str2 at index: %d\n", strstr(str2, str1) - str1-3);

    return 0;
}
