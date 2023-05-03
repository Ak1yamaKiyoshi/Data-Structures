#include <stdio.h>

/*
	2. Факторіал числа х.
		factorial(x) = 1*2*3*4*...*x
		 
		Написати дві функції одна з яких обраховує факторіал за допомогою циклу, а інша за допомогою рекурсії. 
		Функція мейн повинна містити тестовий код для демонстрації обох функцій */
int factorial(int lim) {
    if (lim > 1)
        lim *= factorial(lim-1);
    return lim;
}

int factorialFor(int lim) {
    int n;
    for (int i = lim; i > 1; i--) {
        lim *= i-1;
    }
    return lim;
}

int main()
{
    
    printf("%d", factorial(5));
    printf("\n%d", factorialFor(5));
    return 0;
}
