#include <stdio.h>
#include <string.h>


int main() {
    char str1[] = "begin + ";
    char str2[] = "end";
    char str3[50];
    
    strcat(str3, str1);
    strcat(str3, str2);
    
    puts(str3);

    return 0;
}
