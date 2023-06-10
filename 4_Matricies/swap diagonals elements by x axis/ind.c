#include <stdio.h>
#include <malloc.h>


int main() {

   int cols = 5;
   int rows = 5;

   int *array = (int*)calloc(sizeof(int), cols*rows);

   int c = 1;
   for (int *ptr = array; ptr < array+((rows)*(cols));  ptr++) {
       *ptr = c++;
   }

   
   for (int *ptr = array, i=1; ptr < array+(rows)*(cols);i++, ptr++) {
       printf(" %2d ", *ptr);
        if (i % (rows) == 0)
           printf("\n");
   }

    int y=0;
    for (int i=0,j=rows;i<rows;i++,j--,y+=rows){
        int temp = array[i+y];
        array[i+y] = array[j+y-1];
        array[j+y-1] = temp;
    }
 printf("\n"); printf("\n");

   for (int *ptr = array, i=1; ptr < array+(rows)*(cols);i++, ptr++) {
       printf(" %2d ", *ptr);
        if (i % (rows) == 0)
           printf("\n");
   }

   free(array);

   return 0;
}
