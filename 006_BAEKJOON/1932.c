#include <stdio.h>
#include <string.h>

int triangle[501][501];
unsigned long long dp[501][501];

int main(){
  int n;
  unsigned long long max = 0;

  memset(triangle, 0x00, sizeof(triangle));
  memset(dp, 0x00, sizeof(dp));

  scanf("%d", &n);
  for(int i=1; i<=n; ++i){
    for(int j=1; j<=i; ++j){
      scanf("%d", &(triangle[i][j]));
      dp[i][j] = (dp[i-1][j-1]>dp[i-1][j]?dp[i-1][j-1]:dp[i-1][j]) + triangle[i][j];
      if(max < dp[i][j]){
        max = dp[i][j];
      }
    }
  }

  printf("%llu\n", max);

  return 0;
}