#include <stdio.h>


int main(int argc, char const *argv[])
{
   int max=0, subMax=0, num=1, i; 

   while (num != 0)
   {      

      scanf("%d", &num);

      if (num > max) max = num;
      if (num > subMax && num < max)  subMax = num;
      
      i++;
   }
   printf("max:%d, subMax:%d", max, subMax);

   return 0;
}
