#include <stdio.h>

 int main(void){
   int tc;
   int a, b;
   scanf("%d", &tc);

   for(int i=0; i<tc; ++i){
     scanf("%d%d", &a, &b);
     printf("%d\n", a+b);
   }

   return 0;
 }