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

    int y=0;
    for (int *x=array, *x1=array+rows-1; x<array+(rows*cols)-1;x+=rows+1, x1+=rows-1) {
        int temp = *x;
        *x = *x1; 
        *x1 = temp;
    }


   for (int *ptr = array, i=1; ptr < array+(rows)*(cols);i++, ptr++) {
       printf(" %2d ", *ptr);
       if (i % (rows) == 0)
           printf("\n");
   }

   free(array);

   return 0;
}