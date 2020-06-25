#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  char temp;
  char before_char = 0;
  int result = 0;
  
  while(1){
    temp = getchar();
    if(temp == EOF){
      break;
    }

    if(temp != ' ' && temp != '\t' && temp != '\n'){
      if(before_char == 0){
        result += 1;
        before_char = 1;
      }
    }
    else{
      before_char = 0;
    }
  }

  printf("%d\n", result);

  return 0;
}

