#include <stdio.h>


// 	1. Написати програму яка читає з клавіатури послідовність чисел до появи нуля, знайти суму введених чисел.
//		Вправу зробити з використанням циклів (бажано усіх) та обов’язково рекурсією.
int sumWhile() {
    int sum=0, num;
    scanf("%d", &num);
    while (num != 0) {
        sum += num;
        scanf("%d", &num);
    }
    return sum;
}


int sumFor() {
    int sum=0, num;
    scanf("%d", &num);
    for (; num != 0; scanf("%d", &num)) {
        sum += num;
    }
    return sum;
}


int sumDoWhile() {
    int sum=0, num;
    scanf("%d", &num);
    if (num != 0)
        do 
        {
            sum += num;
            scanf("%d", &num);
        } while (num != 0);
    return sum;
}


int sumRecursion(int sum, int num) {
    scanf("%d", &num);
    if (num != 0) {
        sum += num;
        sum = sumRecursion(sum, num);
    }
    return sum;
}


int main() {
    printf("%d", sumFor());
    //printf("%d", sumWhile());
    //printf("%d", sumDoWhile());
    //printf("%d", sumRecursion(0, 0));
    
    return 0;
}
