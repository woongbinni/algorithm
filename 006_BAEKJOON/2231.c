#include <stdio.h>

int main(void){
  int N;
  scanf("%d", &N);
  int i;

  for(i=1; i<=N; ++i){
    int temp = i;
    int sum = i;
    while(temp != 0){
      sum += temp % 10;
      temp /= 10;
    }
    if(sum == N){
      printf("%d\n", i);
      break;
    }
  }
  if(i > N){
    printf("0\n");
  }

  return 0;
}