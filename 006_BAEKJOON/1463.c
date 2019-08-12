#include <stdio.h>

#define MIN(a, b) (a)<(b)?(a):(b)

int dp[1000001];

int main(){
  int N;
  scanf("%d", &N);

  dp[1] = 0;
  dp[2] = 1;
  dp[3] = 1;

  for(int i=4; i<=N; ++i){
    int temp = dp[i-1] + 1;
    if(i%2==0 && (dp[i/2]+1) < temp){
      temp = dp[i/2]+1;
    }
    if(i%3==0 && (dp[i/3]+1) < temp){
      temp = dp[i/3]+1;
    }
    dp[i] = temp;
  }

  printf("%d\n", dp[N]);

  return 0;
}