#include <stdio.h>
#define PI 3.14159265358979323846
int main()
{      
  int in;
  scanf("%d",&in);
  if(in>0 && in<=10000)
  {
    printf("%.6f\n", (double)(in*in)*PI);
    printf("%.6f\n", (double)(2*in*in));
  }
  return 0;
}