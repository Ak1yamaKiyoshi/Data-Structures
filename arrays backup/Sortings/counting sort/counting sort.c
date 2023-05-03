#include <stdio.h>


void countingSort(int *array, int len) {
    int counters[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < len; i++) counters[array[i]]++;
    int k = 0; 
    for (int i = 0; i < 10; i++) 
        for (int j = 0; j < counters[i]; j++) 
            array[k++] = i;
}

void countingSortMod(int *array, int len) {
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
   const int SIZE = 20;
   int toSort[] = {3, 5, 7, 4, 8, 1, 4, 6, 4, 2, 7, 6, 8, 0, 9, 2, 3, 7, 4, 3, 2};
   int counters[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

   for (int i = 0; i < SIZE; i++)
   {
       counters[toSort[i]] += 1;
   }

   printf("\n");
   int k = 0;
   for (int i = 0; i < 10; i++) {
       for (int j = 0; j < counters[i]; j++) {
           toSort[k] = i;
           k++;
       }
   }
   for (int i = 0; i < SIZE; i++) {
       printf("%d ", toSort[i]);
   }
   printf("\n");
   return 0;
}
