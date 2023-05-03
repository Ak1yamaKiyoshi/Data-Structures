#include <stdio.h>


int main(int argc, char const *argv[])
{
   int x, check = 0, product = 1;

   do 
   {
      scanf("%d",&x);
      if (x == 0) check += 1;
      else product *= x;

   } while (check < 2);
   printf("%d", product);

   return 0;
}
