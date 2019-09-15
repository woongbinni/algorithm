#include <stdio.h>
#include <string.h>

#define MIN(A, B) ((A)<(B))?(A):(B)

typedef struct _matrix {
  int r;
  int c;
}matrix;

matrix M[501];
int dp[501][501];

int main(void){
  int N;
  memset(dp, 0x00, sizeof(dp));

  scanf("%d", &N);
  for(int i=1; i<=N; ++i){
    int r, c;
    scanf("%d%d", &r, &c);
    M[i].r = r;
    M[i].c = c;
    dp[i][i] = 0;
    if(i >= 2){
      dp[i-1][i] = M[i-1].r * M[i].r * M[i].c;
    }
  }

  for(int i=2; i<=N-1; ++i){
    for(int j=1; j<=N-i; ++j){
      int k=j+i;
      dp[j][k] = MIN((dp[j][k-1]+(M[j].r*M[k].r*M[k].c)), ((M[j].r*M[j].c*M[k].c) + dp[j+1][k]));
    }
  }

  printf("%d\n", dp[1][N]);

  return 0;
}