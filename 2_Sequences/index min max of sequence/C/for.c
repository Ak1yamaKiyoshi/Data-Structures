#include <stdio.h>

int main(int argc, char const *argv[])
{
   int i=0, min=0, max=0, minI=0, maxI=0, num=1, pNum=1;
   
   for(i = 0; num != 0; i++)
   {
      
      pNum = num;
      scanf("%d", &num);

      if (i == 1 || pNum < min) {min = pNum; minI = i;}
      if (i == 1 || pNum > max) {max = pNum; maxI = i;}
   }
   printf("min:%d, minI:%d", min, minI);
   printf("\nmax:%d, maxI:%d", max, maxI);

   return 0;
}
