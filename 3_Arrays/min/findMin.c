#include <stdio.h>


int main()
{
    const int ARRAYSIZE = 8;
    int array[ARRAYSIZE];
    int index;
    int minNumber;

    printf("\nenter 8 numbers:");

    for (int k = 0; k < ARRAYSIZE; k++)
      scanf(" %d", &array[k]);

    minNumber=array[0];
    for (int i = 0; i < ARRAYSIZE; i++)
        if (array[i] < minNumber){
            minNumber = array[i];
            index = i;
          }
    printf("\nMinimum: %d", minNumber);
    printf("\nIndex: %d", index);

    return 0;
}