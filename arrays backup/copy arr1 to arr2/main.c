#include <stdio.h>
#include <math.h>

void copyArray(int arrayOne[], int arrayTwo[], const int ARRSIZEONE, const int ARRSIZETWO) {
    if (ARRSIZEONE == ARRSIZETWO) {
        for (int i = 0; i < ARRSIZEONE; i++)
            arrayTwo[i] = arrayOne[i];
    }
}

int main()
{
    const int ARRSIZE = 6;
    int arrayOne[] = {2, 4, 1, -1, 3, 1};    
    int arrayTwo[ARRSIZE];
    
    copyArray(arrayOne, arrayTwo, ARRSIZE, ARRSIZE);
    
    for (int i = 0; i < ARRSIZE; i++)
        printf("%d ", arrayTwo[i]);

    return 0;
}
