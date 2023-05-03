#include <stdio.h>

int main() {
  const int ARRAYSIZE = 10;
  int array[ARRAYSIZE];

  printf("\nenter 10 numbers:");

  for (int k = 0; k < ARRAYSIZE; k++)
    scanf(" %d", &array[k]);

  for (int i = ARRAYSIZE-1; i >= 0; i--) {
    printf(" %d", array[i]);
  }
  return 0;
}