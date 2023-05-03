#include <stdio.h>
#include <string.h>

int main()
{
    
    char *str1 = "aaxx";
    char *str2 = "aacc";

    printf("first: %s", str1);
    printf("second: %s", str2);

    printf("difference etween first two and second two: %d", strncmp(str1, str2, 2));

    return 0;
}
