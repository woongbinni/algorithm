#include <stdio.h>

int main(void){
  char str[101];
  while(scanf("%s", str)!=EOF){
    printf("%s\n", str);
  }
  return 0;
}

