#include <stdio.h>

int main(){
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  if(c - b <= 0){
    printf("-1\n");
  }
  else{
    int ret = a / (c-b);
    printf("%d\n", ret + 1);
  }
  return 0;
}