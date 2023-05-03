#include <stdio.h>

int main(int argc, char const *argv[])
{
   
   int i, sum=0, min, num=1, pNum=1;

   for (i = 0; num != 0; i++)
   {
      pNum = num;
      sum += pNum;
      scanf("%d", &num);
      if (i == 1 || pNum < min) min = pNum;
   }
   printf("min:%d\navg:%d",min, sum/(i-1));

   return 0;
}
