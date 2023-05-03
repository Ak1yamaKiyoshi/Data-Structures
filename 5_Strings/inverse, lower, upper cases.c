#include <stdio.h>
#include <string.h>
#include <malloc.h> 

// Зробити всі літери маленькими 
void lowercase(char *str) {
    for (; *str; ++str) *str = tolower(*str);
}

// Зробити всі літери великими
void uppercase(char *str) {
    for (; *str; ++str) *str = toupper(*str);
}
// Зробити інверсію регістра
void inversecase(char *str) {
    for (; *str; ++str)  {
        if (islower(*str)) *str = toupper(*str);
        else *str = tolower(*str);
    }
}

int main() {

    char *str = (char*)calloc(sizeof(char), 100);
    char *str1 = (char*)calloc(sizeof(char), 100);

    strcpy(str, "Hello");
    int len = 7;
    printf("Firts string: ");
    puts(str);

    strcpy(str1, "WORLD");
    int len1 = 6;
    printf("Second string: ");
    puts(str1);

    lowercase(str1, len1);
    printf("Second string after lowercase: ");
    puts(str1);
    uppercase(str1);
    printf("Second string after uppercase: ");
    puts(str1);

    inversecase(str);
    printf("inversecase first string: ");
    puts(str);

    free(str); 
    free(str1);
    
    return 0;
}