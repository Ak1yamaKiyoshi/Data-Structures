#include <stdio.h>


int main()
{
    const int ARRAYSIZE = 7;
    int array[ARRAYSIZE];
    int null = 0, minus = 0, plus = 0;

    printf("\nenter 7 numbers:");

    for (int k = 0; k < ARRAYSIZE; k++)
      scanf(" %d", &array[k]);
      

    for (int i = 0; i < ARRAYSIZE; i++){
        if (array[i] == 0)
            null++;
        else if (array[i] > 0)
            plus++;
        else
            minus++;
    }
        

    printf("Null: %d\n Plus: %d\n Minus: %d\n", null, plus, minus);

    return 0;
}