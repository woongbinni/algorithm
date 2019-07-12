#include <stdio.h>

int main(){
  int tc;
  int min = 1000000;
  int max = -1000000;
  scanf("%d", &tc);
  while(tc--){
    int temp;
    scanf("%d", &temp);
    if(temp < min){
      min = temp;
    }
    if(temp > max){
      max = temp;
    }
  }
  printf("%d %d\n", min, max);
  return 0;
}