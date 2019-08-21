#include <stdio.h>

int main(void){
  int n;
  int dp[100001];
  int max;

  scanf("%d", &n);

  for(int i=1; i<=n; ++i){
    scanf("%d", &(dp[i]));    
  }

  max = dp[1];

  for(int i=2;i<=n;i++) {

    if (dp[i-1] > 0 && dp[i] + dp[i-1] > 0) {
        dp[i] += dp[i-1];
    } 

    if (max < dp[i]) {
        max = dp[i];
    }
  }

  printf("%d\n", max);

  return 0;
}

