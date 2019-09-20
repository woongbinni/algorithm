#include <stdio.h>
#include <string.h>

#define MIN(A, B) ((A)<(B))?(A):(B)

typedef struct _matrix {
  int r;
  int c;
}matrix;

matrix M[501];
int dp[501][501];

int calc(int start, int end){
  if(start == end){
    return 0;
  }

  if(dp[start][end] != -1){
    return dp[start][end];
  }

  int min = 0x0fffffff;
  for(int i=start; i<end; ++i){
    min = MIN(min, calc(start, i) + calc(i+1, end) + M[start].r *M[i].c * M[end].c);
  }
  dp[start][end] = min;
  return min;
}

int main(void){
  int N;

  scanf("%d", &N);

  for(int i=1; i<=N; ++i){
    for(int j=1; j<=N; ++j){
      dp[i][j] = -1;
    }
  }

  for(int i=1; i<=N; ++i){
    int r, c;
    scanf("%d%d", &r, &c);
    M[i].r = r;
    M[i].c = c;
    dp[i][i] = 0;
  }

  printf("%d\n", calc(1, N));

  return 0;
}