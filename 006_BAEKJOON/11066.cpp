#include <stdio.h>
#include <string.h>

#define MIN(a, b) ((a)<(b))?(a):(b)

int main(void){
  int T, K;
  unsigned int dp[501][501];
  unsigned int file[501];
  unsigned int sum[501];

  scanf("%d", &T);

  for(int i=0; i<T; ++i){
    scanf("%d", &K);
    memset(dp, 0x00, sizeof(dp));
    memset(file, 0x00, sizeof(file));
    memset(sum, 0x00, sizeof(sum));

    for(int j=1; j<=K; ++j){
      scanf("%d", &(file[j]));
      sum[j] = sum[j-1]+file[j];
    }

    for(int k=1; k<K; ++k){
      for(int x=1; x + k <=K; ++x){
        int y = x + k;
        dp[x][y] = __INT_MAX__;

        for(int mid= x; mid < y; ++mid){
          dp[x][y] = MIN(dp[x][y], dp[x][mid] + dp[mid+1][y] + sum[y] - sum[x-1]);
        }
      }
    }

    printf("%d\n", dp[1][K]);
  }
  return 0;
}