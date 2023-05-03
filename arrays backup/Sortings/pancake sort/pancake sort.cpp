#include <iostream>

void randomFilling(int *array, int len) {
    srand(time(NULL));
    for (int i = 0; i < len; i++)
        array[i] = rand() % len;
}

void print(int *array, int len) {
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
}

void flip(int *array, int len) {
    for (int i=0, j=len; i<j; i++, j--) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int max(int *array, int len) {
    int j=array[0];
    for (int i = 1; i < len; i++) 
        if (array[i] > array[j]) 
            j = i;
    return j;
}

void pancakeSort(int *array, int len) {
    for (int size = len; size > 1; --size) { 
        int m = max(array, size);
        if (m != size-1) { 
            flip(array, m); 
            flip(array, size-1); 
        }
    }
}

int main() {
    int len = 14; 
    int *array = new int[len];

    randomFilling(array, len);
    print(array, len);
    pancakeSort(array, len);
    std::cout << "\n";
    print(array, len);

    delete array;

    return 0;
}