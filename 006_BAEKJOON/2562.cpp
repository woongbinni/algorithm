#include <stdio.h>

int main(){
  int idx = 0;
  int max = 0;

  for(int i=0; i<9; ++i){
    int temp;
    scanf("%d", &temp);
    if(temp > max){
      max = temp;
      idx = i+1;
    }
  }

  printf("%d\n", max);
  printf("%d\n", idx);

  return 0;
}