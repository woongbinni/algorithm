#include <stdio.h>

int main(){
  int in;
  int out = 1;
  scanf("%d", &in);

  for(int i=1; i<=in; ++i){
    out *= i;
  }
  printf("%d\n", out);
  
  return 0;
}