/********************************************************************************
 * https://www.acmicpc.net/problem/1149
 * ********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[1001][3];
int N;
int result = 0x7FFFFFFF;

int main(void) {

  scanf("%d", &N);

  for (int i = 1; i <= N; ++i) {
    int R, G, B;
    scanf("%d%d%d", &R, &G, &B);

    if (i == 1) {
      dp[i][0] = R;
      dp[i][1] = G;
      dp[i][2] = B;
    }
    else {
      dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + R;
      dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + G;
      dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + B;
    }

  }
  for (int j = 0; j < 3; ++j) {
    if (result > dp[N][j])
      result = dp[N][j];
  }

  printf("%d\n", result);

  return 0;
}
