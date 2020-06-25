/********************************************************************************
 * ## 문제
 * 집합 A와 B에 각각 N, M개의 자연수가 들어있다. 이제 다음의 행동을 min(N, M)번 시행할 것이다.
 * 집합 A, B에서 각각 자연수 하나씩 고르고, 고른 수는 각 집합에서 삭제한다
 * 고른 두 수의 차를 그룹 C에 넣는다.
 * 우리의 목표는 그룹 C에 있는 원소의 합을 최소로 하는 것이다.
 *
 * ## 입력
 * 첫 번째 줄에 N, M이 공백으로 분리되어 주어진다. (1 ≤ N, M ≤ 1,000)
 * 두 번째 줄에 집합 A의 원소인 N개의 자연수가 공백으로 분리되어 주어진다.
 * 세 번째 줄에 집합 B의 원소인 M개의 자연수가 공백으로 분리되어 주어진다.
 * 모든 집합의 원소는 1 이상 1,000,000 이하이다.
 *
 * ## 출력
 * 첫 번째 줄에 그룹 C의 원소합의 최소값을 출력한다.
 *
 * ## 예제 입력
 * 2 1
 * 10 20
 * 30
 *
 * ## 예제 출력
 * 10
 *
 * ## 힌트
 * D(i, j) = min(D(i-1, j-1) + abs(B[i]-A[j]), D[i][j-1]);
 * ********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MAX 1010
int n, m;
int N[MAX], M[MAX];
int cache[MAX][MAX];

int main()
{
  int i, j;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &N[i]);
  }
  for (i = 1; i <= m; i++)
  {
    scanf("%d", &M[i]);
  }
  sort(&(N[1]), &(N[n + 1]));
  sort(&(M[1]), &(M[m + 1]));

  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= m; j++)
    {
      cache[i][j] = cache[i - 1][j - 1] + abs(N[i] - M[j]);
      if (i > j && cache[i][j] > cache[i - 1][j])
      {
        cache[i][j] = cache[i - 1][j];
      }
      if (j > i && cache[i][j] > cache[i][j - 1])
      {
        cache[i][j] = cache[i][j - 1];
      }
    }
  }
  printf("%d\n", cache[n][m]);
  return 0;
}
