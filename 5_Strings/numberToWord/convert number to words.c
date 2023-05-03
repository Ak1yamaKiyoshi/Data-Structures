#include <stdio.h>
#include <string.h>
#include <string.h>

char *toWords(int num, char *buffer) {
    char *below20[] = {"zero ", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
    char *below100[] = {"", "", "twenty ", "thirty ", "fourty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
    if (num < 20) {
        strcat(buffer, below20[num]);
    }
    else if (num < 100) {
        strcat(buffer, below100[num/10]);
        strcat(buffer, below20[num%10]);
    }
    else if (num < 1000) {
        strcat(buffer, below20[(num%1000)/100]);
        strcat(buffer,  "hundred ");
        strcat(buffer, below100[(num%100)/10]);
        strcat(buffer, below20[num%10]);
    }
    return buffer;
}

int main() {
    
    int num;
    char *buffer = (char*)calloc(sizeof(char), 100);

    printf(" enter num: ");
    scanf("%d", &num);

    buffer = toWords(num, buffer);
    printf("%d - %s", num, buffer);

    free(buffer);
    
    return 0;
}