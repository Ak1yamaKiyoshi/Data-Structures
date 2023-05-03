#include <stdio.h>


int main(int argc, char const *argv[])
{
   int x, check = 0, product = 1;

   
   while (check < 2)
   {
      scanf("%d",&x);
      if (x == 0) check += 1;
      else product *= x;
   } 
   printf("%d", product);

   return 0;
}
