#include <stdio.h>
#include <string.h>

unsigned long long dp[101][10];

int main(){
  int N;
  unsigned long long ret = 0;
  memset(dp, 0x00, sizeof(dp));
  for(int i=1; i<=9; ++i){
    dp[1][i] = 1;
  }
  scanf("%d", &N);

  for(int i=2; i<=N; ++i){
    for(int j=0; j<=9; ++j){
      if(j == 0){
        dp[i][j] = dp[i-1][j+1] % 1000000000;
      }
      else if(j == 9){
        dp[i][j] = dp[i-1][j-1] % 1000000000;
      }
      else {
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
      }
    }
  }

  for(int i=0; i<=9; ++i){
    ret += dp[N][i];
  }

  printf("%llu\n", ret % 1000000000);

  return 0;
}