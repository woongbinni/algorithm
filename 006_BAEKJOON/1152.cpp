#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  char temp;
  char before_temp;
  int result = 0;
  while(1){
    before_temp = temp;
    temp = getchar();
    if(temp == ' '){
      if(before_temp != ' '){
        result += 1;
      }
    }
    else if(temp == EOF){
      if(before_temp != ' '){
        result += 1;
      }
      break;
    }
  }

  printf("%d\n", result);

  return 0;
}

