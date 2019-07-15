#include <stdio.h>

int main(){
  unsigned int a, b, c;
  while(1){
    scanf("%d%d%d", &a, &b, &c);
    if(a == 0 && b == 0 && c == 0){
      return 0;
    }
    else{
      a *= a;
      b *= b;
      c *= c;
      if(c == a+b || b == a+c || a == b+c){
        printf("right\n");
      }
      else{
        printf("wrong\n");
      }
    }
  }
  return 0;
}