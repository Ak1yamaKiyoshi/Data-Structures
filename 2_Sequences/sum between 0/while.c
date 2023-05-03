#include <stdio.h>


int main(int argc, char const *argv[])
{
   int i=0, num, flag=0, sum = 0;

   while (i < 10)
   {

      scanf("%d", &num);

      if (flag>0) {sum += num;}
      if (num == 0 && flag>0) flag = 0;
      else if (num == 0) flag = 1;
      i++;
   }
   printf("%d", sum);

   return 0;
}
