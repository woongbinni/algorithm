#include <stdio.h>
#include <unistd.h>

unsigned int result[10] = {3, 3, 4, 8, 2, 0, 0, 0, 0, 0};

int main(void){

  unsigned int i;
  int j, k;

  for(i=0; i<7830457; i++){
    k = 0;
    for(j=0; j<10; j++){
      result[j] = (result[j] * 2) + k;
      if(result[j] >= 10){
        k = result[j]/10;
        result[j] %= 10;
      }
      else{
        k = 0;
      }
    }
  }

  k=0;
  result[0] = result[0] + 1;
  for(j=0; j<10; j++){
    result[j] = result[j] + k;
    if(result[j] >= 10){
      result[j] -= 10;
      k = 1;
    }
    else{
      k = 0;
    }
  }

  for(j=9; j>=0; j--){
    printf("%d", result[j]);
  }
  printf("\n");

}