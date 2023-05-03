#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  const int ARRAYSIZE = 10;
  int array[ARRAYSIZE];
  srand(time(NULL));
  
  for(int i = 0; i < ARRAYSIZE; i++){
    printf(" %d\n", array[i] = rand() % 100);
  }

  return 0;
    
}