#include <stdio.h>


int main(int argc, char const *argv[])
{
   int num, flag=0, sum = 0;

   for (int i = 0; i < 10; i++)
   {

      scanf("%d", &num);

      if (flag>0) {sum += num;}
      if (num == 0 && flag>0) flag = 0;
      else if (num == 0) flag = 1;
   }
   printf("%d", sum);

   return 0;
}
