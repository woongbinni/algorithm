#include <stdio.h>

#define MAX(a, b) ((a)>(b))?(a):(b)

unsigned long long wine[10001];
unsigned long long dp[10001];

int main(){
  int N;
  scanf("%d", &N);

  for(int i=1; i<=N; ++i){
    scanf("%llu", &(wine[i]));
  }

  dp[1] = wine[1];
  dp[2] = wine[1] + wine[2];
  dp[3] = MAX(wine[1] + wine[3], wine[2]+wine[3]);

  for(int i=4; i<=N; ++i){
    dp[i] = MAX(dp[i-3]+wine[i-2]+wine[i], dp[i-3]+wine[i-1]+wine[i]);
  }

  printf("%llu\n", dp[N]);

  return 0;
}