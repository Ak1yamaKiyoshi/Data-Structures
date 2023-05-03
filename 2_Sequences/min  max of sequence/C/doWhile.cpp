#include <stdio.h>

int main(int argc, char const *argv[])
{
   
   int i=0, sum=0, min, num=1, pNum=1;
   
   do 
   {
      pNum = num;
      sum += pNum;
      scanf("%d", &num);
      if (i == 1 || pNum < min) min = pNum;
      i++;

   } while (num != 0);

   printf("min:%d\navg:%d",min, sum/(i-1));

   return 0;
}
