#include <iostream>

void countingSort(int *array, const int LEN) {
    int counters[10] = {0};

    for (int i = 0, element = 0; i < LEN; i++) {
        element = array[i];
        counters[element]++;
    }

    for (int i = 0, k = 0; i < 10; i++) 
       for (int j = 0; j < counters[i]; j++) 
           array[k++] = i;
}


void countingSortMod1(int *array, int len) {
    int counters[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < len; i++) counters[array[i]]++;
    int k = 0; 
    for (int i = 0; i < 10; i++) 
        for (int j = 0; j < counters[i]; j++) 
            array[k++] = i;
}

void countingSortMod2(int *array, int len) {
    int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int *out = (int*)calloc(len, sizeof(int));
    for (int i = 0; i < len; i++) count[array[i]]++;
    for (int i = 1; i < 10; i++) count[i] += count[i-1];
    for (int i = len-1; i > -1; i--) out[--count[array[i]]] = array[i];
    for (int i = 0; i < len; i++ ) array[i] = out[i];
    free(out);
}

int main()
{
    const int LEN = 20;
    int toSort[] = {3, 5, 7, 4, 8, 1, 4, 6, 4, 2, 7, 6, 8, 0, 9, 2, 3, 7, 4, 3, 2};
    
    // print array 
    for (int& element: toSort) 
        std::cout << element << " ";

    countingSort(&toSort[0], LEN);
    
    // print array 
    std::cout << "\n";
    for (int& element: toSort) 
        std::cout << element << " ";

   printf("\n");
   return 0;
}
