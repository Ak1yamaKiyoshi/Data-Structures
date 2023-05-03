#include <stdio.h>

int main(int argc, char const *argv[])
{

   int min=0, max=0, minCounter=0, maxCounter=0, num=1, pNum=0;
   
   for (int i = 0; num!=0; i++)
   {

      pNum = num;
      scanf("%d", &num);
      
      if (i == 1 || pNum < min) 
      {
         minCounter = 1; 
         min = pNum;
      }
      else if (pNum == min) 
         minCounter += 1; 
      
      if (i == 1 || pNum > max) 
      {
         maxCounter = 1; 
         max = pNum;
      }
      else if (pNum == max) 
         maxCounter += 1; 
   }
   printf("min:%d times:%d", min, minCounter);
   printf("\nmax:%d times:%d", max, maxCounter);

   return 0;
}
