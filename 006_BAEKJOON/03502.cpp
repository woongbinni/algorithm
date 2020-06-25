#include <stdio.h>

int main(){
  char rest[42] = {0, };
  int ret = 0;
  for(int i=0; i<10; ++i){
    int temp;
    scanf("%d", &temp);
    if(rest[temp % 42] == 0){
      ret += 1;
    }
    rest[temp % 42] += 1;
  }
  printf("%d\n", ret);
  
  return 0;
}