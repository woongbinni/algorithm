#include <stdio.h>

unsigned long long P[101];

int main(){
  int T;
  int N;

  P[1] = 1;
  P[2] = 1;
  P[3] = 1;

  for(int i=4; i<=100; ++i){
    P[i] = P[i-2] + P[i-3];
  }

  scanf("%d", &T);

  for(int i=0; i<T; ++i){
    scanf("%d", &N);
    printf("%llu\n", P[N]);
  }

  return 0;
}