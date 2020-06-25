#include <stdio.h>

#define MAX(a, b) (((a)>(b))?(a):(b))

unsigned long long wine[10001];
unsigned long long dp[10001][3];

int main(){
  int N;
  scanf("%d", &N);

  for(int i=1; i<=N; ++i){
    scanf("%llu", &(wine[i]));
  }

  dp[1][0] = wine[1];
  dp[1][1] = wine[1];
  dp[1][2] = 0;
  dp[2][0] = dp[1][1] + wine[2];
  dp[2][1] = wine[2];
  dp[2][2] = wine[1];

  for(int i=3; i<=N; ++i){
    dp[i][0] = dp[i-1][1] + wine[i];
    dp[i][1] = MAX(MAX(dp[i-2][0], dp[i-2][1]), dp[i-2][2]) + wine[i];
    dp[i][2] = MAX(MAX(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
  }

  printf("%llu\n", MAX(MAX(dp[N][0], dp[N][1]), dp[N][2]));

  return 0;
}