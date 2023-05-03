#include <stdio.h>


int euclideanAlg(int a, int b) {
    if (b == 0) {
        return a;
    }
    return euclideanAlg(b, a % b);
    
}

int main()
{
    printf("%i", euclideanAlg(68, 102));

    return 0;
}
