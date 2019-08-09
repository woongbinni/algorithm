#include <stdio.h>
#include <string.h>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y)) 

int step[301];
int dp[301];


int main(){
  int N;
  memset(dp, 0x00, sizeof(dp));
  scanf("%d", &N);

  for(int i=1; i<=N; ++i){
    scanf("%d", &(step[i]));
  }
  dp[1] = step[1];
  dp[2] = MAX(step[1]+step[2], step[2]);
  dp[3] = MAX(step[1]+step[3], step[2]+step[3]);

  for(int i=4; i<=N; ++i){
    dp[i] = MAX(dp[i-3]+step[i-1]+step[i], dp[i-2]+step[i]);
  }

  printf("%d\n", dp[N]);

  return 0;
}