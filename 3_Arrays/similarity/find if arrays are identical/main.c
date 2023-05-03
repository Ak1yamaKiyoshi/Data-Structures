#include <stdio.h>


// Перевірити чи тотожні масиви (порядок та значення елементів мають збігатись).
// checkIdenify(int array[], int arrayTwo[], int ARRSIZE)
// returns: 1 - Arrays are not simmilar, 0 - arrays similar 
int similarityCheck(int array[], int arrayTwo[], int ARRSIZE)
{
    int flag = 0;
    for (int i = 0; i < ARRSIZE; i++) {
        if (array[i] != arrayTwo[i])
            flag = 1;
    }
    return flag;
}

int main()
{

    const int ARRSIZE = 6;
    int array[] =    {4, 5, 2, 7, 8};
    int arrayTwo[] = {4, 5, 2, 7, 8};

    printf("%d", similarityCheck(array, arrayTwo, ARRSIZE));

    return 0;
}
