#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[101];

int main(void){
  scanf("%s", str);

  for(int i=0; i<strlen(str); ++i){
    printf("%c", str[i]);

    if((i+1)%10 == 0)
      printf("\n");
  }
  printf("\n");

  return 0;
}
