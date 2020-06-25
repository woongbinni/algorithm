#include <stdio.h>

int main(){
  int x, y, w, h;
  int ret;
  scanf("%d%d%d%d", &x, &y, &w, &h);

  ret = x;
  if(y < ret){
    ret = y;
  }
  if((w-x) < ret){
    ret = (w-x);
  }
  if((h-y) < ret){
    ret = (h-y);
  }

  printf("%d\n", ret);
  return 0;
}