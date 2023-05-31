#include <stdio.h>

int can_multiply_matrices(int col1, int row2) { return col1 == row2; }

void matrix_multiply(int a[][10], int b[][10], int c[][10], int row1, int col1, int row2, int col2) {

  int i, j, k;

  // Обчислення добутку матриць
  for (i = 0; i < row1; i++) {
    for (j = 0; j < col2; j++) {
      c[i][j] = 0;
      for (k = 0; k < col1; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}


void read_matrix(int matrix[][10], int row, int col) {
  int i, j;

  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
}

int main() {
  int a[10][10], b[10][10], c[10][10];
  int row1, col1, row2, col2, i, j;

  // Введення даних для першої матриці
  printf("Введіть розмірність першої матриці: ");
  scanf("%d%d", &row1, &col1);

  printf("Введіть елементи матриці:\n");
  read_matrix(a, row1, col1);

  // Введення даних для другої матриці
  printf("Введіть розмірність другої матриці: ");
  scanf("%d%d", &row2, &col2);

  printf("Введіть елементи матриці:\n");
  read_matrix(b, row2, col2);

  // Перевірка, чи можливе множення матриць
  if (!can_multiply_matrices(col1, row2)) {
    printf("Помилка: неможливо помножити матриці з такими розмірами.\n");
  } else {
    // Множення матриць
    matrix_multiply(a, b, c, row1, col1, row2, col2);

    // Виведення результату
    printf("Результат множення матриць:\n");
    for (i = 0; i < row1; i++) {
      for (j = 0; j < col2; j++) {
        printf("%d ", c[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}