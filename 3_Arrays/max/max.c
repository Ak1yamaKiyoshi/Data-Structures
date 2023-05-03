#include <stdio.h>

// Знайти максимальне число у масиві.
// findMaxNumber(int array[], int ARRSIZE)
int findMaxNumber(int array[], int ARRSIZE) {
    int max = array[0];
    for (int i = 1; i < ARRSIZE; i++) {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

int main() {
    const int ARRSIZE = 6;
    int array[] = {200, 4, 1, -5, 78, 1};    
    
    printf("%d", findMaxNumber(array, ARRSIZE));
    
    return 0;
}
